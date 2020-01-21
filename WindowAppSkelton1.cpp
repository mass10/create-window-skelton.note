// WindowAppSkelton1.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "framework.h"
#include "WindowAppSkelton1.h"

// グローバル変数
Application Application::_instance;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: ここにコードを挿入してください。
    Application& app = Application::GetInstance();
    app.Run(hInstance, nCmdShow);
}

int Application::Run(HINSTANCE hInstance, int nCmdShow)
{
    this->MyRegisterClass(hInstance);

    // アプリケーション初期化の実行:
    if (!this->InitInstance(nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWAPPSKELTON1));

    MSG msg;

    // メイン メッセージ ループ:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

Application::Application()
{
    this->_hInst = NULL;
    this->_szTitle[0] = 0x00;
    this->_szWindowClass[0] = 0x00;
}

ATOM Application::MyRegisterClass(HINSTANCE hInstance)
{
    this->_hInst = hInstance;

    // グローバル文字列を初期化する
    LoadStringW(this->_hInst, IDS_APP_TITLE, this->_szTitle, MAX_LOADSTRING);
    LoadStringW(this->_hInst, IDC_WINDOWAPPSKELTON1, this->_szWindowClass, MAX_LOADSTRING);

    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = &Application::WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = this->_hInst;
    wcex.hIcon = LoadIcon(this->_hInst, MAKEINTRESOURCE(IDI_WINDOWAPPSKELTON1));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WINDOWAPPSKELTON1);
    wcex.lpszClassName = _szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL Application::InitInstance(int nCmdShow)
{
    HWND hWnd = CreateWindowW(this->_szWindowClass, this->_szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, this->_hInst, nullptr);
    if (!hWnd)
    {
        return FALSE;
    }
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    return TRUE;
}

LRESULT CALLBACK Application::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    Application& app = Application::GetInstance();
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // 選択されたメニューの解析:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(app._hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, &Application::About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        // TODO: HDC を使用する描画コードをここに追加してください...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

Application& Application::GetInstance()
{
    return _instance;
}

// バージョン情報ボックスのメッセージ ハンドラーです。
INT_PTR CALLBACK Application::About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
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
        break;
    }
    return (INT_PTR)FALSE;
}

Application::~Application()
{
}
