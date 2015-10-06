cmake_minimum_required(VERSION 2.6)

set(BIN "bin/game.out")
set(CMAKE_CXX_FLAGS "-std=c++11")
project(${BIN})
include_directories("include")
aux_source_directory("src" SOURCES)
add_executable(${BIN} ${SOURCES})
target_link_libraries(${BIN} SDL2 SDL2_image SDL2_ttf)