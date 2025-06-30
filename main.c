#include "stm32f767xx.h"
#include "cmsis_os2.h"

#include "gpio.h"
#include "usart.h"

#include <stdio.h>

void register_led_task(void);

/**
 * Weird artifact of generating from STMCubeMX
 */
void SystemClock_Config(void);

int main()
{
	// Always init HAL and sys tem clock
	HAL_Init();
	SystemClock_Config();

	// Peripheral inits
	MX_GPIO_Init();
	MX_USART3_UART_Init();

	printf("You wanna see a magic trick?\r\n");

	// Kernel
	osKernelInitialize();
	register_led_task();
	osKernelStart();

	while(1)
	{
	}

	return 0;
}
