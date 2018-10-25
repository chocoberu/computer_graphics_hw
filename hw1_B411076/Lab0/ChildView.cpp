// B411076 민재홍
// ChildView.cpp : CChildView 클래스의 구현
//

#include "stdafx.h"
#include "Lab0.h"
#include "ChildView.h"
#include "MyDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_cnt = 0;
	m_dia_num = 0;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_MFC_DIALOGBOX, &CChildView::OnMfcDialogbox)
	ON_COMMAND(ID_MFC_WRITE, &CChildView::OnMfcWrite)
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.

}



void CChildView::OnMfcDialogbox()
{
	// TODO: Add your command handler code here

	CMyDialog dlg;
	CString str;
	dlg.m_number = m_dia_num;
	int res = dlg.DoModal();

	if (res == IDOK)
	{
		m_dia_num = dlg.m_number;
		str.Format(_T("Input number is %d\n"), m_dia_num);
		MessageBox(str);
	}
	else
		MessageBox(_T("Cancle"));

}


void CChildView::OnMfcWrite()
{
	// TODO: Add your command handler code here
	CString str;
	str.Format(_T("Write menu Clicked! %d times\n"),++m_cnt);
	//str += _T("next line");
	MessageBox(str);
}
