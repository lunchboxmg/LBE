#pragma once

#include <GLFW/glfw3.h>

#include "LbeExports.hpp"

namespace LBE
{
    class LBE_API Window
    {
    private:

        GLFWwindow*  mContext = nullptr;
        unsigned int mWidth = 0;
        unsigned int mHeight = 0;
        float        mAspect = 0.0;
        bool         mCloseRequested = false; // TODO: MAY NOT NEED!
        bool         mInitialized = false;

    public:

        Window();
        ~Window();

        GLFWwindow*  Initialize(unsigned int aWidth, unsigned int aHeight, const char* aTitle);

        GLFWwindow*  GetContext()       { return mContext; }
        unsigned int GetWidth()         { return mWidth; }
        unsigned int GetHeight()        { return mHeight; }
        float        GetAspect()        { return mAspect; }
        bool         IsCloseRequested() { return mCloseRequested; }
        bool         IsInitialized()    { return mInitialized; }
    };
}
