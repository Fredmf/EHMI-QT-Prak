cmake_minimum_required(VERSION 2.8.9)

set(PROJECT "carsmilie")

project(${PROJECT})

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES
    src/main.cpp
    src/mainwindow.h
    src/mainwindow.cpp
    src/gpioListener.h
    src/gpioListener.cpp
)

set(UI_FILES
    ui/gui.ui
)

source_group("UI Files" FILES ${UI_FILES})

qt5_wrap_ui(UI_HEADERS ${UI_FILES})

source_group("Generated UI Headers" FILES ${UI_HEADERS})

add_executable(${PROJECT} ${SOURCE_FILES} ${UI_HEADERS} ${UI_FILES})
qt5_use_modules(${PROJECT} Widgets)
target_link_libraries(carsmilie
    wiringPi
)