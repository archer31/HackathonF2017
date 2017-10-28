//main.cpp
//Author: Alexander Corley, Jacob Hanson, Ryan Lynn
//10-28-2017
#include "ai.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
  Ai ai(9);
  std::ifstream in("grid");
  ai.load_grid(in);
  ai.print(std::cout);
  
  ai.solve();
  ai.print(std::cout);
  return 0;
}
