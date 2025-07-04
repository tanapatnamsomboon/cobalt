#pragma once

#include "cobalt/core/base.h"
#include "cobalt/core/window.h"
#include <windows.h>

namespace cobalt
{
    class windows_window : public window
    {
    public:
        windows_window(const window_props &props);

        virtual ~windows_window() override;

        void on_update() override;

        uint32_t get_width() const override { return m_data.width; }
        uint32_t get_height() const override { return m_data.height; }

    private:
        void init(const window_props &props);

        void shutdown();

        HWND m_handle = nullptr;

        struct window_data
        {
            std::string title;
            uint32_t width, height;
        };

        window_data m_data;
    };
}
