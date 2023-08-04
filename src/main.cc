#include <iostream>

#include "model.h"

int main() {
  std::unique_ptr<Model> model = std::make_unique<Model>();
  model->callGenerateIdealMaze();
  model->callPrintMaze(true);
  return 0;
}