#pragma once

#include "cobalt/core/base.h"
#include <filesystem>

namespace cobalt::internal
{
    inline void assert_fail(const char *condition_str, const char *file, int line, const char *msg_format, ...)
    {
        char buffer[1024];
        va_list args;
        va_start(args, msg_format);
        vsnprintf(buffer, sizeof(buffer), msg_format, args);
        va_end(args);

        CB_CORE_ERROR("Assertion Failed: {}", condition_str);
        CB_CORE_ERROR("Message: {}", buffer);
        CB_CORE_ERROR("File: {}, Line: {}", file, line);
        CB_DEBUGBREAK();
    }

    inline void client_assert_fail(const char *condition_str, const char *file, int line, const char *msg_format, ...)
    {
        char buffer[1024];
        va_list args;
        va_start(args, msg_format);
        vsnprintf(buffer, sizeof(buffer), msg_format, args);
        va_end(args);

        CB_LOG_ERROR("Assertion Failed: {}", condition_str);
        CB_LOG_ERROR("Message: {}", buffer);
        CB_LOG_ERROR("File: {}, Line: {}", file, line);
        CB_DEBUGBREAK();
    }
}

#ifdef CB_ENABLE_ASSERTS
    #define CB_CORE_ASSERT(condition, ...) \
        do { \
            if (!(condition)) { \
                ::cobalt::internal::assert_fail(#condition, __FILE__, __LINE__, __VA_ARGS__); \
            } \
        } while(0)

    #define CB_ASSERT(condition, ...) \
        do { \
            if (!(condition)) { \
                ::cobalt::internal::client_assert_fail(#condition, __FILE__, __LINE__, __VA_ARGS__); \
            } \
        } while(0)
#else
        #define CB_CORE_ASSERT(condition, ...) (void)0
        #define CB_ASSERT(condition, ...) (void)0
#endif
