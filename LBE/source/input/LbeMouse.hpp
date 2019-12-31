#pragma once

#include <GLFW/glfw3.h>

#include "LbeExports.hpp"
#include "LbeInputState.hpp"

namespace LBE
{
    struct LBE_API MouseButtonState : InputState
    {
        // INCLUDE MOUSE POSITION ON EVENT OCCURANCE
        float x = 0.0f;
        float y = 0.0f;
    };

    class LBE_API Mouse
    {
    private:

        MouseButtonState mStates[GLFW_MOUSE_BUTTON_LAST + 1];
        MouseButtonState mStatesPrev[GLFW_MOUSE_BUTTON_LAST + 1];

        float mX, mY;
        float mDeltaX, mDeltaY;
        float mScrollX, mScrollY;

    public:

        Mouse();
        ~Mouse();

        void Update();

        void HandleEvents(GLFWwindow* aWindow, int aButton, int aAction, int aMods);

        float GetX() { return mX; }
        float GetY() { return mY; }

        float GetDX() { return mDeltaX; }
        float GetDY() { return mDeltaY; }

        float GetScrollX() { return mScrollX; }
        float GetScrollY() { return mScrollY; }

        bool IsButtonPressed(unsigned int aButton) { return mStates[aButton].pressed; }
        bool IsButtonHeld(unsigned int aButton) { return mStates[aButton].held; }
        bool IsButtonReleased(unsigned int aButton) { return mStates[aButton].released; }
    
        MouseButtonState GetButonState(unsigned int aButton) { return mStates[aButton]; }
    };
}