#include "Window.h"

#include "Cobalt/Platform/Windows/WindowsWindow.h"

namespace Cobalt
{
    Scope<Window> Window::Create(const WindowProps &props)
    {
        return CreateScope<WindowsWindow>(props);
    }

}