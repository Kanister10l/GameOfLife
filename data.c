#include <malloc.h>
#include "data.h"

//
// Created by kamre on 03.03.2017.
//
gen createMatrix(int x, int y, short type){
    gen matrix = malloc(sizeof * matrix);
    matrix->x = x;
    matrix->y = y;
    matrix->edgeType = type;
    matrix->matrix = malloc(x * sizeof * matrix->matrix);
    for (int i = 0; i < x; ++i)
        matrix->matrix[i] = malloc(y * sizeof * matrix->matrix[x]);
    for (int j = 0; j < x; ++j) {
        for (int i = 0; i < y; ++i) {
            matrix->matrix[j][i] = 0;
        }
    }
    return matrix;
}

void clearMatrix(gen matrix){
    for (int i = 0; i < matrix->x; ++i)
        free(matrix->matrix[i]);
    free(matrix->matrix);
    free(matrix);
}