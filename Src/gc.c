#include <stdint.h>
#include <math.h>
#include "nand.h"
#include "gc.h"
#include "ftl.h"

#define GC_NO_VICTIM_BLOCK  ((uint16_t)0xFFFF)

gc_status_t run_gc(){

	uint16_t victim = gc_select_victim_block();
	if(victim == GC_NO_VICTIM_BLOCK){
		return GC_NO_VICTIM;
	}
	gc_status_t m_status = gc_migrate_valid_pages(victim);
	if(m_status != GC_MIGRATED_VICTIM){
		return m_status;
	}
	gc_status_t e_status = gc_erase_victim_block(victim);
	if(e_status != GC_MIGRATED_VICTIM){
		return e_status;
	}

	return GC_OK;

}

uint16_t gc_select_victim_block(void){
	uint16_t victim = GC_NO_VICTIM;
	uint16_t max_invalid = 0;
	for(uint16_t b = 0; b < BLOCK_COUNT; b++){
		uint16_t invalid = block_table[b].invalid_page_count;
		if(invalid == 0){
			continue;
		}

		if(invalid >= max_invalid ){
			max_invalid = invalid;
			victim = b;
		}
	}
	return victim;
}

gc_status_t gc_migrate_valid_pages(uint16_t victim){
	 uint16_t pages = victim * PAGES_PER_BLOCK;
	 uint8_t temp_buffer[PAGE_SIZE];
	 if(block_table[victim].is_bad ) return BAD_BLOCK;

     for (uint16_t old_ppn = pages; old_ppn < (pages + PAGES_PER_BLOCK); old_ppn++ ){
    	 if(page_state[old_ppn] != PAGE_PROGRAMMED){
    		 continue;
    	 }

    	 lpa_t lpa = ppa_lpa[old_ppn];
		 nand_status_t r_status = nand_read(old_ppn, temp_buffer);
		 if(r_status != NAND_READ_OK){
			 return GC_NAND_ERROR;
		  }

		 ppa_t new_ppn = allocate_free_ppa();
		 if(new_ppn == FTL_INVALID_PPA){
			 return GC_NO_DESTINATION;

		 }
		 nand_status_t p_status = nand_program(new_ppn, temp_buffer);
		 if(p_status != NAND_PROGRAM_OK){
			return GC_NAND_ERROR;
		 }
		 /*update the mapping table*/
		 /*put a mutex lock here later*/

		 ftl_map[lpa]        = new_ppn;
		 ppa_lpa[new_ppn]    = lpa;
		 page_state[old_ppn] = PAGE_INVALID;

		 /*Update the block table counters for both the old and new blocks*/
		 block_table[victim].valid_page_count--;
		 block_table[victim].invalid_page_count++;

		 page_state[new_ppn] = PAGE_PROGRAMMED;
		 uint16_t new_block  = new_ppn/PAGES_PER_BLOCK;
		 block_table[new_block].valid_page_count++;
		 block_table[new_block].free_page_count--;

    	 }
     return GC_MIGRATED_VICTIM;
}
/* Erase function - Do not update maps here*/
gc_status_t gc_erase_victim_block(uint16_t victim){
	nand_status_t e_status = nand_erase(victim);

	if(e_status != NAND_ERASE_OK){
		block_table[victim].is_bad = 1;
		block_table[victim].valid_page_count   = 0;
		block_table[victim].invalid_page_count = 0;
		block_table[victim].free_page_count    = PAGES_PER_BLOCK;
		return GC_NAND_ERROR;
	}

	ppa_t start =  victim * PAGES_PER_BLOCK;
	ppa_t end   =  start  + PAGES_PER_BLOCK;

	for(ppa_t ppa = start; ppa < end; ppa++){
		  ppa_lpa[ppa] = LPA_INVALID;
		  ftl_set_page_status(ppa, PAGE_FREE);
	  }

	block_table[victim].erase_count++;
	if(block_table[victim].erase_count >= MAX_ERASE_COUNT ){
		block_table[victim].is_bad = 1U;
		block_table[victim].valid_page_count   = 0;
		block_table[victim].invalid_page_count = 0;
		block_table[victim].free_page_count    = PAGES_PER_BLOCK;
	}
	block_table[victim].valid_page_count   = 0;
	block_table[victim].invalid_page_count = 0;
	block_table[victim].free_page_count    = PAGES_PER_BLOCK;

	return GC_OK;

}
