#include "Slider.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

void Slider::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->background, states);
    target.draw(this->slider, states);
}

Slider::Slider(const sf::Vector2f &position, const sf::Vector2f &size) {
    this->background.setSize(size);
    this->background.setFillColor(sf::Color(20, 20, 20, 255));
    this->background.setOutlineColor(sf::Color(100, 100, 100, 255));
    this->background.setOutlineThickness(1.0f);
    this->background.setPosition(position);

    this->slider.setSize(sf::Vector2f(size.x, size.y) * 0.8f);
    this->slider.setFillColor(sf::Color(255, 255, 255, 255));
    this->slider.setPosition(position);
}

void Slider::setSliderValue(float value) {
    this->sliderValue = value;
    if (this->isVertical) {
        this->slider.setPosition(this->slider.getPosition().x, this->background.getPosition().y + this->background.getSize().y * (1.0f - this->sliderValue));
    } else {
        this->slider.setPosition(this->background.getPosition().x + this->background.getSize().x * this->sliderValue, this->slider.getPosition().y);
    }
}

float Slider::getSliderValue() const {
    return this->sliderValue;
}

void Slider::setSliderSize(float size) {
    this->slider.setSize(sf::Vector2f(size, size));
}

bool Slider::isMouseOver(const sf::Vector2f &mousePosition) {
    return this->background.getGlobalBounds().contains(mousePosition);
}

void Slider::onMouseEnter() {
    this->background.setOutlineThickness(2);
}

void Slider::onMouseLeave() {
    this->background.setOutlineThickness(1);
}

void Slider::onMousePress() {
    this->slider.setFillColor(sf::Color(200, 200, 200, 255));
}

void Slider::onMouseRelease() {
    this->slider.setFillColor(sf::Color(255, 255, 255, 255));
}

void Slider::updateAnimation() {

}
