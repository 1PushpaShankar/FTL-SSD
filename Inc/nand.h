#ifndef NAND_H
#define NAND_H

/*	Fake NAND:        32 KiB
	Page size:        64 bytes
	Pages per block:  16
	Blocks:           32
	Physical pages:   512
	Logical pages:    384
	Spare pages:      128
*/

/* Header inclusions */
#include <stdint.h>
#include <math.h>
#include "ftl.h"

typedef enum
{
	NAND_PROGRAM_OK = 0,
	NAND_READ_OK,
	NAND_ERASE_OK,
} nand_status_t;

/* Public initialization API */
void nand_init(void);
nand_status_t nand_program(uint32_t ppn, const uint8_t *data_buffer);
nand_status_t nand_read(uint32_t ppn, uint8_t *data_buffer);
nand_status_t nand_erase(uint8_t block_number);

#endif
