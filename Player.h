//
// Created by amichai on 29/11/18.
//

#ifndef YASMIN_CPP_3_PLAYER_H
#define YASMIN_CPP_3_PLAYER_H


#include "Point.h"
#include "Speed.h"

class Player {
public:
    Player(Point point, Speed speed, int id);
    Player();
    Player& operator=(const Player &rhs);
    const Speed &getSpeed() const;
    const Point &getCurrentLocation() const;
    const Point &getPersonalBest() const;
    int getId() const;

    void update(const Player &globalBest);

private:
    int id;
    Point currentLocation;
    Point personalBest;
    Speed speed;

};


#endif //YASMIN_CPP_3_PLAYER_H
