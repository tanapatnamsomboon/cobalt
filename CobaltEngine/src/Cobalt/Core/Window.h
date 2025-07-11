#pragma once

#include "Cobalt/Core/Base.h"
#include <sstream>
#include <functional>

namespace Cobalt
{
    struct WindowProps
    {
        std::string Title;
        u32 Width;
        u32 Height;

        WindowProps(std::string  title = "Cobalt Engine",
            u32 width = 1600,
            u32 height = 900)
            : Title(std::move(title)), Width(width), Height(height)
        {
        }
    };

    class Event;

    using EventCallbackFn = std::function<void(Event&)>;

    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void* GetNativeWindow() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;

        static Scope<Window> Create(const WindowProps &props = WindowProps());
    };
}
