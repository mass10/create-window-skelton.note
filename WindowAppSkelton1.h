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
    HINSTANCE _hInst;                                // ���݂̃C���^�[�t�F�C�X
    WCHAR _szTitle[MAX_LOADSTRING];                  // �^�C�g�� �o�[�̃e�L�X�g
    WCHAR _szWindowClass[MAX_LOADSTRING];            // ���C�� �E�B���h�E �N���X��
    static Application _instance;
};
