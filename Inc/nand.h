#ifndef NAND_H
#define NAND_H


/* Header inclusions */
#include <stdint.h>
#include <math.h>
#include "ftl.h"
#include "app_defs.h"
#include "app_status.h"

/* Public initialization API */
void nand_init(void);
nand_status_t nand_program(uint32_t ppn, const uint8_t *data_buffer);
nand_status_t nand_read(uint32_t ppn, uint8_t *data_buffer);
nand_status_t nand_erase(uint16_t block_number);

#endif
