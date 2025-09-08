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

qt_standard_project_setup(I18N_TRANSLATED_LANGUAGES zh)
# add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})
qt_add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES}
                  ${RESOURCE_FILES})
qt6_add_lupdate(SOURCE_TARGETS ${PROJECT_NAME} TS_FILES ${TRANSLATION_FILES})
qt6_add_translations(${PROJECT_NAME} TS_OUTPUT_DIRECTORY translations
                     QM_OUTPUT_DIRECTORY translations)
# 复制 .qm 文件到资源目录，以便资源系统能找到它们
add_custom_command(
  TARGET ${PROJECT_NAME}
  PRE_BUILD
  COMMAND
    ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/translations/learningqt6_zh.qm
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/
  COMMENT "Copying translation files to resources directory")
# qt6_add_resources(${PROJECT_NAME} "translations" PREFIX "/translations" FILES
# "resources/translations.qrc")
target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)
