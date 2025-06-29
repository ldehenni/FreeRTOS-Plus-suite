# FreeRTOS 'Plus' for STM32F7xx - by Louis Dehennin

The aim of this repository is to explore the FreeRTOS library and its 'Plus' features for the STM32F7xx microcontroller.
Developers that have dabbled in STM microcontrollers and FreeRTOS will know that ST provides FreeRTOS support directly from within their (STM32Cube)IDE,
unfortunately the integrated version is pretty dated and missing a lot of functionality.

The idea to make this repository originates from a search for an appropriate IP stack to incorporate in one of my projects.
ST's supported stack, `lwip`, did not function "as is": there was a pretty severe bug trying to access memory out of physical range.
Despite having fixed the issue, some of its (heap) memory allocation to a *hardcoded* pointer seemed questionable.
Further concerns were raised with the seeming fragilty of lwip in threaded environments.

Some googling (*red.* the thing we used to do before LLMs ...) brought me to the FreeRTOS 'Plus' libraries and the discovery of an arsenal of features.

## Project structure

    Core/      # STM peripheral initialization code
    Drivers/   # STM HAL
    docs/      # Markdown files for project-level documentation (this!)
    FreeRTOS/  # FreeRTOS submodule with FreeRTOS Plus and utilities
        FreeRTOS/
        FreeRTOS-Plus/
    FreeRTOS-Plus-FAT/    # Is still a 'lab' and not an official FreeRTOS lib yet.
    scripts/   # Supporting scripts for interacting with the utilities.


## ST tool dependency

In this project the focus is *not* on the integration of FreeRTOS on the STM32F7.
The platform is rather a means to an end to allow us to explore FreeRTOS.

As such, the use of ST's tools has been purposefully minimized:

* The integrated FreeRTOS version is outdated.
* We want to keep our findings portable and reusable for other platforms.
* We want to *understand* what is required to port the libraries and not have the work done for us.

We end up sticking with the use of `STMCubeMX` for generating:

* Default peripheral configurations
* Explicitly *no* (FreeRTOS) middleware
* A CMake template

As these are 'generate once' kind of files, STMCubeMx is not a dependency of this repository.

## Wishlist features

* FreeRTOS
    * Performance and memory monitoring
* FreeRTOS-Plus-TCP
    * Various utilities over UDP:
        * CLI
        * Logger
        * Datastream
    * FTP server
    * Webserver over TCP
* FAT file system with FreeRTOS-Plus-FAT
    * In RAM
    * Use FTP server to populate