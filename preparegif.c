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
static void createScreen(gen life,int factor){
    for(int i=0;i<life->x;i++){
        for(int j=0;j<life->y;j++){
            /* write larger square now if zoom >1 */
            for(int k=0;k<factor;k++){
                for(int g=0;g<factor;g++){
                    Screen[factor*i+k][factor*j+g] = life->matrix[i][j];
                }
            }
        }
    }
}
int prepareGif(conf config, char* fileName, gen* lifes){
    //allocate memory for screen
    Screen = malloc( config->xSize * config->zoom * sizeof(unsigned short*));
    for (int i = 0 ;i<config->xSize * config->zoom;i++){
        Screen[i] = malloc (config->ySize * config->zoom  * sizeof(unsigned short));
    }

    GIF_Create(fileName, config->xSize* config->zoom, config->ySize* config->zoom, 3, 8); // init gif

    GIF_SetColor(0, 255, 255, 255);        /* white, the background */
    GIF_SetColor(1, 0, 0, 0);        /* black */
    GIF_SetColor(2, 255, 133, 162); /*pink for Kamil */
    GIF_WriteHeader(0);
    //first frame
    for(int i=0;i<config->xSize * config->zoom;i++){
        for(int j=0;j<config->ySize * config->zoom;j++){
            Screen[i][j] = 2;
        }
    }
    GIF_AddFrame(0, 0, -1, -1,100, getPixel);
    for(int i=0;i<config->gifAfterYears;i++){
        createScreen(lifes[i],config->zoom);
        GIF_AddFrame(0, 0, -1, -1,config->speed, getPixel);
    }
    GIF_Close();
    return 0;
}