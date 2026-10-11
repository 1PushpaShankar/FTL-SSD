#include <stdint.h>
#include <math.h>
#include "nand.h"
#include "gc.h"
#include "ftl.h"
#include "app_defs.h"
#include "app_status.h"

wl_status_t wl_run(uint32_t *minCount_er);
void wl_compute_erase_count(uint32_t *maxCount_er, uint32_t *minCount_er );
wl_status_t wl_checkand_run(void);
