cmake_minimum_required(VERSION 3.5)

project(2-11ClassesMultipleFiles LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2-11ClassesMultipleFiles main.cpp
    rectangle.hpp
    box.hpp
)

include(GNUInstallDirs)
install(TARGETS 2-11ClassesMultipleFiles
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
