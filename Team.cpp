//
// Created by amichai on 29/11/18.
//

#include "Team.h"
#include <iostream>
#include <climits>

using namespace std;

bool Team::setNumOfPlayers(const int numOfPlayers) {
    if (numOfPlayers < MIN_PLAYERS || numOfPlayers > MAX_PLAYERS){
        return false;
    }
    Team::numOfPlayers = numOfPlayers;
    players = new Player[numOfPlayers];
    return true;
}


void Team::setPlayer(Player player, int i) {
    players[i] = player;
}

void Team::printPlayersLocations() {
    for (int i=0; i<numOfPlayers; i++){
        cout << players[i].getCurrentLocation().x << " " <<  players[i].getCurrentLocation().y;
        if (i != numOfPlayers-1) {
            cout << endl;
        }
    }
}

void Team::update() {
    updateGlobalBestPlayerId();
    for (int i=0; i<numOfPlayers; i++){
        players[i].update(players[globalBestPlayerId]);
    }
}

int Team::getNumberOfPlayers() const{
    return numOfPlayers;
}

Player Team::getPlayer(int i) const{
    return players[i];
}

void Team::updateGlobalBestPlayerId() {
    double shortestDistanceFromDestination = INT_MAX;
    double currentDistanceFromDestination;

    for (int i=0; i<numOfPlayers; i++){
        currentDistanceFromDestination = players[i].getCurrentLocation().distanceFrom(destinationPoint);
        if (currentDistanceFromDestination < shortestDistanceFromDestination) {
            shortestDistanceFromDestination = currentDistanceFromDestination;
            globalBestPlayerId = i;
        }
    }
}

void Team::setDestinationPoint(Point destinationPoint) {
    Team::destinationPoint = destinationPoint;
}
