//main.cpp
//Author: Alexander Corley, Jacob Hanson, Ryan Lynn
//10-28-2017
#include "ai.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
  Ai ai(std::atoi(argv[1]));
  std::ifstream in(argv[2]);
  ai.load_grid(in);
  ai.print(std::cout, std::cerr);
  
  ai.solve();
  ai.print(std::cout, std::cerr);
  return 0;
}
