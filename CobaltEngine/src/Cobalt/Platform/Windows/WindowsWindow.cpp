#include  "WindowsWindow.h"

#include "Cobalt/Events/ApplicationEvent.h"

namespace Cobalt
{
    static WindowsWindow *s_Instance = nullptr;

    LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);

    WindowsWindow::WindowsWindow(const WindowProps &props)
    {
        Init(props);
    }

    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::OnUpdate()
    {
        MSG msg = {};
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                m_Data.Running = false;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    void WindowsWindow::SetEventCallback(const EventCallbackFn &callback)
    {
        m_Data.EventCallback = callback;
    }

    void WindowsWindow::Init(const WindowProps &props)
    {
        s_Instance = this;

        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        m_Instance = GetModuleHandle(nullptr);

        WNDCLASS wc = {};
        wc.lpfnWndProc = WindowProc;
        wc.hInstance = m_Instance;
        wc.lpszClassName = L"CobaltWindowClass";

        RegisterClass(&wc);

        m_WindowHandle = CreateWindowEx(
            0, L"CobaltWindowClass", std::wstring(m_Data.Title.begin(), m_Data.Title.end()).c_str(),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            static_cast<int>(m_Data.Width), static_cast<int>(m_Data.Height),
            nullptr, nullptr,
            m_Instance, nullptr
        );

        ShowWindow(m_WindowHandle, SW_SHOW);
    }

    void WindowsWindow::Shutdown()
    {
        DestroyWindow(m_WindowHandle);
    }

    LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        if (s_Instance)
        {
            switch (uMsg)
            {
                case WM_CLOSE:
                {
                    WindowCloseEvent event;
                    s_Instance->m_Data.EventCallback(event);
                    return 0;
                }
                default:
                {
                    return DefWindowProc(hWnd, uMsg, wParam, lParam);
                }
            }
        }

        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
}
