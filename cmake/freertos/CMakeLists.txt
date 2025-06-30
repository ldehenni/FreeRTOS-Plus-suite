# Check FreeRTOS CMake for requirements:
#     * Tell where to find config files
#     * Specify target platform

add_library(freertos_config INTERFACE)

target_include_directories(freertos_config SYSTEM INTERFACE
    ../../suite/freertos_config/
) 

target_compile_definitions(freertos_config INTERFACE
    projCOVERAGE_TEST=0
)