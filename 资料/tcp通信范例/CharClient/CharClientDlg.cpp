// CharClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CharClient.h"
#include "CharClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCharClientDlg dialog

CCharClientDlg::CCharClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCharClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCharClientDlg)
	m_strReciveID = _T("");
	m_strSend = _T("");
	m_strUid = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

//	m_stridCpy = m_strUid;
//	UpdateData(FALSE);
}

void CCharClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCharClientDlg)
	DDX_Control(pDX, IDC_LIST_LIVE, m_lsLiving);
	DDX_Control(pDX, IDC_EDIT_RECIVE, m_edRecive);
	DDX_Control(pDX, IDC_BUTTON_SEND, m_btnSend);
	DDX_Control(pDX, IDC_BUTTON_LOG, m_btnLog);
	DDX_Control(pDX, IDC_BUTTON_EXIT, m_btnExit);
	DDX_Text(pDX, IDC_EDIT_RECID, m_strReciveID);
	DDX_Text(pDX, IDC_EDIT_SEND, m_strSend);
	DDX_Text(pDX, IDC_EDIT_UID, m_strUid);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCharClientDlg, CDialog)
	//{{AFX_MSG_MAP(CCharClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_LOG, OnButtonLog)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_BN_CLICKED(IDC_BUTTON_SEND, OnButtonSend)
	ON_WM_CLOSE()
	ON_NOTIFY(NM_CLICK, IDC_LIST_LIVE, OnClickListLive)
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_NETRECEIVE,onNetRecive)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCharClientDlg message handlers

BOOL CCharClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_btnExit.EnableWindow(FALSE);
	m_btnSend.EnableWindow(FALSE);
	Inize();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCharClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCharClientDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCharClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



//////////////////////////////////////////////////
//登入
void CCharClientDlg::OnButtonLog() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strUid.IsEmpty())
	{
        AfxMessageBox("账号不能为空");
		return;
	}
	//创建stocket
	if (!m_socket.Create())
	{
      AfxMessageBox("未成功创建stocket");
	  return;
	}
	//建立连接
	//使用ini读取
	//定义两个变量
	//m_uport为端口号
	//m_strid为id号

	if (!m_socket.Connect(m_strID,m_uPort))
	{
		AfxMessageBox("无法连接服务器");
		m_socket.Close();
		return;
	}
    //发数据
	NET_PACK pack ;
	memset(&pack,0,sizeof(NET_PACK));
	pack.fun = LOGIN;
	lstrcpy(pack.SenderId,(LPCSTR)m_strUid);
	m_socket.Send(&pack,sizeof(NET_PACK));
    m_stridCpy = m_strUid;
	UpdateData(FALSE);
   	m_btnLog.EnableWindow(FALSE);
	m_btnExit.EnableWindow(TRUE);
	m_btnSend.EnableWindow(TRUE);
	Sleep(5);
}

void CCharClientDlg::OnButtonExit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strUid == m_stridCpy)
	{
		NET_PACK pack;
	memset(&pack,0,sizeof(NET_PACK));
	
	pack.fun = LOGOUT;
	lstrcpy(pack.SenderId,(LPCTSTR)m_stridCpy);
	
	m_socket.Send(&pack,sizeof(NET_PACK));
	
	Sleep(5);
	
	m_socket.ShutDown(2);
	m_socket.Close();
	
	m_btnExit.EnableWindow(FALSE);
	m_btnLog.EnableWindow(TRUE);
	m_btnSend.EnableWindow(FALSE);
	}
	else
	{
		AfxMessageBox("请不要把别人的号下线");
		m_strUid = m_stridCpy;
		UpdateData(FALSE);
		return;
	}
	m_lsLiving.DeleteAllItems();
}

void CCharClientDlg::OnButtonSend() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if (m_strSend.IsEmpty())
	{
		AfxMessageBox("请输入内容");
		return;
	}
	if (m_strUid == m_strReciveID)
	{
		 AfxMessageBox("请不要给自己发消息");
		 m_strReciveID.Empty();
		 UpdateData(FALSE);
		 return;
	}
	//发数据
	NET_PACK pack;
	memset(&pack,0,sizeof(NET_PACK));
	pack.fun = TRANSMIT;
     
 



	lstrcpy(pack.Content,(LPCTSTR)m_strSend);
	lstrcpy(pack.ReceiveId,(LPCTSTR)m_strReciveID);
	lstrcpy(pack.SenderId,(LPCTSTR)m_strUid);




	m_socket.Send(&pack,sizeof(NET_PACK));
   	//Sleep(5);
}



LRESULT CCharClientDlg::onNetRecive(WPARAM wparam,LPARAM lparam)
{

	NET_PACK *pPack = 	(NET_PACK *)wparam;
	//CClientSocket * pSocket
	switch(pPack->fun)
	{
	case LOGOK:
		HandleLogOK(pPack);
		break;
	case LOGERR:
		HandleLogERR(pPack);
		break;
	case TRANSMIT:
		HandleTransmit(pPack);
		break;
	case SRVSTOP:
		HandleSrvStop(pPack);
		break;
	case DOLOGOUT:
		HandleDoLogout(pPack);
	}

	return 0;
}


//登入成功
void CCharClientDlg::HandleLogOK(NET_PACK *pPack)
{
	m_btnLog.EnableWindow(FALSE);
	m_btnExit.EnableWindow(TRUE);
	m_btnSend.EnableWindow(TRUE);
   // UpdateData(TRUE);
//	InsertLiving(m_strUid);
	m_lsLiving.DeleteAllItems();
 
	
	
//过滤","算法
	 Transtr(pPack->Content);
//	InsertLiving(pPack->Content);


}


//登入失败
void CCharClientDlg::HandleLogERR(NET_PACK *pPack)
{
	AfxMessageBox(pPack->Content);
	m_socket.ShutDown(2);
	m_socket.Close();
   
	
	m_strUid.Empty();
	UpdateData(FALSE);

	m_btnExit.EnableWindow(FALSE);
	m_btnLog.EnableWindow(TRUE);
	m_btnSend.EnableWindow(FALSE);

}


//数据转换
void CCharClientDlg::HandleTransmit(NET_PACK *pPack)
{
	/*
	CTime tm = CTime::GetCurrentTime();

	CString str = tm.Format(_T("%Y-%m-%d  %H-%M-%S")) ;
	CString str1;
	str1.Format(_T("%s  %s   说:\r\n %s \r\n"),
		str,pPack->SenderId,pPack->Content);
	m_edRecive.SetSel(-1);
	m_edRecive.ReplaceSel(str);
  */
	CString str;//str1,str2;
	
	CTime tm = CTime::GetCurrentTime();
	CString strTime = tm.Format(_T("%Y-%m-%d %H:%M:%S"));
	
	str.Format(_T("%s  %s 说:  \r \n%s\n\n"),
	strTime,pPack->SenderId,pPack->Content);
//	AfxMessageBox(str);
//    m_edRecive.SetWindowText(str);
	m_edRecive.SetSel(-1);
	m_edRecive.ReplaceSel(str);
//	m_edRecive.ReplaceSel("\r\n");
  //  str1.Format(_T(""));
	
//	m_edRecive.SetSel(-1);
//	m_edRecive.ReplaceSel(str1);

}


//服务器停止
void CCharClientDlg::HandleSrvStop(NET_PACK *pPack)
{
	AfxMessageBox(pPack->Content);
	m_socket.ShutDown(2);
	m_socket.Close();

	m_btnExit.EnableWindow(FALSE);
	m_btnLog.EnableWindow(TRUE);
	m_btnSend.EnableWindow(FALSE);


}

void CCharClientDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(TRUE);
	
	NET_PACK pack;
	memset(&pack,0,sizeof(NET_PACK));
	
	pack.fun = TRANSMIT;
	lstrcpy(pack.SenderId,(LPCTSTR)m_strUid);
	
	m_socket.Send(&pack,sizeof(NET_PACK));
	
	Sleep(5);
	
	m_socket.ShutDown(2);
	m_socket.Close();
	
	m_btnExit.EnableWindow(FALSE);
	m_btnLog.EnableWindow(TRUE);
	m_btnSend.EnableWindow(FALSE);
	CDialog::OnClose();
}

void CCharClientDlg::OnClickListLive(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	//int n = m_lsLiving.GetItemText();
	//CString str = m_lsLiving.GetItemText()
   //获取单机所在行号
	
	int n  =0;
	DWORD dwPos = GetMessagePos();
	CPoint point(LOWORD(dwPos),HIWORD(dwPos));
	m_lsLiving.ScreenToClient(&point);
    LVHITTESTINFO lvinfo;
	lvinfo.pt = point;

	int nitem = m_lsLiving.HitTest(&lvinfo);
	if (nitem != -1)
	{n = lvinfo.iItem;}
     
	CString str11 =  m_lsLiving.GetItemText(n,1);

     //AfxMessageBox(str11);
	 m_strReciveID = str11;
	 UpdateData(FALSE);
	 
    
	*pResult = 0;
}

void CCharClientDlg::Inize()
{
	m_lsLiving.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
    m_lsLiving.InsertColumn(0,_T("序号"),LVCFMT_LEFT,50);
	m_lsLiving.InsertColumn(1,_T("当前在线用户"),LVCFMT_LEFT,150);
//	m_lsLiving.InsertColumn(2,_T("时间"),LVCFMT_LEFT,150);

    GetPrivateProfileString(_T("USER"),_T("ID "),"127.0.0.2",m_strID.GetBuffer(20)
		                    ,20,_T("..\\bin\\clineConfig.ini"));
	m_strID.ReleaseBuffer();
	m_uPort = GetPrivateProfileInt(_T("USER"),_T("PORT"),5000,_T("..\\bin\\clineConfig.ini"));


}

void CCharClientDlg::InsertLiving(const CString &strID)
{
     //插入序号
	  
	int ncount = m_lsLiving.GetItemCount();
	  CString str;
	  str.Format(_T("%d"),ncount+1);
	  m_lsLiving.InsertItem(ncount,str,0);
	  //插入用户名
      m_lsLiving.SetItemText(ncount,1,strID);
	  //插入登入时间
//	  CTime tm= CTime::GetCurrentTime();
//	  CString strtm = tm.Format(_T("%Y-%m-%d   %H-%M-%S"));
 //     m_lsLiving.SetItemText(ncount,2,strtm);


	
}
//过滤字符串
void CCharClientDlg::Transtr(const CString &str)
{
     m_lsLiving.DeleteAllItems();
	int h =0;
	int g = -1;
	int i = 0;
	int n = 0;
	int j = 0;
    while(i == 0)
	{
		  n = str.Find(",",g+1);
          j = str.GetLength();
		if ((n+1) == str.GetLength())
		{
			CString strInsert;
			strInsert = str.Mid(g+1,n-g-1);
			InsertLiving(strInsert);
		    g = n;
			i = 1;
			break;
		}
		CString strInsert;
		strInsert = str.Mid(g+1,n-g-1);
		InsertLiving(strInsert);
		g = n;
	}

}

//处理登出操作后在线列表
void CCharClientDlg::HandleDoLogout(NET_PACK *pPack)
{
     Transtr(pPack->Content);
}
