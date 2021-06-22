#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include "Person.h"

Person::Person(){
  this -> position_x = 0;
  this -> position_y = 0;
  this -> velocity_x = 0;
  this -> velocity_y = 0;
  this -> radius = 0;
  this -> color = "0";
  this -> timeR = 0;
}

Person::Person(double position_x, double position_y, double velocity_x, double velocity_y, double radius, std::string color, double timeR){
  this -> position_x = position_x;
  this -> position_y = position_y;
  this -> velocity_x = velocity_x;
  this -> velocity_y = velocity_y;
  this -> radius = radius;
  this -> color = color;
  this -> timeR = timeR;
}

void Person::set_position(double position_x, double position_y){
  this -> position_x = position_x;
  this -> position_y = position_y;
}

void Person::set_velocity(double velocity_x, double velocity_y){
  this -> velocity_x = velocity_x;
  this -> velocity_y = velocity_y;
}

void Person::set_radius(double radius){
  this -> radius = radius;
}

void Person::set_color(std::string color){
  this -> color = color; 
}

void Person::set_timeR(double timeR){
  this -> timeR = timeR; 
}

void Person::set(double position_x, double position_y, double velocity_x, double velocity_y, double radius, std::string color, double timeR){
  this -> position_x = position_x;
  this -> position_y = position_y;
  this -> velocity_x = velocity_x;
  this -> velocity_y = velocity_y;
  this -> radius = radius;
  this -> color = color;
  this -> timeR = timeR;  
}

void Person::print(){
  std::cout << "Position: [" << this -> position_x << ", " << this -> position_y << "]" << std::endl;
  std::cout << "Velocity: [" << this -> velocity_x << ", " << this -> velocity_y << "]" << std::endl;
  std::cout << "Radius: " << radius << std::endl;
  std::cout << "Color: " << color << std::endl;
  std::cout << "Time: " << timeR << std::endl;
} 

double Person::get_position_x(){
  return this -> position_x;
}

double Person::get_position_y(){
  return this -> position_y;
}

double Person::get_velocity_x(){
  return this -> velocity_x;
}

double Person::get_velocity_y(){
  return this -> velocity_y;
}

double Person::get_radius(){
  return this -> radius;
}

std::string Person::get_color(){
  return this -> color;
}

double Person::get_timeR(){
  return this -> timeR;
}
