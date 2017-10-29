//main.cpp
//Author: Alexander Corley, Jacob Hanson, Ryan Lynn
//10-28-2017
#include "ai.h"
#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr <<  "usage: solve <SIZE> <FILE|->\n";
    return 0;
  }
  Ai ai(std::atoi(argv[1]));
  if (argv[2][0] == '-')
    ai.load_grid(std::cin);
  else {
    std::ifstream in(argv[2]);
    ai.load_grid(in);
  }
  ai.print(std::cerr, std::cerr);
  
  ai.solve();
  ai.print(std::cout, std::cerr);
  return 0;
}
