cmake_minimum_required(VERSION 3.5)

project(2-2NonQtConsoleApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2-2NonQtConsoleApp main.cpp)

include(GNUInstallDirs)
install(TARGETS 2-2NonQtConsoleApp
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
