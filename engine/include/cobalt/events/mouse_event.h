#pragma once

#include "cobalt/core/event.h"

namespace cobalt
{
    class mouse_moved_event final : public event
    {
    public:
        mouse_moved_event(float x, float y)
            : m_mouse_x(x), m_mouse_y(y)
        {
        }

        inline float get_x() const { return m_mouse_x; }
        inline float get_y() const { return m_mouse_y; }

        std::string to_string() const override
        {
            std::stringstream ss;
            ss << get_name() << ": " << m_mouse_x << ", " << m_mouse_y;
            return ss.str();
        }

        CB_EVENT_CLASS_TYPE(mouse_moved)
        CB_EVENT_CLASS_CATEGORY(event_category_mouse | event_category_input)

    private:
        float m_mouse_x;
        float m_mouse_y;
    };

    class mouse_button_event : public event
    {
    public:
        inline int get_mouse_button() const { return m_button; }

        CB_EVENT_CLASS_CATEGORY(event_category_mouse | event_category_input | event_category_mouse_button)

    protected:
        mouse_button_event(int button)
            : m_button(button)
        {
        }

        int m_button;
    };

    class mouse_button_pressed_event final : public mouse_button_event
    {
    public:
        mouse_button_pressed_event(int button)
            : mouse_button_event(button)
        {
        }

        std::string to_string() const override
        {
            std::stringstream ss;
            ss << get_name() << ": " << m_button;
            return ss.str();
        }

        CB_EVENT_CLASS_TYPE(mouse_button_pressed)
    };

    class mouse_button_release_event final : public mouse_button_event
    {
    public:
        mouse_button_release_event(int button)
            : mouse_button_event(button)
        {
        }

        std::string to_string() const override
        {
            std::stringstream ss;
            ss << get_name() << ": " << m_button;
            return ss.str();
        }

        CB_EVENT_CLASS_TYPE(mouse_button_released)
    };
}
