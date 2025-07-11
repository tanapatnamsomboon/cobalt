#include "Application.h"

#include "Cobalt/Events/ApplicationEvent.h"

namespace Cobalt
{
    Application::Application()
    {
        // TODO: Init subsystems
        m_Window = Window::Create();
        m_Window->SetEventCallback([this](Event& e)
        {
            this->OnEvent(e);
        });
    }

    Application::~Application() = default;

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& ev)
        {
            return OnWindowClose(ev);
        });
    }

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        CB_CORE_INFO("WindowCloseEvent received in Application.");
        m_Running = false;
        return true;
    }
}
