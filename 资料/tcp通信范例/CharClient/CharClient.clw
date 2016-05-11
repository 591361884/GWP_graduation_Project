; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCharClientDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CharClient.h"

ClassCount=4
Class1=CCharClientApp
Class2=CCharClientDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CClientSocket
Resource3=IDD_CHARCLIENT_DIALOG

[CLS:CCharClientApp]
Type=0
HeaderFile=CharClient.h
ImplementationFile=CharClient.cpp
Filter=N

[CLS:CCharClientDlg]
Type=0
HeaderFile=CharClientDlg.h
ImplementationFile=CharClientDlg.cpp
Filter=D
LastObject=CCharClientDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=CharClientDlg.h
ImplementationFile=CharClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHARCLIENT_DIALOG]
Type=1
Class=CCharClientDlg
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_UID,edit,1350631552
Control3=IDC_BUTTON_LOG,button,1342242816
Control4=IDC_BUTTON_EXIT,button,1342242816
Control5=IDC_EDIT_RECIVE,edit,1352734916
Control6=IDC_EDIT_RECID,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT_SEND,edit,1352728772
Control9=IDC_BUTTON_SEND,button,1342242816
Control10=IDC_LIST_LIVE,SysListView32,1350631425
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308352

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

