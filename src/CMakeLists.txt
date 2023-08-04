cmake_minimum_required(VERSION 3.8)

project(3DViewer2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g")

include_directories(model)

add_executable(
  maze_debug
  main.cc
)

add_library(maze_lib SHARED
  ${CMAKE_SOURCE_DIR}/model/model.cc
  ${CMAKE_SOURCE_DIR}/model/model.h
  ${CMAKE_SOURCE_DIR}/model/maze.cc
  ${CMAKE_SOURCE_DIR}/model/maze.h
  ${CMAKE_SOURCE_DIR}/model/painter.cc
  ${CMAKE_SOURCE_DIR}/model/painter.h
  ${CMAKE_SOURCE_DIR}/model/parser.cc
  ${CMAKE_SOURCE_DIR}/model/parser.h
)

target_link_libraries(
  maze_debug
  maze_lib
)
