#include "LbeClock.hpp"

#include <iostream>

namespace LBE
{
    Clock::Clock() :
        mCurrentTime(0.0),
        mDt(0.0),
        mFrameCount(0)
    {
    }

    Clock::~Clock()
    {
    }

    void Clock::Initialize()
    {
        mCurrentTime = glfwGetTime();
    }

    void Clock::Update()
    {
        double now = glfwGetTime();
        mDt = now - mCurrentTime;
        mCurrentTime = now;
        mFrameCount++;
        // TODO: Add in FPS
        // - NOTE: Do we want the clock to also act as a FPS limiter
#ifdef LBE_DEBUG
        double fps = mDt > 0.0 ? 1.0 / mDt : 0.0;
        std::cout << "DT=" << mDt << ", FPS=" << fps << std::endl;
#endif
    }

    std::time_t Clock::GetWallTime()
    {
        auto now = std::chrono::system_clock::now();
        return std::chrono::system_clock::to_time_t(now);
    }
}