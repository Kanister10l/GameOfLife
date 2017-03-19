#include <malloc.h>
#include <stdio.h>
#include "data.h"

//
// Created by kamre on 03.03.2017.
//
gen createMatrix(int x, int y, short type){
    gen matrix = malloc(sizeof * matrix);
    matrix->x = x;
    matrix->y = y;
    matrix->edgeType = type;
    matrix->matrix = malloc((x + 2) * sizeof * matrix->matrix);
    for (int i = 0; i < x + 2; ++i)
        matrix->matrix[i] = malloc((y + 2) * sizeof * matrix->matrix[x]);
    for (int j = 0; j < x + 2; ++j) {
        for (int i = 0; i < y + 2; ++i) {
            matrix->matrix[j][i] = 0;
        }
    }
    setEdge(matrix);
    return matrix;
}

void freeMatrix(gen matrix){
    for (int i = 0; i < matrix->x + 2; ++i)
        free(matrix->matrix[i]);
    free(matrix->matrix);
    free(matrix);
}

void printMatrix(gen matrix){// with border
    for (int i = 0; i < matrix->x + 2; ++i) {
        for (int j = 0; j < matrix->y + 2; ++j) {
            printf("%d",matrix->matrix[i][j]);
        }
        printf("\n");
    }
}

//For edgeType = 0 there is no need to use this function
void setEdge(gen matrix){
    if (matrix->edgeType == 1){
        for (int i = 0; i < matrix->y + 2; ++i)
            matrix->matrix[0][i] = 1;
        for (int i = 0; i < matrix->y + 2; ++i)
            matrix->matrix[matrix->x+1][i] = 1;
        for (int i = 0; i < matrix->x + 2; ++i)
            matrix->matrix[i][0] = 1;
        for (int i = 0; i < matrix->x + 2; ++i)
            matrix->matrix[i][matrix->y+1] = 1;
    }
    else if (matrix->edgeType == 2){
        for (int i = 0; i < matrix->y + 2; i += 2)
            matrix->matrix[0][i] = 1;
        for (int i = 0; i < matrix->y + 2; i += 2)
            matrix->matrix[matrix->x+1][i] = 1;
        for (int i = 0; i < matrix->x + 2; i += 2)
            matrix->matrix[i][0] = 1;
        for (int i = 0; i < matrix->x + 2; i += 2)
            matrix->matrix[i][matrix->y+1] = 1;
    }
}