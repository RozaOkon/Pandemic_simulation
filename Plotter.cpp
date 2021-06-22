#include<iostream>
#include<vector>
#include <string>
#include <sstream>
#include "matplotlibcpp.h"
#include "Plotter.h"
#include "Person.h"

namespace plt = matplotlibcpp;

void Plotter::plot(double iTime, int NumberPeople, std::vector <Person> people, double BoxSize){
  std::vector <double> vec_x(1);
  std::vector <double> vec_y(1);
  plt::xlim(0., BoxSize);
  plt::ylim(0., BoxSize);

  for (int j = 0; j < people.size(); j++){
    vec_x.push_back(people.at(j).get_position_x());
    vec_y.push_back(people.at(j).get_position_y());
    
    if (people.at(j).get_color() == "green"){
      plt::scatter(vec_x, vec_y, people.at(j).get_radius() * 2000, {{"color", "green"}});
    }

    if (people.at(j).get_color() != "green"){
      plt::scatter(vec_x, vec_y, people.at(j). get_radius() * 2000, {{"color", "red"}});
    }
    
    if (people.at(j).get_color() == "blue"){
      plt::scatter(vec_x, vec_y, people.at(j).get_radius() * 2000, {{"color", "blue"}});
    }

  vec_x.clear();
  vec_y.clear();
  }

  std::stringstream sstream;
  sstream.fill('0');
  sstream.width(4);
  sstream << iTime;
  std::string fileName = "./plots/frame_" + sstream.str() + ".png";
  plt::save(fileName);
  plt::close();

  vec_x.clear();
  vec_y.clear();
}

void Plotter::MakeAnimation(){
  system("convert -delay 0.01 -loop 0 frame*.png animation.gif");
}

