#ifndef _USERTYPE_H
#define _USERTYPE_H

//功能号
typedef enum {LOGIN=1,LOGOUT,LOGERR,LOGOK,TRANSMIT,SRVSTOP,DOLOGOUT} FUN;

//数据格式
typedef struct  
{
	FUN  fun;//功能号
	char SenderId[32];//发送者ID
	char ReceiveId[32];//接收者ID
	char Content[256];//内容

}NET_PACK;

#endif