cmake_minimum_required(VERSION 3.5)

project(2-8Functions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2-8Functions main.cpp)

include(GNUInstallDirs)
install(TARGETS 2-8Functions
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
