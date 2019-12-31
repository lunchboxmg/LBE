#ifndef LBE_CLOCK_HPP
#define LBE_CLOCK_HPP

#include <chrono>
#include <ctime>

#include <GLFW/glfw3.h>

#include "LbeExports.hpp"

namespace LBE
{
    class LBE_API Clock
    {
    private:

        double       mCurrentTime;
        double       mDt;
        unsigned int mFrameCount;

    public:

        Clock();
        ~Clock();

        void         Initialize();

        void         Update();

        std::time_t  GetWallTime();

        double       GetDt()          { return mDt;}
        double       GetCurrentTime() { return mCurrentTime; }
        double       GetDeviceTime()  { return glfwGetTime(); }
        unsigned int GetFrameCount()  { return mFrameCount; }

    };
}

#endif // LBE_CLOCK_HPP
