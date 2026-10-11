#ifndef FTL_H
#define FTL_H

#include <stdint.h>
#include <stdbool.h>
#include "nand.h"
#include "app_defs.h"
#include "app_status.h"
#include "stats.h"

extern volatile bool gc_requested;
extern volatile bool wl_requested;
extern block_stats_t block_table[BLOCK_COUNT];
extern ppa_t ftl_map[LOGICAL_PAGE_COUNT];
extern lpa_t ppa_lpa[PHY_PAGE_COUNT];
extern page_status_t page_state[BLOCK_COUNT * PAGES_PER_BLOCK];


ppa_t get_free_page_spare(uint32_t exclude_blk);
page_status_t ftl_get_page_status(uint32_t ppn);
void ftl_set_page_status(uint32_t ppn, page_status_t status);
ftl_status_t ftl_init(void);
ppa_t allocate_free_ppa(void);
ftl_status_t ftl_program(lpa_t lpa, const uint8_t *data_buffer);
ftl_status_t ftl_read(lpa_t lpa, uint8_t *receiver_buffer);
uint32_t get_free_block_count();
void map_lock(void);
void map_unlock(void);


#endif
