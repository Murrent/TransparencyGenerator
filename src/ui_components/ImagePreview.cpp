#include "ImagePreview.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

void ImagePreview::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(this->rectangleShape);
    target.draw(this->sprite);
    target.draw(this->text);
}
