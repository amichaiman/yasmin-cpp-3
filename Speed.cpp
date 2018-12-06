//
// Created by amichai on 29/11/18.
//

#include "Speed.h"
#include "Point.h"

Speed Speed::operator*(const double &n) const {
    Speed newSpeed;
    newSpeed.speedX = speedX*n;
    newSpeed.speedY = speedY*n;
    return newSpeed;
}

Speed Speed::operator+(const Point &rhs) const {
    Speed newSpeed;
    newSpeed.speedX = speedX + rhs.x;
    newSpeed.speedY = speedY + rhs.y;
    return newSpeed;
}
