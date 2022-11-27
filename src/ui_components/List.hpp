#pragma once


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Interactive.hpp"

class List : public sf::Drawable {
private:
    sf::Text headerText;
    sf::RectangleShape headerBackground;
    sf::RectangleShape contentBackground;
    sf::View view;
    std::vector<Interactive> items;
    unsigned int selectedItemIndex = 0;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
};

