#ifndef COORDONNEE_PONG_H_INCLUDED
#define COORDONNEE_PONG_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <time.h>
#include "config_jeux.h"


typedef struct coordonnees{

    double x;
    double y;

}coordonnees;

typedef enum SensH
{
    Montee,Descente
} SensH;

typedef enum SensW
{
    Gauche,Droite
} SensW;

//prototypes
SensH move_BallH(coordonnees *depBall,SensH sens_h);
SensW move_BallW(coordonnees *depBall,SensW sens_w);
void handleEvents(gameState *state,coordonnees *dep,coordonnees *dep2);
void renderPong(game *myGame,coordonnees *dep,coordonnees *dep2,coordonnees *depBall,SensW sens_w);
int check_collision(SDL_Rect PaddleJ1,SDL_Rect PaddleJ2,SDL_Rect Ball);

#endif // COORDONNEE_PONG_H_INCLUDED
