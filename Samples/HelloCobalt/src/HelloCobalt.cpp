#include <Cobalt/Core/Application.h>
#include <print>

class CobaltApp final : public Cobalt::Application
{
public:
    CobaltApp()
        : Cobalt::Application()
    {
        std::println("Cobalt App created");
    }

    ~CobaltApp() override
    {
        std::println("Cobalt App destroyed");
    }
};

Cobalt::Application *Cobalt::CreateApplication()
{
    return new CobaltApp();
}


int main()
{
    const auto app = Cobalt::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
