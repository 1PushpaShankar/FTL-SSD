#ifndef APP_DEFS_H
#define APP_DEFS_H

/*	Fake NAND:        32 KiB
	Page size:        64 bytes
	Pages per block:  16
	Blocks:           32
	Physical pages:   512
	Logical pages:    384
	Spare pages:      128
*/

/*Geometry definitions */
#define PAGE_SIZE             64U
#define PAGE_SPARE_SIZE       16U
#define PAGE_TOTAL_SIZE       (PAGE_SIZE + PAGE_SPARE_SIZE)  /* 80 */
#define PAGES_PER_BLOCK       16U
#define BLOCK_COUNT           32U
#define PHY_PAGE_COUNT        (BLOCK_COUNT * PAGES_PER_BLOCK )
#define LOGICAL_PAGE_COUNT    384U
#define SPARE_PAGE_COUNT      (PHY_PAGE_COUNT - LOGICAL_PAGE_COUNT)

/* Offsets within the spare area */
#define SPARE_ECC_OFFSET       0U   /* bytes 0-1: ECC parity */
#define SPARE_ECC_SIZE         2U
#define SPARE_BB_MARKER_OFFSET 2U  /* byte 2: bad-block marker */
#define SPARE_VALID_OFFSET     3U  /* byte 3: page-valid / written flag */
#define SPARE_META_OFFSET      4U  /* bytes 4-15: reserved for future */

#define FTL_INVALID_PPA       (0xFFFFFFFFU)
#define BLOCK_INVALID         (0xFFFFFFFFU)
#define LPA_INVALID           ((lpa_t) -1)
#define ECC_ENABLED           1U

#define LOW_WATERMARK_GC   8U
#define HIGH_WATERMARK_GC  16U
#define GC_NO_VICTIM_BLOCK  ((uint16_t)0xFFFF)
#define MAX_ERASE_COUNT    10U
#define NO_EXCLUDED_BLOCK  UINT32_MAX

/* Virtual codeword positions:
 * 1..522 hold data and the 10 Hamming parity bits.
 * Position 523 holds the overall (SECDED) parity bit.
 * Hamming parity positions: 1,2,4,8,16,32,64,128,256,512.
 */
#define CW_SIZE        524u           /* index 0 unused */
#define OVERALL_POS    523u
#define NUM_HAM_PARITY 10u

#define ECC_DATA_BYTES        PAGE_SIZE
#define ECC_PARITY_BYTES      2U
#define ECC_PARITY_OFFSET     PAGE_SIZE
#define PAGE_VALID_OFFSET     (ECC_DATA_BYTES + ECC_PARITY_BYTES)
#define PAGE_VALID_PATTERN    0xA5U

#define WL_SPREAD_THRESHOLD  10U
#define WL_CHECK_INTERVAL_WRITES            100U
#define WL_MIN_FREE_BLOCKS                  5U


#define GPIOAEN			(1U<<0)
#define UART2EN			(1U<<17)
#define CR1_TE			(1U<<3)
#define CR1_RE          (1U<<2)
#define CR1_UE			(1U<<13)

#define SR_TXE			(1U<<7)
#define SR_RXNE			(1U<<5)
#define CR1_RXNEIE      (1U<<5)


#define SYS_FREQ		16000000
#define APB1_CLK		SYS_FREQ

#define UART_BAUDRATE	115200

#endif
