// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "CharClient.h"
#include "ClientSocket.h"


//#include "../Common/UserType.h"
//using namespace std;
#include "CharClientDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
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
	NET_PACK* pPack = new NET_PACK;
	memset(pPack,0,sizeof(NET_PACK));
	
	Receive(pPack,sizeof(NET_PACK));
	
	CCharClientDlg *pMainWnd = (CCharClientDlg *)AfxGetApp()->m_pMainWnd;
	
	//·¢ÏûÏ¢
	pMainWnd->PostMessage(WM_NETRECEIVE,(WPARAM)pPack,(LPARAM)NULL);
	CSocket::OnReceive(nErrorCode);
}
