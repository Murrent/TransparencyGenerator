#pragma once

#include <SFML/Graphics.hpp>

class ImagePreview : public sf::Drawable {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape rectangleShape;
    sf::Text text;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

class Button : public sf::Drawable {
private:
    sf::RectangleShape rectangleShape;
    sf::Text text;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

class GUI {
private:
    sf::RenderWindow window;
    sf::Font font;
    ImagePreview beforeImagePreview;
    ImagePreview afterImagePreview;
    Button replaceColorButton;
    Button replaceColorWithButton;
    Button saveButton;
    Button pngButton, jpgButton, bmpButton, tgaButton;
    std::vector<Button> folderButtons;
    std::vector<Button> imageButtons;

public:
    GUI();

    void run();

    void init();

    void update();

    void draw();
};

