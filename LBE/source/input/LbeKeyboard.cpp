#include "LbeKeyboard.hpp"

LBE::Keyboard::Keyboard()
{
    for (int i = 0; i < 1024; i++)
    {
        mStates[i].state = 0;
        mStates[i].mods = 0;
        mStatesPrev[i].state = 0;
        mStatesPrev[i].mods = 0;
    }
}

LBE::Keyboard::~Keyboard()
{

}

void LBE::Keyboard::Update()
{
    // COPY PREVIOUS STATES AND CLEAR THE CURRENT STATES
    for (int i = 0; i < 1024; i++)
    {
        mStatesPrev[i].state = mStates[i].state;
        mStatesPrev[i].mods = mStates[i].mods;
        mStates[i].state = 0;
        mStates[i].mods = 0;
    }
}

void LBE::Keyboard::HandleEvent(int aKey, int aScancode, int aAction, int aMods)
{
    if (0 <= aKey && aKey <= 1024)
    {
        // LOOKUP glfwGetWindowUserPointer
        InputState prev = mStatesPrev[aKey];
        if (aAction == GLFW_PRESS)
        {
            if (prev.pressed)
                mStates[aKey].held = 1;
            else
                mStates[aKey].pressed = 1;
        }
        if (aAction == GLFW_RELEASE)
        {
            mStates[aKey].held = 0;
            mStates[aKey].released = 0;
        }
        mStates[aKey].mods = aMods;
    }
}