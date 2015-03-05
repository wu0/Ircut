#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gpio.h"
int main(void)
{
	system("devmem 0x200f004c 32 0x00000000");//GPIO4_6
    system("devmem 0x200f0048 32 0x00000000");//GPIO4_7
	
	InitGpio(4,6,GPIO_OUT,0);
	InitGpio(4,7,GPIO_OUT,1);
	SetGpio(4,6,0);
	SetGpio(4,7,1);
	printf("ircut on\n");
	
	sleep(1);
	SetGpio(4,6,1);
	SetGpio(4,7,0);
	printf("ircut off\n");
	
	sleep(1);
	SetGpio(4,6,0);
	SetGpio(4,7,1);
	printf("ircut on\n");
	
	sleep(1);
	printf("ircut end\n");
	return 0;
}