#include "AppManager.hpp"

bool AppManager::loadFile(const std::string &fullPath) {
    return imageEditor.loadImage(fullPath);
}

AppManager::AppManager() : fileManager(), imageEditor() {}

void AppManager::setFolder(const std::string &path) {
    fileManager.setFolder(path);
}

bool AppManager::selectFile(const std::string &filename) {
    bool fileExists = fileManager.selectFile(filename);
    if (fileExists) {
        std::string fullPath = fileManager.getFolder() + "/" + filename;
        bool loadResult = loadFile(fullPath);
        return loadResult;
    }
    return false;
}

bool AppManager::saveFile(const std::string &filename) {
    std::string fullPath = fileManager.getFolder() + "/" + filename;
    bool saveSuccessful = fileManager.saveFile(fullPath, imageEditor.getEditedImage());
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
