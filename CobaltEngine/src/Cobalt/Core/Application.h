#pragma once

#include "Cobalt/Core/Window.h"

namespace Cobalt
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> m_Window;
    };

    Application* CreateApplication();
}
