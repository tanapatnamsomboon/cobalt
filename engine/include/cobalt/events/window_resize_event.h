#pragma once

#include "cobalt/core/event.h"

namespace cobalt
{
    class window_resize_event final : public event
    {
    public:
        window_resize_event(uint32_t width, uint32_t height)
            : m_width(width), m_height(height)
        {
        }

        inline uint32_t get_width() const { return m_width; }
        inline uint32_t get_height() const { return m_height; }

        std::string to_string() const override
        {
            std::stringstream ss;
            ss << get_name() << ": " << m_width << ", " << m_height;
            return ss.str();
        }

        CB_EVENT_CLASS_TYPE(window_resize)
        CB_EVENT_CLASS_CATEGORY(event_category_applicaiton)

    private:
        uint32_t m_width;
        uint32_t m_height;
    };
}
