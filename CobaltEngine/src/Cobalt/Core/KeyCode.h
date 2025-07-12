#pragma once

#include "Cobalt/Core/Base.h"

namespace Cobalt
{
    enum class KeyCode : u16
    {
        Space = 32,

        A = 65, B, C, D, E, F, G,
        H, I, J, K, L, M, N, O, P, Q, R, S,
        T, U, V, W, X, Y, Z,

        Num0 = 48, Num1, Num2, Num3, Num4,
        Num5, Num6, Num7, Num8, Num9,

        Escape = 256,
        Enter,
        Tab,
        Backspace,
        Insert,
        Delete,
        Right,
        Left,
        Down,
        Up,
    };
}