#include  "WindowsWindow.h"

#include "Cobalt/Events/ApplicationEvent.h"

namespace Cobalt
{
    LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        if (uMsg == WM_NCCREATE)
        {
            const auto create = reinterpret_cast<LPCREATESTRUCT>(lParam);
            SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(create->lpCreateParams));
        }

        if (const auto* window = reinterpret_cast<WindowsWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA)))
        {
            switch (uMsg)
            {
                case WM_CLOSE:
                {
                    WindowCloseEvent event;
                    window->m_Data.EventCallback(event);
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
            m_Instance, this
        );

        ShowWindow(m_WindowHandle, SW_SHOW);
    }

    void WindowsWindow::Shutdown()
    {
        DestroyWindow(m_WindowHandle);
    }
}
