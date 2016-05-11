// CharSeverDlg.h : header file
//

#if !defined(AFX_CHARSEVERDLG_H__C153F992_08B3_4270_89B3_978D4BE038FE__INCLUDED_)
#define AFX_CHARSEVERDLG_H__C153F992_08B3_4270_89B3_978D4BE038FE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LisenSocket.h"
#include "ClientSocket.h"
#include "../Common/UserType.h"
/////////////////////////////////////////////////////////////////////////////
// CCharSeverDlg dialog

class CCharSeverDlg : public CDialog
{
// Construction
private:
    CClientSocket* FindList(const CString &strID,BOOL isdelete);
	void  HandleLogin(NET_PACK *pPack, CClientSocket *pSocket);
	void  Initize();
	void  HandleLOGOUT(NET_PACK *pPack);
	void  HandleTRANSMIT(NET_PACK *pPack);
	
public:
	CCharSeverDlg(CWnd* pParent = NULL);	// standard constructor
// Dialog Data

	//{{AFX_DATA(CCharSeverDlg)
	
	enum { IDD = IDD_CHARSEVER_DIALOG };
	CListCtrl	m_lcLog;
	CButton	m_btnStop;
	CButton	m_btnStart;
	UINT	m_uPort;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharSeverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
private:
	void InsertLOG(const CString &strID,const CString &strLOG);
	CLisenSocket    m_socket;  //¸ºÔð¼àÌýµÄsocket

protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCharSeverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonStop();
	afx_msg void OnClose();
	//}}AFX_MSG
	afx_msg LRESULT onNetRecvice(WPARAM wparam,LPARAM lparam);
	 
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARSEVERDLG_H__C153F992_08B3_4270_89B3_978D4BE038FE__INCLUDED_)
