#include <stdint.h>
#include <math.h>
#include "nand.h"
#include "gc.h"
#include "ftl.h"

#define WL_SPREAD_THRESHOLD  10U
#define WL_CHECK_INTERVAL_WRITES 100U

typedef enum{
	WL_OK,
	WL_NONE_FOUND,
	WL_NOT_NEEDED,
	WL_MIGRATION_ERROR,
	WL_ERASE_ERROR,
}wl_status_t;

wl_status_t wl_run(uint32_t *minCount_er);
void wl_compute_erase_count(uint32_t *maxCount_er, uint32_t *minCount_er );
wl_status_t wl_checkand_run(void);
