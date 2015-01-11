// LogDlg.cpp : implementation file
//
#include "stdafx.h"
#include "Test.h"
#include "LogDlg.h"
#include "TestDlg.h"
#include "afxdialogex.h"

// CLogDlg dialog

IMPLEMENT_DYNAMIC(CLogDlg, CDialogEx)

CLogDlg::CLogDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLogDlg::IDD, pParent)
{
	m_pMainDlg = pParent;
	ASSERT(m_pMainDlg!=NULL);
}

CLogDlg::~CLogDlg()
{
}

void CLogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOG, m_cLog);
}

BEGIN_MESSAGE_MAP(CLogDlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &CLogDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_CLEAR_BTN, &CLogDlg::OnBnClickedClearBtn)
END_MESSAGE_MAP()


// CLogDlg message handlers
void CLogDlg::OnBnClickedCancel()
{
	((CTestDlg*)m_pMainDlg)->PostMessage(WM_USER_LOG_CLOSED);
	CDialogEx::OnCancel();
	// or make this sync. call after OnCancel():
	//((CTestDlg*)m_pMainDlg)->OnLogDlgClose();
}

void CLogDlg::AddLog(CString &msg) {
	int nEnd = m_cLog.GetWindowTextLength();
    m_cLog.SetSel(nEnd, nEnd);
	m_cLog.ReplaceSel(msg);
}

void CLogDlg::OnBnClickedClearBtn()
{
	int nEnd = m_cLog.GetWindowTextLength();
    m_cLog.SetSel(0, nEnd);
	m_cLog.ReplaceSel("");
}


BOOL CLogDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
