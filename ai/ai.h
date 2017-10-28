//ai.h
//Author: Alexander Corley, Jacob Hanson, Ryan Lynn
//10-28-2017
#ifndef AI_H
#define AI_H

#include <vector>
#include <iostream>
using std::size_t;

class Ai {
  public:
  Ai(size_t);
  Ai();
  void print(std::ostream&) const;
  bool solve();
  void load_grid(std::istream&);
  private:
  class Constraint;
  class Variable {
    public:
    std::vector<int> domain;
    std::vector<Constraint> cons;
  };
  class Constraint {
    public:
    Variable *left = nullptr, *right = nullptr;
  };
	size_t size;
  std::vector<Variable> vars;
  size_t iters;
  bool solved;

  void fill_cons();
	void fill_vars();
  Variable& get_pos(size_t, size_t);
};

#endif //AI_H
