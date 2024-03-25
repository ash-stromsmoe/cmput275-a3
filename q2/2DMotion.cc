#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>
#include "2DMotion.h"

using namespace std;

Point::Point() : x{0}, y{0} {};
Point::Point(float init_x, float init_y) : x{init_x}, y{init_y} {};

Point &Point::operator+(Force &f) {
    float x_disp;
    float y_disp;
    x_disp = cos((f.angle)*(PI/180));
    y_disp = sin((f.angle)*(PI/180));
    Point p{x+x_disp,y+y_disp};
    return p;
};


int Point::quadrant() {
    if(x > 0 && y > 0) {
        return 1;
    } 
    else if(x < 0 && y > 0) {
        return 2;
    }
    else if(x < 0 && y < 0) {
        return 3;
    }
    else if(x > 0 && y < 0) {
        return 4;
    }
    else return 0;
};

ostream &operator<<(ostream &out, const Point &p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

istream &operator>>(istream &in, Point &p) {
    in >> p.x >> p.y;
    return in;
}

Force::Force() :angle{0}, magnitude{0} {};

Force::Force(float init_angle, float init_magnitude) : angle{init_angle}, magnitude{init_magnitude} {};

istream &operator>>(istream &in, Force &f) {
    in >> f.angle >> f.magnitude;
    return in;
}

ostream &operator<<(ostream &out, const Force &f) {
    out << f.angle << " degrees with magnitude of " << f.magnitude;
    return out;
};

Force &Force::operator*(int scalar) {
    float newMagnitude = magnitude*scalar;
    Force f{angle, newMagnitude};
    return f;
};





