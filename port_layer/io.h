//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& ���Զ����� &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//*�ļ�����:halt_ato.c

//*�ļ�����:�г�ͨ�����߹�����

//*�ļ�����:mmaple

//*��������:2010��12��
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

#ifndef IO_H
#define IO_H

typedef void (*io_handler_callback)(uint8);

//��������ܽŶ���
#define INPUT_PIN	1
#define OUTPUT_PIN	0

//��ƽ����
#define IO_LEVEL_HIGH	1
#define IO_LEVEL_LOW	0


#define IO_VALID		(IO_LEVEL_LOW)
#define IO_UNVALID		(IO_LEVEL_HIGH)


//io�ܽų�ʼ��
void io_init(void);
//����io�ܽŵ�ƽ״̬
void io_set_level(uint8 pin_cmd, uint8 level);
//�ض�io�ܽŵ�ƽ״̬
uint8 io_get_level(uint8 pin_cmd);
//io�ܽų�ʼ��
void io_add_pin_init(uint8 pin_cmd,io_handler_callback handler);

#endif


