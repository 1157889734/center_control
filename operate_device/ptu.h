//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& PC������� &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//*�ļ�����:setup.h

//*�ļ�����:PC�������

//*�ļ�����:mmaple

//*��������:2007��5��
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&



#ifndef PTU_H
#define PTU_H

#define PTU_DIR_UP			0
#define PTU_DIR_DOWN		1

void ptu_init(void);
void ptu_send_log_dev_status_packet(uint8 *buf, uint16 len);

void ptu_stop_tba_bus_send_pack(void);
void ptu_resume_tba_bus_send_pack(void);
void ptu_send_dev_status(uint8 *buf, uint16 len);

//ͨ��pisc_id��ö�Ӧ�ĳ����
uint8 ptu_get_cab_id_from_dev_id(uint8 dev_id);

#endif
