
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
CFont g_editFont;


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, year1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, year1);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication1Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication1Dlg::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT5, &CMFCApplication1Dlg::OnEnChangeEdit5)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnEnChangeEdit1()
{

}


void CMFCApplication1Dlg::OnEnChangeEdit2()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnEnChangeEdit3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMFCApplication1Dlg::OnBnClickedButton1()
{
	int a, b, c;
	a = 0;
	b = 0;
	c = 0;

	a = GetDlgItemInt(IDC_EDIT1);
	b = GetDlgItemInt(IDC_EDIT2);
	c = GetDlgItemInt(IDC_EDIT3);

	Day dayday(a, b, c);

	
	CWnd::SetDlgItemText(IDC_EDIT5, dayday.showday());

	return;
}


void CMFCApplication1Dlg::OnEnChangeEdit4()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


LPCTSTR Day::showday() {

	return day1;
}

Day::Day(int y, int m, int d) {
	int m123[12];
	std::copy_n(mm, 12, m123);
	int a = 0;
	long b = 0;


	year = y;
	month = m;
	date = d;

	bool yun = (!(year % 4) && year % 100) || !(year % 400);

	bool yyy = year != 0;
	bool mmm = 1 <= month && 12 >= month;
	bool ddd = 1 <= date && 31 >= date;
	bool mmm123 = month == 4 || month == 6 || month == 9 || month == 11;


	if (month == 2) {
		ddd = 1 <= date && 28 >= date;
		if (yun == 1) {
			ddd = 1 <= date && 29 >= date;
		}
	}
	else if (mmm123 != 0) {
		ddd = 1 <= date && 30 >= date;
	}

	bool ymd = yyy && mmm && ddd;

	if (ymd == 0) {

		if (yyy == 0) {
			day1 = L"정확한 년도를 입력해 주세요";
		}
		if (mmm == 0) {
			day1 = L"정확한 월을 입력해 주세요";
		}
		if (ddd == 0) {
			day1 = L"정확한 날짜를 입력해 주세요";
		}
	}
	else {
		if (year >= 2023) {
			int i;
			bool yunfor = 0;
			for (i = 2023; i < year; i++) {
				yunfor = !(i % 4) && i % 100 || !(i % 400);
				if (yunfor == 1) {
					m123[1] = 29;
					for (int j = 0; j < 12; j++) {
						b += m123[j];
					}
				}
				else {
					m123[1] = 28;
					for (int j = 0; j < 12; j++) {
						b += m123[j];
					}
				}
			}
			if (yun == 1) {
				m123[1] = 29;
			}
			else {
				m123[1] = 28;
			}
			for (int j = 0; j < month - 1; j++) {
				b += m123[j];
			}
			b += date;

		}



		else if (year <= 2022) {
			int i;
			bool yunfor = 0;
			for (i = 2022; i > year; i--) {
				yunfor = !(i % 4) && i % 100 || !(i % 400);
				if (yunfor == 1) {
					m123[1] = 29;
					for (int j = 0; j < 12; j++) {
						b += m123[j];
					}
				}
				else {
					m123[1] = 28;
					for (int j = 0; j < 12; j++) {
						b += m123[j];
					}


				}
			}
			if (yun == 1) {
				m123[1] = 29;
			}
			else {
				m123[1] = 28;
			}
			for (int j = 11; j > month - 1; j--) {
				b += m123[j];
			}
			b += m123[month - 1] - date;

		}

		a = b % 7;

		if (year >= 2023) {
			switch (a) {
			case 0:
				day1 = L"토요일";
				break;
			case 1:
				day1 = L"일요일";
				break;
			case 2:
				day1 = L"월요일";
				break;
			case 3:
				day1 = L"화요일";
				break;
			case 4:
				day1 = L"수요일";
				break;
			case 5:
				day1 = L"목요일";
				break;
			case 6:
				day1 = L"금요일";
				break;



			}
		}

		else if (year <= 2022) {
			switch (a) {
			case 0:
				day1 = L"토요일";
				break;
			case 1:
				day1 = L"금요일";
				break;
			case 2:
				day1 = L"목요일";
				break;
			case 3:
				day1 = L"수요일";
				break;
			case 4:
				day1 = L"화요일";
				break;
			case 5:
				day1 = L"월요일";
				break;
			case 6:
				day1 = L"일요일";
				break;



			}
		}

	}
}





Day::Day() {

}

Day::~Day() {

}

void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnOK();
}


void CMFCApplication1Dlg::OnEnChangeEdit5()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
