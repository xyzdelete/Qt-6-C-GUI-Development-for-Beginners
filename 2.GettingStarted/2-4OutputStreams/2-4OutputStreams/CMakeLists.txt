cmake_minimum_required(VERSION 3.5)

project(2-4OutputStreams LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(2-4OutputStreams main.cpp)

include(GNUInstallDirs)
install(TARGETS 2-4OutputStreams
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
