#pragma once

#include "Cobalt/Core/Base.h"
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
        Scope<Window> m_Window;
    };

    Application* CreateApplication();
}
