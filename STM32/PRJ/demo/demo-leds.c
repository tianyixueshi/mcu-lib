#include "stm32f10x_gpio.h"
#define LED_ON  (1)
#define LED_OFF (0)

#define LED1    (1)
#define LED2    (2)
#define LED3    (3)

#define LEDA    (1)
#define LEDB    (2)
#define LEDC    (3)

#define LEDALL  (5)

void EVB_LEDConfig(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_7 | GPIO_Pin_6;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOC, &GPIO_InitStructure);
}
static void delay(int n)
{
    while (n--)
        ;
}
void EVB_LEDControl(int index, int cmd)
{
    switch (index)
    {
        case LED1:
        {
            if (cmd == LED_ON)
            {
                GPIO_SetBits(GPIOC, GPIO_Pin_8);
            }
            else
            {
                GPIO_ResetBits(GPIOC, GPIO_Pin_8);
            }
            break;
        }
        case LED2:
        {
            if (cmd == LED_ON)
            {
                GPIO_SetBits(GPIOC, GPIO_Pin_7);
            }
            else
            {
                GPIO_ResetBits(GPIOC, GPIO_Pin_7);
            }
            break;
        }
        case LED3:
        {
            if (cmd == LED_ON)
            {
                GPIO_SetBits(GPIOC, GPIO_Pin_6);
            }
            else
            {
                GPIO_ResetBits(GPIOC, GPIO_Pin_6);
            }
            break;
        }
        default:
        {
            if (cmd == LED_ON)
            {
                GPIO_SetBits(GPIOC, GPIO_Pin_8 | GPIO_Pin_7 | GPIO_Pin_6);
            }
            else
            {
                GPIO_ResetBits(GPIOC, GPIO_Pin_8 | GPIO_Pin_7 | GPIO_Pin_6);
            }
            break;
        }
    }
}

void main()
{
    EVB_LEDConfig();
      while (1)
    {
        delay(0x7fffff);
        EVB_LEDControl(1, 1);
        delay(0x7fffff);
        EVB_LEDControl(1, 0);
        delay(0x7fffff);
        EVB_LEDControl(2, 1);
        delay(0x7fffff);
        EVB_LEDControl(2, 0);
        delay(0x7fffff);
        EVB_LEDControl(3, 1);
        delay(0x7fffff);
        EVB_LEDControl(3, 0);
        delay(0x7fffff);
        EVB_LEDControl(4, 1);
        delay(0x7fffff);
        EVB_LEDControl(4, 0);
    }
	//return 0;
}