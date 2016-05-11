#if !defined(AFX_CLIENTSOCKET_H__45BC1584_20F4_46A1_A2CF_24F97AC0C8CB__INCLUDED_)
#define AFX_CLIENTSOCKET_H__45BC1584_20F4_46A1_A2CF_24F97AC0C8CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//负责客户端的socket

#include <list>
using namespace std;

/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();

// Overrides
public:
	CString m_strUid;   //客户端用户ID
	static list<CClientSocket *>   m_listClient; //存放和客户端通信的Socket
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__45BC1584_20F4_46A1_A2CF_24F97AC0C8CB__INCLUDED_)
