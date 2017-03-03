//
// Created by kamre on 03.03.2017.
//
#include <stdio.h>
#include <malloc.h>
#include "data.h"
#include "config.h"
#include "simulation.h"
#include "random.h"

int main(){
    conf config = malloc(sizeof * config);
    readConfig(config);
    gen life = createMatrix(100,100,0);
    createRandomGeneration(life, 0.3);
    gen *lifes = simulateAllGenerations(life, config->gifAfterYears);
    for (int i = 0; i < lifes[99]->x; ++i) {
        for (int j = 0; j < lifes[99]->y; ++j) {
            printf("%d", lifes[5]->matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
