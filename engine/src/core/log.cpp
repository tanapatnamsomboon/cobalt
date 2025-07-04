#include "pch.h"

#include "cobalt/core/log.h"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace cobalt
{
    std::shared_ptr<spdlog::logger> log::s_core_logger;
    std::shared_ptr<spdlog::logger> log::s_client_logger;

    void log::init()
    {
        auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        console_sink->set_pattern("%^[%T] [%-5l] [%n] %v%$");

        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("cobalt.log", true);
        file_sink->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%l] [%n] %v");

        s_core_logger = std::make_shared<spdlog::logger>("cobalt", spdlog::sinks_init_list({console_sink, file_sink}));
        spdlog::register_logger(s_core_logger);
        s_core_logger->set_level(spdlog::level::trace);
        s_core_logger->flush_on(spdlog::level::trace);

        s_client_logger = std::make_shared<spdlog::logger>("client", spdlog::sinks_init_list({console_sink, file_sink}));
        spdlog::register_logger(s_client_logger);
        s_client_logger->set_level(spdlog::level::trace);
        s_client_logger->flush_on(spdlog::level::trace);
    }
}
