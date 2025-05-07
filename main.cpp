#define UNICODE
#define _UNICODE
#include <windows.h>
#include <string>

// 常量定义
#define ID_BUTTON_SWITCH 101

// 全局变量
bool g_isChineseLanguage = false;  // 默认使用英文

// 窗口过程函数
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// 更新窗口标题和内容文本
void UpdateWindowText(HWND hwnd) {
    if (g_isChineseLanguage) {
        // 设置中文标题
        SetWindowText(hwnd, L"\u4F60\u597D\u4E16\u754C\u5E94\u7528");  // "你好世界应用"
        
        // 更新按钮文本
        SetDlgItemText(hwnd, ID_BUTTON_SWITCH, L"\u5207\u6362\u82F1\u6587");  // "切换英文"
    } else {
        // 设置英文标题
        SetWindowText(hwnd, L"Hello World Application");
        
        // 更新按钮文本
        SetDlgItemText(hwnd, ID_BUTTON_SWITCH, L"Switch to Chinese");
    }
    
    // 强制重绘窗口，更新文本显示
    InvalidateRect(hwnd, NULL, TRUE);
}

// WinMain - 应用程序入口点
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow) {
    // 注册窗口类
    const wchar_t CLASS_NAME[] = L"HelloWorldWindowClass";
    
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);
    
    RegisterClass(&wc);
    
    // 创建窗口
    HWND hwnd = CreateWindowEx(
        0,                          // 扩展样式
        CLASS_NAME,                 // 窗口类名
        L"Hello World Application",  // 窗口标题(默认英文)
        WS_OVERLAPPEDWINDOW,        // 窗口样式
        
        // 大小和位置
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
        
        NULL,       // 父窗口
        NULL,       // 菜单
        hInstance,  // 实例句柄
        NULL        // 额外数据
    );
    
    if (hwnd == NULL) {
        return 0;
    }
    
    // 创建语言切换按钮
    CreateWindow(
        L"BUTTON",                  // 按钮类
        L"Switch to Chinese",       // 按钮文本(默认显示"切换中文")
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // 样式
        350,                        // x位置
        450,                        // y位置
        200,                        // 宽度
        40,                         // 高度
        hwnd,                       // 父窗口
        (HMENU)ID_BUTTON_SWITCH,    // 按钮ID
        hInstance,                  // 应用实例
        NULL                        // 附加数据
    );
    
    // 显示窗口
    ShowWindow(hwnd, nCmdShow);
    
    // 消息循环
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_COMMAND: {
        // 处理按钮点击事件
        if (LOWORD(wParam) == ID_BUTTON_SWITCH) {
            // 切换语言状态
            g_isChineseLanguage = !g_isChineseLanguage;
            
            // 更新窗口文本
            UpdateWindowText(hwnd);
            return 0;
        }
        break;
    }
    
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        
        // 获取客户区域大小
        RECT rect;
        GetClientRect(hwnd, &rect);
        
        // 根据当前语言选择文本
        const wchar_t* text;
        if (g_isChineseLanguage) {
            text = L"\u4F60\u597D\uFF0C\u4E16\u754C\uFF01";  // "你好，世界！"
        } else {
            text = L"Hello, World!";
        }
        
        // 设置文本格式和颜色
        SetTextColor(hdc, RGB(0, 0, 128));  // 深蓝色文本
        SetBkMode(hdc, TRANSPARENT);        // 透明背景
        
        // 选择字体
        HFONT hFont = CreateFont(
            48,                     // 高度
            0,                      // 宽度
            0,                      // 角度
            0,                      // 倾斜角度
            FW_BOLD,                // 粗体
            FALSE,                  // 斜体
            FALSE,                  // 下划线
            FALSE,                  // 删除线
            DEFAULT_CHARSET,        // 字符集
            OUT_OUTLINE_PRECIS,     // 输出精度
            CLIP_DEFAULT_PRECIS,    // 裁剪精度
            CLEARTYPE_QUALITY,      // 质量
            DEFAULT_PITCH | FF_SWISS, // 间距和字体族
            L"Arial"                // 字体名称
        );
        
        HFONT hOldFont = (HFONT)SelectObject(hdc, hFont);
        
        // 在窗口中间显示文本
        SetTextAlign(hdc, TA_CENTER | TA_BASELINE);
        TextOut(hdc, rect.right / 2, rect.bottom / 2, text, (int)wcslen(text));
        
        // 清理资源
        SelectObject(hdc, hOldFont);
        DeleteObject(hFont);
        
        EndPaint(hwnd, &ps);
        return 0;
    }
    
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    
    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;
    }
    
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
} 