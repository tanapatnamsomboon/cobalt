#include "pch.h"

#include "cobalt/core/application.h"

namespace cobalt
{
    application::application()
    {
        CB_LOG_INFO("Create Application");
        m_window = window::create({"Cobalt Application", 1280, 720});
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


}
