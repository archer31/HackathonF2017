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
  Ai();
  void print(std::ostream&) const;
  bool solve();
  void load_grid(std::istream&);
  private:
  class Constraint;
  class Variable {
    public:
    Variable();
    std::vector<int> domain;
    std::vector<Constraint> cons;
  };
  class Constraint {
    public:
    Variable& var;
  };
	size_t size;
  std::vector<Variable> vars;
  size_t iters;

  void fill_cons();
	void fill_vars();
};

#endif //AI_H
