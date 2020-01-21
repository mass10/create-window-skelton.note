#pragma once

#include "resource.h"

#define MAX_LOADSTRING 100

class Application {
public:
    Application();
    ~Application();
    ATOM MyRegisterClass(HINSTANCE hInstance);
    BOOL InitInstance(int nCmdShow);
    static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
    static INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
    static Application& GetInstance();
private:
    HINSTANCE _hInst;                                // 現在のインターフェイス
    WCHAR _szTitle[MAX_LOADSTRING];                  // タイトル バーのテキスト
    WCHAR _szWindowClass[MAX_LOADSTRING];            // メイン ウィンドウ クラス名
    static Application _instance;
};
