#include <iostream>
#include <cstdlib>
#include "Simulation.h"
#include <ctime>

using namespace std;

int main(int argc, char **argv) {
    srand(static_cast<unsigned int>(time(NULL)));

    if (argc != 3){
        cerr << "ERROR: Invalid input." << endl;
        exit(1);
    }

    Simulation simulation;

    if (!simulation.config(argv[1]) || !simulation.init(argv[2])){
        cerr << "ERROR: Invalid input." << endl;
        exit(2);
    }

    simulation.run();
    return 0;
}