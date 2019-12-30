#pragma once

#ifdef LBE_EXPORTS
#define LBE_API __declspec(dllexport)
#else
#define LBE_API __declspec(dllimport)
#endif
