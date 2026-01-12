# HVC Firmware

STM32L4 project containing firmware for the HVC board. This repository includes
an MCP2515 CAN controller driver and a Makefile-based build system (STM32
toolchain + HAL).

Quick start

- Build: `make` or use the "Build STM" task in VS Code (requires an installed
  ARM toolchain and the `stm32-for-vscode` extension if using the tasks).
- Flash: use the "Flash STM" task, or call OpenOCD with `openocd.cfg`.

Driver documentation

- `Core/Src/mcp2515.c` now includes a Doxygen-style file header and several
  function-level comments for SPI/register helpers and message send/receive
  helpers.
- If you want full API docs, I can add a `Doxyfile` and generate HTML docs.

Notes

- SPI peripheral referenced in the driver: `hspi4` (see `Core/Src/mcp2515.c`).
- Adapt `startSPI()`/`endSPI()` to match the MCU GPIO pin used for CS.

Want more?

I can expand the Doxygen comments across the whole driver, add a `Doxyfile`,
and generate documentation output — tell me if you want that next.
HVC Firmware