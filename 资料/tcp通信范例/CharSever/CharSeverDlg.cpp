// CharSeverDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CharSever.h"
#include "CharSeverDlg.h"


#include "../Common/UserType.h"
#include "ClientSocket.h"
#include "LisenSocket.h"
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
// CCharSeverDlg dialog

CCharSeverDlg::CCharSeverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCharSeverDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCharSeverDlg)
	m_uPort = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCharSeverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCharSeverDlg)
	DDX_Control(pDX, IDC_LIST_LOG, m_lcLog);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_btnStop);
	DDX_Control(pDX, IDC_BUTTON_START, m_btnStart);
	DDX_Text(pDX, IDC_EDIT_PORT, m_uPort);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCharSeverDlg, CDialog)
	//{{AFX_MSG_MAP(CCharSeverDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, OnButtonStop)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
	ON_MESSAGE(WM_NETRECIVE,onNetRecvice)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCharSeverDlg message handlers

BOOL CCharSeverDlg::OnInitDialog()
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
	Initize();
	return FALSE;  // return TRUE  unless you set the focus to a control
}

void CCharSeverDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCharSeverDlg::OnPaint() 
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
HCURSOR CCharSeverDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



//////////////////////////
//////////////////////////

LRESULT CCharSeverDlg::onNetRecvice(WPARAM wparam,LPARAM lparam)
{
	NET_PACK *pPack = (NET_PACK *) wparam;
	CClientSocket *pSocket = (CClientSocket*) lparam;
	switch(pPack->fun)
	{
	case LOGIN://�����¼
		HandleLogin(pPack,pSocket);
		break;
	case LOGOUT://�����˳������ߣ�
		HandleLOGOUT(pPack);
		break;
	case TRANSMIT://����ת��
		HandleTRANSMIT(pPack);
		break;
	
	}
	if (NULL != pPack)
	{
		delete pPack;
		pPack = NULL;
	}
	return 0;

}

void CCharSeverDlg::OnButtonStart() 
{
	// TODO: Add your control notification handler code here
	//��������socket
	UpdateData(TRUE);
	
	if (!m_socket.Create(5500,SOCK_STREAM,"127.0.0.1"))
	{
		AfxMessageBox("�޷�����socket");
		return;
	}
	//��ʼ����
	if (!m_socket.Listen())
	{
		AfxMessageBox("�޷�����");
		m_socket.Close();
		return;
	}
    
    InsertLOG(_T("������"),_T("������������......."));

	//������ť����
	m_btnStart.EnableWindow(FALSE);
	m_btnStop.EnableWindow(TRUE);

}

void CCharSeverDlg::OnButtonStop() 
{
	// TODO: Add your control notification handler code here
	
	
    

	NET_PACK pack;
	memset(&pack,0,sizeof(NET_PACK));
	pack.fun = SRVSTOP;
	lstrcpy(pack.Content,(LPCTSTR)_T("������ά����...."));
	
	CClientSocket* pSocket = NULL;
	
	//����������
	//Ⱥ��ֹͣ��Ϣ
	list<CClientSocket*>::iterator iter;
	
	for(iter =CClientSocket::m_listClient.begin();
	iter != CClientSocket::m_listClient.end();
	iter++)
	{
		pSocket = *iter;
		
		pSocket->Send(&pack,sizeof(NET_PACK));
		
		delete pSocket;
		pSocket = NULL;
	}
	
	//�������
	CClientSocket::m_listClient.clear();

    InsertLOG(_T("������"),_T("��ֹͣ...."));
    
	m_socket.ShutDown(2);
	m_socket.Close();
	//������ť����
	m_btnStart.EnableWindow(TRUE);
	m_btnStop.EnableWindow(FALSE);
}


//��ʼ������
void CCharSeverDlg::Initize()
{
	m_btnStop.EnableWindow(FALSE);
    m_uPort = 5500;//�˿ںţ����������豸
    
    UpdateData(FALSE);
	SetWindowText(_T("��������"));

	//��ʼ��clistctril
	m_lcLog.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);

	m_lcLog.InsertColumn(0,_T("���"),LVCFMT_LEFT,50);
	m_lcLog.InsertColumn(1,_T("�û���"),LVCFMT_LEFT,80);
	m_lcLog.InsertColumn(2,_T("ʱ��"),LVCFMT_LEFT,150);
	m_lcLog.InsertColumn(3,_T("�¼�"),LVCFMT_LEFT,150);
	
	m_btnStart.SetFocus();

}
//����������
void CCharSeverDlg::HandleLogin(NET_PACK *pPack, CClientSocket *pSocket)
{
    CClientSocket *pClient = FindList(pPack->SenderId,FALSE);

	NET_PACK pack;
	memset(&pack,0,sizeof(NET_PACK));

	if (NULL != pClient)
	{  //�ѵ���
		pack.fun = LOGERR;

		lstrcpy(pack.Content,(LPCTSTR)_T("һ����"));
        
		pSocket->Send(&pack,sizeof(NET_PACK));
        	Sleep(5);
		pSocket->ShutDown(2);
		delete pSocket;
		pSocket = NULL;
	}
	else
	{
		//δ����
		pack.fun = LOGOK;
		pSocket->m_strUid = pPack->SenderId;
	/*
		CString str;
        list<CClientSocket*>::iterator iter;
		for(iter =CClientSocket::m_listClient.begin();
		iter != CClientSocket::m_listClient.end();
		iter++)
		{
			pSocket = *iter;
			str += pSocket->m_strUid;
			str +=",";
		}


		
		
		
		
		lstrcpy(pack.Content,str);
       */
		
	
	    //��������    	
		CClientSocket::m_listClient.push_back(pSocket);
        
		
		CString str;
        list<CClientSocket*>::iterator iter;
		for(iter =CClientSocket::m_listClient.begin();
		iter != CClientSocket::m_listClient.end();
		iter++)
		{
			pSocket = *iter;
			str += pSocket->m_strUid;
			str += ",";
		
		}
		
		lstrcpy(pack.Content,str);
        list<CClientSocket*>::iterator iter1;
		for(iter1 =CClientSocket::m_listClient.begin();
		iter1!= CClientSocket::m_listClient.end();
		iter1++)
		{
			pSocket = *iter1;
			pSocket->Send(&pack,sizeof(pack));
			
		}
		
        
		InsertLOG(pPack->SenderId,_T("�ѵ���........."));
	}
	
	
    
}

//����ǳ�����
void CCharSeverDlg::HandleLOGOUT(NET_PACK *pPack)
{
    //������ɾ��  
	CClientSocket *pClient = FindList(pPack->SenderId,TRUE);
    /////////////////////////////////////////////////  
    NET_PACK pack;
	memset(&pack,0,sizeof(NET_PACK));
	pack.fun = DOLOGOUT;
//	pSocket->m_strUid = pPack->SenderId;
    CString str;
	CClientSocket *pSocket;
	
	
	
	list<CClientSocket*>::iterator iter;
	for(iter =CClientSocket::m_listClient.begin();
	iter != CClientSocket::m_listClient.end();
	iter++)
	{
		pSocket = *iter;
		str += pSocket->m_strUid;
		str += ",";
		
	}
	lstrcpy(pack.Content,str);
	
	
	list<CClientSocket*>::iterator iter1;
	for(iter1 =CClientSocket::m_listClient.begin();
	iter1!= CClientSocket::m_listClient.end();
	iter1++)
	{
		pSocket = *iter1;
		pSocket->Send(&pack,sizeof(pack));
		
	}





	  if (NULL != pClient)
	  {
		  pClient->ShutDown(2);
		  delete pClient;
		  pClient = NULL;
		  InsertLOG(pPack->SenderId,_T("������....."));
	  }
     
    
}

//����ת������
void CCharSeverDlg::HandleTRANSMIT(NET_PACK *pPack)
{
     CClientSocket *pClient = FindList(pPack->ReceiveId,FALSE);

	 if (NULL != pClient)
	 {
		 pClient->Send(pPack,sizeof(NET_PACK));
	 }
	 else
	 {
		 //����Է�����
		 //
	     CClientSocket *pClient = FindList(pPack->SenderId,FALSE);
		
	 }
}



 CClientSocket *CCharSeverDlg::FindList(const CString &strID, BOOL isdelete = FALSE)
{  
    /*
	 CClientSocket * pClient = NULL; 
     //����������  
	 list<CClientSocket *> ::iterator iter;
	 for (iter = CClientSocket::m_listClient.begin();iter != CClientSocket::m_listClient.end();iter++)
	 {
		 if (pClient->m_strUid.Compare(strID)==0)
		 {
			 if (isdelete)
			 {
				 CClientSocket::m_listClient.erase(iter);
			 }
			 return pClient;

		 }
	 }
   return NULL;
   */
	 CClientSocket* pSocket = NULL;
	 
	 //����������
	 list<CClientSocket*>::iterator iter;
	 
	 for(iter =CClientSocket::m_listClient.begin();
	 iter != CClientSocket::m_listClient.end();
	 iter++)
	 {
		 pSocket = *iter;
		 
		 //�ҵ�
		 if(pSocket->m_strUid.Compare(strID) == 0)
		 {
			 //�Ƿ�ɾ��
			 if(isdelete)
			 {
				 CClientSocket::m_listClient.erase(iter);
			 }
			 return pSocket;
		 }
	 }
	 
	return NULL;
 }



 //����
void CCharSeverDlg::InsertLOG(const CString &strID, const CString &strLOG)
{
      //�������  0
	  int ncount = m_lcLog.GetItemCount();
	  CString str;
	  str.Format(_T("%d"),ncount+1);
	  m_lcLog.InsertItem(ncount,str,0);
	  
	  
	  //����id    1
	  m_lcLog.SetItemText(ncount,1,strID);
	 
	  //����ʱ��   2
	   CTime tm = CTime::GetCurrentTime();
	  CString strtm = tm.Format(_T("%Y-%m-%d  %H:%M:%S"));
	  m_lcLog.SetItemText(ncount,2,strtm);
     
	  //�����¼�   3
      m_lcLog.SetItemText(ncount,3,strLOG);

}

void CCharSeverDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	
	NET_PACK pack;
	memset(&pack,0,sizeof(NET_PACK));
	pack.fun = SRVSTOP;
	lstrcpy(pack.Content,(LPCTSTR)_T("������ά����...."));
	
	CClientSocket* pSocket = NULL;
	
	//����������
	//Ⱥ��ֹͣ��Ϣ
	list<CClientSocket*>::iterator iter;
	
	for(iter =CClientSocket::m_listClient.begin();
	iter != CClientSocket::m_listClient.end();
	iter++)
	{
		pSocket = *iter;
		
		pSocket->Send(&pack,sizeof(NET_PACK));
		
		delete pSocket;
		pSocket = NULL;
	}
	
	//�������
	CClientSocket::m_listClient.clear();
	
    InsertLOG(_T("������"),_T("��ֹͣ...."));
    
	m_socket.ShutDown(2);
	m_socket.Close();
	//������ť����
	m_btnStart.EnableWindow(TRUE);
	m_btnStop.EnableWindow(FALSE);
	CDialog::OnClose();
}
