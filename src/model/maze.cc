#include "maze.h"

#include <iostream>

Maze::Maze(size_t row, size_t col) : maze_{row, col} { InitializeMaze(); }

void Maze::GenerateIdealMaze() {
  SetWestWalls();
  SetSouthWalls();
}

type_maze& Maze::GetMaze() { return maze_; }

void Maze::InitializeMaze() {
  maze_.maze.first.resize(maze_.row, std::vector<bool>(maze_.col));
  maze_.maze.second.resize(maze_.row, std::vector<bool>(maze_.col));
}

void Maze::SetWall(size_t row, size_t col, type_wall wall, bool value) {
  auto& maze_ref =
      (wall == type_wall::kSouth) ? maze_.maze.second : maze_.maze.first;

  if (row < maze_.row && col < maze_.col) {
    maze_ref[row][col] = value;
  }
}

void Maze::SetWestWalls() {
  Random random_boolean;
  for (size_t i = 0; i < maze_.row; ++i) {
    maze_.set.push_back(i);
    if (random_boolean()) {
      SetWall(0, i, type_wall::kWest, true);
    }
  }

  for (size_t i = 0; i < maze_.row; ++i) {
    if (!maze_.maze.first[0][i] && (i + 1) < maze_.row) {
      maze_.set.at(i + 1) = maze_.set.at(i);
    }
  }
  SetWall(0, maze_.row - 1, type_wall::kWest, true);
}

void Maze::SetSouthWalls() {
  Random random_boolean;
  bool was_door = false;
  for (size_t i = 0; i < maze_.row; ++i) {
    if (i == 0 && maze_.set.at(i) != maze_.set.at(i + 1)) {
      continue;
    }

    if ((i != (maze_.row - 1)) && (maze_.set.at(i) != maze_.set.at(i + 1))) {
      if (was_door) {
        SetWall(0, i, type_wall::kSouth, true);
      }
      was_door = false;
    } else if (i == (maze_.row - 1)) {
      if (was_door) {
        SetWall(0, i, type_wall::kSouth, true);
      }
    } else {
      if (was_door) {
        SetWall(0, i, type_wall::kSouth, true);
      } else {
        if (random_boolean()) {
          SetWall(0, i, type_wall::kSouth, true);
        } else {
          was_door = true;
        }
      }
    }
  }
}
