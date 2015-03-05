#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "gpio.h"
int main(void)
{
	int ret=-1;
	system("devmem 0x200f0030 32 0x00000000");//GPIO3_0 红外灯输入信号，平时读入为0，输入高电平1需要切换IRCUT
	InitGpio(3,0,GPIO_IN,1);
	while(1)
	{
		ReadGpio(3,0,&ret);
		printf("read gpio3_0=%d\n",ret);
		ret=-1;
		sleep(1);	
	}
	return 0;
}