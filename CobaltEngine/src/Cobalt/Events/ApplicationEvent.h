#pragma once

#include "Cobalt/Events/Event.h"

namespace Cobalt
{
    class WindowCloseEvent final : public Event
    {
    public:
        WindowCloseEvent() = default;

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class WindowResizeEvent final : public Event
    {
    public:
        WindowResizeEvent(const u32 width, const u32 height)
            : m_Width(width), m_Height(height)
        {}

        u32 GetWidth() const { return m_Width; }
        u32 GetHeight() const { return m_Height; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResize: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)

    private:
        u32 m_Width;
        u32 m_Height;
    };
}