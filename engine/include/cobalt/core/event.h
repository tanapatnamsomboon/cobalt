#pragma once

#include "cobalt/core/base.h"
#include "cobalt/events/event_defs.h"

namespace cobalt
{
    class event
    {
    public:
        virtual ~event() = default;

        virtual event_type get_event_type() const = 0;

        virtual const char *get_name() const = 0;

        virtual int get_category_flags() const = 0;

        bool is_in_category(event_category category) const
        {
            return get_category_flags() & category;
        }

        std::string to_string() const
        {
            return get_name();
        }
    };

    class event_dispatcher
    {
    public:
        event_dispatcher(event &e)
            : m_event(e)
        {
        }

        template<typename T, typename F>
        bool dispatch(const F &func)
        {
            if (m_event.get_event_type() == T::get_static_type())
            {
                func(static_cast<T &>(m_event));
                return true;
            }
            return false;
        }

    private:
        event &m_event;
    };

    using event_callback_fn = std::function<void(event&)>;
}
