#pragma once

//----------------------------------------------------------
// LabelEx Control
//----------------------------------------------------------
// Programmed by William Kim
//----------------------------------------------------------

// CLabelEx
class CLabelEx : public CWnd
{
	DECLARE_DYNAMIC(CLabelEx)

public:
	CLabelEx();
	virtual ~CLabelEx();

public :
	//----- Set Enable & Disable Control -----//
	void SetEnable(bool bEnable) { m_bEnable = bEnable; Invalidate(); }
	
	//----- Set & Get Text -----//
	void SetText(CString strText) { SetWindowText(strText); Invalidate(); }
	CString GetText();
	int		GetTextInt();

	//----- Set Offset -----//
	void SetOffsetText	(int nX, int nY) { m_nOffsetTextX = nX; m_nOffsetTextY = nY; Invalidate(); }

	//----- Set Size -----//
	void SetSizeText	(float fSize) { m_fSizeText		= fSize; }
	void SetSizeBorder	(float fSize) { m_fSizeBorder	= fSize; }
	void SetSizeImage	(int nLeft, int nTop, int nWidth, int nHeight) { m_rcImage = Rect(nLeft, nTop, nWidth, nHeight); Invalidate(); }

	//----- Set Color -----//
	void SetColorBkg	(int nA, int nR, int nG, int nB) { m_clrBkg		= Color(nA, nR, nG, nB); Invalidate(); }
	void SetColorBorder	(int nA, int nR, int nG, int nB) { m_clrBorder	= Color(nA, nR, nG, nB); Invalidate(); }
	void SetColorText	(int nA, int nR, int nG, int nB) { m_clrText	= Color(nA, nR, nG, nB); Invalidate(); }

	//----- Set Text Alignment -----//
	void SetAlignTextLT() { m_nTextAlign1 = 0; m_nTextAlign2 = 0; Invalidate(); }
	void SetAlignTextCT() { m_nTextAlign1 = 1; m_nTextAlign2 = 0; Invalidate(); }				   
	void SetAlignTextRT() { m_nTextAlign1 = 2; m_nTextAlign2 = 0; Invalidate(); }
	void SetAlignTextLM() { m_nTextAlign1 = 0; m_nTextAlign2 = 1; Invalidate(); }
	void SetAlignTextCM() { m_nTextAlign1 = 1; m_nTextAlign2 = 1; Invalidate(); }
	void SetAlignTextRM() { m_nTextAlign1 = 2; m_nTextAlign2 = 1; Invalidate(); }
	void SetAlignTextLB() { m_nTextAlign1 = 0; m_nTextAlign2 = 2; Invalidate(); }
	void SetAlignTextCB() { m_nTextAlign1 = 1; m_nTextAlign2 = 2; Invalidate(); }
	void SetAlignTextRB() { m_nTextAlign1 = 2; m_nTextAlign2 = 2; Invalidate(); }

	//----- Set Image -----//
	bool LoadImageFromFile(CString strPath);
	bool LoadImageFromResource(UINT ID, bool bPNG);

private :
	bool	m_bEnable;
	int		m_nOffsetTextX;
	int		m_nOffsetTextY;
	int		m_nTextAlign1;
	int		m_nTextAlign2;
	float	m_fSizeText;
	float	m_fSizeBorder;
	Color	m_clrBkg;
	Color	m_clrText;
	Color	m_clrBorder;
	Rect	m_rcImage;
	Bitmap* m_pBmpImage;

private :
	void DrawBorder(Graphics *pG);
	void DrawBkg(Graphics *pG);
	void DrawImage(Graphics *pG);
	void DrawText(Graphics *pG);
	bool IsFileExist(CString strPath);
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	virtual void PreSubclassWindow();
};


