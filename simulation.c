#include <malloc.h>
#include <stdio.h>
#include "data.h"

//
// Created by kamre on 03.03.2017.
//
int findAliveNeighbours(gen life, int x, int y){
    int n = 0;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (i+x >= 0 && i+x <= life->x-1 && j+y >= 0 && j+y <= life->y-1) {
                if (!(i == 0 && j == 0)) {
                    if (life->matrix[i + x][j + y] == 1)
                        n++;
                }
            }
        }
    }
    return n;
}

gen jumpToNextGeneration(gen life){
    gen nextOne = createMatrix(life->x, life->y, life->edgeType);
    for (int i = 0; i < life->x; ++i) {
        for (int j = 0; j < life->y; ++j) {
            if (life->matrix[i][j] == 0 && findAliveNeighbours(life, i, j) == 3)
                nextOne->matrix[i][j] = 1;
            else if (life->matrix[i][j] == 1 && (findAliveNeighbours(life, i, j) == 2 || findAliveNeighbours(life, i, j) == 3))
                nextOne->matrix[i][j] = 1;
            else
                nextOne->matrix[i][j] = 0;
        }
    }
    //clearMatrix(life);
    //life = nextOne;
    return nextOne;
}

gen *simulateAllGenerations(gen base, int lifeLength){
    gen *lifes = malloc(lifeLength * sizeof * lifes);
    for (int i = 0; i < lifeLength; ++i)
        lifes[i] = createMatrix(base->x, base->y, base->edgeType);

    lifes[0] = base;
    for (int j = 1; j < lifeLength; ++j)
        lifes[j] = jumpToNextGeneration(lifes[j-1]);
    return lifes;
}