
#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "nand.h"
#include "ftl.h"
#include "gc.h"

ppa_t ftl_map[LOGICAL_PAGE_COUNT];
block_stats_t block_table[BLOCK_COUNT];
page_status_t page_state[BLOCK_COUNT * PAGES_PER_BLOCK];
lpa_t ppa_lpa[PHY_PAGE_COUNT];



ftl_status_t ftl_init(){
  for(lpa_t lpa = 0U; lpa < LOGICAL_PAGE_COUNT; lpa++){
	  ftl_map[lpa] = FTL_INVALID_PPA;
  }

  for(ppa_t ppa = 0U; ppa < PHY_PAGE_COUNT ; ppa++){
	  ppa_lpa[ppa] = LPA_INVALID;
  }

  for(uint8_t block = 0; block < BLOCK_COUNT; block++){
	  block_table[block].valid_page_count   = 0;
	  block_table[block].invalid_page_count = 0;
	  block_table[block].erase_count        = 0;
	  block_table[block].read_count         = 0;
	  block_table[block].reprogram_count    = 0;
	  block_table[block].free_page_count    = PAGES_PER_BLOCK;
   }

  for(ppa_t ppn = 0U; ppn < PHY_PAGE_COUNT ; ppn++){
	  ftl_set_page_status(ppn, PAGE_FREE);
  }

  nand_init();

  return FTL_OK;
}

page_status_t ftl_get_page_status(uint32_t ppn){
	assert(ppn < PHY_PAGE_COUNT);
	return page_state[ppn];
}

void ftl_set_page_status(ppa_t ppn, page_status_t status ){
	assert(ppn < PHY_PAGE_COUNT);
	page_state[ppn] = status;
}

static ppa_t get_free_page_spare(){
	for(ppa_t ppn = 0 ; ppn < PHY_PAGE_COUNT; ppn++){
		if(ftl_get_page_status(ppn) == PAGE_FREE){
			 return ppn;
		}
	}
	return FTL_INVALID_PPA;
}

uint32_t get_free_block_count(){
	uint32_t count = 0;
	for (uint32_t block = 0; block < BLOCK_COUNT; block++){
		if (block_table[block].free_page_count == PAGES_PER_BLOCK){
			count ++;
		}
	}

	return count;
}

ppa_t allocate_free_ppa(void){
	ppa_t ppn = get_free_page_spare();
	if(ppn == FTL_INVALID_PPA) {
		return FTL_INVALID_PPA;
	}
	return ppn;
}

uint8_t ftl_get_block_number(ppa_t ppn){
	uint8_t block_number = ppn/PAGES_PER_BLOCK;
	return block_number;

}

uint8_t ftl_get_page_number(ppa_t ppn){
	uint8_t page_number = ppn % PAGES_PER_BLOCK;
	return page_number;
}

ftl_status_t ftl_program(lpa_t lpa, const uint8_t *data_buffer){
	 if(data_buffer == NULL){
       return FTL_ERR_NULL_BUFFER;
	 }
      if(lpa >= LOGICAL_PAGE_COUNT ){
    	  return FTL_ERR_BAD_LPA;
      }
      ppa_t old_ppn =  ftl_map[lpa];
      ppa_t new_ppn = allocate_free_ppa();

      if(new_ppn == FTL_INVALID_PPA){
    	  gc_status_t gc_status =  run_gc();
		  new_ppn = allocate_free_ppa();
    	  if(new_ppn == FTL_INVALID_PPA){
    		  return  FTL_ERR_NO_FREE_PAGE;
      }
    }

      nand_status_t status = nand_program(new_ppn, data_buffer);
      if(status != NAND_PROGRAM_OK){
    	  return FTL_ERR_NAND;
      }

      ftl_map[lpa]     = new_ppn;
      ppa_lpa[new_ppn] = lpa;
      ftl_set_page_status(new_ppn, PAGE_PROGRAMMED );

      uint16_t new_block = ftl_get_block_number(new_ppn);
      block_table[new_block].valid_page_count++ ;
      block_table[new_block].free_page_count--;

      if(old_ppn != FTL_INVALID_PPA ){
          ftl_set_page_status(old_ppn, PAGE_INVALID);
          ppa_lpa[old_ppn]  = LPA_INVALID;
          uint16_t old_block = ftl_get_block_number(old_ppn);
		  block_table[old_block].invalid_page_count++ ;
		  block_table[old_block].valid_page_count-- ;
      }

      return FTL_OK;
}

static ftl_status_t ftl_erase(lpa_t lpa){
	if(lpa >= LOGICAL_PAGE_COUNT ){
		return FTL_ERR_BAD_LPA;
	}

	ppa_t ppn = ftl_map[lpa];

	if (ppn == FTL_INVALID_PPA) {
		return FTL_ERR_MAPPING;
	}

	uint8_t block_number = ftl_get_block_number(ppn);

	if (block_number >= BLOCK_COUNT) {
	    return FTL_ERR_BAD_PPN;
	}

	nand_status_t status = nand_erase(block_number);
	if(status != NAND_ERASE_OK){
	   return FTL_ERR_NAND;
	}

	ppa_t start =  block_number * PAGES_PER_BLOCK;
	ppa_t end   =  start  + PAGES_PER_BLOCK;

	for(ppa_t ppa = start; ppa < end; ppa++){
		  lpa_t lpa    = ppa_lpa[ppa];

		  if (lpa != LPA_INVALID) {
			  ppa_lpa[ppa] = LPA_INVALID;
			  ftl_set_page_status(ppa, PAGE_FREE);
			  ftl_map[lpa] = FTL_INVALID_PPA;
		  }
	 }
	block_table[block_number].erase_count++;
	block_table[block_number].valid_page_count   = 0;
	block_table[block_number].invalid_page_count = 0;
	block_table[block_number].free_page_count    = PAGES_PER_BLOCK;

	return FTL_OK;
}

ftl_status_t ftl_read(lpa_t lpa, uint8_t *receiver_buffer){
	if(receiver_buffer == NULL){
	    return FTL_ERR_NULL_BUFFER;
	}
	if(lpa >= LOGICAL_PAGE_COUNT ){
	   return FTL_ERR_BAD_LPA;
	 }
	ppa_t ppn = ftl_map[lpa];

	if (ppn == FTL_INVALID_PPA) {
	    return FTL_ERR_MAPPING;
	}

	nand_status_t status = nand_read(ppn, receiver_buffer);
	 if(status != NAND_READ_OK){
		 return FTL_ERR_NAND;
	 }
	 uint8_t block_number = ftl_get_block_number(ppn);
	 block_table[block_number].read_count++;

  return FTL_OK;

}

