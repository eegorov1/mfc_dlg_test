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
{
}

CSettingsDialog::~CSettingsDialog()
{
}

void CSettingsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SERVER_NAME, Glob.ServerName);
}


BEGIN_MESSAGE_MAP(CSettingsDialog, CDialog)
	ON_BN_CLICKED(IDOK, &CSettingsDialog::OnBnClickedOk)
END_MESSAGE_MAP()

void CSettingsDialog::OnBnClickedOk()
{
	UpdateData(TRUE);

	Glob.SaveAllParams();

	CDialog::OnOK();
}
