cmake_minimum_required(VERSION 4.0)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(learningqt6 VERSION 1.0.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
file(GLOB SOURCE_FILES src/*.cpp)
file(GLOB RESOURCE_FILES resources/*.qrc)
file(GLOB TRANSLATION_FILES translations/*.ts)
file(GLOB HEADER_FILES include/*.h)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets LinguistTools)

qt_standard_project_setup(I18N_TRANSLATED_LANGUAGES en zh ja)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES}
                               ${RESOURCE_FILES})
qt6_add_lupdate(SOURCE_TARGETS ${PROJECT_NAME} TS_FILES ${TRANSLATION_FILES})
qt6_add_translations(${PROJECT_NAME} TS_OUTPUT_DIRECTORY translations)
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
