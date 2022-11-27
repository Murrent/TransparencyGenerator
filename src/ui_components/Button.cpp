#include "Button.hpp"
#include <SFML/Graphics/RenderTarget.hpp>
#include <utility>

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->shape, states);
    target.draw(this->text, states);
}

Button::Button(const sf::Vector2f &position,
               const sf::Vector2f &size,
               const std::string &text,
               const sf::Font &font,
               std::function<void()> function) :
               shape(size),
               text(text, font, 20),
               onClick(std::move(function)) {

}

void Button::setFunction(std::function<void()> function) {
    this->onClick = std::move(function);
}

void Button::setShapeColor(const sf::Color &color) {
    this->shape.setFillColor(color);
}

void Button::setOutlineColor(const sf::Color &color) {
    this->shape.setOutlineColor(color);
}

void Button::setTextColor(const sf::Color &color) {
    this->text.setFillColor(color);
}

bool Button::isMouseOver(const sf::Vector2f &mousePosition) {
    return this->shape.getGlobalBounds().contains(mousePosition);
}

void Button::onMouseEnter() {
    sf::Color currentOutlineColor = this->shape.getOutlineColor();
    currentOutlineColor.a = 255;
    this->shape.setOutlineColor(currentOutlineColor);
    this->shape.setOutlineThickness(2);
}

void Button::onMouseLeave() {
    sf::Color currentOutlineColor = this->shape.getOutlineColor();
    currentOutlineColor.a = 0;
    this->shape.setOutlineColor(currentOutlineColor);
    this->shape.setOutlineThickness(0);
}

void Button::onMousePress() {
    sf::Color currentFillColor = this->shape.getFillColor();
    currentFillColor.a = 200;
    this->shape.setFillColor(currentFillColor);
}

void Button::onMouseRelease() {
    sf::Color currentFillColor = this->shape.getFillColor();
    currentFillColor.a = 255;
    this->shape.setFillColor(currentFillColor);
    this->onClick();
}

