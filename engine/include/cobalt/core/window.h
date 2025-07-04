#pragma once

#include "cobalt/core/base.h"

namespace cobalt
{
    struct window_props
    {
        std::string title = "Cobalt Engine";
        uint32_t width = 1280;
        uint32_t height = 720;

        window_props() = default;

        window_props(const std::string &title, uint32_t width, uint32_t height)
            : title(title), width(width), height(height)
        {
        }
    };

    class window
    {
    public:
        virtual ~window() = default;

        virtual void on_update() = 0;
        virtual uint32_t get_width() const = 0;
        virtual uint32_t get_height() const = 0;

        static std::unique_ptr<window> create(const window_props& props);
    };
}
