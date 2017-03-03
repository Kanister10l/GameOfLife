#include <stdlib.h>
#include <time.h>
#include "data.h"

//
// Created by kamre on 03.03.2017.
//
void createRandomGeneration(gen life, double probability){
    srand(time(NULL));
    double chance;

    for (int i = 0; i < life->x; ++i) {
        for (int j = 0; j < life->y; ++j) {
            chance = (double)rand()/RAND_MAX;
            if (chance < probability)
                life->matrix[i][j] = 1;
            else
                life->matrix[i][j] = 0;
        }
    }
}