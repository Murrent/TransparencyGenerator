#pragma once

#include "FileManager.hpp"
#include "ImageEditor.hpp"

class AppManager {
private:
    FileManager fileManager;
    ImageEditor imageEditor;

public:
    AppManager();

    void setFolder(const std::string &path);

    bool selectFile(const std::string &filename);

    bool saveFile(const std::string &filename);

    bool setSaveFormat(const std::string &format);

    std::vector<std::string> getFolders();

    std::vector<std::string> getImages();

    void setReplaceColor(const sf::Color &color);

    sf::Color getReplaceColor();

    void setReplaceColorWith(const sf::Color &color);

    sf::Color getReplaceColorWith();

    sf::Image getOriginalImage();

    sf::Image getEditedImage();
};

