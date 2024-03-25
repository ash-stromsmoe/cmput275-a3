#ifndef MOTION2D
#define MOTION2D
#include <iostream>

// Predefined constant for pi, to be used if/when converting degrees
// to radians.
#define PI  3.14159265

// Forward declation of Force. Needed in case any of Point references
// the existence of type Force.
class Force;

class Point {
  int x, y;
  Point(float init_x, float init_y);
  public:
  Point();
  Point &operator+(Force &);
  int quadrant();
  friend std::istream &operator>>(std::istream &, Point &);
  friend std::ostream &operator<<(std::ostream &, const Point &);
  
};

class Force {
  Force(float init_angle, float init_magnitude);
  public:
  float angle, magnitude;
  Force();
  Force &operator*(int scalar);
  friend std::istream &operator>>(std::istream &, Force &);
  friend std::ostream &operator<<(std::ostream &, const Force &);
  

};

#endif