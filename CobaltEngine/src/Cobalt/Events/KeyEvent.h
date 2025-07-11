#pragma once

#include "Cobalt/Events/Event.h"

namespace Cobalt
{
    class KeyEvent : public Event
    {
    public:
        i32 GetKeyCode() const { return m_KeyCode; }

        EVENT_CLASS_CATEGORY(EventCategory::EventCategoryKeyboard | EventCategory::EventCategoryInput)

    protected:
        explicit KeyEvent(const i32 keycode)
            : m_KeyCode(keycode)
        {
        }

        i32 m_KeyCode;
    };

    class KeyPressedEvent final : public KeyEvent
    {
    public:
        explicit KeyPressedEvent(const i32 keycode, const i32 repeatCount)
            : KeyEvent(keycode), m_RepeatCount(repeatCount)
        {
        }

        i32 GetRepeatCount() const { return m_RepeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressed: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::KeyPressed)

    private:
        i32 m_RepeatCount;
    };

    class KeyReleasedEvent final : public KeyEvent
    {
    public:
        explicit KeyReleasedEvent(const i32 keycode)
            : KeyEvent(keycode)
        {
        }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleased: " << m_KeyCode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(EventType::KeyReleased)
    };
}
