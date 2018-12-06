//
// Created by amichai on 29/11/18.
//

#include <cmath>
#include <iostream>
#include "Field.h"

void Field::setGoalDestination(const Point &goalDestination) {
    Field::goalDestination = goalDestination;
    destinationSpot = &field[static_cast<int>(goalDestination.y)][static_cast<int>(goalDestination.x)];
}

Field::Field() {}

bool Field::hasPlayerInDestination() {
    return destinationSpot->getNumOfPlayers() != 0;
}

void Field::update(const Team &team) {
    for (int i=0; i<FIELD_SIZE_Y_PLANE; i++){
        for (int j=0; j<FIELD_SIZE_X_PLANE; j++){
            field[i][j].setNumOfPlayers(0);
            for (int k=0; k<team.getNumberOfPlayers(); k++) {
                if (field[i][j].hasPlayerInSpot(team.getPlayer(k), i, j)){
                    field[i][j]++;
                }
            }
        }
    }
}
