cmake_minimum_required(VERSION 3.5)

project(2-10ClassConstructors LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2-10ClassConstructors main.cpp)

include(GNUInstallDirs)
install(TARGETS 2-10ClassConstructors
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
