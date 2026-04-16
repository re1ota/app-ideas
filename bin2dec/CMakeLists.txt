cmake_minimum_required(VERSION 3.16)

project(. VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.11.0\\mingw_64\\")

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(bin2dec WIN32
        main.cpp
        bin2dec.cpp
        bin2dec.h
)


target_link_libraries(bin2dec PRIVATE Qt6::Widgets)

set_target_properties(bin2dec PROPERTIES WIN32_EXECUTABLE ON)