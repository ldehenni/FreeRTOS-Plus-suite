#include "stm32f767xx.h"
#include "gpio.h"

int main()
{
	HAL_Init();
	MX_GPIO_Init();

	while(1)
	{
		HAL_Delay(1000);
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
	}

	return 0;
}
