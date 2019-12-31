#pragma once

#include <iostream>
#include <bitset>

#include "LbeExports.hpp"

namespace LBE
{
    struct LBE_API InputState
    {
        union
        {
            struct
            {
                unsigned char pressed  : 1;
                unsigned char held     : 1;
                unsigned char released : 1;
            };
            unsigned char state = 0;
        };
        union
        {
            struct
            {
                unsigned char shift   : 1;
                unsigned char control : 1;
                unsigned char alt     : 1;
                unsigned char super   : 1;
                unsigned char caplock : 1;
                unsigned char numlock : 1;
            };
            unsigned char mods = 0;
        };

        void Output()
        {
            std::cout << "  state = " << std::bitset<8>(state) << std::endl;
            std::cout << "  mods  = " << std::bitset<8>(mods) << std::endl;
        }
    };
}