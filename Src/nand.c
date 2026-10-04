
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "nand.h"
#include "ftl.h"

/* Internal NAND flash array */
static uint8_t nand_array[BLOCK_COUNT][PAGES_PER_BLOCK][PAGE_SIZE];

void nand_init(void)
{
	memset(nand_array, 0xFF, sizeof(nand_array));
}

nand_status_t nand_program(ppa_t ppn, const uint8_t *data_buffer){

	uint8_t block_number = ppn/PAGES_PER_BLOCK;
	uint8_t page_number  = ppn % PAGES_PER_BLOCK;
	memcpy(nand_array[block_number][page_number], data_buffer, PAGE_SIZE);

	return NAND_PROGRAM_OK;
}

nand_status_t nand_read(uint32_t ppn, uint8_t *data_buffer){

	uint16_t block_number = ppn/PAGES_PER_BLOCK;
	uint16_t page_number  = ppn % PAGES_PER_BLOCK;
	memcpy(data_buffer, nand_array[block_number][page_number], PAGE_SIZE);

	return NAND_READ_OK;
}


nand_status_t nand_erase(uint16_t block_number){

    uint32_t  first_ppn = block_number * PAGES_PER_BLOCK;
    uint32_t  last_ppn  = first_ppn  + PAGES_PER_BLOCK - 1;

    for(uint32_t ppn = first_ppn; ppn  <= last_ppn; ppn++ ){
		//page_status_t st = nand_get_page_status(ppn);
		//assert(st != PAGE_PROGRAMMED);
		memset(nand_array[block_number][ppn - first_ppn], 0xFF, PAGE_SIZE);
    }

   return NAND_ERASE_OK;
}

