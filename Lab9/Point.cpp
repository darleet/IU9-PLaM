//
// Created by darleet on 5/18/23.
//

#include <cmath>
#include "Point.h"

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

double Point::getX() const {
    return this->x;
}

double Point::getY() const {
    return this->y;
}

double Point::getZ() const {
    return this->z;
}

double Point::dist(const Point& p) const {
    double d1 = this->x - p.getX();
    double d2 = this->y - p.getY();
    double d3 = this->z - p.getZ();
    return sqrt(d1*d1 + d2*d2 + d3*d3);
}

Point::~Point() = default;
