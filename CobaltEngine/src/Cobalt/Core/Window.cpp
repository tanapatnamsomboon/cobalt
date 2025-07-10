#include "Window.h"

#include "Cobalt/Platform/Windows/WindowsWindow.h"

namespace Cobalt
{
    std::unique_ptr<Window> Window::Create(const WindowProps &props)
    {
        return std::make_unique<WindowsWindow>(props);
    }

}