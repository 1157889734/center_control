//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& 数字报站器 &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//*文件名称:dva.h
//*文件作用:数字报站器
//*文件作者:mmaple
//*创建日期:2007年5月
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


#ifndef LED_DRIVER_H
#define LED_DRIVER_H


#define  LED_ON    0x00
#define  LED_OFF   0x01

#define  ERR_STA   0x01      
#define  NOR_STA   0x00


#define  LED_SYS_RUN        (0)
#define  LED_MANUAL         (1)
#define  LED_TMS            (2)
#define  LED_ATC            (3)
#define  LED_OCC            (4)
#define  LED_ACTIVE         (5)
#define  LED_MIC            (6)
#define  LED_ERR            (7)



//void led_init(void);
//void led_onoff(uint8 led_no, uint8 onoff);
//void led_toggle(uint8 led_no);
void LED_Init(void);


#endif



