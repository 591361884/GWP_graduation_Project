#ifndef _USERTYPE_H
#define _USERTYPE_H

//���ܺ�
typedef enum {LOGIN=1,LOGOUT,LOGERR,LOGOK,TRANSMIT,SRVSTOP,DOLOGOUT} FUN;

//���ݸ�ʽ
typedef struct  
{
	FUN  fun;//���ܺ�
	char SenderId[32];//������ID
	char ReceiveId[32];//������ID
	char Content[256];//����

}NET_PACK;

#endif