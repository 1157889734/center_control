//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& ���ֱ�վ�� &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//*�ļ�����:dva.h
//*�ļ�����:���ֱ�վ��
//*�ļ�����:mmaple
//*��������:2007��5��
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


#ifndef LCU_LED_H
#define LCU_LED_H


void lcu_led_init(void);
void lcu_led_show(void);
void lcu_led_roll_sec(void);
//���ÿ���������ʾ����
//void lcu_led_set_content(uint8 broadcast_type_c,uint8 language_c);
void lcu_led_set_content(uint8* path,uint16 *list,uint16 list_num);
//���Ϳ���led����ʾ����
void lcu_led_send_content(void);


#endif


