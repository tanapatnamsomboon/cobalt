#pragma once

#include "cobalt/core/event.h"

namespace cobalt
{
    class window_close_event final : public event
    {
    public:
        window_close_event() = default;

        CB_EVENT_CLASS_TYPE(window_close)
        CB_EVENT_CLASS_CATEGORY(event_category_applicaiton)
    };
}
