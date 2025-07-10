#pragma once

#include <sstream>
#include <memory>
#include <utility>

namespace Cobalt
{
    struct WindowProps
    {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(std::string  title = "Cobalt Engine",
            unsigned int width = 1600,
            unsigned int height = 900)
            : Title(std::move(title)), Width(width), Height(height)
        {
        }
    };

    class Window
    {
    public:
        virtual ~Window() = default;

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        static std::unique_ptr<Window> Create(const WindowProps &props = WindowProps());
    };
}
