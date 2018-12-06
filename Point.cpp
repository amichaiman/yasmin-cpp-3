//
// Created by amichai on 29/11/18.
//

#include <cmath>
#include "Point.h"
#include "Speed.h"
#include "Field.h"

Point Point::operator+(const Speed &rhs) const {

    Point newPoint;
    newPoint.x = x+rhs.speedX;
    newPoint.y = y+rhs.speedY;

    if (newPoint.x < 0) {
        newPoint.x = 0;
    }
    if (newPoint.y < 0) {
        newPoint.y = 0;
    }
    if (newPoint.x > Field::FIELD_SIZE_X_PLANE) {
        newPoint.x = Field::FIELD_SIZE_X_PLANE;
    }
    if (newPoint.y > Field::FIELD_SIZE_Y_PLANE) {
        newPoint.y = Field::FIELD_SIZE_Y_PLANE;
    }
    return newPoint;
}

Point Point::operator-(const Point &rhs) const {
    Point newPoint;
    newPoint.x = x-rhs.x;
    newPoint.y = y-rhs.y;

    return newPoint;
}

Point Point::operator*(const double &n) const {
    Point newPoint;
    newPoint.x = x*n;
    newPoint.y = y*n;

    return newPoint;
}

double square(double n) {
    return n*n;
}

double Point::distanceFrom(const Point &point) const {
    return sqrt(square(x-point.x) + square(y-point.y));
}
