cmake_minimum_required(VERSION 3.20)

project(Dyna3D)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CURRENT_INCLUDE_DIR ON)
set(Qt6_DIR "Library/Qt")
list(APPEND CMAKE_PREFIX_PATH "Library/Qt")

find_package(Qt6 CONFIG REQUIRED COMPONENTS Widgets)

add_executable(Dyna3D
    main.cpp
    DynaMainWindow.cpp
    DynaMainWindow.h
    DynaExplorer.cpp
    DynaExplorer.h
    DynaProperties.cpp
    DynaProperties.h
    DynaDoc.cpp
    DynaDoc.h
    )

target_link_libraries(Dyna3D Qt6::Widgets)