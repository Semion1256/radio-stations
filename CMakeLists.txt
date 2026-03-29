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
    src/models/operator.cpp
    src/models/station.cpp
    src/models/license.cpp
    src/repositories/operatorRepository.cpp
    src/repositories/stationRepository.cpp
    src/repositories/licenseRepository.cpp
    src/validators/operatorValidator.cpp
    src/validators/stationValidator.cpp
    src/validators/licenseValidator.cpp
    src/services/operatorService.cpp
    src/services/stationService.cpp
    src/services/licenseService.cpp


)

set(HEADERS
    src/mainwindow.h
    src/config/envLoader.h
    src/database/databaseManager.h
    src/models/operator.h
    src/models/station.h
    src/models/license.h
    src/repositories/baseRepository.h
    src/repositories/operatorRepository.h
    src/repositories/stationRepository.h
    src/repositories/licenseRepository.h
    src/validators/operatorValidator.h
    src/validators/stationValidator.h
    src/validators/licenseValidator.h
    src/services/operatorService.h
    src/services/stationService.h
    src/services/licenseService.h

)

add_executable(radio-stations ${SOURCES} ${HEADERS}
    src/resources/form.ui
)

target_link_libraries(radio-stations Qt6::Core Qt6::Widgets Qt6::Sql)

target_include_directories(radio-stations PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/src

)
