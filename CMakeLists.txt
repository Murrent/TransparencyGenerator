cmake_minimum_required(VERSION 3.20)
project(TransparencyGenerator)

set(CMAKE_CXX_STANDARD 17)

set(dir ${CMAKE_CURRENT_SOURCE_DIR})
set(src ${dir}/src)

add_executable(TransparencyGenerator
        src/main.cpp
        src/FileManager.cpp
        src/FileManager.hpp
        src/ImageEditor.cpp
        src/ImageEditor.hpp
        src/GUI.cpp
        src/GUI.hpp
        src/AppManager.cpp
        src/AppManager.hpp
        src/ui_components/Interactive.cpp
        src/ui_components/Interactive.hpp
        src/ui_components/Button.cpp
        src/ui_components/Button.hpp
        src/ui_components/List.cpp
        src/ui_components/List.hpp
        src/ui_components/Slider.cpp
        src/ui_components/Slider.hpp
        src/ui_components/ImagePreview.cpp
        src/ui_components/ImagePreview.hpp
        src/ui_components/Panel.cpp
        src/ui_components/Panel.hpp)

include_directories(headers /usr/include c:/SFML/include)
#include_directories(box2d C:/Users/Martin/Downloads/box2d-master/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(TransparencyGenerator ${SFML_LIBRARIES})
endif ()

# file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build
if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    # file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    # file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()