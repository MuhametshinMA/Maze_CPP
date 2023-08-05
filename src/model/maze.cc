#include "maze.h"

// #include <iostream>

Maze::Maze(size_t row, size_t col) : maze_{row, col} {
  painter_ = std::make_unique<Painter>();
  InitializeMaze();
}

void Maze::GenerateIdealMaze() {
  painter_->PrintNordWalls(maze_);
  SetWestWalls(0);
  JoinSets(0);
  SetSouthWalls(0);
  painter_->PrintMazeString(0, maze_);
  // CopyWalls(0);
  // DeleteWestWalls(1);
  // DeleteFromSetWithSouthWalls(1);
  // SetUniqueSet(1);
  // SetWestWalls(1);
  // JoinSets(1);
  // SetSouthWalls(1);
  // painter_->PrintMazeString(1, maze_, true);
  // CopyWalls(1);
  // DeleteWestWalls(2);
  // DeleteFromSetWithSouthWalls(2);
  // SetUniqueSet(2);
  // SetWestWalls(2);
  // JoinSets(2);
  // SetSouthWalls(2);
  // painter_->PrintMazeString(2, maze_, true);
  // CopyWalls(2);
  // DeleteWestWalls(3);
  // DeleteFromSetWithSouthWalls(3);
  // SetUniqueSet(3);
  // SetWestWalls(3);
  // JoinSets(3);
  // painter_->PrintMazeString(3, maze_, true);
  // // SetSouthWalls(3);
  for (size_t i = 0; i < maze_.set.size(); ++i) {
    if (i > 0) {
      CopyWalls(i - 1);
      DeleteWestWalls(i);
      DeleteFromSetWithSouthWalls(i);
      SetUniqueSet(i);
      SetWestWalls(i);
      JoinSets(i);
      SetSouthWalls(i);
      painter_->PrintMazeString(i, maze_);
    }
  }
}

type_maze& Maze::GetMaze() { return maze_; }

void Maze::InitializeMaze() {
  for (size_t i = 0; i < maze_.row; ++i) {
    maze_.set.push_back(i + 1);
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
      if (maze_.set.at(i) != maze_.set.at(i + 1)) {
        if (random_boolean()) {
          SetWall(index, i, type_wall::kWest, true);
        }
      } else {
        SetWall(index, i, type_wall::kWest, true);
      }
    }
  }
  SetWall(index, maze_.row - 1, type_wall::kWest, true);
}

void Maze::SetSouthWalls(size_t index) {
  RandomBoolean random_boolean;
  bool was_door = false;
  for (size_t i = 0; i < maze_.row; ++i) {
    if (maze_.maze.first.at(index)[i] == true) {
      if (was_door) {
        if (random_boolean()) {
          SetWall(index, i, type_wall::kSouth, true);
        } else {
          was_door = true;
        }
      } else {
        continue;
      }
      was_door = false;
    } else {
      if (random_boolean()) {
        SetWall(index, i, type_wall::kSouth, true);
      } else {
        was_door = true;
      }
    }
  }
}

void Maze::CopyWalls(size_t index) {
  maze_.maze.first.at(index + 1) = maze_.maze.first.at(index);
  maze_.maze.second.at(index + 1) = maze_.maze.second.at(index);
}

void Maze::DeleteWestWalls(size_t index) {
  for (size_t i = 0; i < maze_.maze.first.at(index).size(); ++i) {
    maze_.maze.first.at(index)[i] = false;
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
  for (size_t i = 0; i < maze_.set.size(); ++i) {
    if (maze_.set.at(i) == 0) {
      if (i == 0) {
        maze_.set.at(i) = maze_.set.at(i + 1) + 2;
      } else if (i < maze_.set.size() - 1) {
        maze_.set.at(i) = maze_.set.at(i - 1) + 1;
        if (maze_.set.at(i) == maze_.set.at(i + 1)) {
          maze_.set.at(i) -= 1;
        }
      }
    }
  }
}

void Maze::JoinSets(size_t index) {
  for (size_t i = 0; i < maze_.row; ++i) {
    if (!maze_.maze.first[index][i] && (i + 1) < maze_.row) {
      maze_.set.at(i + 1) = maze_.set.at(i);
    }
  }
}
