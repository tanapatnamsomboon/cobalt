#include <Cobalt/Core/Application.h>
#include <Cobalt/Core/Log.h>

class CobaltApp final : public Cobalt::Application
{
public:
    CobaltApp()
        : Cobalt::Application()
    {
        CB_INFO("Cobalt App created");
    }

    ~CobaltApp() override
    {
        CB_INFO("Cobalt App destroyed");
    }
};

Cobalt::Application *Cobalt::CreateApplication()
{
    return new CobaltApp();
}


int main(int argc, char** argv)
{
    Cobalt::Log::Init();

    const auto app = Cobalt::CreateApplication();
    app->Run();
    delete app;
    return 0;
}
