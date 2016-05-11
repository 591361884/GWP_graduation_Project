// CharClientDlg.h : header file
//

#if !defined(AFX_CHARCLIENTDLG_H__672D944D_F109_46AA_95C3_E760137DE2FB__INCLUDED_)
#define AFX_CHARCLIENTDLG_H__672D944D_F109_46AA_95C3_E760137DE2FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ClientSocket.h"
#include "../Common/UserType.h"
//using namespace std;

/////////////////////////////////////////////////////////////////////////////
// CCharClientDlg dialog

class CCharClientDlg : public CDialog
{
// Construction
public:
	void Transtr(const CString &str);
	void InsertLiving(const CString &strID);
	void HandleSrvStop(NET_PACK *pPack);
	void HandleTransmit(NET_PACK *pPack);
	void HandleLogERR(NET_PACK *pPack);
	void HandleLogOK(NET_PACK *pPack);
	void HandleDoLogout(NET_PACK *pPack);
	CCharClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCharClientDlg)
	enum { IDD = IDD_CHARCLIENT_DIALOG };
	CListCtrl	m_lsLiving;
	CEdit	m_edRecive;
	CButton	m_btnSend;
	CButton	m_btnLog;
	CButton	m_btnExit;
	CString	m_strReciveID;
	CString	m_strSend;
	CString	m_strUid;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCharClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
private:
	  void Inize();
     CClientSocket     m_socket;
	 CString   m_stridCpy;

	 CString  m_strID;
	 UINT     m_uPort;
	 
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCharClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonLog();
	afx_msg void OnButtonExit();
	afx_msg void OnButtonSend();
	afx_msg void OnClose();
	afx_msg void OnClickListLive(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg LRESULT onNetRecive(WPARAM wparam,LPARAM lparam);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHARCLIENTDLG_H__672D944D_F109_46AA_95C3_E760137DE2FB__INCLUDED_)
