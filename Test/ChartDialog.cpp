// ChartDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Test.h"
#include "ChartDialog.h"
#include "afxdialogex.h"
#include "Global.h"


// CChartDialog dialog

IMPLEMENT_DYNAMIC(CChartDialog, CDialogEx)

CChartDialog::CChartDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CChartDialog::IDD, pParent)
{

}

CChartDialog::~CChartDialog()
{
}

void CChartDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHART_RECT, m_cChartRect);
}

BEGIN_MESSAGE_MAP(CChartDialog, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CChartDialog message handlers

void CChartDialog::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialogEx::OnPaint() for painting messages
	
	// -- drawing inside the client rect of the Dialog --------------------------
	CPen pen;
	CBrush brush;
	// Magenta pen
	pen.CreatePen(PS_SOLID, 1, 0x00FF00FF);
	// Cyan brush
	brush.CreateSolidBrush(0x00FFFF00);
	// select brush and pen	

	dc.SelectObject(&pen);
	dc.SelectObject(&brush);
	// rectangle with magenta frame and cyan background
	dc.Rectangle(0,0,20,20); 

	// -- drawing inside the client rect of the control (m_cChartRect) -------------------------------------------------
	CDC* pDC = m_cChartRect.GetDC();

	CRect clientRect;
    m_cChartRect.GetClientRect(&clientRect);

	if (Glob.pLogDlg)
	    Glob.pLogDlg->AddLog(CString("Chart dialog opened/r/n"));	
	
	pDC->SelectObject(&pen);
	pDC->SelectObject(&brush);
	// rectangle with magenta frame and cyan background
	pDC->Rectangle(0,0,20,20); 
	
	int offset = 15;
	pDC->MoveTo(offset, offset);
    pDC->LineTo(offset, clientRect.bottom - offset);
	pDC->LineTo(clientRect.right - offset, clientRect.bottom - offset);

	m_StartPoint.SetPoint(offset, clientRect.bottom - offset);

	// Magenta pen
	pen.DeleteObject();
	pen.CreatePen(PS_SOLID, 1, RGB(0,0,255));
	// Cyan brush
	brush.DeleteObject();
	brush.CreateSolidBrush(RGB(0,255,0));
	// select brush and pen	
	pDC->SelectObject(&pen);
	pDC->SelectObject(&brush);

	DrawChart(pDC, chartTrend);

	ReleaseDC(pDC);
}


BOOL CChartDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CPoint point;
	chartTrend.reserve(100);
	for (int i = 1; i < 25; i++){
       point.SetPoint(i*20, (int)(50*sqrt((double)i)) );
	   chartTrend.push_back(point);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CChartDialog::DrawChart(CDC * pDC, CHART_ARRAY & trend) 
{
	CHART_ARRAY::iterator itr;
	int x1, x2, y1, y2;
    for (itr = trend.begin(); itr != trend.end(); itr++)
	{
		CPoint point = *itr;
        x1 = m_StartPoint.x + point.x - 5;
        x2 = m_StartPoint.x + point.x + 5;
        y1 = m_StartPoint.y - point.y + 5;
        y2 = m_StartPoint.y - point.y - 5;
		
		pDC->Rectangle(x1, y1, x2, y2); 
	}
}
