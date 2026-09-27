#ifndef GC_H
#define GC_H

#include <stdint.h>
#include <math.h>
#include <stdbool.h>
#include "nand.h"
#include "ftl.h"

typedef enum
{
	GC_OK = 0,
	GC_NO_VICTIM,
	GC_MIGRATED_VICTIM,
	GC_NAND_ERROR,
	GC_NO_FREE_SPACE,
	GC_NO_DESTINATION,
} gc_status_t;


gc_status_t run_gc();
uint16_t gc_select_victim_block(void);
gc_status_t gc_migrate_valid_pages(uint16_t victim);
gc_status_t gc_erase_victim_block(uint16_t victim);

#endif
