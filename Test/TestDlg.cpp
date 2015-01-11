
// TestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "Global.h"
#include "TestDlg.h"
#include "LogDlg.h"
#include "SettingsDialog.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestDlg dialog

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDlg::IDD, pParent)
	, m_Message(_T(""))
	, m_UserSelected(_T(""))
	, m_pLogDlg(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SERVER_NAME, Glob.ServerName);
	DDX_Control(pDX, IDC_USERS, m_cUsers);
	DDX_Text(pDX, IDC_MESSAGE, m_Message);
	DDV_MaxChars(pDX, m_Message, 1000);
	DDX_Control(pDX, IDC_MSG_LOG, m_cMsgLog);
	DDX_CBString(pDX, IDC_USERS, m_UserSelected);
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, &CTestDlg::OnBnClickedConnect)
	ON_BN_CLICKED(IDC_SEND, &CTestDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDC_SETTINGS, &CTestDlg::OnBnClickedSettings)
	ON_BN_CLICKED(IDC_BTN_LOG, &CTestDlg::OnBnClickedBtnLog)
	ON_BN_CLICKED(IDC_TEST, &CTestDlg::OnBnClickedTest)
END_MESSAGE_MAP()


// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_cUsers.AddString(_T("User1"));
    m_cUsers.AddString(_T("User2"));
    m_cUsers.AddString(_T("User3"));

	GetDlgItem(IDC_SEND)->EnableWindow(FALSE);

	#ifndef DEBUG
	    GetDlgItem(IDC_TEST)->ShowWindow(SW_HIDE); //SW_SHOW
    #endif

	CButton* pBtn= (CButton*)GetDlgItem(IDC_SETTINGS);
	pBtn->ModifyStyle( 0, BS_BITMAP );
	
	HANDLE hIcn = ::LoadImage(0, "settings.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	//CImage image;
    //image.Load ( "settings.png" );	

	pBtn->SetBitmap((HBITMAP)hIcn);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CTestDlg::OnBnClickedConnect()
{
    CString str;

	UpdateData(TRUE);

	if (Glob.ServerName.GetLength() == 0) {
	   AfxMessageBox("Please specify the server name in Settings dialog");
	   return;
	}

	str.Format("Connect: server=%s, port=%s \r\n", Glob.ServerName, "no port yet");
	if (m_pLogDlg)
	    m_pLogDlg -> AddLog(str);

	GetDlgItem(IDC_SEND)->EnableWindow(TRUE);
}

//void CTestDlg::OnBnClickedClearLog()
//{
//	int count = m_cLog.GetCount();
//	for (int i = 0; i < count; i++)
//	{
//	   m_cLog.DeleteString(0);
//	}
//}

void CTestDlg::OnBnClickedSend()
{
	CString str;
    UpdateData(TRUE);

	if (m_UserSelected.GetLength() == 0 || m_Message.GetLength() == 0) {
	   AfxMessageBox("The destination client is not chosen or the message is empty");
	   return;
	}
    
	str.Format("me->%s: %s\r\n", m_UserSelected, m_Message);

	int nEnd = m_cMsgLog.GetWindowTextLength();
    m_cMsgLog.SetSel(nEnd, nEnd);
	m_cMsgLog.ReplaceSel(str);

	if (m_pLogDlg)
	    m_pLogDlg -> AddLog(str);
}

void CTestDlg::OnBnClickedSettings()
{
	CSettingsDialog dlg;
	if (dlg.DoModal() == IDOK) {
		//OK btn pressed
		 UpdateData(FALSE);	
	} else {
	    //cancel was pressed
	}
}

void CTestDlg::OnBnClickedBtnLog()
{
	if (m_pLogDlg)
		return;

    m_pLogDlg = new CLogDlg(this);
	if (m_pLogDlg != NULL)
	{
		BOOL ret = m_pLogDlg->Create(IDD_LOG_DIALOG, this);

		if (!ret)   //Create failed.
		{
			AfxMessageBox(_T("Error creating Log Dialog"));
		}    
		m_pLogDlg->ShowWindow(SW_SHOW);
	}
}

void CTestDlg::OnLogDlgClose(void)
{
	if (m_pLogDlg) {
		delete m_pLogDlg;
	    m_pLogDlg = NULL;
	}
}

void CTestDlg::OnBnClickedTest()
{
	//for testing ...
}

LRESULT CTestDlg::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch ( message )
    {  //Обработка пользовательских сообщений
       case WM_USER_LOG_CLOSED:
		   OnLogDlgClose();
		   break;
	}

	return CDialogEx::DefWindowProc(message, wParam, lParam);
}
