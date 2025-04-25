#include "SDL3/SDL_keyboard.h"

namespace keyboard 
{
    bool check(SDL_Keycode keycode) 
    {
        const bool* keyboard_state = SDL_GetKeyboardState(nullptr);
        return keyboard_state[keycode];
    }
};