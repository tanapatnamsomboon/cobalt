#include "Cobalt/Platform/Windows/WindowsInput.h"

#include "Cobalt/Core/Application.h"
#include <windows.h>

namespace Cobalt
{
    WindowsInput::WindowsInput()
    {
    }

    bool WindowsInput::IsKeyPressed(KeyCode key) const
    {
        return GetAsyncKeyState(static_cast<int>(key)) & 0x8000;
    }

    bool WindowsInput::IsMouseButtonPressed(MouseCode button) const
    {
        return GetAsyncKeyState(VK_LBUTTON + static_cast<int>(button)) & 0x8000;
    }

    float WindowsInput::GetMouseX() const
    {
        return GetMousePosition().first;
    }

    float WindowsInput::GetMouseY() const
    {
        return GetMousePosition().second;
    }

    std::pair<float, float> WindowsInput::GetMousePosition() const
    {
        if (auto window = static_cast<HWND>(Application::Get().GetWindow().GetNativeWindow()))
        {
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(window, &p);
            return {static_cast<float>(p.x), static_cast<float>(p.y)};
        }

        return {0.0f, 0.0f};
    }
}
