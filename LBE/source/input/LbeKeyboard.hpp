#pragma once

#include <GLFW/glfw3.h>

#include "LbeExports.hpp"
#include "LbeInputState.hpp"

namespace LBE
{
    struct LBE_API KeyState : InputState {};

    class LBE_API Keyboard
    {
    private:

        // KEY STATE ARRAYS
        KeyState mStates[1024];
        KeyState mStatesPrev[1024];

    public:

        Keyboard();
        ~Keyboard();

        void Update();

        void HandleEvent(int aKey, int aScancode, int aAction, int aMods);

        bool IsKeyPressed(unsigned int aKeyCode) { return mStates[aKeyCode].pressed; }
        bool IsKeyHeld(unsigned int aKeyCode) { return mStates[aKeyCode].held; }
        bool IsKeyReleased(unsigned int aKeyCode) { return mStates[aKeyCode].released; }

        KeyState GetKeyState(unsigned int aKeyCode) { return mStates[aKeyCode]; }
        KeyState GetKeyPrevState(unsigned int aKeyCode) { return mStatesPrev[aKeyCode]; }
    };

    class KeyEvent
    {
    };

    class KeyPressedEvent : public KeyEvent
    {

    };
}
