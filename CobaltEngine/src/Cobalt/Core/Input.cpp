#include "Cobalt/Core/Input.h"

#include "Cobalt/Platform/Windows/WindowsInput.h"

namespace Cobalt
{
    Scope<Input> Input::Create()
    {
        return CreateScope<WindowsInput>();
    }
}