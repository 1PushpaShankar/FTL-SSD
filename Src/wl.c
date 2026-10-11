#include <stdint.h>
#include <math.h>
#include "nand.h"
#include "gc.h"
#include "wl.h"
#include "ftl.h"
#include "stats.h"
#include "profiler.h"


void wl_compute_erase_count(uint32_t *maxCount_er, uint32_t *minCount_er ){
	uint32_t minCount = UINT32_MAX;
	uint32_t maxCount = 0 ;

	for(uint16_t b = 0; b < BLOCK_COUNT; b++){
		if (block_table[b].is_bad) continue;
		uint32_t ec = block_table[b].erase_count;
		minCount = ec < minCount ?  ec : minCount;
		maxCount = ec > maxCount ?  ec : maxCount;
		}

	*maxCount_er = maxCount;
	*minCount_er = minCount;
}

wl_status_t wl_run(uint32_t *minCount_er){
	/*Loop over the blocks and Check if the block is bad, if bad continue to check the next one*/
	/*A block is cold block if its erase count is too low - close to minCount_er*/
	/* has many valid pages*/
	/* Force it to be erased, so that its erase count goes up and the erase spread is even*/
	for(uint16_t b = 0; b < BLOCK_COUNT; b++){
		if(block_table[b].is_bad) continue;
		if(block_table[b].erase_count == *minCount_er) {
			gc_status_t m_status = gc_migrate_valid_pages(b);
				if(m_status != GC_MIGRATED_VICTIM){
					return WL_MIGRATION_ERROR;
				}
				gc_status_t e_status = gc_erase_victim_block(b);
				if(e_status != GC_OK){
					return WL_ERASE_ERROR;
				}
			 }
		}
	return WL_OK;
	}

wl_status_t wl_checkand_run(void){
	uint32_t start = profiler_get_cycles();
	uint32_t minCount;
	uint32_t maxCount;
	wl_compute_erase_count(&maxCount, &minCount);
	uint32_t spread = maxCount - minCount;
	if(spread < WL_SPREAD_THRESHOLD){
		uint32_t elapsed = profiler_elapsed_cycles(start);
		stats_report_wl(elapsed);
		return WL_NOT_NEEDED;
	}
	wl_status_t wl_st = wl_run(&minCount);
	uint32_t elapsed = profiler_elapsed_cycles(start);
	stats_report_wl(elapsed);
	return wl_st;
}
