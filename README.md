# HVC Firmware

Firmware for the HVC board built on STM32L432 (HAL + FreeRTOS/CMSIS-RTOS v2).
The project includes:

- Core application startup and peripheral initialization
- CAN manager infrastructure
- MCP2515 SPI CAN controller driver
- IO manager for digital and analog signal sampling
- Host unit-test workflow (Unity + CMock)

## Repository Layout

- `Core/Inc`, `Core/Src`: application code and module headers
- `Drivers/`, `Middlewares/`: STM32 HAL, CMSIS, FreeRTOS sources
- `Makefile`: firmware build (generated STM32 Make flow)
- `tests/`, `tests.mk`: host unit tests
- `Dockerfile.test`: containerized test runner
- `openocd.cfg`: OpenOCD debug/flash configuration

## Firmware Architecture

Current boot/runtime flow in `main.c`:

1. HAL and clocks initialize
2. Peripherals initialize (`CAN1`, `SPI1`, `ADC`, etc.)
3. CAN peripheral starts (`HAL_CAN_Start`)
4. RTOS objects initialize (mutexes, queues, tasks)
5. Scheduler starts (`osKernelStart`)

Main tasks currently created:

- `CAN_ManagerTask`
- `SPICANIntCallbackTask`
- `defaultTask`

## Build and Flash

### Option A: VS Code tasks (recommended for day-to-day work)

- Build: `Build STM`
- Clean build: `Build Clean STM`
- Flash: `Flash STM`

### Option B: CLI build

From repository root:

```bash
make
```

This uses the generated firmware `Makefile` and requires an ARM GCC toolchain
(`arm-none-eabi-*`) in your PATH.

### Flashing via OpenOCD

Use your existing OpenOCD setup with `openocd.cfg` for board programming.

## Unit Tests

Unit tests are host-side and do not require flashing hardware.

- Quick guide: `tests/README.md`
- Build/run all on host: `make -f tests.mk test`
- Build/run a single module: `make -f tests.mk test <module>`

For containerized test execution, see `tests/README.md`.

## CAN and MCP2515 Notes

- MCP2515 driver source is in `Core/Src/mcp2515.c`.
- Active SPI handle in the current code is `hspi1`.
- The project currently contains both `CANSPI.*` and `spi_can.*` naming patterns
  in different areas; follow the naming used by the file you are editing.

## Naming and Portability Guidance

- Keep filename and include casing consistent (`CANSPI.h` vs `spi_can.h`).
- On Linux/container builds, include path casing is strict.
- For active firmware source membership, treat the generated `Makefile` as the
  source-of-truth list of compiled C files.