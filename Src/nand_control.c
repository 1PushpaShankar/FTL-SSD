#include <stdint.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "FreeRTOS.h"
#include "task.h"
#include "nand.h"
#include "nand_control.h"


static ecc_status_t ecc_encode(const uint8_t *data, uint8_t *parity_out);
static ecc_status_t ecc_decode(uint8_t *data, const uint8_t *parity, int *corrected_bits);
nand_status_t nand_control_erase_block(uint16_t block_number);

static const uint32_t ham_parity_pos[NUM_HAM_PARITY] = {
    1u, 2u, 4u, 8u, 16u, 32u, 64u, 128u, 256u, 512u
};

static int is_ham_parity_pos(uint32_t pos)
{
    for (uint32_t i = 0u; i < NUM_HAM_PARITY; i++) {
        if (ham_parity_pos[i] == pos) {
            return 1;
        }
    }
    return 0;
}


nand_status_t nand_control_program_page(ppa_t ppn, const uint8_t* data64){

	uint8_t page_image[PAGE_TOTAL_SIZE];
	uint8_t ecc_parity[ECC_PARITY_BYTES];
	ecc_status_t ecc_rc = ecc_encode(data64, ecc_parity);

	if (ecc_rc != ECC_OK) {
	    return ECC_ERROR;
	}

	/* Build the 80-byte page image */
	memset(page_image, 0xFF, PAGE_TOTAL_SIZE );
	memcpy(page_image, data64, PAGE_SIZE);
	memcpy(&page_image[ECC_PARITY_OFFSET], ecc_parity, ECC_PARITY_BYTES );
	page_image[PAGE_VALID_OFFSET] = PAGE_VALID_PATTERN;

	nand_status_t ns = nand_program(ppn, page_image);
	if(ns != NAND_PROGRAM_OK){
		 return NAND_PROGRAM_ERR;
	}

	return NAND_PROGRAM_OK;
}

nand_status_t nand_control_read_page(ppa_t ppa, uint8_t* data64){
	uint8_t  page_image[PAGE_TOTAL_SIZE];
    uint8_t  ecc_parity[ECC_PARITY_BYTES];
    uint8_t  corrected_data[ECC_DATA_BYTES];
    nand_status_t ns = nand_read(ppa, page_image );

    if(ns != NAND_READ_OK){
    	return NAND_READ_ERR;
    }

    if (page_image[PAGE_VALID_OFFSET] != PAGE_VALID_PATTERN) {
           return NAND_READ_ERR;
       }

    memcpy(ecc_parity, &page_image[ECC_PARITY_OFFSET], ECC_PARITY_BYTES);
    ecc_status_t ecc_drc = ecc_decode(page_image, ecc_parity, (int*) corrected_data);
    if (ecc_drc == ECC_UNCORRECTABLE) {
           return NAND_READ_ERR;
       }
    memcpy(data64, page_image, PAGE_SIZE);

      return NAND_READ_OK;
}

nand_status_t nand_control_erase_block(uint16_t block_number)
{
    if (block_number >= BLOCK_COUNT) {
        return NAND_ERASE_ERR;
    }

    return nand_erase(block_number);
}

static void build_codeword(const uint8_t *data,  const uint8_t *parity, uint8_t cw[CW_SIZE])

{
    uint32_t data_bit = 0u;

    for (uint32_t pos = 1u; pos < OVERALL_POS; pos++) {
        if (is_ham_parity_pos(pos)) {
            continue;
        }
        cw[pos] = (data[data_bit >> 3] >> (data_bit & 7u)) & 1u;
        data_bit++;
    }

    for (uint32_t i = 0u; i < NUM_HAM_PARITY; i++) {
        uint32_t p = ham_parity_pos[i];
        cw[p] = (parity[i >> 3] >> (i & 7u)) & 1u;
    }

    cw[OVERALL_POS] = (parity[1] >> 2) & 1u;
}

/* Write corrected data bits back from codeword to the 64-byte buffer. */
static void extract_data(const uint8_t cw[CW_SIZE], uint8_t *data)
{
    uint32_t data_bit = 0u;

    for (uint32_t i = 0u; i < ECC_DATA_BYTES; i++) {
        data[i] = 0u;
    }

    for (uint32_t pos = 1u; pos < OVERALL_POS; pos++) {
        if (is_ham_parity_pos(pos)) {
            continue;
        }
        data[data_bit >> 3] |= (uint8_t)(cw[pos] << (data_bit & 7u));
        data_bit++;
    }
}

static ecc_status_t ecc_encode(const uint8_t *data, uint8_t *parity_out)
{
    uint8_t cw[CW_SIZE] = {0u};
    uint32_t data_bit = 0u;
    uint8_t overall = 0u;

    /* Place data bits at non-parity positions. */
    for (uint32_t pos = 1u; pos < OVERALL_POS; pos++) {
        if (is_ham_parity_pos(pos)) {
            continue;
        }
        cw[pos] = (data[data_bit >> 3] >> (data_bit & 7u)) & 1u;
        data_bit++;
    }


    for (uint32_t i = 0u; i < NUM_HAM_PARITY; i++) {
        uint32_t p = ham_parity_pos[i];
        uint8_t sum = 0u;

        for (uint32_t pos = 1u; pos < OVERALL_POS; pos++) {
            if ((pos & p) != 0u && pos != p) {
                sum ^= cw[pos];
            }
        }
        cw[p] = sum;
    }

    /* Overall parity: make the number of 1s in positions 1..522 even. */
    for (uint32_t pos = 1u; pos < OVERALL_POS; pos++) {
        overall ^= cw[pos];
    }
    cw[OVERALL_POS] = overall;
    *(parity_out)     = 0U;
    *(parity_out + 1) = 0U;

    for (uint32_t i = 0u; i < NUM_HAM_PARITY; i++) {
        if (cw[ham_parity_pos[i]] != 0u) {
        	parity_out[i >> 3] |= (uint8_t)(1u << (i & 7u));
        }
    }
    if (cw[OVERALL_POS] != 0u) {
    	parity_out[1] |= (uint8_t)(1u << 2);
    }

    return ECC_OK;
}

static ecc_status_t ecc_decode(uint8_t *data, const uint8_t *parity, int *corrected_bits)

{
    uint8_t cw[CW_SIZE];
    uint32_t syndrome = 0u;
    uint8_t overall = 0u;
    int overall_bad;

    if (corrected_bits != NULL) {
        *corrected_bits = 0;
    }

    build_codeword(data, parity, cw);

    for (uint32_t i = 0u; i < NUM_HAM_PARITY; i++) {
        uint32_t p = ham_parity_pos[i];
        uint8_t sum = 0u;

        for (uint32_t pos = 1u; pos < OVERALL_POS; pos++) {
            if ((pos & p) != 0u && pos != p) {
                sum ^= cw[pos];
            }
        }

        if (sum != cw[p]) {
            syndrome |= p;
        }
    }

    /* Overall parity check: XOR of positions 1..522 must equal the
     * stored overall parity bit. */
    for (uint32_t pos = 1u; pos < OVERALL_POS; pos++) {
        overall ^= cw[pos];
    }
    overall_bad = (overall != cw[OVERALL_POS]);

    if (syndrome == 0u && !overall_bad) {
        return ECC_OK;
    }

    if (syndrome != 0u && overall_bad) {
        /* Single-bit error: syndrome is the error position. */
        if (syndrome < OVERALL_POS) {
            cw[syndrome] ^= 1u;
            extract_data(cw, data);
            if (corrected_bits != NULL) {
                *corrected_bits = 1;
            }
            return ECC_CORRECTED;
        }
        return ECC_UNCORRECTABLE;
    }

    if (syndrome != 0u && !overall_bad) {
        /* Two data/parity-bit errors: syndrome is meaningless. */
        return ECC_UNCORRECTABLE;
    }

    /* syndrome == 0 but overall parity is wrong:
     * the overall parity bit itself was flipped. */
    if (corrected_bits != NULL) {
        *corrected_bits = 1;
    }
    return ECC_CORRECTED;
}


