#pragma once

#include "Cobalt/Core/Base.h"
#include "Cobalt/Core/Window.h"
#include "Cobalt/Core/Input.h"
#include "Cobalt/Events/Event.h"
#include "Cobalt/Events/ApplicationEvent.h"

int main(int argc, char **argv);

namespace Cobalt
{
    class Application
    {
    public:
        Application();

        virtual ~Application();

        virtual void OnEvent(Event& e);

        Window& GetWindow() const { return *m_Window; }
        Input& GetInput() const { return *m_Input; }

        static Application& Get() { return *s_Instance; }

    private:
        void Run();
        bool OnWindowClose(WindowCloseEvent& e);

    private:
        Scope<Window> m_Window;
        Scope<Input> m_Input;
        bool m_Running = true;

    private:
        static Application *s_Instance;
        friend int ::main(int argc, char **argv);
    };

    Application *CreateApplication();
}
