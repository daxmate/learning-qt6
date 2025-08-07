cmake_minimum_required(VERSION 3.29)
project(learning_qt6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/qt/6.9.1/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(learning_qt6 main.cpp
        mainwindow.cpp mainwindow.h)
target_link_libraries(learning_qt6
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

