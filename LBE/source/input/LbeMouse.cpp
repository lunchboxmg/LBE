#include "LbeMouse.hpp"

LBE::Mouse::Mouse():
    mX(0.0f),
    mY(0.0f),
    mDeltaX(0.0f),
    mDeltaY(0.0f),
    mScrollX(0.0f),
    mScrollY(0.0f)
{
    for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST + 1; i++)
    {
        mStates[i].state = 0;
        mStates[i].mods = 0;
        mStates[i].x = 0.0f;
        mStates[i].y = 0.0f;
        mStatesPrev[i].state = 0;
        mStatesPrev[i].mods = 0;
        mStatesPrev[i].x = 0.0f;
        mStatesPrev[i].y = 0.0f;
    }
}

LBE::Mouse::~Mouse()
{

}

void LBE::Mouse::Update()
{

}

void LBE::Mouse::HandleEvents(GLFWwindow* aWindow, int aButton, int aAction, int aMods)
{

}
