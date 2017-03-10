//
// Created by kamre on 10.03.2017.
//

#include <stdio.h>
#include "saved_state.h"
#include "data.h"

void saveGenerationToFile(FILE *output, gen life){
    for (int i = 1; i < life->y + 1; ++i) {
        for (int j = 1; j < life->x + 1; ++j) {
            fprintf(output, "%d", life->matrix[j][i]);
        }
        fprintf(output, "\n");
    }
}

void loadGenerationFromFile(FILE *input, gen life){
    int i = 1, j = 1, v;
    while ((v = fgetc(input)) != EOF){
        j = 1;
        life->matrix[j++][i] = v - '0';
        while ((v = fgetc(input)) != '\n'){
            life->matrix[j++][i] = v - '0';
        }
        i++;
    }
}