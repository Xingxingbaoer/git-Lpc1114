#include "LPC11XX.H"
void delay()
{
    uint16_t i = 10000;
    while(i--);
}
void GPIOInit(void)
{
    LPC_GPIO2 ->DIR = 0xFFF;				//??P2_0~P2_11???
}
void Display(uint32_t value)
{

    uint32_t i;
    uint32_t temp;
    i = value;

    temp = table[i / 1000];
    temp &= ~(1 << 8);
    temp |= (1 << 9);
    temp |= (1 << 10);
    temp |= (1 << 11);
    LPC_GPIO2->DATA	= temp;
    delay();
    temp |= 0xFF;
    LPC_GPIO2->DATA |= (1 << 8);

    temp = table[i % 1000 / 100];
    temp |= (1 << 8);
    temp &= ~(1 << 9);
    temp |= (1 << 10);
    temp |= (1 << 11);
    LPC_GPIO2->DATA	= temp;
    delay();
    temp |= 0xFF;
    LPC_GPIO2->DATA |= (1 << 9);

    temp = table[i % 1000 % 100 / 10];
    temp |= (1 << 8);
    temp |= (1 << 9);
    temp &= ~(1 << 10);
    temp |= (1 << 11);
    LPC_GPIO2->DATA	= temp;
    delay();
    temp |= 0xFF;
    LPC_GPIO2->DATA |= (1 << 10);

    temp = table[i % 1000 % 100 % 10];
    temp |= (1 << 8);
    temp |= (1 << 9);
    temp |= (1 << 10);
    temp &= ~(1 << 11);
    LPC_GPIO2->DATA	= temp;
    delay();
    temp |= 0xFF;
    LPC_GPIO2->DATA |= (1 << 11);
}
