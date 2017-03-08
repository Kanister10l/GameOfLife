#include <malloc.h>
#include "preparegif.h"
#include "gifsave.h"
#include "data.h"

//
// Created by HubertDryja on 2017-03-08.
//
//callback function fetching a pixel value from the buffer
static unsigned short **Screen;

static int getPixel(int x, int y)
{
    return Screen[x][y];
}
static void copyMatrix(gen life){
    for(int i=0;i<life->x;i++){
        for(int j=0;j<life->y;j++){
            Screen[i][j]= life->matrix[i][j];
        }
    }
}
int prepareGif(conf config, char* fileName, gen* lifes){
    //allocate memory for screen
    Screen = malloc( config->xSize * sizeof(unsigned short*));
    for (int i = 0 ;i<config->xSize;i++){
        Screen[i] = malloc (config->ySize * sizeof(unsigned short));
    }

    GIF_Create(fileName, config->xSize, config->ySize, 2, 8); // init gif

    GIF_SetColor(0, 255, 255, 255);        /* white, the background */
    GIF_SetColor(1, 0, 0, 0);        /* black */

    GIF_WriteHeader(0);
    for(int i=0;i<config->gifAfterYears;i++){
        copyMatrix(lifes[i]);
        GIF_AddFrame(0, 0, -1, -1,config->speed, getPixel);
    }
    GIF_Close();
    return 0;
}