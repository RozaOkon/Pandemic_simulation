#include "Person.h"
#include "Plotter.h"
#include "City.h"
#include <iostream>
#include <sstream>

int main(int argc, char * argv[]){
  if (argc == 1){
    City mycity(false);
    mycity.evolution(true);
  }
  else{
    City mycity(true);
    mycity.parseParameters(argc, argv);
  }
  return 0;
}