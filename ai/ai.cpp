//ai.cpp
//Author: Alexander Corley, Jacob Hanson, Ryan Lynn
//10-28-2017
#include "ai.h"
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
using std::size_t;
using std::sqrt;

Ai::Ai(size_t size) 
  : size(size)
  , vars(size*size)
  , solved(false)
  , backTracks(0)
  , guessesTaken(0) {
  fill_vars();
  fill_cons();
}

Ai::Ai()
  : Ai(9) {}

void Ai::print(std::ostream& out, std::ostream& err) {
  if (!solved) out << "Error: game not solved\n";
  for (size_t row = 0; row < size; ++row) {
    for (size_t col = 0; col < size; ++col) {
      if (get_pos(row, col).domain.size() != 1)
        out << '-';
      else
        out << get_pos(row, col).domain[0];
    }
//    out << '\n';
  }
  err << "iters:\t" << iters << "\n";
  err << "guesses:\t" << guessesTaken << "\n";
  err << "back Tracks:\t" << backTracks << "\n";
}

bool Ai::solve() {
  if (is_solved()) return true;
  std::vector<Constraint> q;
  std::vector<std::vector<Variable> > vec;
  std::vector<std::pair<Variable, size_t> > guesses;
  do {
    for (size_t i = 0; i < size*size; ++i) {
      Variable& var = vars[i];
      for (auto con = var.cons.begin(); con != var.cons.end(); ++con) {
        q.push_back((*con));
      }
    }
    while (!q.empty()) {
      ++iters;
      Constraint &con = q[0]; q.erase(q.begin());
      if (con.left->domain.size() == 0) {
        if (guesses.size() == 0) return false;
        ++backTracks;
        vars = *(vec.end()-1);
        vec.erase(vec.end()-1);
        vars[(guesses.end()-1)->second] = (guesses.end()-1)->first;
        guesses.erase(guesses.end()-1);
      }
      if (con.right->domain.size() != 1) continue;
      auto it = std::find(con.left->domain.begin(), con.left->domain.end(), con.right->domain[0]);
      if (it != con.left->domain.end()) {
        con.left->domain.erase(it);
        for (size_t i = 0; i < con.left->cons.size(); ++i) {
          q.push_back(Constraint(con.left->cons[i].right, con.left));
        }
      }
    }
    //make a guess
    if (!is_solved()) {
      vec.push_back(vars);
      size_t index = make_guess();
      if (index > vars.size()) return false;
      Variable var = vars[index];
      int guess = var.domain[rand()%var.domain.size()];
      var.domain.erase(std::find(var.domain.begin(), var.domain.end(), guess));
      vars[index].domain.clear();
      vars[index].domain.push_back(guess);
      guesses.push_back(std::make_pair(var, index));
    }
  } while (!is_solved());
  return false;
}

size_t Ai::make_guess() {
  ++guessesTaken;
  std::srand(std::time(0));
  size_t min = size;
  vector<size_t> mins;
  for (size_t i = 0; i < size*size; ++i) {
    if (vars[i].domain.size() != 1 && vars[i].domain.size() < min) {
      min = vars[i].domain.size();
      mins.clear();
      mins.push_back(i);
    } else if (vars[i].domain.size() != 1 && vars[i].domain.size() == min) {
      mins.push_back(i);
    }
  }
  if (mins.size() == 0) return vars.size()+1;
  return mins[std::rand()%mins.size()];
}

bool Ai::is_solved() {
  for (auto it = vars.begin(); it != vars.end(); ++it) {
    if (it->domain.size() != 1)
      return false;
  }
  solved = true;
  return true;
}

Ai::Variable& Ai::get_pos(size_t row, size_t col) {
  return vars[row*size + col];
}

void Ai::load_grid(std::istream& in) {
  std::string line;
  std::stringstream s;
  char c;
  for(size_t row = 0; row < size; row++) {
    std::getline(in, line);
    for(size_t col = 0; col < size; col++) {
      c = line[col];
      if(c != '0') {
        Variable& ref = get_pos(row, col);
        ref.domain.clear();
        ref.domain.push_back(c-48);
      }
    }
  }
}

void Ai::fill_cons() {
  for (size_t row = 0; row < size; ++row) {
    for (size_t col = 0; col < size; ++col) {
      Variable& var = get_pos(row, col);

      // vertical col
      for(size_t c=0; c<size; c++) {
        if(c == col) continue;

        var.cons.push_back(Constraint(&var, &get_pos(row, c)));
      }

      // horizontal row
      for(size_t r=0; r<size; r++) {
        if(r == row) continue;
        var.cons.push_back(Constraint(&var, &get_pos(r, col)));
      }

      // local square
      size_t start_row = floor(row / sqrt(size)) * sqrt(size);
      size_t start_col = floor(col / sqrt(size)) * sqrt(size);
      for(size_t r=start_row; r<start_row+sqrt(size); r++) {
        for(size_t c=start_col; c<start_col+sqrt(size); c++) {
          if(r == row && c == col) continue;
          var.cons.push_back(Constraint(&var, &get_pos(r, c)));
        }
      }
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
