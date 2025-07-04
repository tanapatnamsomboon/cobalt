#pragma once

#ifdef _WIN32
    #ifdef _WIN64
        #define CB_PLATFORM_WINDOWS
    #else
        #error "x86 Builds are not supported!"
    #endif
#elif defined(__APPLE__) || defined(__MACH__)
    #error "Apple is not currently supported!"
#elif defined(__ANDROID__)
    #define CB_PLATFORM_ANDROID
    #error "Android is not currently supported!"
#elif defined(__linux__)
    #define CB_PLATFORM_LINUX
    #error "Linux is not currently supported!"
#else
    #error "Unknown platform!"
#endif