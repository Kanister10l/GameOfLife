//
// Created by kamre on 10.03.2017.
//

#include "data.h"

#ifndef GAMEOFLIFE_FILE_LOADER_H
#define GAMEOFLIFE_FILE_LOADER_H

void saveGenerationToFile(FILE *output, gen life);

void loadGenerationFromFile(FILE *input, gen life);

#endif //GAMEOFLIFE_FILE_LOADER_H
