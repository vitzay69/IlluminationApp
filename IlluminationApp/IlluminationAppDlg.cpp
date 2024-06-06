#include "pch.h"
#include "framework.h"
#include "IlluminationApp.h"
#include "IlluminationAppDlg.h"
#include "afxdialogex.h"
#include "SmartIlluminationDevice.h"
#include "BasicIlluminationDevice.h"
#include <atlconv.h>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

class CAboutDlg : public CDialogEx
{
public:
    CAboutDlg();

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_ABOUTBOX };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);

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

CIlluminationAppDlg::CIlluminationAppDlg(CWnd* pParent /*=nullptr*/)
    : CDialogEx(IDD_ILLUMINATIONAPP_DIALOG, pParent)
{
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIlluminationAppDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_DEVICE_LIST, m_deviceList);
}

BEGIN_MESSAGE_MAP(CIlluminationAppDlg, CDialogEx)
    ON_BN_CLICKED(IDC_CREATE_BASIC_DEVICE, &CIlluminationAppDlg::OnBnClickedCreateBasicDevice)
    ON_BN_CLICKED(IDC_CREATE_SMART_DEVICE, &CIlluminationAppDlg::OnBnClickedCreateSmartDevice)
    ON_BN_CLICKED(IDC_CALL_METHOD, &CIlluminationAppDlg::OnBnClickedCallMethod)
    ON_BN_CLICKED(IDC_DELETE_DEVICE, &CIlluminationAppDlg::OnBnClickedDeleteDevice)
END_MESSAGE_MAP()

BOOL CIlluminationAppDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    SetIcon(m_hIcon, TRUE);
    SetIcon(m_hIcon, FALSE);

    return TRUE;
}

void CIlluminationAppDlg::OnBnClickedCreateBasicDevice()
{
    m_container.addDevice(new BasicIlluminationDevice("Basic Light", 60, "Incandescent", 75, "Soft White"));
    m_deviceList.AddString(_T("Basic Light"));
}

void CIlluminationAppDlg::OnBnClickedCreateSmartDevice()
{
    m_container.addDevice(new SmartIlluminationDevice("Smart Light", 75, "LED", 90, "Warm White", true));
    m_deviceList.AddString(_T("Smart Light"));
}

void CIlluminationAppDlg::OnBnClickedCallMethod()
{
    int index = m_deviceList.GetCurSel();
    if (index != LB_ERR)
    {
        CString str;
        m_deviceList.GetText(index, str);
        CStringA deviceNameA(str);
        std::string deviceName(deviceNameA.GetString());
        IlluminationDevice* device = m_container.findDeviceByName(deviceName);
        if (device)
        {
            device->turnOn();
            AfxMessageBox(_T("Device turned on."));
        }
    }
}

void CIlluminationAppDlg::OnBnClickedDeleteDevice()
{
    int index = m_deviceList.GetCurSel();
    if (index != LB_ERR)
    {
        CString str;
        m_deviceList.GetText(index, str);
        std::string deviceName(CT2CA(str).m_psz);
        m_container.deleteDeviceByName(deviceName);
        m_deviceList.DeleteString(index);
    }
}
