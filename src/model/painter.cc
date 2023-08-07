#include "painter.h"

#include <iostream>

void Painter::PrintMaze(type_maze &maze_, bool print_set) {
  std::string set;

  auto it = maze_.maze.second;
  auto it_col = it.begin();
  for (size_t i = 0; i < maze_.maze.first.size(); ++i) {
    std::cout << "___ ";
  }
  std::cout << "\n";
  for (size_t i = 0; i < maze_.maze.first.size(); ++i) {
    for (size_t j = 0; j < maze_.maze.first[i].size(); ++j) {
      if (print_set) {
        if (maze_.maze.second[i][j]) {
          std::cout << "_" << maze_.set.at(j) << "_";
        } else {
          std::cout << " " << maze_.set.at(j) << " ";
        }
      } else {
        if (maze_.maze.second[i][j]) {
          std::cout << "___";
        } else {
          std::cout << "   ";
        }
      }
      if (maze_.maze.first[i][j]) {
        std::cout << "|";
      } else {
        std::cout << " ";
      }
    }
    std::cout << "\n";
  }
}

void Painter::PrintMazeString(size_t index, type_maze &maze_, bool print_set) {
  std::string set;

  auto it = maze_.maze.second;
  auto it_col = it.begin();
  std::cout << "|";
  for (size_t j = 0; j < maze_.maze.first[index].size(); ++j) {
    if (print_set) {
      if (maze_.maze.second[index][j]) {
        std::cout << "_" << maze_.temp_set.at(j) << "_";
      } else {
        std::cout << " " << maze_.temp_set.at(j) << " ";
      }
    } else {
      if (maze_.maze.second[index][j]) {
        std::cout << "___";
      } else {
        std::cout << "   ";
      }
    }
    if (maze_.maze.first[index][j]) {
      std::cout << "|";
    } else {
      std::cout << " ";
    }
  }
  std::cout << "\n";
}

void Painter::PrintNordWalls(type_maze &maze_) {
  std::cout << " ";
  for (size_t i = 0; i < maze_.maze.first.at(0).size(); ++i) {
    std::cout << "___ ";
  }
  std::cout << "\n";
}
