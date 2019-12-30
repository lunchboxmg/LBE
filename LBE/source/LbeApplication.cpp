#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "LbeApplication.hpp"

namespace // GLFW CALLBACKS
{
    void KeyCallback(GLFWwindow* aWindow, int aKey, int aScancode, int aAction, int aMods)
    {
        auto appPtr = reinterpret_cast<LBE::Application*>(glfwGetWindowUserPointer(aWindow));
        appPtr->GetKeyboard().HandleEvent(aKey, aScancode, aAction, aMods);
    }
}

LBE::Application::Application():
    mKeyboard(),
    mMouse(),
    mWindow()
{

}

LBE::Application::~Application()
{

}

int LBE::Application::Initialize(unsigned int aWidth, unsigned int aHeight, const char* aTitle)
{
    if (mInitialized) return 1;

    // INITIALIZE AND CONFIGURE GLFW
    if (!glfwInit())
    {
        std::cout << "GLFW did not initialize properly!" << std::endl;
        return -999;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // INITIALIZE THE APPLICATION WINDOW
    GLFWwindow* context = mWindow.Initialize(aWidth, aHeight, aTitle);
    if (context == nullptr)
    {
        glfwTerminate();
        return -10;
    }

    // LOAD ALL OPENGL FUNCTION POINTERS
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        glfwTerminate();
        return -20;
    }

    // SAVE A REFERENCE TO THIS APPLICATION WITHIN GLFW SO THAT CALLBACKS MAY
    // ACCESS THE VARIOUS APPLICATION COMPONENTS
    glfwSetWindowUserPointer(context, this);

    // BIND GLFW CALLBACKS
    glfwSetKeyCallback(context, KeyCallback);
    // TODO: MOUSE CALLBACK HERE
    // TODO: SCROLL CALLBACK HERE

    mInitialized = true;
    return 1;
}