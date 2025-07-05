#pragma once

namespace cobalt
{
    enum class event_type
    {
        none = 0,
        window_close, window_resize,
        key_pressed, ket_released,
        mouse_button_pressed, mouse_button_released, mouse_moved
    };

    enum event_category
    {
        none                        = 0,
        event_category_applicaiton  = 1 << 0,
        event_category_input        = 1 << 1,
        event_category_keyboard     = 1 << 2,
        event_category_mouse        = 1 << 3,
        event_category_mouse_button = 1 << 4
    };

#define CB_EVENT_CLASS_TYPE(type) \
    static  event_type  get_static_type()                   { return event_type::type; } \
    virtual event_type  get_event_type()     const override { return get_static_type(); } \
    virtual const char* get_name()           const override { return #type; }

#define CB_EVENT_CLASS_CATEGORY(category) \
    virtual int         get_category_flags() const override { return category; }

}
