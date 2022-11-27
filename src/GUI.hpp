#pragma once

#include <SFML/Graphics.hpp>
#include "ui_components/Interactive.hpp"

class GUI {
private:
    sf::RenderWindow window;
    sf::Font font;
    std::vector<Interactive> interactives;

public:
    GUI();

    void run();

    void init();

    void update();

    void draw();
};
