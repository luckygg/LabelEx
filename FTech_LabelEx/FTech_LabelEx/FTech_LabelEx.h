
// FTech_LabelEx.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFTech_LabelExApp:
// See FTech_LabelEx.cpp for the implementation of this class
//

class CFTech_LabelExApp : public CWinApp
{
public:
	CFTech_LabelExApp();

	ULONG_PTR m_gdiplusToken;
// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

extern CFTech_LabelExApp theApp;