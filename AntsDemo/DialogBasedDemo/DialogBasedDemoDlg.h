
// DialogBasedDemoDlg.h : header file
//

#pragma once


// CDialogBasedDemoDlg dialog
class CDialogBasedDemoDlg : public CDialogEx
{
// Construction
public:
	CDialogBasedDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DIALOGBASEDDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	double _number1;
	double _number2;
	double _result;
	afx_msg void OnBnClickedButtonAdd();
};
