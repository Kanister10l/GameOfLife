#include <malloc.h>
#include "preparegif.h"
#include "gifsave.h"

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
int prepareGif(int width, int height, char* fileName, int lifesNum, gen* lifes){
    //allocate memory for screen
    Screen = malloc( width * sizeof(unsigned char*));
    for (int i = 0 ;i<width;i++){
        Screen[i] = malloc (height * sizeof(unsigned char));
    }

    GIF_Create(fileName, width, height, 2, 8); // init gif

    GIF_SetColor(0, 255, 255, 255);        /* white, the background */
    GIF_SetColor(1, 0, 0, 0);        /* black */

    GIF_WriteHeader(0);
    for(int i=0;i<lifesNum;i++){
        copyMatrix(lifes[i]);
        GIF_AddFrame(0, 0, -1, -1,50, getPixel);
    }
    GIF_Close();
    return 0;
}