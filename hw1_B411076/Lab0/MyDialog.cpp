// MyDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Lab0.h"
#include "MyDialog.h"
#include "afxdialogex.h"


// CMyDialog dialog

IMPLEMENT_DYNAMIC(CMyDialog, CDialogEx)

CMyDialog::CMyDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyDialog::IDD, pParent)
	, m_number(0)
{

}

CMyDialog::~CMyDialog()
{
}

void CMyDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Number, m_number);
	DDV_MinMaxInt(pDX, m_number, 0, 255);
}


BEGIN_MESSAGE_MAP(CMyDialog, CDialogEx)
END_MESSAGE_MAP()


// CMyDialog message handlers
