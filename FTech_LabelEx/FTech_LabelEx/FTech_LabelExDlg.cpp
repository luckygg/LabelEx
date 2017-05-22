
// FTech_LabelExDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FTech_LabelEx.h"
#include "FTech_LabelExDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFTech_LabelExDlg dialog



int g_nA=0,g_nR=0,g_nG=0,g_nB=0, g_nOrgX=0;
CFTech_LabelExDlg::CFTech_LabelExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFTech_LabelExDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_plbTest = NULL;
}

void CFTech_LabelExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LB_TEST, m_lbTest);
	DDX_Control(pDX, IDC_LB_TEST2, m_lbTest2);
}

BEGIN_MESSAGE_MAP(CFTech_LabelExDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BTN_TIMER, &CFTech_LabelExDlg::OnBnClickedBtnTimer)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CFTech_LabelExDlg message handlers

BOOL CFTech_LabelExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	m_lbTest.SetAlignTextLB();
	m_lbTest.LoadImageFromResource(IDB_PNG1, true);
	m_lbTest.SetSizeImage(10,0,60,60);

	m_lbTest.SetAlignTextCM();
	m_lbTest.SetColorBkg(255,128,128,128);
	m_lbTest.SetColorBorder(255,100,100,100);

	srand((unsigned)time(NULL));

	m_plbTest = new CLabelEx();
	m_plbTest->CreateContol(this,CRect(200,75,320,120),2020);
	m_plbTest->SetColorBkg(255,128,128,128);
	m_plbTest->SetText(_T("Push Button"));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFTech_LabelExDlg::OnPaint()
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
HCURSOR CFTech_LabelExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFTech_LabelExDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 100)
	{
		g_nA+=1;
		g_nR+=3;
		g_nG+=5;
		g_nB+=7;

		if (g_nA > 128) g_nA =0;
		if (g_nR > 255) g_nR =0;
		if (g_nG > 255) g_nG =0;
		if (g_nB > 255) g_nB =0;
		
		int r = rand()%100;
		int r2 = rand()%50;

		m_lbTest.SetColorBkg(g_nA,g_nR,g_nG,g_nB);
		m_lbTest.SetColorBorder(g_nA,g_nG,g_nB,g_nR);
		m_lbTest.SetOffsetText(r,0);

		m_lbTest.SetSizeImage(r2,0,60,60);

		OnUpdateTime();
	}

	CDialogEx::OnTimer(nIDEvent);
}

void CFTech_LabelExDlg::OnBnClickedBtnTimer()
{
	CString caption = _T("");
	GetDlgItemText(IDC_BTN_TIMER, caption);

	if (caption == _T("Start"))
	{
		SetTimer(100,30,NULL);
		SetDlgItemText(IDC_BTN_TIMER, _T("Stop"));
	}
	else
	{
		KillTimer(100);

		SetDlgItemText(IDC_BTN_TIMER, _T("Start"));
	}
}


void CFTech_LabelExDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	if (m_plbTest != NULL)
	{
		m_plbTest->DestroyWindow();
		delete m_plbTest;
		m_plbTest = NULL;
	}
}

void CFTech_LabelExDlg::OnUpdateTime()
{
	CTime time;
	time = CTime::GetCurrentTime();

	CString strTime=_T("");
	strTime.Format(_T("%02d:%02d:%02d"),time.GetHour(),time.GetMinute(),time.GetSecond());

	m_lbTest2.SetText(strTime);
}