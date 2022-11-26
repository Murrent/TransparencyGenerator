#include "AppManager.hpp"

AppManager::AppManager() : fileManager(), imageEditor() {}

void AppManager::setFolder(const std::string &path) {
    fileManager.setFolder(path);
}

bool AppManager::selectFile(const std::string &filename) {
    bool fileExists = fileManager.selectFile(filename);
    if (fileExists) {
        imageEditor.loadImage(filename);
        return true;
    }
    return false;
}

bool AppManager::saveFile(const std::string &filename) {
    bool saveSuccessful = fileManager.saveFile(filename, imageEditor.getOriginalImage());
    if (saveSuccessful)
        return true;
    return false;
}

bool AppManager::setSaveFormat(const std::string &format) {
    bool formatSet = fileManager.setSaveFormat(format);
    if (formatSet)
        return true;
    return false;
}

std::vector<std::string> AppManager::getFolders() {
    return fileManager.getFolders();
}

std::vector<std::string> AppManager::getImages() {
    return fileManager.getImages();
}

void AppManager::setReplaceColor(const sf::Color &color) {
    imageEditor.setReplaceColor(color);
}

sf::Color AppManager::getReplaceColor() {
    return imageEditor.getReplaceColor();
}

void AppManager::setReplaceColorWith(const sf::Color &color) {
    imageEditor.setReplaceColorWith(color);
}

sf::Color AppManager::getReplaceColorWith() {
    return imageEditor.getReplaceColorWith();
}

sf::Image AppManager::getOriginalImage() {
    return imageEditor.getOriginalImage();
}

sf::Image AppManager::getEditedImage() {
    return imageEditor.getEditedImage();
}
