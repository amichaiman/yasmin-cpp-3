//
// Created by amichai on 29/11/18.
//

#ifndef YASMIN_CPP_3_SIMULATION_H
#define YASMIN_CPP_3_SIMULATION_H

#include <string>
#include <fstream>
#include "Field.h"
#include "Team.h"

using namespace std;
class Simulation {
public:
    Simulation();
    virtual ~Simulation();
    Simulation& operator=(const Simulation &rhs);
    void run();
    bool config(char* fileName);
    bool init(char* fileName);

    /* getters */
    int getCurTime() const;
    int getTotalTime() const;
    const Field &getField() const;
    const Team &getTeam() const;
private:
    int curTime;
    int totalTime;
    Field field;
    Team team;
    void update();
    void printResults();
    bool fileStateIsGood(const ifstream &file);
};

#endif //YASMIN_CPP_3_SIMULATION_H
