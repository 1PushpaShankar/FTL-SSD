#ifndef STATS_H
#define STATS_H

#include <stdint.h>
#include <stdbool.h>
#include "app_defs.h"

typedef struct{
	uint16_t valid_page_count;
	uint16_t invalid_page_count;
	uint16_t erase_count;
	uint16_t read_count;
	uint16_t reprogram_count;
	uint16_t free_page_count;
	uint8_t  is_bad;
}block_stats_t;

typedef struct{
   uint32_t count;
   uint32_t total_cycles;
   uint32_t min_cycles;
   uint32_t max_cycles;
   uint32_t last_cycles;
   uint32_t average_cycles;
}profiler_stats_t;


/* NAND activity profiling */
typedef struct {
    uint32_t program_count;
    uint32_t read_count;
    uint32_t erase_count;

    uint64_t program_time_us;
    uint64_t read_time_us;
    uint64_t erase_time_us;

    uint32_t program_min_us;
    uint32_t program_max_us;

    uint32_t read_min_us;
    uint32_t read_max_us;

    uint32_t erase_min_us;
    uint32_t erase_max_us;
} nand_stats_t;

typedef struct{
	uint32_t ecc_corrected_count;
	uint32_t ecc_uncorrectable_count;
} ecc_stats_t;

/* FTL activity / write amplification */
typedef struct {
    uint32_t logical_read_count;
    uint32_t logical_write_count;
    uint32_t physical_program_count;
    uint32_t physical_erase_count;
} ftl_stats_t;

/* Garbage collection */
typedef struct {
    uint32_t gc_runs;
    uint32_t pages_copied;
    uint32_t blocks_erased;
} gc_stats_t;

/* Wear leveling */
typedef struct {
    uint32_t wl_runs;
    uint32_t blocks_relocated;
} wl_stats_t;

/* Top-level statistics container */
typedef struct {
    nand_stats_t nand;
    ecc_stats_t ecc;
    ftl_stats_t ftl;
    gc_stats_t gc;
    wl_stats_t wl;
    block_stats_t blocks[BLOCK_COUNT];
    profiler_stats_t program_profiler;
    profiler_stats_t read_profiler;
    profiler_stats_t erase_profiler;
    profiler_stats_t ftl_profiler;
    profiler_stats_t gc_profiler;
    profiler_stats_t wl_profiler;
} system_stats_t;

void stats_report_program(uint32_t elapsed_cycles);
void stats_report_read(uint32_t elapsed_cycles);
void stats_report_erase(uint32_t elapsed_cycles);
void stats_report_gc(uint32_t elapsed_cycles);
void stats_report_wl(uint32_t elapsed_cycles);

profiler_stats_t stats_get_program_profiler(void);
profiler_stats_t stats_get_read_profiler(void);
profiler_stats_t stats_get_erase_profiler(void);
profiler_stats_t stats_get_gc_profiler(void);
profiler_stats_t stats_get_wl_profiler(void);



#endif
