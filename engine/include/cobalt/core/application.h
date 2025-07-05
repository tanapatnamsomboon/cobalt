#pragma once

#include "cobalt/core/base.h"
#include "cobalt/core/window.h"

namespace cobalt
{
    class application
    {
    public:
        application();

        virtual ~application();

        void run();

    protected:
        std::unique_ptr<window> m_window;
        bool m_running = true;
    };

    application *create_application();
}
