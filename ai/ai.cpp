//ai.cpp
//Author: Alexander Corley, Jacob Hanson, Ryan Lynn
//10-28-2017
#include "ai.h"
#include <cmath>
#include <algorithm>
using std::size_t;

Ai::Ai(size_t size) 
  : size(size)
  , vars(size*size)
  , solved(false) {
  fill_vars();
  fill_cons();
  std::vector<Constraint*> meme;
}

Ai::Ai()
  : Ai(9) {}


void Ai::print(std::ostream& out) const {
  if (!solved) out << "Error: game not solved\n";
  //TODO
}

bool Ai::solve() {
  if (solved) return true;
  std::vector<int*> q;
/*  for (size_t i = 0; i < size*size; ++i) {
    Variable& var = vars[i];
    for (auto con = var.cons.begin(); con != var.cons.end(); ++con) {
      q.push_back(&(*con));
    }
  }
  while (!q.empty()) {
    ++iters;
    Constraint *con = q[0]; q.erase(q.begin());
    if (con->left->domain.size() == 1) continue;
    if (con->right->domain.size() != 1) continue;
    auto it = std::find(con->left->domain.begin(), con->left->domain.end(), con->right->domain[0]);
    if (it != con->left->domain.end()) {
      con->left->domain.erase(it);
      for (size_t i = 0; i < con->left->cons.size(); ++i) {
        Constraint *c = new Constraint();
        c->left = con->left->cons[i].left;
        c->right = con->left;
        q.push_back(c);
      }
    }
    if (iters >= 1944) {
      delete con;
    }
  }*/
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
  for (size_t row = 0; row < size; ++row) {
    for (size_t col = 0; col < size; ++col) {
      Variable& var = get_pos(row, col);
//      for (size_t row1 = 0; 
    }
  }
}

void Ai::fill_vars() {
  for (size_t var = 0; var < size*size; ++var) {
    vars[var].domain.resize(size);
    for (size_t i = 1; i <= size; ++i) {
      vars[var].domain[i-1] = i;
    }
  }
}
