
// ApplicationDlg.h : header file
//

#pragma once

#include <GdiPlus.h>

class CStaticImage : public CStatic
{
public:
	// Overridables (for owner draw only)
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;
};

class CStaticHistogram : public CStatic
{
public:
	// Overridables (for owner draw only)
	void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;
};


// CApplicationDlg dialog
class CApplicationDlg : public CDialogEx
{
	// Construction
public:
	enum
	{
		WM_DRAW_IMAGE = (WM_USER + 1),
		WM_DRAW_HISTOGRAM
	};

	CApplicationDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_APPLICATION_DIALOG };
#endif

protected:
	void DoDataExchange(CDataExchange* pDX) override;	// DDX/DDV support

	void OnOK() override {}
	void OnCancel() override {}


	// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	BOOL OnInitDialog() override;
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	CString path_name;
	DECLARE_MESSAGE_MAP()
	CImage *image = nullptr;
	BITMAP bitmap;
	float CApplicationDlg::ScaleImage(CRect r, BITMAP bi);
	int histogramR[255] = { 0 };
	int histogramG[255] = { 0 };
	int histogramB[255] = { 0 };
	bool checkRed = false;
	bool checkGreen = false;
	bool checkBlue = false;
	int tmp_histogram[256] = { 0 };
	int m_hR[256] = { 0 };
	int m_hG[256] = { 0 };
	int m_hB[256] = { 0 };
	int max_hist = 0;
	int min_hist = 0;
	bool test = false;
	BYTE *byte_ptr;
	int pitch;
	int width, height;
	

public:
	afx_msg void OnFileOpen();
	afx_msg void OnUpdateFileOpen(CCmdUI *pCmdUI);
	afx_msg void OnFileClose();
	afx_msg void OnUpdateFileClose(CCmdUI *pCmdUI);
	afx_msg void OnClose();
	afx_msg LRESULT OnDrawImage(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnDrawHistogram(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	void Histogram();
	void KresliHistogram(CRect rect, CDC * pDC, int *pole, COLORREF color, float scale);
	afx_msg void OnHistogramRed();
	afx_msg void OnHistogramGreen();
	afx_msg void OnHistogramBlue();
	afx_msg void OnUpdateHistogramRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHistogramGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdateHistogramBlue(CCmdUI *pCmdUI);
	afx_msg void OnTimer(UINT_PTR id);

protected:
	CStaticImage m_ctrlImage;
	CStaticHistogram m_ctrlHistogram;
	CPoint m_ptImage;
	CPoint m_ptHistogram;

public:
	afx_msg void OnStnClickedImage();
};
