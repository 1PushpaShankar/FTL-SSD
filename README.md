# STM32 FTL + Garbage Collector with FreeRTOS

A lightweight Flash Translation Layer (FTL) and garbage collector (GC) for an emulated NAND flash, implemented in C on STM32 with FreeRTOS.

This project demonstrates:

- Basic NAND flash abstraction (pages, blocks, program/erase constraints).
- A full FTL: logical-to-physical mapping, page status tracking, and block statistics.
- A background garbage collector that reclaims invalid pages.
- A FreeRTOS-based scheduler with two tasks:
  - High-priority FTL task (simulates host I/O).
  - Low-priority GC task (runs when free pages drop below a threshold).

## Features

### NAND Flash Emulation

- Configurable geometry:
  - `PAGE_SIZE`, `PAGES_PER_BLOCK`, `BLOCK_COUNT`
- Operations:
  - `nand_program_page()`
  - `nand_read_page()`
  - `nand_erase_block()`
- Enforces NAND constraints:
  - Cannot program an already-programmed page.
  - Cannot program a free page.
  - Must erase a block before reusing its pages.

### Flash Translation Layer (FTL)

- Logical-to-physical mapping:
  - `ftl_map[LPA]` → PPA
  - `ppa_lpa[PPA]` → LPA (reverse mapping)
- Page status tracking:
  - `PAGE_FREE`, `PAGE_PROGRAMMED`, `PAGE_INVALID`
- Block statistics:
  - `valid_page_count`, `invalid_page_count`, `free_page_count`
- Core operations:
  - `ftl_program(lpa, data)`
  - `ftl_read(lpa, buffer)`
  - `ftl_get_status()`

### Garbage Collection

- Triggered when free pages drop below `LOW_WATERMARK_GC`.
- Victim selection:
  - Chooses the block with the most invalid pages.
- Migration:
  - Moves all valid pages to new locations via `ftl_program()`.
  - Updates mapping and page status.
- Erase:
  - Erases the victim block and updates block stats.

### FreeRTOS Scheduler

- Two tasks:
  - **FTL Task** (high priority):
    - Continuously issues writes (and optionally reads).
    - Simulates host workload.
  - **GC Task** (low priority):
    - Sleeps on a semaphore.
    - Woken by FTL task when free pages ≤ `LOW_WATERMARK_GC`.
    - Runs one GC cycle, then goes back to sleep.
- Synchronization:
  - One-way binary semaphore from FTL → GC.
  - No direct FTL↔GC data sharing; GC uses global FTL state.

## Project Structure

Key files:

- `nand_flash.h/c` – NAND emulation and low-level operations.
- `ftl.h/c` – FTL data structures and API.
- `main.c` – FreeRTOS task creation, scheduler start.

## How It Works

1. **FTL Task**:
   - Writes data to sequential LPAs in a loop.
   - After each write, checks `ftl_get_status().free_pages`.
   - If `free_pages <= LOW_WATERMARK_GC`, gives the GC semaphore.

2. **GC Task**:
   - Blocks on the semaphore.
   - When signaled, scans `block_table[]` to find a victim block.
   - Migrates valid pages, erases the victim block.
   - Returns to waiting on the semaphore.

3. **Integrity**:
   - Mapping consistency:
     - `ftl_map[lpa]` ↔ `ppa_lpa[ppn]`
   - Page state consistency:
     - `page_state[ppn]` matches mapping.
   - Block counters:
     - `valid + invalid + free == PAGES_PER_BLOCK`.

TODO : add an `ftl_verify_integrity()` function (debug-only) to assert these invariants periodically.

## Building & Running

- Target: STM32 (e.g., STM32F4/F7/H7) with FreeRTOS.
- Toolchain: STM32CubeIDE / GCC ARM.
- Steps:
  1. Import project into your IDE.
  2. Ensure FreeRTOS is configured and running.
  3. Build and flash to your board (or run in QEMU / simulator if configured).
  4. Observe:
     - FTL and GC tasks running.
     - Profilers incrementing.
     - Mapping and block stats updating in the debugger.

## Future Improvements

- Add UART interface:
  - Command-line interface for basic FTL operations (read/write/erase, status).
  - Simple test scripts to validate FTL and GC behavior over UART.
- Add Ethernet interface:
  - Higher-speed host interface for stress testing the FTL and GC.
  - Potential for network-based storage experiments.
- Enhance garbage collection:
  - More sophisticated victim selection policies.
  - Tunable watermarks and GC aggressiveness.
- Add wear leveling:
  - Distribute writes across blocks to extend flash lifetime.
- Improve robustness:
  - Power-failure safety (e.g., metadata checkpoints, journaling).
  - More integrity checks and debug utilities.

## License

MIT License

Copyright (c) 2026 Pushpa Shankar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

## Author

Pushpa Shankar
