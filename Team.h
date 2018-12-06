//
// Created by amichai on 29/11/18.
//

#ifndef YASMIN_CPP_3_TEAM_H
#define YASMIN_CPP_3_TEAM_H


#include "Player.h"

class Team {
public:
    static const int MAX_PLAYERS = 100;
    static const int MIN_PLAYERS = 2;
    bool setNumOfPlayers(int numOfPlayers);
    void setPlayer(Player player, int i);

    void printPlayersLocations();

    void update();

    int getNumberOfPlayers() const;

    Player getPlayer(int i) const;

    void setDestinationPoint(Point destinationPoint);

private:
    int numOfPlayers;
    Player *players;
    int globalBestPlayerId;
    void updateGlobalBestPlayerId();
    Point destinationPoint;
};


#endif //YASMIN_CPP_3_TEAM_H
