/*Copyright 2015 Huawei Technologies Co., Ltd. All rights reserved.
eSDK is licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
		http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.*/

// DispatchParamDlg.cpp : implementation file
//

#include "stdafx.h"
#include "eLTE_Video.h"
#include "DispatchParamDlg.h"
#include "afxdialogex.h"


// DispatchParamDlg dialog

IMPLEMENT_DYNAMIC(DispatchParamDlg, CDialogEx)

DispatchParamDlg::DispatchParamDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DispatchParamDlg::IDD, pParent)
	, m_pDispatchParamInfo(NULL)
{

}

DispatchParamDlg::~DispatchParamDlg()
{
}

void DispatchParamDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(DispatchParamDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &DispatchParamDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &DispatchParamDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// DispatchParamDlg message handlers


void DispatchParamDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CComboBox* pCComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_FORMAT);
	int iSel = pCComboBox->GetCurSel();
	if (0 == iSel)
	{
		m_pDispatchParamInfo->strFormat = _T("D1");
	}
	else if (1 == iSel)
	{
		m_pDispatchParamInfo->strFormat = _T("CIF");
	}
	else if (2 == iSel)
	{
		m_pDispatchParamInfo->strFormat = _T("QCIF");
	}
	else if (3 == iSel)
	{
		m_pDispatchParamInfo->strFormat = _T("720P");
	}
	else if (4 == iSel)
	{
		m_pDispatchParamInfo->strFormat = _T("1080P");
	}
	CString strDstViewers;
	((CEdit*)GetDlgItem(IDC_EDIT_DSTVIEWER))->GetWindowText(strDstViewers);

	int pos = strDstViewers.Find(_T(";"));
	while (pos > 0)
	{
		CString strTemp = strDstViewers.Left(pos);
		m_pDispatchParamInfo->strDstViewerList.push_back(strTemp);
		int length = strDstViewers.Delete(0,pos + 1);
		strDstViewers = strDstViewers.Right(length); 
		pos = strDstViewers.Find(_T(";"));
	}
	m_pDispatchParamInfo->strDstViewerList.push_back(strDstViewers);
	
	CDialogEx::OnOK();
}


void DispatchParamDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


BOOL DispatchParamDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CComboBox* pCComboBox = (CComboBox*)GetDlgItem(IDC_COMBO_FORMAT);
	if (NULL != pCComboBox)
	{
		pCComboBox->InsertString(0, _T("1080P"));
		pCComboBox->InsertString(0, _T("720P"));
		pCComboBox->InsertString(0, _T("QCIF"));
		pCComboBox->InsertString(0, _T("CIF"));
		pCComboBox->InsertString(0, _T("D1"));
		pCComboBox->SetCurSel(0);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
