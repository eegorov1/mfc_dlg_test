#pragma once
#include "afxwin.h"
#include "libs\ETSLayout.h"

// CLogDlg dialog

class CLogDlg : public ETSLayoutDialog
{
	DECLARE_DYNAMIC(CLogDlg)

public:
	CLogDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLogDlg();
	void AddLog(CString &msg);

// Dialog Data
	enum { IDD = IDD_LOG_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	CWnd* m_pMainDlg;
public:
	afx_msg void OnBnClickedCancel();
	CEdit m_cLog;
	afx_msg void OnBnClickedClearBtn();
	virtual BOOL OnInitDialog();
};
