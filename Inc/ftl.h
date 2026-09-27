#ifndef FTL_H
#define FTL_H

#include <stdint.h>
#include <stdbool.h>
#include "nand.h"

/*Geometry definitions */
#define PAGE_SIZE             64U
#define PAGES_PER_BLOCK       16U
#define BLOCK_COUNT           32U
#define PHY_PAGE_COUNT        (BLOCK_COUNT * PAGES_PER_BLOCK )
#define LOGICAL_PAGE_COUNT    384U
#define SPARE_PAGE_COUNT      (PHY_PAGE_COUNT - LOGICAL_PAGE_COUNT)

#define FTL_INVALID_PPA       (0xFFFFFFFFU)
#define LPA_INVALID           ((lpa_t) -1)

#define LOW_WATERMARK_GC   8U
#define HIGH_WATERMARK_GC  16U

typedef uint32_t lpa_t;
typedef uint32_t ppa_t;
// In ftl.h (or tasks.h)
extern volatile bool gc_requested;

typedef enum
{
    FTL_OK,
    FTL_ERR_NULL_BUFFER,
    FTL_ERR_BAD_LPA,
    FTL_ERR_NO_FREE_PAGE,
    FTL_ERR_MAPPING,
    FTL_ERR_NAND,
	FTL_ERR_BAD_PPN,
	FTL_ERR_BAD_BLOCK ,
	FTL_ERR_PAGE_INVALID,
}ftl_status_t;

typedef struct{
	uint16_t valid_page_count;
	uint16_t invalid_page_count;
	uint16_t erase_count;
	uint16_t read_count;
	uint16_t reprogram_count;
	uint16_t free_page_count;
}block_stats_t;

typedef enum
{
	PAGE_FREE = 0,
	PAGE_PROGRAMMED,
	PAGE_INVALID,

} page_status_t;

extern block_stats_t block_table[BLOCK_COUNT];
extern ppa_t ftl_map[LOGICAL_PAGE_COUNT];
extern lpa_t ppa_lpa[PHY_PAGE_COUNT];
extern page_status_t page_state[BLOCK_COUNT * PAGES_PER_BLOCK];

int16_t get_free_page();
page_status_t ftl_get_page_status(uint32_t ppn);
void ftl_set_page_status(uint32_t ppn, page_status_t status);
ftl_status_t ftl_init(void);
ppa_t allocate_free_ppa(void);
ftl_status_t ftl_program(lpa_t lpa, const uint8_t *data_buffer);
ftl_status_t ftl_read(lpa_t lpa, uint8_t *receiver_buffer);
uint32_t get_free_block_count();


#endif
