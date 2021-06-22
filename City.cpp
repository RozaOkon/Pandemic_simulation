#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <stdlib.h>
#include "Person.h"
#include "Plotter.h"
#include "City.h"



City::City(bool parse){
  if (parse == false){
    std::string input_type = City::select_input();
    if (input_type == "test"){
      nIter = 50;
      dt = 0.02;
      boxSize = 0.25;
      recoveryTime = 0.5;
      NumberPeople = 3;
    }
    else if (input_type == "random"){
      nIter = 50;
      dt = 0.02;
      boxSize = 1;
      recoveryTime = 0.7;
    }
    else if (input_type == "file"){
      nIter = 50;
      dt = 0.02;
      boxSize = 1;
      recoveryTime = 0.7;
    }
    City::run_selected_input(input_type);
  }
  else{
  }
}

City::City(int nIter, double dt, double boxSize, double recoveryTime, std::string input_type, int NumberPeople){
  this -> nIter = nIter;
  this -> dt = dt;
  this -> boxSize = boxSize;
  this -> recoveryTime = recoveryTime;
  this -> NumberPeople = NumberPeople;
  if (input_type != "random"){
    City::run_selected_input(input_type);

  }
  else{
    City::randomConfiguration(NumberPeople);
  }
}

std::string City::select_input(){
  std::string input_type;
  std::cout << "Select citizens parameters input: " << std::endl;
  std::cout << "Run test version - enter 'test'" << std::endl;
  std::cout << "Set random parameters - enter 'random'" << std::endl;
  std::cout << "Read parameters from a file - enter 'file'" << std::endl;
  std::cin >> input_type;
  return input_type;
}
void City::run_selected_input(std::string input_type){
  if (input_type == "test"){
    City::testConfiguration();
  }
  else if (input_type == "random"){
      City::randomConfiguration(City::get_NumberPeople());
  }
  else if (input_type == "file"){
      City::readConfiguration();
  }  
  else {
    std::cout << "Invalid input" << std::endl;
    City::select_input();
  }
}

void City::testConfiguration(){
    NumberPeople = 3;
    Person Person_1(0.1, 0.2, 0.1, 0.2, 0.02, "green", 0);
    Person Person_2(0.1, 0.1, 0.5, 0.3, 0.05, "green", 0);
    Person Person_3(0.2, 0.1, 0.3, 0.6, 0.03, "red", 0);
    people.push_back(Person_1);
    people.push_back(Person_2);
    people.push_back(Person_3);
}

int City::get_NumberPeople(){
    std::cout << "Enter number of citizens: " << std::endl;
    std::cin >> NumberPeople;
    return NumberPeople;
}

void City::randomConfiguration(int NumberPeople){ 
    for (int i = 0; i < NumberPeople; i++){
      Person Person_i;
      people.push_back(Person_i);
    }

    for (int i = 0; i < NumberPeople; i++){
      std::random_device rd;
      std::mt19937 generator(rd());
      std::uniform_real_distribution<double> random_position(0.05, 0.95);
      std::uniform_real_distribution<double> random_velocity(-0.5, 0.5);
      std::uniform_real_distribution<double> random_radius(0.01, 0.05);
      people.at(i).set_position(random_position(generator), random_position(generator));
      people.at(i).set_velocity(random_velocity(generator), random_velocity(generator));
      people.at(i).set_radius(random_radius(generator));
    }
    for (int i = 0; i < 0.9 * NumberPeople; i++){
      people.at(i).set_color("green");
    }
    for (int i = 0.9 * NumberPeople; i < NumberPeople; i++){
      people.at(i).set_color("red");
    }
}

bool City::readConfiguration(){
  std::ifstream inp("input_configuration.txt");

  bool reading_status;
  if (inp.fail()){
    reading_status = false;
    std::cout << "No file found. Select other input." << std::endl;
    std::cout << "Run test version - enter 'test" << std::endl;
    std::cout << "Set random parameters - enter 'random'" << std::endl;
    std::string input_type;
    std::cin >> input_type;
    if (input_type == "test"){
      City::testConfiguration();
    }
    else if (input_type == "random"){
        City::randomConfiguration(City::get_NumberPeople());
    }
    else{
      std::cout << "Invalid input" << std::endl;
    }
  }

  else{
    double input_position_x, input_position_y, input_velocity_x, input_velocity_y, input_radius;
    std::string input_color;
    reading_status = true;
    int NumberPeople = 0;
    while (true){
      inp >> input_position_x >> input_position_y >> input_velocity_x >> input_velocity_y >> input_radius >> input_color; 
      NumberPeople += 1;
      if(inp.fail()){
        break; 
      }
    }
    inp.close();

    for (int i = 0; i < NumberPeople; i++){
      Person Person_i;
      people.push_back(Person_i);
    }

    inp.open("input_configuration.txt");
    int i = 0;
    while (true){
      inp >> input_position_x >> input_position_y >> input_velocity_x >> input_velocity_y >> input_radius >> input_color;
      if(inp.fail()){
        break; 
      }
      people.at(i).set_position(input_position_x, input_position_y);
      people.at(i).set_velocity(input_velocity_x, input_velocity_y);
      people.at(i).set_radius(input_radius);
      people.at(i).set_color(input_color);
      i += 1;
    }
    people.pop_back();
    inp.close();
  }
  return reading_status;
}

void City::parseParameters(int argc,  char * argv[]){
  bool flag_nIter = false;
  bool flag_dt = false;
  bool flag_boxSize = false;
  bool flag_recoveryTime = false;
  bool flag_input = false;
  bool flag_nPeople = false;
  int nIter;
  std::string input_type, output_string, doFrames_string;
  int NumberPeople = 0;
  double dt, boxSize, recoveryTime; 
  bool output = false; 
  bool doFrames = true;

  for (int i = 0; i < argc; i++){
    std::istringstream i_value(argv[i]);
    std::string i_string;
    i_value >> i_string;
    if (i_string == "--nIter"){
      flag_nIter = true; 
      std::istringstream nIter_input(argv[i+1]); 
      nIter_input >> nIter;   
    }
    if (i_string == "--dt"){
      flag_dt = true;
      std::istringstream dt_input(argv[i+1]);
      dt_input >> dt;
    }
    if (i_string == "--boxSize"){
      flag_boxSize = true;
      std::istringstream boxSize_input(argv[i+1]);
      boxSize_input >> boxSize;
    }
    if (i_string == "--recoveryTime"){
      flag_recoveryTime = true;
      std::istringstream recoveryTime_input(argv[i+1]);
      recoveryTime_input >> recoveryTime;
    }
    if (i_string == "--input"){
      flag_input = true;
      std::istringstream input_type_input(argv[i+1]);
      input_type_input >> input_type;
    }
    if (i_string == "--nPeople"){
      flag_nPeople = true;
      std::istringstream nPeople_input(argv[i+1]);
      nPeople_input >> NumberPeople;
    }
    if (i_string == "--output"){
      std::istringstream output_input(argv[i+1]);
      output_input >> output_string;
      if (output_string == "true"){
        output = true;
      }
      else {
        output = false;
      }
    }
    if (i_string == "--doFrames"){
      std::istringstream doFrames_input(argv[i+1]);
      doFrames_input >> doFrames_string;
      if (doFrames_string == "false"){
        doFrames = false;
      }
      else {
        output = true;
      }
    }
  }

  if (flag_nIter == false){
    nIter = 50;
    std::cout << "You did not specified the number of iterations. Taking a default value nIter = 50." << std::endl;
  }
  if (flag_dt == false){
    dt = 0.02;
    std::cout << "You did not specified the time step. Taking a default value dt = 0.02." << std::endl;
  }
  if (flag_boxSize == false){
    boxSize = 1;
    std::cout << "You did not specified the size of the city. Taking a default value boxSize = 1." << std::endl;
  }
  if (flag_recoveryTime == false){
    recoveryTime = 0.7;
    std::cout << "You did not specified the recovery time. Taking a default value recoveryTime = 0.7." << std::endl;
  }
  if (flag_input == false){
    std::cout << "You did not specified the input type" << std::endl;
    City::select_input();
  }

  if (input_type == "random" && flag_nPeople == false){
      std::cout << "Nie podano liczby osob." << std::endl;
      NumberPeople = City::get_NumberPeople();
  }
  City mycity(nIter, dt, boxSize, recoveryTime, input_type, NumberPeople);
  mycity.evolution(doFrames);

  if (output == true){
    mycity.outputConfiguration();
  }
}

void City::MovePeople(){
  for (int iTime = 0; iTime < people.size(); iTime++){
    people.at(iTime).set_position(people.at(iTime).get_position_x() + dt * people.at(iTime).get_velocity_x(), people.at(iTime).get_position_y() + dt * people.at(iTime).get_velocity_y());
    City::CityBoundary(iTime);
  }
}


void City::CityBoundary(int iTime){
    if(
      people.at(iTime).get_position_x() + people.at(iTime).get_radius() >= boxSize || people.at(iTime).get_position_x() - people.at(iTime).get_radius() <= 0)
      {
        people.at(iTime).set_velocity(people.at(iTime).get_velocity_x() * (-1), people.at(iTime).get_velocity_y());
      }

    if(
      people.at(iTime).get_position_y() + people.at(iTime).get_radius() >= boxSize || people.at(iTime).get_position_y() - people.at(iTime).get_radius() <= 0){
        people.at(iTime).set_velocity(people.at(iTime).get_velocity_x(), people.at(iTime).get_velocity_y() * (-1));
      }
}

void City::Infection(){
  for (int i = 0; i < people.size(); i++){
    for (int j = 0; j < people.size(); j++){
      if(j != i){
        if (sqrt(pow(people.at(i).get_position_x() - people.at(j).get_position_x(), 2) + pow(people.at(i).get_position_y() - people.at(j).get_position_y(), 2)) <= people.at(j).get_radius()){
          if (people.at(j).get_color() == "red" && people.at(i).get_color() == "green"){
            people.at(i).set_color("red");
          }
        }
      }
    }
  }
}

void City::IncreaseTimeR(){
  for (int i = 0; i < people.size(); i++){
    if (people.at(i).get_color() == "red"){
      people.at(i).set_timeR(people.at(i).get_timeR() + dt);

      if (people.at(i).get_timeR() >= recoveryTime){
        people.at(i).set_color("blue");
      }
    }
  }
}

void City::round(){
  City::MovePeople();
  City::Infection();
  City::IncreaseTimeR();
}

void City::evolution(bool doFrames){
  Plotter myplotter;
  if (doFrames == true){
    for (int i = 0; i < nIter; i++){
      myplotter.plot(i, NumberPeople, people, boxSize);
      City::round();
    }
    myplotter.MakeAnimation();
  }
  else {
    City::round();
  }
}

void City::outputConfiguration(){
  std::ofstream out("output_configuration.txt");
  for (int i = 0; i < people.size(); i++){
    out << people.at(i).get_position_x() << ", " << people.at(i).get_position_y() << ", " << people.at(i).get_velocity_x() << ", " << people.at(i).get_velocity_y() << ", " << people.at(i).get_radius() << ", " << people.at(i).get_color() << std::endl;
  }
}
