#if !defined(AFX_LISENSOCKET_H__4CC58AEA_8420_4591_9D06_FAC6ABB59A9C__INCLUDED_)
#define AFX_LISENSOCKET_H__4CC58AEA_8420_4591_9D06_FAC6ABB59A9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LisenSocket.h : header file
//¸ºÔð¼àÌýµÄsocket



/////////////////////////////////////////////////////////////////////////////
// CLisenSocket command target

class CLisenSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CLisenSocket();
	virtual ~CLisenSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLisenSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CLisenSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISENSOCKET_H__4CC58AEA_8420_4591_9D06_FAC6ABB59A9C__INCLUDED_)
