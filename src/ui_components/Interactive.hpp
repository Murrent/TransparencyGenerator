#pragma once

#include <SFML/Graphics/Drawable.hpp>

class Interactive : public sf::Drawable {
protected:
    bool isHovered = false;
    bool isPressed = false;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override = 0;

public:
    virtual bool isMouseOver(const sf::Vector2f &mousePosition) = 0;

    virtual void onMouseEnter() = 0;

    virtual void onMouseLeave() = 0;

    virtual void onMousePress() = 0;

    virtual void onMouseRelease() = 0;

    virtual void updateAnimation() = 0;
};
