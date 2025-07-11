#pragma once

#include "Cobalt/Core/Base.h"
#include "Cobalt/Core/Window.h"
#include "Cobalt/Events/Event.h"
#include "Cobalt/Events/ApplicationEvent.h"

int main(int argc, char** argv);

namespace Cobalt
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        virtual void OnEvent(Event& e);

    private:
        void Run();
        bool OnWindowClose(WindowCloseEvent& e);

    private:
        Scope<Window> m_Window;
        bool m_Running = true;

    private:
        friend int ::main(int argc, char** argv);
    };

    Application* CreateApplication();
}
