#if !defined(AFX_NUMBEREDIT_H__9DBD11F5_3CAF_4B52_B080_D995EA0F8BE8__INCLUDED_)
#define AFX_NUMBEREDIT_H__9DBD11F5_3CAF_4B52_B080_D995EA0F8BE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NumberEdit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNumberEdit window

class CNumberEdit : public CEdit
{
// Construction
public:
	CNumberEdit();
private:
   int i ;    //iΪС���ı��
   int j ;    //jΪ���ŵı�־

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumberEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNumberEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNumberEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMBEREDIT_H__9DBD11F5_3CAF_4B52_B080_D995EA0F8BE8__INCLUDED_)
