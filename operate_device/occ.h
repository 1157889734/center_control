//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& �г�ͨ�����߽ӿ� &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//*�ļ�����:tba_bus.h

//*�ļ�����:�г�ͨ�����߽ӿ�

//*�ļ�����:

//*��������:2007��5��
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


#ifndef OCC_H
#define OCC_H

#define STATUS_ON 1
#define STATUS_OFF 0


void occ_init(void);
void occ_set_occ_status(uint8 flag);
void occ_send_audio(void);
uint8 get_occ_status(void);


#endif

