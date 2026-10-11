#ifndef APP_STATUS_H
#define APP_STATUS_H

typedef uint32_t lpa_t;
typedef uint32_t ppa_t;

typedef enum{
 ECC_OK,
 ECC_CORRECTED,
 ECC_UNCORRECTABLE,
 ECC_ERROR,
}ecc_status_t;

typedef enum
{
    FTL_OK,
    FTL_ERR_NULL_BUFFER,
    FTL_ERR_BAD_LPA,
    FTL_ERR_NO_FREE_PAGE,
    FTL_ERR_MAPPING,
    FTL_ERR_NAND,
	FTL_ERR_BAD_PPN,
	FTL_ERR_BAD_BLOCK ,
	FTL_ERR_PAGE_INVALID,
}ftl_status_t;

typedef enum {
	BLOCK_ERR_INVALID,
	BAD_BLOCK,
}block_state;

typedef enum
{
	PAGE_FREE = 0,
	PAGE_PROGRAMMED,
	PAGE_INVALID,

} page_status_t;

typedef enum
{
	GC_OK = 0,
	GC_NO_VICTIM,
	GC_MIGRATED_VICTIM,
	GC_NAND_ERROR,
	GC_NO_FREE_SPACE,
	GC_NO_DESTINATION,
} gc_status_t;

typedef enum
{
	NAND_PROGRAM_OK = 0,
	NAND_READ_OK,
	NAND_ERASE_OK,
	NAND_PROGRAM_ERR,
	NAND_READ_ERR,
	NAND_ERASE_ERR,
}nand_status_t;

typedef enum{
	WL_OK,
	WL_NONE_FOUND,
	WL_NOT_NEEDED,
	WL_MIGRATION_ERROR,
	WL_ERASE_ERROR,
}wl_status_t;



#endif
