#pragma once

#include "Cobalt/Core/Input.h"

namespace Cobalt
{
    class WindowsInput final : public Input
    {
    public:
        WindowsInput();

        bool IsKeyPressed(KeyCode key) const override;
        bool IsMouseButtonPressed(MouseCode button) const override;
        float GetMouseX() const override;
        float GetMouseY() const override;
        std::pair<float, float> GetMousePosition() const override;
    };
}