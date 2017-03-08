#include <string.h>
#include <stdlib.h>
#include "data.h"
#include "ini.h"

//
// Created by kamre on 03.03.2017.
//
static int handler(void* user, const char* section, const char* name, const char* value){
    conf pconfig = (conf)user;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(name, n) == 0
    if (MATCH("mandatory", "edgeType"))
        pconfig->edgeType = atoi(value);
    else if (MATCH("mandatory", "isRandom"))
        pconfig->isRandom = atoi(value);
    else if (MATCH("mandatory", "lifeLength"))
        pconfig->gifAfterYears = atoi(value);
    else if (MATCH("random", "xSize"))
        pconfig->xSize = atoi(value);
    else if (MATCH("random", "ySize"))
        pconfig->ySize = atoi(value);
    else if (MATCH("random", "probability"))
        pconfig->probability = atof(value);
    else if (MATCH("gif", "speed"))
        pconfig->speed = atoi(value);
    else if (MATCH("gif", "zoom"))
        pconfig->zoom = atoi(value);
    else
        return 0;
    return 1;
}

void readConfig(conf config){
    ini_parse("config.ini", handler, config);
}
