cmake_minimum_required(VERSION 3.5)

project(NesEmulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NesEmulator main.cpp
    ppu.h ppu.cpp
    palette.h palette.cpp
    light_rai.h
    linux_input.h linux_input.cpp
    i_device.h
    memory_mapped.h memory_mapped.cpp
)

target_link_libraries(NesEmulator X11)
include(GNUInstallDirs)
install(TARGETS NesEmulator
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
