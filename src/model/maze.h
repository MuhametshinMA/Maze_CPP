#ifndef A1_MAZE_0_MODEL_MAZE_H
#define A1_MAZE_0_MODEL_MAZE_H

#include <memory>

#include "painter.h"
#include "random.h"
#include "type_maze.h"

enum class type_wall { kSouth, kWest };

class Maze {
 public:
  Maze();
  void GenerateIdealMaze(size_t rows, size_t cols);
  type_maze &GetMaze();

 private:
  type_maze maze_;
  std::unique_ptr<Painter> painter_;

  void InitializeMaze(size_t rows, size_t cols);
  void SetWall(size_t row, size_t col, type_wall wall, bool value);
  void SetWestWalls(size_t index);
  void SetSouthWalls(size_t index);
  void CopyWalls(size_t index);
  void SetUniqueSet(size_t index);
  void JoinSet(size_t index);
  void SetLastWalls();
};

#endif  // A1_MAZE_0_MODEL_MAZE_H
