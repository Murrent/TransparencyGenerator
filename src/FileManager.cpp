#include "FileManager.hpp"

FileManager::FileManager() : directoryIterator(fs::directory_iterator(fs::current_path())), saveFormat("png") {}

void FileManager::setFolder(const std::string &path) {
    this->directoryIterator = fs::directory_iterator(path.c_str());
}

bool FileManager::selectFile(const std::string &filename) {
    // Finding the file
    std::any_of(begin(this->directoryIterator), end(this->directoryIterator), [&](const auto &entry) {
        return entry.path().filename() == filename;
    });
    return false;
}

bool FileManager::saveFile(const std::string &filename, const sf::Image &image) {
    bool saveSuccessful = image.saveToFile(filename + this->saveFormat);
    if (saveSuccessful)
        return true;
    return false;
}

bool FileManager::setSaveFormat(const std::string &format) {
    if (format == "png" || format == "jpg" || format == "bmp" || format == "tga") {
        this->saveFormat = format;
        return true;
    }
    return false;
}

std::vector<std::string> FileManager::getFolders() {
    std::vector<std::string> folders;
    std::for_each(begin(this->directoryIterator), end(this->directoryIterator), [&](const auto &entry) {
        if (entry.is_directory())
            folders.push_back(entry.path().filename());
    });
    return folders;
}

std::vector<std::string> FileManager::getImages() {
    std::vector<std::string> images;
    std::for_each(begin(this->directoryIterator), end(this->directoryIterator), [&](const auto &entry) {
        if (entry.extension() == ".png" || entry.extension() == ".jpg" ||
            entry.extension() == ".bmp" || entry.extension() == ".tga")
            images.push_back(entry.path().filename());
    });
    return images;
}

