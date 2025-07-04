#include "pch.h"

#include "cobalt/platform/windows/windows_window.h"

namespace cobalt
{
    static LRESULT CALLBACK window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        switch (msg)
        {
            case WM_CLOSE: PostQuitMessage(0);
                return 0;
            default:
                return DefWindowProc(hwnd, msg, wparam, lparam);
        }
    }

    windows_window::windows_window(const window_props& props)
    {
        init(props);
    }

    windows_window::~windows_window()
    {
        shutdown();
    }

    void windows_window::on_update()
    {
        MSG msg;
        while (::PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void windows_window::init(const window_props& props)
    {
        m_data.title = props.title;
        m_data.width = props.width;
        m_data.height = props.height;

        WNDCLASS wc = {};
        wc.lpfnWndProc = window_proc;
        wc.hInstance = GetModuleHandle(nullptr);
        wc.lpszClassName = L"CobaltWindowClass";

        RegisterClass(&wc);

        m_handle = CreateWindowEx(
            0, L"CobaltWindowClass", std::wstring(props.title.begin(), props.title.end()).c_str(),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT, props.width, props.height,
            nullptr, nullptr, GetModuleHandle(nullptr), nullptr
        );

        if (m_handle == nullptr)
        {
            CB_CORE_ERROR("Failed to create window.");
            return;
        }

        ShowWindow(m_handle, SW_SHOW);
        CB_CORE_INFO("Window Created: {} ({}x{})", props.title, props.width, props.height);
    }

    void windows_window::shutdown()
    {
        DestroyWindow(m_handle);
        CB_CORE_INFO("Window Destroyed");
    }


}
