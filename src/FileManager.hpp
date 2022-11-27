#pragma once

#include <filesystem>
#include <SFML/Graphics/Image.hpp>

namespace fs = std::filesystem;

class FileManager {
private:
    fs::directory_iterator directoryIterator;
    std::string saveFormat;

public:
    FileManager();

    void setFolder(const std::string &path);

    std::string getFolder();

    bool selectFile(const std::string &filename);

    bool saveFile(const std::string &filepath, const sf::Image &image);

    bool setSaveFormat(const std::string &format);

    std::vector<std::string> getFolders();

    std::vector<std::string> getImages();
};

