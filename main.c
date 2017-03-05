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
    createRandomGeneration(life, config->probability);
    gen *lifes = simulateAllGenerations(life, config->gifAfterYears);   //lifes to tablica generacji do gif
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            printf("%d",lifes[99]->matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
