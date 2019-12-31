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
    for (int i = 0; i < 1024; i++)
    {
        mStates[i].state = mStates[i].held ? 1 << 1 : 0;
    }
}

void LBE::Keyboard::HandleEvent(int aKey, int aScancode, int aAction, int aMods)
{
    if (0 <= aKey && aKey <= 1024)
    {
        if (aAction == GLFW_PRESS)
        {
            mStates[aKey].pressed = 1;
            mStates[aKey].held = 1;
        }
        if (aAction == GLFW_RELEASE)
        {
            mStates[aKey].held = 0;
            mStates[aKey].released = 1;
        }
        mStates[aKey].mods = aMods;
        //mStates[aKey].state |= (aMods << 3);
    }
}