# FreeRTOS 'Plus' for STM32F7xx - by Louis Dehennin

The aim of this repository is to explore the FreeRTOS library and its 'Plus' features for the STM32F7xx microcontroller.

**See documentation section for detailed content**.

## Compilation

    mkdir build ; cd build
    cmake ../
    make -j

## Documentation

Requires mkdocs

    # Make python virtual environment
    python3 -m venv venv
    source venv/bin/activate
    pip install -r requirements.txt
    mkdocs serve -a localhost:8000

In the root of the project there is a makefile with a target to launch the docs server:

    make doc

In your favorite browser you can now access the documentation at `localhost:8000`.

Or you can view the markdown files in the `docs` folder in github.