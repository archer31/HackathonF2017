//ai.cpp
//Author: Alexander Corley, Jacob Hanson, Ryan Lynn
//10-28-2017
#include "ai.h"
using std::size_t;

Ai::Ai() {

}

void Ai::print(std::ostream& out) const {

}

bool Ai::solve() {
  return false;
}

void Ai::load_grid(std::istream& in) {

}

void Ai::fill_cons() {
  
}

void Ai::fill_vars() {
  for (size_t var = 0; var < size*size; ++var) {
    for (size_t i = 1; i <= size; ++i) {
      vars[var].domain[i-1] = i;
    }
  }
}

