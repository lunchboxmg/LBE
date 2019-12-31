#include <iostream>

#include "LbeWindow.hpp"


LBE::Window::Window()
{

}

LBE::Window::~Window()
{

}

GLFWwindow* LBE::Window::Initialize(unsigned int aWidth, unsigned int aHeight, const char* aTitle)
{
    mInitialized = false;

    // TODO: ADD ARGUMENT ERROR CHECKING
    mWidth = aWidth;
    mHeight = mHeight;
    mAspect = (float)aWidth / (float)aHeight;

    // CREATE THE CONTEXT
    mContext = glfwCreateWindow(aWidth, aHeight, aTitle, NULL, NULL);
    if (mContext == nullptr)
    {
        std::cout << "FAILED TO CREATE GLFW WINDOW!" << std::endl;
        return nullptr;
    }
    glfwMakeContextCurrent(mContext);
    mInitialized = true;

    return mContext;
}