#include "data.h"

//
// Created by kamre on 03.03.2017.
//
int findAliveNeighbours(gen life, int x, int y){
    int n = 0;
    if ( x > 0 && x < (life->x - 1) && y > 0 && y < (life->y - 1)){
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (life->matrix[x+i-1][y+j-1] == 1 && i != x && j != y)
                    n++;
            }
        }
    }
    else if (x == 0){
        if (y == 0){
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    if (life->matrix[x+i][y+j] == 1 && i != x && j != y)
                        n++;
                }
            }
        }
        else if (y == life->y - 1){
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    if (life->matrix[x+i][y+j-1] == 1 && i != x && j != y)
                        n++;
                }
            }
        }
        else
            return 0;
    }
    else if (x == life->x - 1){
        if (y == 0){
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    if (life->matrix[x+i-1][y+j] == 1 && i != x && j != y)
                        n++;
                }
            }
        }
        else if (y == life->y - 1){
            for (int i = 0; i < 2; ++i) {
                for (int j = 0; j < 2; ++j) {
                    if (life->matrix[x+i-1][y+j-1] == 1 && i != x && j != y)
                        n++;
                }
            }
        }
        else
            return 0;
    }
    else
        return 0;
    return n;
}

gen jumpToNextGeneration(gen life){
    gen nextOne = createMatrix(life->x, life->y, life->edgeType);
    for (int i = 0; i < life->x; ++i) {
        for (int j = 0; j < life->y; ++j) {
            if (life->matrix[i][j] == 0 && findAliveNeighbours(life, i, j) == 3)
                nextOne->matrix[i][j] = 1;
            else if (life->matrix[i][j] == 1 && findAliveNeighbours(life, i, j) == (2 || 3))
                ;
            else
                nextOne->matrix[i][j] = 0;
        }
    }
    clearMatrix(life);
    life = nextOne;
    return life;
}
