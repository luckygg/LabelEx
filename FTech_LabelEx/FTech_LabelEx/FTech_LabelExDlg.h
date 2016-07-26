
// FTech_LabelExDlg.h : header file
//

#pragma once
#include "LabelEx.h"


// CFTech_LabelExDlg dialog
class CFTech_LabelExDlg : public CDialogEx
{
// Construction
public:
	CFTech_LabelExDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FTech_LabelEx_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CLabelEx m_lbTest;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedBtnTimer();
};
