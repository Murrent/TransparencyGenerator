#pragma once

#include <SFML/Graphics/Image.hpp>

class ImageEditor {
private:
    sf::Image originalImage;
    sf::Image editedImage;
    sf::Color colorToReplace;
    sf::Color colorToReplaceWith;

    void replaceColor();

public:
    ImageEditor();

    bool loadImage(const std::string &filename);

    void setReplaceColor(const sf::Color &color);

    sf::Color getReplaceColor();

    void setReplaceColorWith(const sf::Color &color);

    sf::Color getReplaceColorWith();

    sf::Image getOriginalImage();

    sf::Image getEditedImage();
};

