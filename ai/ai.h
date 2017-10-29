//ai.h
//Author: Alexander Corley, Jacob Hanson, Ryan Lynn
//10-28-2017
#ifndef AI_H
#define AI_H

#include <vector>
#include <iostream>
using std::size_t;
using std::vector;

class Ai {
  public:
  Ai(size_t);
  Ai();
  void print(std::ostream&, std::ostream&);
  bool solve();
  void load_grid(std::istream&);
  bool is_solved();
  private:
  class Variable;
  class Constraint {
    public:
    Constraint(Variable* l, Variable* r): left(l), right(r) {};
    Variable *left = nullptr, *right = nullptr;
  };
  class Variable {
    public:
    std::vector<int> domain;
    std::vector<Constraint> cons;
  };
	size_t size;
  std::vector<Variable> vars;
  size_t iters = 0;
  bool solved = false;
  size_t backTracks = 0;
  size_t guessesTaken = 0;

  size_t make_guess();

  void fill_cons();
	void fill_vars();
  Variable& get_pos(size_t, size_t);
};

#endif //AI_H
