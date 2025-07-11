#pragma once

#include "Cobalt/Core/Base.h"
#include <spdlog/spdlog.h>

namespace Cobalt
{
    class Log
    {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

#define CB_CORE_TRACE(...)    ::Cobalt::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CB_CORE_INFO(...)     ::Cobalt::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CB_CORE_WARN(...)     ::Cobalt::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CB_CORE_ERROR(...)    ::Cobalt::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CB_CORE_CRITICAL(...) ::Cobalt::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define CB_TRACE(...)         ::Cobalt::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CB_INFO(...)          ::Cobalt::Log::GetClientLogger()->info(__VA_ARGS__)
#define CB_WARN(...)          ::Cobalt::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CB_ERROR(...)         ::Cobalt::Log::GetClientLogger()->error(__VA_ARGS__)
#define CB_CRITICAL(...)      ::Cobalt::Log::GetClientLogger()->critical(__VA_ARGS__)