#include <cobalt/cobalt.h>

class hello_cobalt_app : public cobalt::application
{
public:
    hello_cobalt_app() = default;
    ~hello_cobalt_app() override = default;
};

cobalt::application *cobalt::create_application()
{
    return new hello_cobalt_app();
}


int main()
{
    cobalt::log::init();

    auto app = cobalt::create_application();
    app->run();
    delete app;

    return 0;
}
