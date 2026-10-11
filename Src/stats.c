#include "stats.h"
#include "profiler.h"

static system_stats_t system_stats;

ftl_stats_t stats_get_ftl_stats(void)
{
    return system_stats.ftl;
}

ecc_stats_t stats_get_ecc_stats(void)
{
    return system_stats.ecc;
}

nand_stats_t stats_get_nand_stats(void)
{
    return system_stats.nand;
}

gc_stats_t stats_get_gc_stats(void)
{
    return system_stats.gc;
}

wl_stats_t stats_get_wl_stats(void)
{
    return system_stats.wl;
}

block_stats_t stats_get_block_stats(uint16_t block_num)
{
    if (block_num >= BLOCK_COUNT)
    {
        block_stats_t empty = {0};
        return empty;
    }

    return system_stats.blocks[block_num];
}

void stats_report_program(uint32_t elapsed_cycles)
{
    profiler_update(&system_stats.program_profiler, elapsed_cycles);
}

void stats_report_read(uint32_t elapsed_cycles)
{
    profiler_update(&system_stats.read_profiler, elapsed_cycles);
}

void stats_report_erase(uint32_t elapsed_cycles)
{
    profiler_update(&system_stats.erase_profiler, elapsed_cycles);
}

profiler_stats_t stats_get_program_profiler(void)
{
    return system_stats.program_profiler;
}

profiler_stats_t stats_get_read_profiler(void)
{
    return system_stats.read_profiler;
}

profiler_stats_t stats_get_erase_profiler(void)
{
    return system_stats.erase_profiler;
}


void stats_report_gc(uint32_t elapsed_cycles)
{
    profiler_update(&system_stats.gc_profiler, elapsed_cycles);
}

profiler_stats_t stats_get_gc_profiler(void)
{
    return system_stats.gc_profiler;
}


void stats_report_wl(uint32_t elapsed_cycles)
{
    profiler_update(&system_stats.wl_profiler, elapsed_cycles);
}

profiler_stats_t stats_get_wl_profiler(void)
{
    return system_stats.wl_profiler;
}
