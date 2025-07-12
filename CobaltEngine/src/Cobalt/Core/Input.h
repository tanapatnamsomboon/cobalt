#pragma once

#include "Cobalt/Core/Base.h"
#include "Cobalt/Core/KeyCode.h"
#include "Cobalt/Core/MouseCode.h"

namespace Cobalt
{
    class Input
    {
    public:
        virtual ~Input() = default;

        virtual bool IsKeyPressed(KeyCode key) const = 0;
        virtual bool IsMouseButtonPressed(MouseCode button) const = 0;
        virtual float GetMouseX() const = 0;
        virtual float GetMouseY() const = 0;
        virtual std::pair<float, float> GetMousePosition() const = 0;

        static Scope<Input> Create();
    };
}