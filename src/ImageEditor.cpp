#include "ImageEditor.hpp"

void ImageEditor::replaceColor() {
    this->editedImage = this->originalImage;
    for (int x = 0; x < this->originalImage.getSize().x; x++) {
        for (int y = 0; y < this->originalImage.getSize().y; y++) {
            if (this->originalImage.getPixel(x, y) == this->colorToReplace)
                this->editedImage.setPixel(x, y, this->colorToReplaceWith);
        }
    }
}

ImageEditor::ImageEditor() : originalImage(), colorToReplace(sf::Color::White), colorToReplaceWith(sf::Color::Transparent) {}

bool ImageEditor::loadImage(const std::string &filename) {
    bool loadSuccessful = this->originalImage.loadFromFile(filename);
    if (loadSuccessful){
        this->editedImage = this->originalImage;
        replaceColor();
        return true;
    }
    return false;
}

void ImageEditor::setReplaceColor(const sf::Color &color) {
    this->colorToReplace = color;
    replaceColor();
}

sf::Color ImageEditor::getReplaceColor() {
    return this->colorToReplace;
}

void ImageEditor::setReplaceColorWith(const sf::Color &color) {
    this->colorToReplaceWith = color;
    replaceColor();
}

sf::Color ImageEditor::getReplaceColorWith() {
    return this->colorToReplaceWith;
}

sf::Image ImageEditor::getOriginalImage() {
    return this->originalImage;
}

sf::Image ImageEditor::getEditedImage() {
    return this->editedImage;
}


