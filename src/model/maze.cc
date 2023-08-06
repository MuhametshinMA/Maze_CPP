#include "maze.h"

#include <iostream>

Maze::Maze(size_t row, size_t col) : maze_{row, col} {
  painter_ = std::make_unique<Painter>();
  InitializeMaze();
}

void Maze::GenerateIdealMaze() {
  painter_->PrintNordWalls(maze_);
  SetUniqueSet(0);
  SetWestWalls(0);
  SetSouthWalls(0);
  painter_->PrintMazeString(0, maze_, true);
  std::cout << "\n";

  CopyWalls(0);
  painter_->PrintMazeString(1, maze_, true);
  SetUniqueSet(1);
  // painter_->PrintMazeString(1, maze_, true);
  SetWestWalls(1);
  // painter_->PrintMazeString(1, maze_, true);
  SetSouthWalls(1);
  painter_->PrintMazeString(1, maze_, true);

  std::cout << "\n";

  CopyWalls(1);
  painter_->PrintMazeString(2, maze_, true);
  SetUniqueSet(2);
  // painter_->PrintMazeString(2, maze_, true);
  SetWestWalls(2);
  // painter_->PrintMazeString(2, maze_, true);
  SetSouthWalls(2);
  painter_->PrintMazeString(2, maze_, true);

  // for (size_t i = 0; i < maze_.temp_set.size(); ++i) {
  //   std::cout << maze_.temp_set.at(i) << " ";
  // }
  // std::cout << "\n";
  // for (size_t i = 0; i < maze_.set.size(); ++i) {
  //   std::cout << maze_.set.at(i) << " ";
  // }

  // for (size_t i = 0; i < maze_.col; ++i) {
  //   if (i > 0) {
  //     CopyWalls(i - 1);
  //     SetUniqueSet(i);
  //     SetWestWalls(i);
  //     SetSouthWalls(i);
  //     painter_->PrintMazeString(i, maze_);
  //   }
  // }
  painter_->PrintMaze(maze_);
}

type_maze& Maze::GetMaze() { return maze_; }

void Maze::InitializeMaze() {
  for (size_t i = 0; i < maze_.row; ++i) {
    maze_.temp_set.push_back(0);
  }

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

void Maze::SetWestWalls(size_t index) {
  RandomBoolean random_boolean;
  for (size_t i = 0; i < maze_.row; ++i) {
    if (i < maze_.row - 1) {
      if (maze_.temp_set.at(i) != maze_.temp_set.at(i + 1)) {
        if (random_boolean()) {
          SetWall(index, i, type_wall::kWest, true);
        }
      } else {
        SetWall(index, i, type_wall::kWest, true);
      }
    }
    // join set
    if (!maze_.maze.first[index][i] && (i + 1) < maze_.row) {
      maze_.temp_set.at(i + 1) = maze_.temp_set.at(i);
    }
    // join set
  }
  SetWall(index, maze_.row - 1, type_wall::kWest, true);
}

void Maze::SetSouthWalls(size_t index) {
  RandomBoolean random_boolean;
  bool was_door = false;
  bool changed_set = true;
  for (size_t i = 0; i < maze_.row; ++i) {
    if (i < maze_.row - 1) {
      if (maze_.temp_set.at(i) == maze_.temp_set.at(i + 1)) {
        if (changed_set) {
          changed_set = false;
          if (random_boolean()) {
            SetWall(index, i, type_wall::kSouth, true);
          } else {
            was_door = true;
          }
        } else {
          if (random_boolean()) {
            SetWall(index, i, type_wall::kSouth, true);
          } else {
            was_door = true;
          }
        }
      } else {
        if (was_door) {
          if (random_boolean()) {
            SetWall(index, i, type_wall::kSouth, true);
          } else {
            was_door = true;
          }
        } else {
          was_door = false;
          continue;
        }
        was_door = false;
        changed_set = true;
        continue;
      }
    }
  }
}

void Maze::CopyWalls(size_t index) {
  maze_.maze.first.at(index + 1) = maze_.maze.first.at(index);
  maze_.maze.second.at(index + 1) = maze_.maze.second.at(index);

  for (size_t i = 0; i < maze_.row; ++i) {
    maze_.maze.first.at(index + 1)[i] = false;
    if (maze_.maze.second.at(index + 1)[i]) {
      maze_.temp_set.at(i) = 0;
      maze_.maze.second.at(index + 1)[i] = false;
    }
  }

  for (size_t i = 0; i < maze_.row; ++i) {
    if (i < maze_.row - 1 && maze_.temp_set.at(i) == maze_.temp_set.at(i + 1) &&
        maze_.temp_set.at(i) != 0) {
      SetWall(index + 1, i, type_wall::kWest, true);
    }
  }
}

void Maze::DeleteFromSetWithSouthWalls(size_t index) {
  for (size_t i = 0; i < maze_.set.size(); ++i) {
    if (maze_.maze.second.at(index)[i]) {
      maze_.set.at(i) = 0;
      maze_.maze.second.at(index)[i] = false;
    }
  }
}

void Maze::SetUniqueSet(size_t index) {
  size_t size_set = maze_.temp_set.size();
  for (size_t i = 0; i < maze_.temp_set.size(); ++i) {
    maze_.set.push_back(size_set - i);
  }

  maze_.set.erase(std::remove_if(maze_.set.begin(), maze_.set.end(),
                                 [&](int val) {
                                   return std::find(maze_.temp_set.begin(),
                                                    maze_.temp_set.end(),
                                                    val) !=
                                          maze_.temp_set.end();
                                 }),
                  maze_.set.end());
  for (size_t i = 0; i < maze_.temp_set.size(); ++i) {
    if (maze_.temp_set.at(i) == 0) {
      maze_.temp_set.at(i) = maze_.set.back();
      maze_.set.pop_back();
    }
  }

  // for (size_t i = 0; i < maze_.set.size(); ++i) {
  //   for (size_t j = 0; j < maze_.set.size(); ++j) {
  //     if (maze_.set.at(i) == maze_.temp_set.at(j)) {

  //     }
  //   }
  // }
  // for (size_t i = 0; i < maze_.set.size(); ++i) {
  //   if (maze_.set.at(i) == 0) {
  //     if (i == 0) {
  //       maze_.set.at(i) = maze_.set.at(i + 1) + 3;
  //     } else if (i < maze_.set.size() - 1) {
  //       maze_.set.at(i) = maze_.set.at(i - 1) + 2;
  //       if (maze_.set.at(i) == maze_.set.at(i + 1)) {
  //         maze_.set.at(i) -= 1;
  //       }
  //     }
  //   }
  // }
}
