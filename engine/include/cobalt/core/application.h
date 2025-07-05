#pragma once

#include "cobalt/core/base.h"
#include "cobalt/core/window.h"
#include "cobalt/events/window_close_event.h"
#include "cobalt/events/window_resize_event.h"
#include "cobalt/events/key_event.h"
#include "cobalt/events/mouse_event.h"

namespace cobalt
{
    class application
    {
    public:
        application();

        virtual ~application();

        void run();

        void on_event(event& e);

    protected:
        virtual bool on_window_close(window_close_event& e);
        virtual bool on_window_resize(window_resize_event& e);
        virtual bool on_key_pressed(key_pressed_event& e);
        virtual bool on_key_released(key_released_event& e);
        virtual bool on_mouse_moved(mouse_moved_event& e);
        virtual bool on_mouse_button_pressed(mouse_button_pressed_event& e);
        virtual bool on_mouse_button_released(mouse_button_release_event& e);

        std::unique_ptr<window> m_window;
        bool m_running = true;

    private:
        event_callback_fn m_event_callback;
    };

    application *create_application();
}
