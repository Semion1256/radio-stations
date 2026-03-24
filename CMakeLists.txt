cmake_minimum_required(VERSION 3.16)
project(radio-stations VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Sql)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/src/resources)
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/config/envLoader.cpp
    src/database/databaseManager.cpp

)

set(HEADERS
    src/mainwindow.h
    src/config/envLoader.h
    src/database/databaseManager.h

)

add_executable(radio-stations ${SOURCES} ${HEADERS}
    src/resources/form.ui
)

target_link_libraries(radio-stations Qt6::Core Qt6::Widgets Qt6::Sql)

target_include_directories(radio-stations PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src

)
