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

LBE::Application::Application() :
    mKeyboard(),
    mMouse(),
    mWindow()
{

}

LBE::Application::~Application()
{
    if (mInitialized)
        glfwTerminate();
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

    // INITIALIZE ADDITIONAL COMPONENTS
    mClock.Initialize();
    mInitialized = true;
    return 1;
}

void LBE::Application::InternalUpdate()
{
    // DO OUR OWN INTERNAL UPDATES FIRST
    mClock.Update();
    mKeyboard.Update();
    glfwPollEvents();

    // CALL USER SUPPLIED UPDATE
    Update();
}

void LBE::Application::Start()
{
    mClock.Start();
    while (true)
    {
        InternalUpdate();
        // TODO: CHECK TERMINATION CONDITION HERE
        if (glfwWindowShouldClose(mWindow.GetContext())) break;
        unsigned char done = mKeyboard.IsKeyPressed(GLFW_KEY_ESCAPE);
        if (done) break;

        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.2, 0.2, 0.2, 1.0);

        glfwSwapBuffers(mWindow.GetContext());

        KeyState a = mKeyboard.GetKeyState(GLFW_KEY_A);
        if (a.state)
            a.Output();
    }
}

// VIRTUAL
void LBE::Application::Update()
{

}