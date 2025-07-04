#include "pch.h"

#include "cobalt/core/window.h"
#include "cobalt/platform/windows/windows_window.h"

namespace cobalt
{
    std::unique_ptr<window> window::create(const window_props &props)
    {
#ifdef CB_PLATFORM_WINDOWS
        return std::make_unique<windows_window>(props);
#else
        CB_CORE_ASSERT(false, "Unknown platform!");
        return nullptr_t;
#endif
    }
}
