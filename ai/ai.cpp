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

Ai::Variable& Ai::get_pos(size_t row, size_t col) {
  return vars[row*size + col];
}

void Ai::load_grid(std::istream& in) {
  char c;
  for(size_t row = 0; row < size; row++) {
    for(size_t col = 0; col < size; col++) {
      in >> c;
      if(c != ' ') {
        Variable& ref = get_pos(row, col);
        ref.domain.clear();
        ref.domain.push_back( (size_t)(c - 48) );
      }
    }
  }
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
