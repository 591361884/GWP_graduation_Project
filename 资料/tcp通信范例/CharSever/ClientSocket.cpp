// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "CharSever.h"
#include "ClientSocket.h"


#include <list>
#include "../Common/UserType.h"
#include "CharSeverDlg.h"

using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CClientSocket
list<CClientSocket*> CClientSocket::m_listClient;

CClientSocket::CClientSocket()
{
	m_strUid = _T("");
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	NET_PACK *pPack = new NET_PACK;
	//初始化缓冲区
	memset(pPack,0,sizeof(NET_PACK));
    //接收消息
	Receive(pPack,sizeof(NET_PACK));

    //派发消息
    CCharSeverDlg* pMain = (CCharSeverDlg *)AfxGetApp()->m_pMainWnd;
	pMain->PostMessage(WM_NETRECIVE,(WPARAM)pPack,(LPARAM)this);


	CSocket::OnReceive(nErrorCode);
}
