// CharClient.h : main header file for the CHARCLIENT application
//

#if !defined(AFX_CHARCLIENT_H__D3F9FFC3_6535_4507_813A_4A911E69F4E5__INCLUDED_)
#define AFX_CHARCLIENT_H__D3F9FFC3_6535_4507_813A_4A911E69F4E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCharClientApp:
// See CharClient.cpp for the implementation of this class
//

class CCharClientApp : public CWinApp
{
public:
	CCharClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCharClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARCLIENT_H__D3F9FFC3_6535_4507_813A_4A911E69F4E5__INCLUDED_)
