#ifndef A1_MAZE_0_MODEL_TYPE_MAZE_H
#define A1_MAZE_0_MODEL_TYPE_MAZE_H

#include <vector>

struct type_maze {
  using matriсes =
      std::pair<std::vector<std::vector<bool>>, std::vector<std::vector<bool>>>;
  using set_matrix = std::vector<size_t>;
  size_t row;
  size_t col;
  matriсes maze;
  set_matrix set;
};

#endif  // A1_MAZE_0_MODEL_TYPE_MAZE_H
