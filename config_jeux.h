#ifndef CONFIG_JEUX_H_INCLUDED
#define CONFIG_JEUX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <time.h>

typedef struct game{
     SDL_Window *g_pWindow;
     SDL_Renderer *g_pRenderer;
     SDL_Texture *g_ptexture;
     SDL_Surface *g_psurface;
}game;

typedef struct gameState{
    int g_bRunning;
}gameState;


//prototypes
int init(char *title, int xpos,int ypos,int width, int height,int flags,game *myGame);
void destroy(game *myGame);
void delay(unsigned int frameLimit);

#endif // CONFIG_JEUX_H_INCLUDED
