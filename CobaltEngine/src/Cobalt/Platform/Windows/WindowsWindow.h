#pragma once

#include "Cobalt/Core/Window.h"
#include <windows.h>

namespace Cobalt
{
    class WindowsWindow final : public Window
    {
    public:
        WindowsWindow(const WindowProps &props);
        virtual ~WindowsWindow();

        void OnUpdate() override;

        unsigned int GetWidth() const override { return m_Data.Width; }
        unsigned int GetHeight() const override { return m_Data.Height; }

    private:
        void Init(const WindowProps &props);
        void Shutdown();

    private:
        HWND m_WindowHandle = nullptr;
        HINSTANCE m_Instance = nullptr;

        struct WindowData
        {
            std::string Title;
            unsigned int Width;
            unsigned int Height;
            bool Running = true;
        };

        WindowData m_Data;
    };
}
