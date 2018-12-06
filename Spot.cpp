//
// Created by amichai on 29/11/18.
//

#include "Spot.h"

int Spot::getNumOfPlayers() {
    return numOfPlayers;
}

bool Spot::hasPlayerInSpot(Player player, int i, int j) {
    return player.getCurrentLocation().y >= i &&
           player.getCurrentLocation().y < i+1 &&
           player.getCurrentLocation().x >= j &&
           player.getCurrentLocation().x < j+1;


}

Spot &Spot::operator++(int) {
    numOfPlayers++;
    return *this;
}

Spot &Spot::operator--(int) {
    numOfPlayers--;
    return *this;
}
void Spot::setNumOfPlayers(int numOfPlayers) {
    Spot::numOfPlayers = numOfPlayers;
}
