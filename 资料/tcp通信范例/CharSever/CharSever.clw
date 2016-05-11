; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCharSeverDlg
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CharSever.h"

ClassCount=5
Class1=CCharSeverApp
Class2=CCharSeverDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CLisenSocket
Class4=CClientSocket
Resource3=IDD_CHARSEVER_DIALOG

[CLS:CCharSeverApp]
Type=0
HeaderFile=CharSever.h
ImplementationFile=CharSever.cpp
Filter=N

[CLS:CCharSeverDlg]
Type=0
HeaderFile=CharSeverDlg.h
ImplementationFile=CharSeverDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_LIST_LOG

[CLS:CAboutDlg]
Type=0
HeaderFile=CharSeverDlg.h
ImplementationFile=CharSeverDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHARSEVER_DIALOG]
Type=1
Class=CCharSeverDlg
ControlCount=5
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_PORT,edit,1350631552
Control3=IDC_BUTTON_START,button,1342242816
Control4=IDC_BUTTON_STOP,button,1342242816
Control5=IDC_LIST_LOG,SysListView32,1350631425

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

[CLS:CLisenSocket]
Type=0
HeaderFile=LisenSocket.h
ImplementationFile=LisenSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

