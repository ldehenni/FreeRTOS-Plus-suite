#include "stm32f767xx.h"
#include "gpio.h"
#include "cmsis_os2.h"

void register_led_task(void);

/**
 * Weird artifact of generating from STMCubeMX
 */
void SystemClock_Config(void);

int main()
{
	HAL_Init();

	SystemClock_Config();

	osKernelInitialize();

	// Peripheral inits
	MX_GPIO_Init();
	register_led_task();

	osKernelStart();

	while(1)
	{
	}

	return 0;
}
