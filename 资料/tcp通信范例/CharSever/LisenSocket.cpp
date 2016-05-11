// LisenSocket.cpp : implementation file
//

#include "stdafx.h"
#include "CharSever.h"
#include "LisenSocket.h"

#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CLisenSocket

CLisenSocket::CLisenSocket()
{
}

CLisenSocket::~CLisenSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CLisenSocket, CSocket)
	//{{AFX_MSG_MAP(CLisenSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CLisenSocket member functions

void CLisenSocket::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class

	
	CClientSocket *pSocket = new CClientSocket;
    Accept(*pSocket);


	CSocket::OnAccept(nErrorCode);
}
