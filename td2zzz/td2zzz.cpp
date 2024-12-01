#include <iostream>
#include <stdio.h>
int __io_putchar(int ch)

{

HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);

return ch;

}



int __io_getchar(void)

{

uint8_t ch = 0;

__HAL_UART_CLEAR_OREFLAG(&huart2);

HAL_UART_Receive(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);

HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, HAL_MAX_DELAY);

return ch;

}
int main(void) {
	uint8_t c;
	for (c=0;c<=254;c++){
	   printf("c = %d %x %c \n\r",c,c,c);}
	printf("c = %d %x %c \n\r",c,c,c);
	c++;
	printf("c = %d %x %c \n\r",c,c,c);

	return 0;
}
