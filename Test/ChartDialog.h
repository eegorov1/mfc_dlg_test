#pragma once
#include "afxwin.h"
#include "Global.h"


// CChartDialog dialog

class CChartDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CChartDialog)

public:
	CChartDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CChartDialog();

	void DrawChart(CDC * pDC, CHART_ARRAY & trend);

// Dialog Data
	enum { IDD = IDD_CHART_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	CHART_ARRAY chartTrend;
	CPoint m_StartPoint;

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CStatic m_cChartRect;
	virtual BOOL OnInitDialog();
};
