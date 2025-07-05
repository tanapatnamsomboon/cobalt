#pragma once

#include "cobalt/core/base.h"
#include "cobalt/core/window.h"
#include "cobalt/events/window_close_event.h"

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

        std::unique_ptr<window> m_window;
        bool m_running = true;

    private:
        event_callback_fn m_event_callback;
    };

    application *create_application();
}
