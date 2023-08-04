#ifndef A1_MAZE_0_MODEL_MAZE_H
#define A1_MAZE_0_MODEL_MAZE_H

#include "random.h"
#include "type_maze.h"

enum class type_wall { kSouth, kWest };

class Maze {
 public:
  explicit Maze(size_t row, size_t col);
  void GenerateIdealMaze();
  type_maze& GetMaze();

 private:
  type_maze maze_;

  void InitializeMaze();
  void SetWall(size_t row, size_t col, type_wall wall, bool value);
  void SetWestWalls();
  void SetSouthWalls();
};

#endif  // A1_MAZE_0_MODEL_MAZE_H
