#ifndef A1_MAZE_0_MODEL_MODEL_H
#define A1_MAZE_0_MODEL_MODEL_H

#include <memory>

#include "maze.h"
// #include "painter.h"

class Model {
 public:
  Model() : maze_(new Maze()) {}
  ~Model() { delete maze_; }
  // void callPrintMaze(bool print_set = false) { painter_.PrintMaze(print_set);
  // }
  void callGenerateIdealMaze() { maze_->GenerateIdealMaze(5, 5); }

 private:
  Maze* maze_;
  // Painter painter_;
};

#endif  // A1_MAZE_0_MODEL_MODEL_H
