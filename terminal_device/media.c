//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& ���ֱ�վ�� &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
//*�ļ�����:dva.c
//*�ļ�����:���ֱ�վ��
//*�ļ�����:mmaple
//*��������:2007��5��
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&


#include "../include/include.h"


#define CHANNEL_MEDIA	(CHANNEL_RIGHT)

//int fp_tmp=0;
FILE* fp_tmp=0;
uint32 read_index=0;
uint8 buf_tmp[1024]={0};

void media_init(void)
{	
	//fp_tmp=fopen("test.wav","r");

}


void media_play(void)
{

}

void media_stop(void)
{
}
//����ý����Ƶ����
void media_send_audio(void)
{
	static uint16 read_num=0;

	uint16 media_buf[AUDIO_CHANNEL_SIZE_SHORT];
	uint16 media_len=0;
#if 1
	//��������
	if(BH_TRUE==soundcard_get_data(CHANNEL_MEDIA,media_buf,&media_len))
	{
		read_num++;
		if((read_num%100)==0)
		{
			//printf("soundcard_get_media_data: %d\r\n",media_len);
			//print_buf((uint8 *)media_buf,30);
		}
		broadcast_audio_send_audio(broadcast_get_broadcast_operate_dev_type(),broadcast_get_broadcast_operate_dev_id(),(uint8 *)media_buf,media_len);
	}
#else

	//��wav�ļ�
	{
	   if(fp_tmp>0)
	   {
	   
		   //printf("wav_head size of is: %d\r\n",sizeof(struct wav_head));
		   //fread(buf_tmp,45,1,fp_tmp);
		  // fread(buf_tmp,58,1,fp_tmp);
		   fread(buf_tmp,sizeof(buf_tmp),1,fp_tmp);
		   
		   broadcast_audio_send_audio(buf_tmp,sizeof(buf_tmp));
		   printf("send wave data: %d\r\n",sizeof(buf_tmp));
			print_buf(buf_tmp,20);
	}

	}

#endif
}


