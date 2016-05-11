// NumberEdit.cpp : implementation file
//

#include "stdafx.h"
//#include "text1_1.h"
#include "NumberEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumberEdit

CNumberEdit::CNumberEdit()
{
}

CNumberEdit::~CNumberEdit()
{
}


BEGIN_MESSAGE_MAP(CNumberEdit, CEdit)
	//{{AFX_MSG_MAP(CNumberEdit)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumberEdit message handlers

void CNumberEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if (isdigit(nChar)||8 ==nChar )       //isdigit（）判断是否为数字
	{	
		CEdit::OnChar(nChar, nRepCnt, nFlags);
	}
	if (nChar == 45 &&j!=1 )
	{
		CString str;
		GetWindowText(str);
		str ="-"+str;
        SetWindowText(str);
         
		//设置光标位置
		SetSel(-1);
		j = 1;
	}
	if (nChar == 46&&i !=1)
	{
		CString str1;
		GetWindowText(str1);
		str1 =str1+".";
        SetWindowText(str1);			
		SetSel(-1);
		i = 1;
	}
    CString str2;		
	GetWindowText(str2);
	if (str2.Find(_T(".")) == -1)
	{
		i=0;
	}
	if (str2.Find(_T("-")) == -1)
	{
		j=0;
	}

}
