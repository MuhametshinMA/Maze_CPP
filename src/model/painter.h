#ifndef A1_MAZE_0_MODEL_PAINTER_H
#define A1_MAZE_0_MODEL_PAINTER_H

#include <functional>

#include "type_maze.h"

class Painter {
 public:
  explicit Painter(std::reference_wrapper<type_maze> maze);
  void PrintMaze(bool print_set = false);

 private:
  type_maze& maze_;
};

#endif  // A1_MAZE_0_MODEL_PAINTER_H
