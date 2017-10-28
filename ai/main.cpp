//main.cpp
//Author: Alexander Corley, Jacob Hanson, Ryan Lynn
//10-28-2017
#include "ai.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
  Ai ai;
  std::ifstream in("grid");
  ai.load_grid(in);
  ai.solve();
  return 0;
}
