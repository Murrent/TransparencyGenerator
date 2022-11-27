#pragma once


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Panel : public sf::Drawable {
protected:
    sf::RectangleShape rectangleShape;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    Panel(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color);


};

