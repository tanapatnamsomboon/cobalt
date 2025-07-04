#include <cobalt/core/log.h>
#include "cobalt/core/window.h"

int main()
{
    cobalt::log::init();

    CB_LOG_INFO("Starting HelloCobalt");

    auto window = cobalt::window::create({"Hello Window", 800, 600});

    while (true)
    {
        window->on_update();
    }

    return 0;
}
