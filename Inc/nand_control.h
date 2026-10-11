
#ifndef NAND_CONTROL_H
#define NAND_CONTROL_H

#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <stdbool.h>
#include "nand.h"
#include "ftl.h"
#include "FreeRTOS.h"
#include "task.h"
#include "nand.h"
#include "app_defs.h"
#include "app_status.h"

nand_status_t nand_control_program_page(ppa_t ppn, const uint8_t* data64);
nand_status_t nand_control_read_page(ppa_t ppa, uint8_t* data64);
nand_status_t nand_control_erase_block(uint16_t block_number);


#endif
