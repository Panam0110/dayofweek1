
// MFCApplication1Dlg.h: 헤더 파일
//

#pragma once
#include <iostream>
// CMFCApplication1Dlg 대화 상자
class CMFCApplication1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	int yy1, mm1, dd1 = 0;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	int year1;
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit5();
};

class Day {
private:
	int year;
	int month;
	int date;
	int mm[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	LPCTSTR day1;
public:
	LPCTSTR showday();
	Day(int, int, int);
	Day();
	~Day();


};