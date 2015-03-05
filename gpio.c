#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "gpio.h"

/* gpio ioc command */
#define  GPIO_MAGIC	    'G'

#define	GPIO_SET_DIR     _IOW(GPIO_MAGIC, 64, gpio_groupbit_info)
#define	GPIO_GET_DIR     _IOR(GPIO_MAGIC, 65, gpio_groupbit_info)
#define	GPIO_READ_BIT    _IOR(GPIO_MAGIC, 66, gpio_groupbit_info)
#define	GPIO_WRITE_BIT   _IOW(GPIO_MAGIC, 67, gpio_groupbit_info)

typedef struct 
{
	unsigned int  groupnumber;
	unsigned int  bitnumber;
	unsigned int  value;
}gpio_groupbit_info;

int InitGpio(int group,int pin,int direct,int value)//ircut £ºInitGpio(4,6,GPIO_OUT,0); readled: InitGpio(3,0,GPIO_IN,1);
{
	int ret,fd;
	gpio_groupbit_info gpio_set;

	gpio_set.groupnumber = group;    
	gpio_set.bitnumber = pin;    
	gpio_set.value = direct;  

	fd = open("/dev/gpio",O_WRONLY);
	if(fd<0)
	{
		printf("open /dev/gpio fail\n");
		return 0;
	}
	ret = ioctl(fd, GPIO_SET_DIR, &gpio_set); 	
	if(ret<0)
	{		
		printf("Set Gpio DIR Fail\n");
		close(fd);
		return 0;			
	}
	
	gpio_set.groupnumber = group;    
	gpio_set.bitnumber = pin;    
	gpio_set.value = value;  
	ret = ioctl(fd, GPIO_WRITE_BIT, &gpio_set); 	
	if(ret<0)
	{		
		printf("Set Gpio Value Fail\n");
		close(fd);
		return 0;			
	}
	close(fd);
	return 1;
}

int SetGpio(int group,int pin,int value)
{
	int ret,fd;
	gpio_groupbit_info gpio_set;
	fd = open("/dev/gpio",O_WRONLY);
	if(fd<0)
	{
		printf("open /dev/gpio fail\n");
		return 0;
	}
	
	gpio_set.groupnumber = group;    
	gpio_set.bitnumber = pin;    
	gpio_set.value = value;  
	ret = ioctl(fd, GPIO_WRITE_BIT, &gpio_set); 	
	if(ret<0)
	{		
		printf("Set Gpio Value Fail\n");
		close(fd);
		return 0;			
	}
	close(fd);
	return 1;
}
int ReadGpio(int group,int pin,int *value)
{
    int ret,fd;
	gpio_groupbit_info gpio_set;
	fd = open("/dev/gpio",O_WRONLY);
	if(fd<0)
	{
		printf("open /dev/gpio fail\n");
		return 0;
	}
	
	gpio_set.groupnumber = group;    
	gpio_set.bitnumber = pin;    
	gpio_set.value = 0;  
	ret = ioctl(fd, GPIO_READ_BIT, &gpio_set); 	
	if(ret<0)
	{		
		printf("Set Gpio Value Fail\n");
		close(fd);
		return 0;			
	}
	close(fd);
	*value=gpio_set.value;
	return 1;
}    
int FreeGpio(int group,int pin)
{
    return 1;
}


