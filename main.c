//
// Created by kamre on 03.03.2017.
//
#include <stdio.h>
#include <malloc.h>
#include "data.h"
#include "config.h"
#include "simulation.h"
#include "random.h"
#include "preparegif.h"

int main(){
    conf config = malloc(sizeof * config);
    readConfig(config);

    int width=100, height=100; //wielkosc planszy

    gen life = createMatrix(width,height,0);
    createRandomGeneration(life, config->probability);
    gen *lifes = simulateAllGenerations(life, config->gifAfterYears);   //lifes to tablica generacji do gif

    prepareGif(width,height,"anim.gif",config->gifAfterYears,lifes);
    return 0;
}
