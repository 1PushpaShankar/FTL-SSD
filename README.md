# STM32 FTL + Garbage Collector + Wear Leveling with FreeRTOS

A lightweight Flash Translation Layer (FTL), garbage collector (GC), and wear-leveling (WL) system for emulated NAND flash, implemented in C on an STM32 microcontroller with FreeRTOS.

The project demonstrates how a storage system can manage logical-to-physical mapping, reclaim invalid pages, distribute wear across flash blocks, and expose runtime control through an interrupt-driven UART command-line interface.

## Features

### NAND Flash Emulation

- Configurable geometry:
  - `PAGE_SIZE`
  - `PAGES_PER_BLOCK`
  - `BLOCK_COUNT`
- Low-level operations:
  - `nand_program_page()`
  - `nand_read_page()`
  - `nand_erase_block()`
- NAND constraints enforced:
  - A programmed page cannot be programmed again.
  - A free page cannot be read as valid data.
  - A block must be erased before its pages can be reused.

### Flash Translation Layer

- Logical-to-physical address mapping:
  - `ftl_map[LPA] → PPA`
  - `ppa_lpa[PPA] → LPA`
- Page state tracking:
  - `PAGE_FREE`
  - `PAGE_PROGRAMMED`
  - `PAGE_INVALID`
- Per-block statistics:
  - Valid page count
  - Invalid page count
  - Free page count
- Core API:
  - `ftl_program(lpa, data)`
  - `ftl_read(lpa, buffer)`
  - `ftl_get_status()`
  - `get_free_block_count()`

### Garbage Collection

- Triggered when the number of free blocks falls below `LOW_WATERMARK_GC`.
- Victim-block selection:
  - Selects the block with the highest number of invalid pages.
- Valid-page migration:
  - Copies valid pages from the victim block to a new location.
  - Updates logical-to-physical and reverse mappings.
- Block reclamation:
  - Erases the victim block.
  - Updates page and block statistics.
- Runs as a lower-priority FreeRTOS task and is activated using a binary semaphore.

### Wear Leveling

- Periodically evaluates flash-block wear.
- Triggered after a configurable number of FTL writes or after GC activity.
- Moves data from frequently erased or heavily used blocks to less-used blocks.
- Helps distribute erase cycles more evenly across the NAND device.
- Runs as the lowest-priority FreeRTOS task and is activated using a binary semaphore.

### FreeRTOS Scheduler

The system uses three cooperating tasks:

| Task | Priority | Responsibility |
|---|---:|---|
| `uart_cli_task` | Configurable | Receives UART commands, parses them, and calls FTL/GC/WL functions |
| `ftl_task` | High | Simulates host writes and monitors free-block level |
| `gc_task` | Medium/Low | Reclaims blocks containing invalid pages |
| `wl_task` | Low | Performs wear-leveling checks and page relocation |

> Note: In FreeRTOS, a higher numeric priority means a higher task priority.

### Profiling

The project includes lightweight cycle-based profiling for major operations:

- FTL program operations
- Garbage-collection cycles
- Wear-leveling operations

Statistics include operation count, total cycles, minimum cycles, maximum cycles, and average cycles. These values can be displayed through the UART CLI.

## UART Command-Line Interface

The project includes an interrupt-driven UART CLI.

Data flow:

```text
PC terminal
   ↓
USART2 RX interrupt
   ↓
FreeRTOS queue
   ↓
uart_cli_task()
   ↓
line buffer
   ↓
handle_command()
   ↓
FTL / GC / WL functions
   ↓
UART response
```

The UART ISR only reads a received byte and places it into a FreeRTOS queue. The CLI task performs line assembly, command parsing, and command execution.

Example interaction:

```text
> help
Commands:
help
status
read <lpa>
write <lpa> <byte>
gc

> status
FTL writes: 120
FTL avg cycles: 17450
GC runs: 2
GC avg cycles: 48300
WL checks: 1
WL avg cycles: 9100
Free blocks: 13
```

## Project Structure

```text
main.c          FreeRTOS task creation, scheduler startup, workload generation
uart.c/.h       UART initialization, TX/RX, interrupt handler, queue interface
cli.c/.h        UART CLI task and command parser
nand.c/.h       Emulated NAND flash and low-level flash operations
ftl.c/.h        Logical-to-physical mapping, program/read operations, FTL state
gc.c/.h         Garbage collection and victim-block reclamation
wl.c/.h         Wear-leveling checks and page relocation
profiler.c/.h   Cycle-based performance profiling
```

## How It Works

1. `main()` initializes UART, FTL, profiler, FreeRTOS objects, and tasks.
2. `ftl_task()` continuously writes data to sequential logical page addresses.
3. After a configured number of writes, the FTL task signals the wear-leveling task.
4. If the number of free blocks falls below the GC watermark, the FTL task signals the GC task.
5. `gc_task()` selects a victim block, migrates valid pages, erases the victim block, and updates mappings.
6. `wl_task()` evaluates block wear and relocates pages when appropriate.
7. `uart_cli_task()` receives user commands and provides runtime access to FTL state and operations.

## Synchronization

- Binary semaphores are used for one-way task signaling:
  - FTL task → GC task
  - FTL task / GC task → WL task
- A FreeRTOS queue transfers received UART characters from the ISR to the CLI task.
- The FTL, GC, and WL modules operate on shared FTL state protected by the system’s task scheduling and signaling design.

## Integrity

The system maintains consistency between:

- `ftl_map[LPA]` and `ppa_lpa[PPA]`
- Page state and current mapping
- Block-level valid, invalid, and free page counters

Planned improvement:

- Add `ftl_verify_integrity()` as a debug-only function to periodically assert these invariants.

## Building and Running

### Requirements

- STM32 development board, such as an STM32F4 Discovery board
- STM32CubeIDE or GCC ARM toolchain
- FreeRTOS
- USB-UART terminal application, such as PuTTY, Tera Term, Minicom, or screen

### Steps

1. Import the project into STM32CubeIDE.
2. Build the project.
3. Flash the firmware to the board.
4. Open a serial terminal at `115200` baud.
5. Use the CLI to inspect FTL state and issue commands.

Example:

```text
> status
> write 10 65
> read 10
> gc
```

## Future Improvements

- FPGA-based NAND controller:
  - Move time-critical NAND operations into an FPGA.
  - Implement NAND command sequencing, ECC, bad-block management, and page caching in hardware.
  - Use the STM32 as a host processor and the FPGA as a storage accelerator.
  - Communicate between STM32 and FPGA using SPI, UART, parallel bus, or high-speed interface such as FMC.

- Hardware-accelerated FTL components:
  - Offload mapping-table lookup, page-status tracking, and block-statistics updates to FPGA logic.
  - Implement parallel garbage-collection scanning for faster victim-block selection.
  - Accelerate CRC/ECC calculation and data integrity checking.

- Full CLI support for:
  - `status`
  - `read <lpa>`
  - `write <lpa> <byte>`
  - `gc`
  - `wl`
  - `erase`

- Automated UART test scripts.

- `ftl_verify_integrity()` for runtime consistency checking.

- Improved GC victim-selection policies.

- Configurable GC and WL watermarks.

- Power-failure safety using metadata checkpoints or journaling.

- Ethernet or USB Mass Storage as a higher-performance host interface.

- Bad-block management and retention-aware page placement.
- Add full CLI support for:
  - `status`
  - `read <lpa>`
  - `write <lpa> <byte>`
  - `gc`
  - `wl`
  - `erase`
- Add automated UART test scripts.
- Add `ftl_verify_integrity()` for runtime consistency checking.
- Improve GC victim-selection policies.
- Add configurable GC and WL watermarks.
- Add power-failure safety using metadata checkpoints or journaling.
- Add Ethernet or USB Mass Storage as a higher-performance host interface.
- Add bad-block management and retention-aware page placement.

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
