#include "FileManager.hpp"

FileManager::FileManager() : directoryIterator(fs::directory_iterator(fs::current_path())), saveFormat("png") {}

void FileManager::setFolder(const std::string &path) {
    this->directoryIterator = fs::directory_iterator(path.c_str());
}

std::string FileManager::getFolder() {
    return this->directoryIterator->path().parent_path().string();
}

bool FileManager::selectFile(const std::string &filename) {
    for (const auto &entry : directoryIterator) {
        if (entry.path().filename().string() == filename) {
            return true;
        }
    }
    return false;
}

bool FileManager::saveFile(const std::string &filepath, const sf::Image &image) {
    bool saveSuccessful = image.saveToFile(filepath + "." + this->saveFormat);
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
            folders.push_back(entry.path().filename().string());
    });
    return folders;
}

std::vector<std::string> FileManager::getImages() {
    std::vector<std::string> images;
    std::for_each(begin(this->directoryIterator), end(this->directoryIterator), [&](const auto &entry) {
        std::string extension = entry.path().extension().string();
        if (extension == ".png" || extension == ".jpg" || extension == ".bmp" || extension == ".tga")
            images.push_back(entry.path().filename().string());
    });
    return images;
}


