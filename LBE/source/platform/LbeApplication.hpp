#pragma once

#include "glad/glad.h";
#include "glfw3.h"

#include "LbeExports.hpp"
#include "LbeKeyboard.hpp"
#include "LbeMouse.hpp"
#include "LbeWindow.hpp"

namespace LBE
{
    class LBE_API Application
    {
    private:

        Keyboard mKeyboard;
        Mouse mMouse;
        Window mWindow;

        bool mInitialized = false;

    public:

        Application();
        ~Application();

        int Initialize(unsigned int aWidth, unsigned int aHeight, const char* aTitle);

        bool IsInitialized() { return mInitialized; }

        Keyboard& GetKeyboard() { return mKeyboard; }
        Mouse& GetMouse() { return mMouse; }
        Window& GetWindow() { return mWindow; }
    };
}
