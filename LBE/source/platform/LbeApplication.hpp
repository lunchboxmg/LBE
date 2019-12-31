#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "LbeExports.hpp"
#include "LbeWindow.hpp"

#include "input/LbeKeyboard.hpp"
#include "input/LbeMouse.hpp"
#include "LbeClock.hpp"

namespace LBE
{
    class LBE_API Application
    {
    private:

        Keyboard mKeyboard;
        Mouse mMouse;
        Window mWindow;
        Clock mClock;

        bool mInitialized = false;

    public:

        Application();
        ~Application();

        int Initialize(unsigned int aWidth, unsigned int aHeight, const char* aTitle);

        void Start();

        void Update();

        bool IsInitialized() { return mInitialized; }

        Keyboard& GetKeyboard() { return mKeyboard; }
        Mouse& GetMouse() { return mMouse; }
        Window& GetWindow() { return mWindow; }

    };
}
