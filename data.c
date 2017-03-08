#include <malloc.h>
#include <stdio.h>
#include "data.h"

//
// Created by kamre on 03.03.2017.
//
gen createMatrix(int x, int y, short type){
    gen matrix = malloc(sizeof * matrix);
    matrix->x = x + 2;
    matrix->y = y + 2;
    matrix->edgeType = type;
    matrix->matrix = malloc((x + 2) * sizeof * matrix->matrix);
    for (int i = 0; i < x + 2; ++i)
        matrix->matrix[i] = malloc((y + 2) * sizeof * matrix->matrix[x]);
    for (int j = 0; j < x + 2; ++j) {
        for (int i = 0; i < y + 2; ++i) {
            matrix->matrix[j][i] = 0;
        }
    }
    return matrix;
}

void freeMatrix(gen matrix){
    for (int i = 0; i < matrix->x; ++i)
        free(matrix->matrix[i]);
    free(matrix->matrix);
    free(matrix);
}

void printMatrix(gen matrix){
    for (int i = 1; i < matrix->x - 1; ++i) {
        for (int j = 1; j < matrix->y - 1; ++j) {
            printf("%d",matrix->matrix[i][j]);
        }
        printf("\n");
    }
}