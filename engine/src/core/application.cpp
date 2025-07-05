#include "pch.h"

#include "cobalt/core/application.h"

namespace cobalt
{
    application::application()
    {
        CB_LOG_INFO("Create Application");
        m_window = window::create({"Cobalt Application", 1280, 720});
        m_window->set_event_callback([this](event& e){ on_event(e); });
    }

    application::~application()
    {
        CB_LOG_INFO("Destroying Application");
    }

    void application::run()
    {
        while (m_running)
        {
            m_window->on_update();
        }
    }

    void application::on_event(event &e)
    {
        event_dispatcher dispatcher(e);
        dispatcher.dispatch<window_close_event>([this](window_close_event& ev)
        {
           return on_window_close(ev);
        });
    }

    bool application::on_window_close(window_close_event &e)
    {
        m_running = false;
        return true;
    }
}
