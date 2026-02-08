#define MAX_LOADSTRING 100

#include "framework.h"
#include "HelloWorld.h"

HINSTANCE hInst;
BOOL                InitInstance(HINSTANCE, int);
INT_PTR CALLBACK    HelloWorldDlg(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    return 0;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    INT_PTR nResponse;
    INITCOMMONCONTROLSEX InitCtrls;
    hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной
    InitCtrls.dwSize = sizeof(InitCtrls);
    // Выберите этот параметр для включения всех общих классов управления, которые необходимо использовать
    // в вашем приложении.
    InitCtrls.dwICC = ICC_WIN95_CLASSES;
    InitCommonControlsEx(&InitCtrls);
    nResponse = DialogBox(hInst, MAKEINTRESOURCE(IDD_HELLOWORLD_DIALOG), NULL, HelloWorldDlg);
    if (nResponse == IDOK)
    {

    }
    else if (nResponse == IDCANCEL)
    {

    }
    else if (nResponse == -1)
        return FALSE;
   return TRUE;
}


INT_PTR CALLBACK HelloWorldDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDC_BUTTON1)
        {
            MessageBox(hDlg, _T("Hello,World!!!"), _T("Hello"), 0);
        }
        if (LOWORD(wParam) == IDC_BUTTON2)
        {
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}