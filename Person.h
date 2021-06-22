#ifndef PERSON_H
#define PERSON_H

class Person {
    private:
        double position_x;
        double position_y;
        double velocity_x;
        double velocity_y;
        double radius;
        std::string color;
        double timeR;
    public:
      Person();
      Person(double, double, double, double, double, std::string, double);
      void set_position(double, double);
      void set_velocity(double, double);
      void set_radius(double);
      void set_color(std::string);
      void set_timeR(double);
      void set(double, double, double, double, double, std::string, double);
      double get_position_x();
      double get_position_y();
      double get_velocity_x();
      double get_velocity_y();
      double get_radius();
      std::string get_color();
      double get_timeR();
      void print();

};

#endif
