PROGRAMMER_CLI = "/opt/st/stm32cubeclt_1.17.0/STM32CubeProgrammer/bin/STM32_Programmer_CLI"
MAKEFLAGS += --no-print-directory

.PHONY: all
all: build/
	@cmake --build build/

.PHONY: clean
clean:
	@ $(MAKE) -C build/ --no-print-directory clean


.PHONY: flash
flash:
	$(PROGRAMMER_CLI) --connect port=swd --download "build/RTOS-suite.elf" -rst

.PHONY: doc
doc:
	@. .venv/bin/activate ; mkdocs serve -a localhost:8000 > /dev/null 2>&1 & 

build/:
	@cmake -S ./ -B build/ -DCMAKE_BUILD_TYPE=Release
