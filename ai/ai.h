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
  void solve();
  void load_grid(std::istream&);
  private:
	size_t size;
  std::vector<std::vector<int> > variables;
  size_t iters;

	void fill_vars();
};

#endif //AI_H
