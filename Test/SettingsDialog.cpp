// SettingsDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "Global.h"
#include "SettingsDialog.h"
#include "afxdialogex.h"

// CSettingsDialog dialog

IMPLEMENT_DYNAMIC(CSettingsDialog, CDialog)

CSettingsDialog::CSettingsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingsDialog::IDD, pParent)	
	, m_ServerPort(_T(""))
{
}

CSettingsDialog::~CSettingsDialog()
{
}

void CSettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SERVER_NAME, Glob.ServerName);
	DDX_Text(pDX, IDC_SETTING_PORT, Glob.ServerPort);
}


BEGIN_MESSAGE_MAP(CSettingsDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CSettingsDialog::OnBnClickedOk)
//	ON_EN_CHANGE(IDC_SETTING_PORT, &CSettingsDialog::OnEnChangeSettingPort)
END_MESSAGE_MAP()

void CSettingsDialog::OnBnClickedOk()
{
	UpdateData(TRUE);

	Glob.SaveAllParams();

	CDialog::OnOK();
}


