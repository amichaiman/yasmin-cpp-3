#include "Simulation.h"
#include "Point.h"
#include <fstream>
#include <iostream>

void Simulation::run() {
    for (curTime=0; curTime < totalTime && !field.hasPlayerInDestination(); curTime++){
        update();
    }
    printResults();
}

Simulation::Simulation(): curTime(0) {}

bool Simulation::config(char* fileName) {
    ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        return false;
    }
    Point goalDestination;
    file >> goalDestination.x >> goalDestination.y;
    if (!fileStateIsGood(file) || file.eof()){
        return false;
    }
    field.setGoalDestination(goalDestination);
    team.setDestinationPoint(goalDestination);
    file >> totalTime;
    return fileStateIsGood(file) ;
}

bool Simulation::init(char* fileName) {
    ifstream file;
    file.open(fileName);

    if (!file.is_open()) {
        return false;
    }

    int numOfPlayers;
    file >> numOfPlayers;

    if (!fileStateIsGood(file) || file.eof()){
        return false;
    }
    if (!team.setNumOfPlayers(numOfPlayers)){ //function returns false if number of players isn't valid
        return false;
    }

    Point startingPoint;
    Speed startingSpeed;

    for (int i=0; i<numOfPlayers; i++){
        file >> startingPoint.x >> startingPoint.y >> startingSpeed.speedX >> startingSpeed.speedY;
        if (!fileStateIsGood(file)){
            return false;
        }
        if (i!=numOfPlayers-1 && file.eof()) {
            return false;
        }
        Player player(startingPoint, startingSpeed, i);
        team.setPlayer(player, i);
    }
    return file.eof();
}

bool Simulation::fileStateIsGood(const ifstream &file) {
    return !file.fail() && !file.bad();
}

void Simulation::update() {
    team.update();
    field.update(team);
}

void Simulation::printResults() {
    cout << curTime << endl;
    team.printPlayersLocations();
}

Simulation::~Simulation() { }

Simulation &Simulation::operator=(const Simulation &rhs) {
    curTime = rhs.getCurTime();
    totalTime = rhs.getTotalTime();
    field = rhs.getField();
    team = rhs.getTeam();
    return *this;
}

int Simulation::getCurTime() const {
    return curTime;
}

int Simulation::getTotalTime() const {
    return totalTime;
}

const Field &Simulation::getField() const {
    return field;
}

const Team &Simulation::getTeam() const {
    return team;
}
