cmake_minimum_required(VERSION 3.16)
project(github_status)

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Widgets Network)

qt_standard_project_setup()

qt_add_executable(github_status
        main.cpp
        mainwindow.cpp
        mainwindow.h
)

target_link_libraries(github_status PRIVATE Qt6::Widgets Qt6::Network)

set_target_properties(github_status PROPERTIES WIN32_EXECUTABLE ON)