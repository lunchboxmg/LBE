#pragma once

namespace LBE
{
    struct InputState
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
            int mods = 0;
        };
    };
}