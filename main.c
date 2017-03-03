//
// Created by kamre on 03.03.2017.
//
#include <stdio.h>
#include <malloc.h>
#include "data.h"
#include "config.h"

int main(){
    conf config = malloc(sizeof * config);
    readConfig(config);
    printf("%d",config->gifAfterYears);
    return 0;
}
