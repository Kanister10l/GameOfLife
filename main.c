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
    gen life = createMatrix(config->xSize, config->ySize, config->edgeType);

    if (config->load_from_file == 1 && config->isRandom != 1){
        FILE *input = fopen(config->load_file_name, "r");
        if (input == NULL){
            printf("Could not open input file: %s, generating random base generation.", config->load_file_name);
            createRandomGeneration(life, config->probability);
        }
        else
            loadGenerationFromFile(input, life);
        fclose(input);
    }
    if (config->isRandom == 1)
        createRandomGeneration(life, config->probability);

    gen *lifes = simulateAllGenerations(life, config->gifAfterYears);

    if(config->save_to_file == 1){
        FILE *output = fopen(config->save_file_name, "w");
        if (output == NULL)
            printf("Could not open output file: %s", config->save_file_name);
        else if (config->generation_to_save >= config->gifAfterYears)
            printf("Number of generation to save: %d exceeds life length: %d", config->generation_to_save, config->gifAfterYears);
        else
            saveGenerationToFile(output, lifes[config->generation_to_save]);
        fclose(output);
    }

    prepareGif(config, config->gif_name, lifes);

    for (int i = 0; i < config->gifAfterYears; ++i)
        freeMatrix(lifes[i]);
    free(lifes);

    return 0;
}
