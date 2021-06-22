#ifndef PLOTTER_H
#define PLOTTER_H

#include "Person.h"
#include <vector>

class Plotter{
  public:
  void plot(double, int, std::vector <Person>, double);
  void MakeAnimation();
};

#endif