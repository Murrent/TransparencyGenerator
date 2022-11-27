#pragma once


#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class ImagePreview : public sf::Drawable {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape rectangleShape;
    sf::Text text;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

};

