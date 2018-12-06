//
// Created by amichai on 29/11/18.
//

#include <cstdlib>
#include <iostream>
#include "Player.h"

Player::Player(Point point, Speed speed, int id) {
    Player::currentLocation = point;
    Player::personalBest = currentLocation;
    Player::speed = speed;
    Player::id = id;
}
Player::Player() { }

Player &Player::operator=(const Player &rhs) {
    if (&rhs == this){
        return *this;
    }
    Player::speed = rhs.getSpeed();
    Player::currentLocation = rhs.getCurrentLocation();
    Player::personalBest = rhs.getPersonalBest();
    Player::id = rhs.getId();
    return *this;
}

int Player::getId() const {
    return id;
}

const Point &Player::getPersonalBest() const {
    return personalBest;
}

const Speed &Player::getSpeed() const {
    return speed;
}

const Point &Player::getCurrentLocation() const {
    return currentLocation;
}

double r() {
    return static_cast<double>(rand())/RAND_MAX;
}

void Player::update(const Player &globalBest) {
    Speed newSpeed = speed*0.25 + (globalBest.getCurrentLocation()-currentLocation)*r()
            + (personalBest-currentLocation)*r();
    currentLocation = currentLocation+speed;
    speed = newSpeed;
}






