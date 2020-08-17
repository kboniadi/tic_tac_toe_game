cmake_minimum_required(VERSION 3.17)
project(tic_tac_toe)

find_package(raylib 2.5.0 REQUIRED)
set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(pages)

add_executable(tic_tac_toe
    pages/INSTRUC_PAGE.cpp
    pages/INSTRUC_PAGE.h
    pages/MAIN_PAGE.cpp
    pages/MAIN_PAGE.h
    pages/MULTI_PAGE.cpp
    pages/MULTI_PAGE.h
    pages/SINGLE_PAGE.cpp
    pages/SINGLE_PAGE.h
    pages/TABLE_PAGE.cpp
    pages/TABLE_PAGE.h
    GAME_CONTROLLER.cpp
    GAME_CONTROLLER.h
    GAME_DATA.cpp
    GAME_DATA.h
    INDEX.h
    LIMITS.h
    main.cpp
    raygui.h
    raylib.h)

target_link_libraries(tic_tac_toe raylib)