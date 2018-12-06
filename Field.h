//
// Created by amichai on 29/11/18.
//

#ifndef YASMIN_CPP_3_FIELD_H
#define YASMIN_CPP_3_FIELD_H


#include "Point.h"
#include "Spot.h"
#include "Team.h"

class Field {
public:
    Field();
    static const int FIELD_SIZE_X_PLANE = 61;
    static const int FIELD_SIZE_Y_PLANE = 30;
    void setGoalDestination(const Point &goalDestination);
    bool hasPlayerInDestination();

    void update(const Team &team);

private:
    Point goalDestination;
    Spot field[FIELD_SIZE_Y_PLANE][FIELD_SIZE_X_PLANE];
    Spot *destinationSpot;
};


#endif //YASMIN_CPP_3_FIELD_H
