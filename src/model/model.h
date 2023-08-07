#ifndef A1_MAZE_0_MODEL_MODEL_H
#define A1_MAZE_0_MODEL_MODEL_H

#include <memory>

#include "maze.h"
// #include "painter.h"

class Model {
 public:
  Model()
      : maze_(std::make_unique<Maze>(20, 20)) /*, painter_(maze_->GetMaze())*/ {
  }
  // void callPrintMaze(bool print_set = false) { painter_.PrintMaze(print_set);
  // }
  void callGenerateIdealMaze() { maze_->GenerateIdealMaze(); }

 private:
  std::unique_ptr<Maze> maze_;
  // Painter painter_;
};

#endif  // A1_MAZE_0_MODEL_MODEL_H
