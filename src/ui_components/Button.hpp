#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Interactive.hpp"

class Button : public Interactive {
private:
    sf::RectangleShape shape;
    sf::Text text;
    std::function<void()> onClick;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    Button(const sf::Vector2f &position, const sf::Vector2f &size, const std::string &text, const sf::Font &font,
           std::function<void()> function);

    void setFunction(std::function<void()> function);

    void setShapeColor(const sf::Color &color);

    void setOutlineColor(const sf::Color &color);

    void setTextColor(const sf::Color &color);

    bool isMouseOver(const sf::Vector2f &mousePosition) override;

    void onMouseEnter() override;

    void onMouseLeave() override;

    void onMousePress() override;

    void onMouseRelease() override;
};

