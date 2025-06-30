# Notes on FreeRTOS

## Integration

### Clocking

When using FreeRTOS it is recommended to select a timer peripheral as the system timer, instead of the more common sys tick.
We picked TIM6 for example.

The lingering definition of the SysTick_Handler will cause problems down the line, see *Compilation Errors* section.

### CMake

FreeRTOS comes with an easy to use CMake file.
All you need is to provide:

* A target `freertos_config` that provides the `target_include_directories` where "FreeRTOSConfig.h" will be found.
    * `FreeRTOSConfig.h` is a **user-provided** configuration file. I grbbed an example from somewhere, you are welcome to grab mine.
    * The point is very much to tune the configuration to your needs and target platform. Avaiilable RAM for example plays a big factor.
* A `FREERTOS_PORT` option -- for STM32F7 this is `GCC_ARM_CM7` (Cortex-M7).
* Select `FREERTOS_HEAP` implementation (heap_4 is nice). 
* Add FreeRTOS as a subdirectory in your toplevel CMake.
* Link `freertos_kernel` to your target!

At CMake's top level it can look like this:

``` cmake
# FreeRTOS
set(FREERTOS_PORT "GCC_ARM_CM7")
set(FREERTOS_HEAP 4)
add_subdirectory(cmake/freertos)  # Provides freertos_config target
add_subdirectory(FreeRTOS/FreeRTOS/Source)  # Actual kernel compilation

<...>

target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx
    freertos_kernel 
    # Add user defined libraries
)
```

where `cmake/freertos` is

``` cmake
add_library(freertos_config INTERFACE)

target_include_directories(freertos_config SYSTEM INTERFACE
    ../../suite/freertos_config/  # Where to find freeRTOSConfig.h
) 

target_compile_definitions(freertos_config INTERFACE
    projCOVERAGE_TEST=0
)
```

### Compilation errors

These are the errors I encountered:

* Missing function definitions (see CMSIS porting)
* Some interrupt handler are defined multiple times:
    * Since we've decided not to use ST's FreeRTOS integration,
    the generated code from CubeMX didn't remove unnecessary definitions available in FreeRTOS.
    * In `Core/Src/stm32f7xx_it.c` you can safely remove the `SysTick` handler, `SVC_Handler` and `PendSV_Handler`.

## CMSIS porting

FreeRTOS is platform agnostic so it needs a *porting* layer to the target hardware.
CMSIS is the software abstraction of Cortex processors and also provides a port of the FreeRTOS interface.

It is currently sufficient to compile `cmsis_os2.c` and link to it for FreeRTOS to function.

!!! bug
    There are some function definitions missing that were otherwise defined in cmsis_os2 when using ST's FreeRTOS integration.
    It is unclear why they are defined there, some investigation is required to rehome them if possible.

!!! info "TODO"
    Explicit here which function definitions need to be added.