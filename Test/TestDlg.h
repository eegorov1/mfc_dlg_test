
// TestDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "LogDlg.h"

#define WM_USER_LOG_CLOSED   (WM_USER+1)

// CTestDlg dialog
class CTestDlg : public CDialogEx
{
// Construction
public:
	CTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;
	CLogDlg * m_pLogDlg;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedConnect();
	CComboBox m_cUsers;
	CString m_Message;
	CEdit m_cMsgLog;
	CString m_UserSelected;
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedSettings();
	afx_msg void OnBnClickedBtnLog();
	void OnLogDlgClose(void);
	afx_msg void OnBnClickedTest();
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};
