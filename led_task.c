#include "FreeRTOS.h"
#include "task.h"
#include "cmsis_os2.h"
#include "stm32f7xx.h"

static const osThreadAttr_t _atrribute = {
    .name = "defaultTask",
    .stack_size = 128 * 4,
    .priority = (osPriority_t) osPriorityNormal,
};

static void led_task(void* context);


void register_led_task()
{
    osThreadNew(led_task, NULL, &_atrribute);
}

static void led_task(void* context)
{
    for(;;)
    {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
        osDelay(1000);
    }
}