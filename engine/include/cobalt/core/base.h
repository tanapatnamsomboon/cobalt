#pragma once

#include <memory>

#define CB_EXPAND(x) x
#define CB_STRINGIFY(x) #x
#define CB_CONCAT(x, y) a##b

#include "cobalt/core/platform_detection.h"

#ifdef CB_BUILD_DEBUG
    #if defined(CB_PLATFORM_WINDOWS)
        #define CB_DEBUGBREAK() __debugbreak()
    #elif defined(CB_PLATFORM_LINUX)
        #include <signal.h>
        #define CB_DEBUGBREAK() raise(SIGTRAP)
    #else
        #error "Platform doesn't support debugbreak yet!"
    #endif
    #define CB_ENABLE_ASSERTS
#else
    #define CB_DEBUGBREAK()
#endif

#include "cobalt/core/log.h"
#include "cobalt/core/assert.h"