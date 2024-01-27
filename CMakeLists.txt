cmake_minimum_required(VERSION 3.5)

project(NesEmulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NesEmulator main.cpp)

include(GNUInstallDirs)
install(TARGETS NesEmulator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
