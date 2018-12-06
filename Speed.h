//
// Created by amichai on 29/11/18.
//

#ifndef YASMIN_CPP_3_SPEED_H
#define YASMIN_CPP_3_SPEED_H

class Point;

class Speed {
public:
    Speed operator*(const double &n) const;
    Speed operator+(const Point &rhs) const;
    double speedX, speedY;
};


#endif //YASMIN_CPP_3_SPEED_H
