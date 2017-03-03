//
// Created by kamre on 03.03.2017.
//
#include <stdio.h>
#include <malloc.h>
#include "data.h"
#include "config.h"
#include "simulation.h"

int main(){
    conf config = malloc(sizeof * config);
    readConfig(config);
    printf("%d",config->gifAfterYears);
    gen life = createMatrix(30,30,0);
    life = jumpToNextGeneration(life);
    return 0;
}
