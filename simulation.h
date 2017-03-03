//
// Created by kamre on 03.03.2017.
//

#ifndef GAMEOFLIFE_SIMULATION_H
#define GAMEOFLIFE_SIMULATION_H


#include "data.h"

int findAliveNeighbours(gen life, int x, int y);

gen jumpToNextGeneration(gen life);

#endif //GAMEOFLIFE_SIMULATION_H
