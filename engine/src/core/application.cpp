#include "pch.h"

#include "cobalt/core/application.h"

namespace cobalt
{
    application::application()
    {
        CB_LOG_INFO("Create Application");
        m_window = window::create({"Cobalt Application", 1280, 720});
        m_window->set_event_callback([this](event &e) { on_event(e); });
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
        dispatcher.dispatch<window_close_event>(CB_BIND_EVENT_FN(on_window_close));
        dispatcher.dispatch<window_resize_event>(CB_BIND_EVENT_FN(on_window_resize));
        dispatcher.dispatch<key_pressed_event>(CB_BIND_EVENT_FN(on_key_pressed));
        dispatcher.dispatch<key_released_event>(CB_BIND_EVENT_FN(on_key_released));
        dispatcher.dispatch<mouse_moved_event>(CB_BIND_EVENT_FN(on_mouse_moved));
        dispatcher.dispatch<mouse_button_pressed_event>(CB_BIND_EVENT_FN(on_mouse_button_pressed));
        dispatcher.dispatch<mouse_button_release_event>(CB_BIND_EVENT_FN(on_mouse_button_released));
    }

    bool application::on_window_close(window_close_event &e)
    {
        m_running = false;
        return true;
    }

    bool application::on_window_resize(window_resize_event &e)
    {
        CB_LOG_INFO("Window resized to {}x{}", e.get_width(), e.get_height());
        return true;
    }

    bool application::on_key_pressed(key_pressed_event &e)
    {
        CB_LOG_INFO("KeyPressed: {}", e.get_keycode());
        return true;
    }

    bool application::on_key_released(key_released_event &e)
    {
        CB_LOG_INFO("KeyReleased: {}", e.get_keycode());
        return true;
    }

    bool application::on_mouse_moved(mouse_moved_event &e)
    {
        CB_LOG_INFO("MouseMoved: {}, {}", e.get_x(), e.get_y());
        return true;
    }

    bool application::on_mouse_button_pressed(mouse_button_pressed_event &e)
    {
        CB_LOG_INFO("MouseButtonPressed: {}", e.get_mouse_button());
        return true;
    }

    bool application::on_mouse_button_released(mouse_button_release_event &e)
    {
        CB_LOG_INFO("MouseButtonReleased: {}", e.get_mouse_button());
        return true;
    }
}
