//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& 主函数 &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//*文件名称: main.c
//*文件作用: 主函数
//*文件作者:  mmaple
//*创建日期: 2012年3月
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#include "../include/include.h"
#include "libledgpio.h"
#include "led.h"

#define CHIP_ADDR   0x20
#define I2C_DEV_PATH "/dev/i2c-0"

#define LED_ON_VALUE		(0)	//0值表示点亮
#define LED_OFF_VALUE		(1)


static int i2c_fd;

static uint8 led_onoff_status=0xff;
#if 0
void led_init(void)
{
	int error = 0;
	i2c_fd = open(I2C_DEV_PATH, O_RDWR);
	if (i2c_fd < 0)
	{
		printf("i2c open failed %d\n", CHIP_ADDR);
		return;
	}
	error = ioctl(i2c_fd, I2C_SLAVE, CHIP_ADDR);
	if (error < 0)
	{
		printf("i2c set I2C_SLAVE error, error is %d\n", error);
	}
	else
	{
	}

	//	  error = ioctl(i2c_fd, I2C_TENBIT, 0);
	//	  if(error < 0)
	//	  {
	//		  printf("i2c set I2C_TENBIT error, error is %d\n", error);
	//	  }

	error = ioctl(i2c_fd, I2C_TIMEOUT, 0);
	if (error < 0)
	{
		printf("i2c set I2C_TIMEOUT error, error is %d\n", error);
	}

	error = ioctl(i2c_fd, I2C_RETRIES, 1);
	if (error < 0)
	{
		printf("i2c set I2C_RETRIES error, error is %d\n", error);
	}
}
void led_onoff(uint8 led_no, uint8 onoff)
{
	int res;
	uint8 led_onoff_status_tmp=led_onoff_status;

	if(!LED_ON_VALUE)
	{
		if(onoff)led_onoff_status_tmp &= ~(1<<led_no);
		else led_onoff_status_tmp |= (1<<led_no);
	}	


	if(led_onoff_status_tmp!=led_onoff_status)
	{
		led_onoff_status=led_onoff_status_tmp;
		#if 0
		   res = write(i2c_fd, &led_onoff_status, 1);
				if (res <= 0)
				{
				printf("i2c write error, error is %d,i2c_fd:%d\r\n", res,i2c_fd);
				}
				else
				{
					//printf("i2c write ok, led_onoff_status: 0x%x, res = %d\r\n", led_onoff_status, res);
				}		
	  	#endif
				
	}
}

static uint8 led_get_onoff(uint8 led_no)
{
	uint8 tmp=((led_onoff_status>>led_no)&1);
	if(tmp==LED_ON_VALUE)return 1;
	else return 0;
}
void led_toggle(uint8 led_no)
{
	uint8 tmp=(1-led_get_onoff(led_no));
	if(led_no==MIC_LED_BIT)
	{
		printf("tmp: %d\r\n",tmp);
	}
	led_onoff(led_no,tmp);
}
#endif


uint8_t  gu8LED_Status = 0x00;



static int  _LED_IO_CTRL(const int _iled,const int _iValue)
{
	int iGpio = 0;
	if(_iValue == LED_ON)
	{
		gu8LED_Status &= ~(1<<_iled);
	}else
	{
		gu8LED_Status |= (1<<_iled);
	}
	
	switch (_iled)
	  {
		
		case LED_SYS_RUN:
			iGpio = LED60_SYSRUN;
		  	break;
		case LED_MANUAL:
		    iGpio = LED1_MANUAL;
			break;
		case LED_TMS:
		    iGpio = LED2_TMS;
			break;
		case LED_ATC:
			iGpio = LED3_ATC;
			break;
		case LED_OCC:
			iGpio = LED4_OCC;
			break;
		case LED_ACTIVE:
		    iGpio = LED5_ACTIVE;
			break;
		case LED_MIC:
			iGpio = LED8_MEDIA;
			break;
		case LED_ERR:
			iGpio = LED60_ERR;
			break;
	   default:
	   	     break;
	  }
	  return gpio_output_ctrl(iGpio,_iValue);
}

static int  _LED_GetValue(const int _iled)
{
	
	return (gu8LED_Status >>_iled)&0x01;

}



void LED_Init(void)
{


    GPIO_Init(LED60_SYSRUN,0);
	GPIO_Init(LED1_MANUAL,0);
    GPIO_Init(LED2_TMS,0);
	GPIO_Init(LED3_ATC,0);
	GPIO_Init(LED4_OCC,0);
	GPIO_Init(LED5_ACTIVE,0);
	GPIO_Init(LED8_MEDIA,0);
	GPIO_Init(LED60_ERR,0);
   
    _LED_IO_CTRL(LED_SYS_RUN,LED_OFF);
	_LED_IO_CTRL(LED_MANUAL,LED_OFF);
	_LED_IO_CTRL(LED_TMS,LED_OFF);
	_LED_IO_CTRL(LED_ATC,LED_OFF);
	_LED_IO_CTRL(LED_OCC,LED_OFF);
	_LED_IO_CTRL(LED_ACTIVE,LED_OFF);
	_LED_IO_CTRL(LED_MIC,LED_OFF);
	_LED_IO_CTRL(LED_ERR,NOR_STA);
    

}

int  LED_Ctrl(const int _iLed,const int _iStatus)
{

	return 	_LED_IO_CTRL(_iLed,_iStatus);
    
}

int  LED_Toggle(const int _iLed)
{
	int value = _LED_GetValue(_iLed);

	value  = !value;
    _LED_IO_CTRL(_iLed,value);
	
}


