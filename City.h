#ifndef CITY_H
#define CITY_H

#include "Person.h"
#include "Plotter.h"
#include <vector>
#include <string>

class City {
    private:
        std::vector <Person> people;
        int nIter;
        double dt;
        double boxSize;
        double recoveryTime;
        void MovePeople();
        void CityBoundary(int);
        void Infection();
        void IncreaseTimeR();
    public:
        City(bool);
        City(int, double, double, double, std::string, int);
        std::string select_input();
        void parseParameters(int argc, char * argv[]);
        int NumberPeople;
        std::vector <Person> get_people();
        int get_NumberPeople();
        void run_selected_input(std::string);
        void testConfiguration();
        void randomConfiguration(int);
        bool readConfiguration();
        void round();
        void evolution(bool);
        void outputConfiguration();
};

#endif