#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "cli.h"
#include "ftl.h"
#include "uart.h"
#include "profiler.h"
#include "stats.h"


/* Forward declarations */
static void cli_print_status(void);
static void cli_handle_read(char *args);
static void cli_handle_write(char *args);
static void cli_handle_gc(void);
static void cli_print_profiler_stats(void);


void handle_command(char *line)
{
    char *cmd;
    char *args;

    /* Skip leading whitespace */
    while (*line == ' ' || *line == '\t')
    {
        line++;
    }

    cmd = line;

    /* Find end of command word */
    args = cmd;
    while (*args != '\0' && *args != ' ' && *args != '\t')
    {
        args++;
    }

    if (*args != '\0')
    {
        *args = '\0';   /* terminate command */
        args++;         /* point to first char after space */
        while (*args == ' ' || *args == '\t')
        {
            args++;
        }
    }
    else
    {
        args = NULL;
    }

    if (strcmp(cmd, "help") == 0)
    {
        uart2_write_string("\r\nFTL Commands:\r\n");
        uart2_write_string("  help\r\n");
        uart2_write_string("  status\r\n");
        uart2_write_string("  read <lpa>\r\n");
        uart2_write_string("  write <lpa> <byte>\r\n");
        uart2_write_string("  gc\r\n");
        uart2_write_string("  prof\r\n");
    }
    else if (strcmp(cmd, "status") == 0)
    {
        cli_print_status();
    }
    else if (strcmp(cmd, "read") == 0)
    {
        cli_handle_read(args);
    }
    else if (strcmp(cmd, "write") == 0)
    {
        cli_handle_write(args);
    }
    else if (strcmp(cmd, "gc") == 0)
    {
        cli_handle_gc();
    }
    else if (strcmp(cmd, "prof") == 0)
    {
        cli_print_profiler_stats();
    }
    else
    {
        uart2_write_string("\r\nUnknown command. Type 'help' for list.\r\n");
    }
}

static void cli_print_profiler_stats()
{
	 profiler_stats_t gc_prof = stats_get_gc_profiler();
	 profiler_stats_t wl_prof = stats_get_wl_profiler();
	 profiler_stats_t prog_prof = stats_get_program_profiler();
	 profiler_stats_t read_prof = stats_get_read_profiler();
	 profiler_stats_t erase_prof = stats_get_erase_profiler();

	   uart2_write_string("\r\n=== Profiler Stats ===\r\n");
	   uart2_write_string("FTL program:\r\n");
	   uart2_write_string("  count: ");
	   uart2_write_number(prog_prof.count);
	   uart2_write_string("\r\n");
	   uart2_write_string("  total time: ");
	   uart2_write_number(profiler_cycles_to_us(prog_prof.total_cycles));
	   uart2_write_string(" us\r\n");;
	   uart2_write_string("\r\n");

	   uart2_write_string("FTL read:\r\n");
	   uart2_write_string("  count: ");
	   uart2_write_number(read_prof.count);
	   uart2_write_string("\r\n");
	   uart2_write_string("  total time: ");
	   uart2_write_number(profiler_cycles_to_us(read_prof.total_cycles));
	   uart2_write_string(" us\r\n");
	   uart2_write_string("\r\n");

	   uart2_write_string("FTL erase:\r\n");
	   uart2_write_string("  count: ");
	   uart2_write_number(erase_prof.count);
	   uart2_write_string("\r\n");
	   uart2_write_string("  total time: ");
	   uart2_write_number(profiler_cycles_to_us(erase_prof.total_cycles));
	   uart2_write_string(" us\r\n");
	   uart2_write_string("\r\n");

		uart2_write_string("GC profiler:\r\n");
		uart2_write_string("  count: ");
		uart2_write_number(gc_prof.count);
		uart2_write_string("\r\n");
		uart2_write_string("  total time: ");
		uart2_write_number(profiler_cycles_to_us(gc_prof.total_cycles));
		uart2_write_string(" us\r\n");
		uart2_write_string("\r\n");

		uart2_write_string("WL profiler:\r\n");
		uart2_write_string("  count: ");
		uart2_write_number(wl_prof.count);
		uart2_write_string("\r\n");
		uart2_write_string("  total time: ");
		uart2_write_number(profiler_cycles_to_us(wl_prof.total_cycles));
		uart2_write_string(" us\r\n");
		uart2_write_string("\r\n");

		uart2_write_string("======================\r\n\r\n");
}

static void cli_print_status(void)
{
    uint32_t total_free_pages = 0U;
    uint32_t total_valid_pages = 0U;
    uint32_t total_invalid_pages = 0U;
    uint16_t min_erase = 0xFFFFU;
    uint16_t max_erase = 0U;
    uint32_t bad_blocks = 0U;

    uint16_t max_invalid = 0U;
    uint32_t candidate = BLOCK_INVALID;

    for (uint32_t b = 0U; b < BLOCK_COUNT; b++)
    {
        total_free_pages    += block_table[b].free_page_count;
        total_valid_pages   += block_table[b].valid_page_count;
        total_invalid_pages += block_table[b].invalid_page_count;

        if (block_table[b].is_bad)
        {
            bad_blocks++;
            continue;
        }

        if (block_table[b].erase_count < min_erase)
        {
            min_erase = block_table[b].erase_count;
        }
        if (block_table[b].erase_count > max_erase)
        {
            max_erase = block_table[b].erase_count;
        }

        /* GC candidate: non-bad block with most invalid pages */
        if (block_table[b].invalid_page_count > max_invalid)
        {
            max_invalid = block_table[b].invalid_page_count;
            candidate = b;
        }
    }

    uart2_write_string("\r\n=== FTL Status ===\r\n");

    uart2_write_string("Total blocks: ");
    uart2_write_number(BLOCK_COUNT);
    uart2_write_string("\r\n");

    uart2_write_string("Bad blocks: ");
    uart2_write_number(bad_blocks);
    uart2_write_string("\r\n");

    uart2_write_string("Free pages: ");
    uart2_write_number(total_free_pages);
    uart2_write_string("\r\n");

    uart2_write_string("Valid pages: ");
    uart2_write_number(total_valid_pages);
    uart2_write_string("\r\n");

    uart2_write_string("Invalid pages: ");
    uart2_write_number(total_invalid_pages);
    uart2_write_string("\r\n");

    uart2_write_string("Wear level (min/max erase): ");
    uart2_write_number(min_erase);
    uart2_write_string("/");
    uart2_write_number(max_erase);
    uart2_write_string("\r\n");

    uart2_write_string("Free blocks (approx): ");
    uart2_write_number(get_free_block_count());
    uart2_write_string("\r\n");

    if (candidate != BLOCK_INVALID)
    {
        uart2_write_string("GC candidate block: ");
        uart2_write_number(candidate);
        uart2_write_string("\r\n");

        uart2_write_string("Candidate valid pages: ");
        uart2_write_number(block_table[candidate].valid_page_count);
        uart2_write_string("\r\n");

        uart2_write_string("Candidate invalid pages: ");
        uart2_write_number(block_table[candidate].invalid_page_count);
        uart2_write_string("\r\n");

        uart2_write_string("Candidate erase count: ");
        uart2_write_number(block_table[candidate].erase_count);
        uart2_write_string("\r\n");
    }
    else
    {
        uart2_write_string("GC candidate block: none\r\n");
    }

    uart2_write_string("===================\r\n\r\n");
}

static void cli_handle_read(char *args)
{
    char *endptr;
    unsigned long parsed_lpa = strtoul(args, &endptr, 0);

    if (endptr == args ||
        (*endptr != '\0' && *endptr != ' ' && *endptr != '\t') ||
        parsed_lpa >= LOGICAL_PAGE_COUNT)
    {
        uart2_write_string("\r\nInvalid LPA\r\n");
        return;
    }

    lpa_t requested_lpa = (lpa_t)parsed_lpa;

    uint32_t data[PAGE_SIZE];
    ftl_status_t rc = ftl_read(requested_lpa, (uint8_t *)data);

    if (rc == FTL_OK)
    {
        static const char hex[] = "0123456789ABCDEF";

        uart2_write_string("\r\nRead OK: LPA ");
        uart2_write_number((uint32_t)requested_lpa);
        uart2_write_string(" = 0x");
        uart2_write(hex[(data[0] >> 4) & 0x0FU]);
        uart2_write(hex[data[0] & 0x0FU]);
        uart2_write_string("\r\n\r\n");
    }
    else
    {
        uart2_write_string("\r\nRead error: ");
        uart2_write_number((uint32_t)rc);
        uart2_write_string("\r\n\r\n");
    }

}
/*
 * write <lpa> <byte>
 */
static void cli_handle_write(char *args)
{
    uint32_t lpa;
    uint32_t value;
    uint8_t  data;
    char    *endptr;
    ftl_status_t rc;
    char     buf[80];

    if (args == NULL)
    {
        uart2_write_string("\r\nUsage: write <lpa> <byte>\r\n");
        return;
    }

    lpa = (uint32_t)strtoul(args, &endptr, 0);

    while (*endptr == ' ' || *endptr == '\t')
    {
        endptr++;
    }

    if (*endptr == '\0')
    {
        uart2_write_string("\r\nMissing value for write.\r\n");
        return;
    }

    value = strtoul(endptr, NULL, 0);
    if (value > 0xFFU)
    {
        uart2_write_string("\r\nValue must be 0–255.\r\n");
        return;
    }

    if (lpa >= LOGICAL_PAGE_COUNT)
    {
        uart2_write_string("\r\nInvalid LPA (out of range).\r\n");
        return;
    }

    data = (uint8_t)value;

    rc = ftl_program((lpa_t)lpa, &data);
    if (rc == FTL_OK)
    {
        snprintf(buf, sizeof(buf), "\r\nWrite OK: LPA %lu = 0x%02X\r\n\r\n",
                 (unsigned long)lpa, (unsigned int)data);
        uart2_write_string(buf);
    }
    else
    {
        snprintf(buf, sizeof(buf), "\r\nWrite error: %d\r\n\r\n", (int)rc);
        uart2_write_string(buf);
    }
}

/*
 * gc – trigger one GC run by setting the global flag.
 * Adjust this if your GC task uses a different mechanism.
 */
static void cli_handle_gc(void)
{
    gc_requested = true;

    uart2_write_string("\r\nGC requested.\r\n\r\n");
}

/*
 * CLI task: receives characters from uart_rx_queue,
 * builds a line, and calls handle_command() on Enter.
 */
void uart_cli_task(void *pvParameters)
{
    (void)pvParameters;

    uint8_t c;
    char line[64];
    uint16_t index = 0U;

    for (;;)
    {
        if (xQueueReceive(uart_rx_queue, &c, portMAX_DELAY) == pdTRUE)
        {
            /* Echo back */
            uart2_write((char)c);

            if (c == '\r' || c == '\n')
            {
                if (index > 0U)
                {
                    line[index] = '\0';
                    uart2_write_string("\r\n");
                    handle_command(line);
                    index = 0U;
                }
            }
            else if (index < (sizeof(line) - 1U))
            {
                line[index++] = (char)c;
            }
        }
    }
}
