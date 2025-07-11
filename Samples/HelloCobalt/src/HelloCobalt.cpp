#include <Cobalt/Core/Application.h>
#include <Cobalt/Core/Log.h>

class CobaltApp final : public Cobalt::Application
{
public:
    CobaltApp()
        : Cobalt::Application()
    {
        COBALT_INFO(L"Cobalt App created");
    }

    ~CobaltApp()
    {
        COBALT_INFO(L"Cobalt App destroyed");
    }
};

Cobalt::Application *Cobalt::CreateApplication()
{
    return new CobaltApp();
}


int main()
{
    Cobalt::Log::Init();

    const auto app = Cobalt::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
