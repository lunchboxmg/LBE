#pragma once

#ifdef LBE_STATIC_LIB
    #define LBE_API
#else
    #ifdef LBE_BUILD_DLL
        #define LBE_API __declspec(dllexport)
    #else
        #define LBE_API __declspec(dllimport)
    #endif
#endif
