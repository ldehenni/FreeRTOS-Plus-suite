PROGRAMMER_CLI = "/opt/st/stm32cubeclt_1.17.0/STM32CubeProgrammer/bin/STM32_Programmer_CLI"

.PHONY: flash
flash:
	$(PROGRAMMER_CLI) --connect port=swd --download "build/RTOS-suite.elf" -rst
