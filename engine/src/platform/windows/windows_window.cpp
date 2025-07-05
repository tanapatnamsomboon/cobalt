#include "pch.h"

#include "cobalt/platform/windows/windows_window.h"

#include "cobalt/events/key_event.h"
#include "cobalt/events/mouse_event.h"
#include "cobalt/events/window_close_event.h"
#include "cobalt/events/window_resize_event.h"
#include <windowsx.h>

namespace cobalt
{
    static LRESULT CALLBACK window_proc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
    {
        windows_window *window = reinterpret_cast<windows_window *>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
        switch (msg)
        {
            case WM_KEYDOWN:
            {
                int keycode = static_cast<int>(wparam);
                int repeat = LOWORD(lparam);
                key_pressed_event event(keycode, repeat);
                if (window && window->m_event_callback)
                    window->m_event_callback(event);
                return 0;
            }
            case WM_KEYUP:
            {
                int keycode = static_cast<int>(wparam);
                key_released_event event(keycode);
                if (window && window->m_event_callback)
                    window->m_event_callback(event);
                return 0;
            }
            case WM_MOUSEMOVE:
            {
                auto x = static_cast<float>(GET_X_LPARAM(lparam));
                auto y = static_cast<float>(GET_Y_LPARAM(lparam));
                mouse_moved_event event(x, y);
                if (window && window->m_event_callback)
                    window->m_event_callback(event);
                return 0;
            }
            case WM_LBUTTONDOWN:
            {
                mouse_button_pressed_event event(0);
                if (window && window->m_event_callback) window->m_event_callback(event);
                return 0;
            }
            case WM_LBUTTONUP:
            {
                mouse_button_release_event event(0);
                if (window && window->m_event_callback) window->m_event_callback(event);
                return 0;
            }
            case WM_RBUTTONDOWN:
            {
                mouse_button_pressed_event event(1);
                if (window && window->m_event_callback) window->m_event_callback(event);
                return 0;
            }
            case WM_RBUTTONUP:
            {
                mouse_button_release_event event(1);
                if (window && window->m_event_callback) window->m_event_callback(event);
                return 0;
            }
            case WM_MBUTTONDOWN:
            {
                mouse_button_pressed_event event(2);
                if (window && window->m_event_callback) window->m_event_callback(event);
                return 0;
            }
            case WM_MBUTTONUP:
            {
                mouse_button_release_event event(2);
                if (window && window->m_event_callback) window->m_event_callback(event);
                return 0;
            }
            case WM_SIZE:
            {
                uint32_t width = LOWORD(lparam);
                uint32_t height = HIWORD(lparam);
                window_resize_event event(width, height);
                if (window && window->m_event_callback)
                    window->m_event_callback(event);
                return 0;
            }
            case WM_CLOSE:
            {
                window_close_event event;
                if (window && window->m_event_callback)
                    window->m_event_callback(event);
                return 0;
            }
        }

        return DefWindowProc(hwnd, msg, wparam, lparam);
    }

    windows_window::windows_window(const window_props &props)
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

    void windows_window::set_event_callback(const event_callback_fn &callback)
    {
        m_event_callback = callback;
    }


    void windows_window::init(const window_props &props)
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

        SetWindowLongPtr(m_handle, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

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
