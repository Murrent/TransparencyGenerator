#include <iostream>
#include "AppManager.hpp"

int main()
{
    AppManager appManager;
    appManager.setFolder("C:/Users/Martin/Desktop/test");
    if (!appManager.selectFile("test.png")){
        std::cout << "File not found" << std::endl;
        return 0;
    }
    appManager.setReplaceColor(sf::Color::White);
    appManager.setReplaceColorWith(sf::Color::Transparent);
    if (!appManager.setSaveFormat("png")) {
        std::cout << "Invalid format" << std::endl;
        return 0;
    }
    if (!appManager.saveFile("test2")) {
        std::cout << "Save failed" << std::endl;
        return 0;
    }
    std::cout << "Save successful" << std::endl;
    return 0;
}