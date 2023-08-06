#ifndef A1_MAZE_0_MODEL_MAZE_H
#define A1_MAZE_0_MODEL_MAZE_H

#include <memory>

#include "painter.h"
#include "random.h"
#include "type_maze.h"

enum class type_wall { kSouth, kWest };

class Maze {
 public:
  explicit Maze(size_t row, size_t col);
  void GenerateIdealMaze();
  type_maze &GetMaze();

 private:
  type_maze maze_;
  std::unique_ptr<Painter> painter_;

  void InitializeMaze();
  void SetWall(size_t row, size_t col, type_wall wall, bool value);
  void SetWestWalls(size_t index);
  void SetSouthWalls(size_t index);
  void CopyWalls(size_t index);
  void DeleteFromSetWithSouthWalls(size_t index);
  void SetUniqueSet(size_t index);
  
};

#endif  // A1_MAZE_0_MODEL_MAZE_H
