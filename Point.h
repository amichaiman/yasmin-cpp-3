//
// Created by amichai on 29/11/18.
//

#ifndef YASMIN_CPP_3_POINT_H
#define YASMIN_CPP_3_POINT_H


class Speed;

class Point {
public:
    double x,y;
    Point operator+(const Speed &rhs) const;
    Point operator-(const Point &rhs) const;
    Point operator*(const double &n) const;
    double distanceFrom(const Point& point) const;
};


#endif //YASMIN_CPP_3_POINT_H
