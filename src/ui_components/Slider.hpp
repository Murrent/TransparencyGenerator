#pragma once


#include <SFML/Graphics/RectangleShape.hpp>
#include "Interactive.hpp"

class Slider : public Interactive {
private:
    sf::RectangleShape background;
    sf::RectangleShape slider;
    float sliderValue = 0.0f; // 0.0f - 1.0f
    bool isVertical = false;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    Slider(const sf::Vector2f &position, const sf::Vector2f &size);

    void setSliderValue(float value);

    float getSliderValue() const;

    void setSliderSize(float height);

    bool isMouseOver(const sf::Vector2f &mousePosition) override;

    void onMouseEnter() override;

    void onMouseLeave() override;

    void onMousePress() override;

    void onMouseRelease() override;

    void updateAnimation() override;
};

