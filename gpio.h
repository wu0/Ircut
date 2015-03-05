#ifndef _GPIO_H
#define _GPIO_H

#define GPIO_IN  0
#define GPIO_OUT 1

#define GPIO_H   1
#define GPIO_L   0

int InitGpio(int group,int pin,int direct,int value);
int SetGpio(int group,int pin,int value);//输出时置高低电平
int ReadGpio(int group,int pin,int *value);//输入时读引脚电平
int FreeGpio(int group,int pin);

#endif
