cmake_minimum_required(VERSION 4.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(learning_qt6 VERSION 1.0)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
file(GLOB SOURCE_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE Qt::Core Qt::Gui Qt::Widgets)
target_include_directories(${PROJECT_NAME} PRIVATE include)
