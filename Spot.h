//
// Created by amichai on 29/11/18.
//

#ifndef YASMIN_CPP_3_SPOT_H
#define YASMIN_CPP_3_SPOT_H


#include "Team.h"

class Spot {
public:
    int getNumOfPlayers();
    bool hasPlayerInSpot(Player player, int i, int j);
    void setNumOfPlayers(int numOfPlayers);
    Spot& operator++(int);
    Spot& operator--(int);

private:
    int numOfPlayers;

};


#endif //YASMIN_CPP_3_SPOT_H
