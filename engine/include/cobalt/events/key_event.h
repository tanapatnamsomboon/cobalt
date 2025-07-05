#pragma once

#include "cobalt/core/event.h"

namespace cobalt
{
    class key_event : public event
    {
    public:
        inline int get_keycode() const { return m_keycode; }

        CB_EVENT_CLASS_CATEGORY(event_category_keyboard | event_category_input)

    protected:
        key_event(int keycode)
            : m_keycode(keycode)
        {
        }

        int m_keycode;
    };

    class key_pressed_event final : public key_event
    {
    public:
        key_pressed_event(int keycode, int repeat_count)
            : key_event(keycode), m_repeat_count(repeat_count)
        {
        }

        inline int get_repeat_count() const { return m_repeat_count; }

        std::string to_string() const override
        {
            std::stringstream ss;
            ss << get_name() << ": " << m_keycode << " (" << m_repeat_count << " repeats)";
            return ss.str();
        }

        CB_EVENT_CLASS_TYPE(key_pressed)

    private:
        int m_repeat_count;
    };

    class key_released_event final : public key_event
    {
    public:
        key_released_event(int keycode)
            : key_event(keycode)
        {
        }

        std::string to_string() const override
        {
            std::stringstream ss;
            ss << get_name() << ": " << m_keycode;
            return ss.str();
        }

        CB_EVENT_CLASS_TYPE(key_released)
    };
};
