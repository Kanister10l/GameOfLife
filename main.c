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
#include "saved_state.h"

int main(){
    conf config = malloc(sizeof * config);
    readConfig(config);
    FILE *output = fopen(config->save_file_name, "w");
    FILE *input = fopen(config->load_file_name, "r");
    gen life = createMatrix(config->xSize,config->ySize,0);
    createRandomGeneration(life, config->probability);
    //loadGenerationFromFile(input, life);
    saveGenerationToFile(output, life);
    fclose(output);
    fclose(input);

    gen *lifes = simulateAllGenerations(life, config->gifAfterYears);   //lifes to tablica generacji do gif

    prepareGif(config,"test.gif",lifes);
    return 0;
}
