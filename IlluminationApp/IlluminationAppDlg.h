#pragma once
#include "DeviceContainer.h"
#include "IlluminationDevice.h"

class CIlluminationAppDlg : public CDialogEx
{
public:
    CIlluminationAppDlg(CWnd* pParent = nullptr);

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ILLUMINATIONAPP_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

protected:
    HICON m_hIcon;
    DeviceContainer m_container;
    CListBox m_deviceList;

    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedCreateBasicDevice();
    afx_msg void OnBnClickedCreateSmartDevice();
    afx_msg void OnBnClickedCallMethod();
    afx_msg void OnBnClickedDeleteDevice();
};
