# Notes on FreeRTOS

## Integration

FreeRTOS comes with an easy to use CMake file.
All you need is to provide:

* A target `freertos_config` that provides the `target_include_directories` where "FreeRTOSConfig.h" will be found.
* A `FREERTOS_PORT` option -- for STM32F7 this is `GCC_ARM_CM7` (Cortex-M7).
* Add FreeRTOS as a subdirectory in your toplevel CMake.

## CMSIS porting

FreeRTOS is platform agnostic so it needs a *porting* layer to the target hardware.
CMSIS is the software abstraction of Cortex processors and also provides a port of the FreeRTOS interface.

I did not get it to work just this time. More later.