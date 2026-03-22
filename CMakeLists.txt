cmake_minimum_required(VERSION 3.16)
project(radio-stations VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

set(SOURCES
    main.cpp
    mainwindow.cpp
)

set(HEADERS
    mainwindow.h
)

add_executable(radio-stations ${SOURCES} ${HEADERS}
    form.ui)

target_link_libraries(radio-stations Qt6::Core Qt6::Widgets)
