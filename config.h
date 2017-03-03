//
// Created by kamre on 03.03.2017.
//

#ifndef GAMEOFLIFE_CONFIG_H
#define GAMEOFLIFE_CONFIG_H


#include "data.h"

static int handler(void* user, const char* section, const char* name, const char* value);

void readConfig(conf config);

#endif //GAMEOFLIFE_CONFIG_H
