#include "Application.h"

namespace Cobalt
{
    Application::Application()
    {
        // TODO: Init subsystems
        m_Window = Window::Create();
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (true)
        {
            m_Window->OnUpdate();
        }
    }

}
