#pragma once

#include <spdlog/spdlog.h>

namespace cobalt
{
    class log
    {
    public:
        static void init();

        static std::shared_ptr<spdlog::logger> &get_core_logger() { return s_core_logger; }
        static std::shared_ptr<spdlog::logger> &get_client_logger() { return s_client_logger; }

    private:
        static std::shared_ptr<spdlog::logger> s_core_logger;
        static std::shared_ptr<spdlog::logger> s_client_logger;
    };
} // namespace cobalt

#if defined(CB_RELEASE)
    #define CB_CORE_TRACE(...)    void(0)
    #define CB_CORE_DEBUG(...)    void(0)
    #define CB_CORE_INFO(...)     ::cobalt::log::get_core_logger()->info(__VA_ARGS__)
    #define CB_CORE_WARN(...)     ::cobalt::log::get_core_logger()->warn(__VA_ARGS__)
    #define CB_CORE_ERROR(...)    ::cobalt::log::get_core_logger()->error(__VA_ARGS__)
    #define CB_CORE_CRITICAL(...) ::cobalt::log::get_core_logger()->critical(__VA_ARGS__)
#else
    #define CB_CORE_TRACE(...)    ::cobalt::log::get_core_logger()->trace(__VA_ARGS__)
    #define CB_CORE_DEBUG(...)    ::cobalt::log::get_core_logger()->debug(__VA_ARGS__)
    #define CB_CORE_INFO(...)     ::cobalt::log::get_core_logger()->info(__VA_ARGS__)
    #define CB_CORE_WARN(...)     ::cobalt::log::get_core_logger()->warn(__VA_ARGS__)
    #define CB_CORE_ERROR(...)    ::cobalt::log::get_core_logger()->error(__VA_ARGS__)
    #define CB_CORE_CRITICAL(...) ::cobalt::log::get_core_logger()->critical(__VA_ARGS__)
#endif

#if defined(CB_RELEASE)
    #define CB_TRACE(...)    void(0)
    #define CB_DEBUG(...)    void(0)
    #define CB_INFO(...)     ::cobalt::log::get_client_logger()->info(__VA_ARGS__)
    #define CB_WARN(...)     ::cobalt::log::get_client_logger()->warn(__VA_ARGS__)
    #define CB_ERROR(...)    ::cobalt::log::get_client_logger()->error(__VA_ARGS__)
    #define CB_CRITICAL(...) ::cobalt::log::get_client_logger()->critical(__VA_ARGS__)

    #define CB_LOG(...)      ::cobalt::log::get_client_logger()->info(__VA_ARGS__)
#else
    #define CB_TRACE(...)    ::cobalt::log::get_client_logger()->trace(__VA_ARGS__)
    #define CB_DEBUG(...)    ::cobalt::log::get_client_logger()->debug(__VA_ARGS__)
    #define CB_INFO(...)     ::cobalt::log::get_client_logger()->info(__VA_ARGS__)
    #define CB_WARN(...)     ::cobalt::log::get_client_logger()->warn(__VA_ARGS__)
    #define CB_ERROR(...)    ::cobalt::log::get_client_logger()->error(__VA_ARGS__)
    #define CB_CRITICAL(...) ::cobalt::log::get_client_logger()->critical(__VA_ARGS__)

    #define CB_LOG(...)      ::cobalt::log::get_client_logger()->debug(__VA_ARGS__)
#endif
