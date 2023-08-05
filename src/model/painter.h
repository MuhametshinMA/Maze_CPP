#ifndef A1_MAZE_0_MODEL_PAINTER_H
#define A1_MAZE_0_MODEL_PAINTER_H

#include <functional>

#include "type_maze.h"

class Painter {
 public:
  // explicit Painter();
  void PrintMaze(type_maze &maze_, bool print_set = false);
  void PrintMazeString(size_t index, type_maze &maze_, bool print_set = false);
  void PrintNordWalls(type_maze &maze_);

  //  private:
  //   type_maze& maze_;
};

#endif  // A1_MAZE_0_MODEL_PAINTER_H
