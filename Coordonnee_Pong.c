#include "Coordonnee_Pong.h"
#include "define.h"

SensH move_BallH(coordonnees *depBall,SensH sens_h)
{
 if (sens_h==Montee)
{
    depBall->y-=2;
}
else if (sens_h==Descente)
{
 depBall->y+=2;
}
if (depBall->y>SCREEN_HEIGHT-20)
{
    sens_h=Montee;
}
else if (depBall->y<0)
{
    sens_h=Descente;
}
return sens_h;
}



SensW move_BallW(coordonnees *depBall,SensW sens_w)
{
 if (sens_w==Gauche)
{
    depBall->x-=2;
}
else if (sens_w==Droite)
{
 depBall->x+=2;
}
if (depBall->x>SCREEN_WIDTH-20)
{
    sens_w=Gauche;
}
else if (depBall->x<0)
{
    sens_w=Droite;
}
return sens_w;
}

void renderPong(game *myGame,coordonnees *dep,coordonnees *dep2,coordonnees *depBall,SensW sens_w) {

        int verif_collision=0;
        int i;

        //defini le filet
        SDL_Rect filet;
        filet.x = SCREEN_WIDTH/2;
        filet.y = 20;
        filet.w = 5;
        filet.h = 15;


       //Définition du rectangle 1 a dessiner
        SDL_Rect PaddleJ1;
        PaddleJ1.x=0;//debut x
        PaddleJ1.y=dep->y;//debut y
        PaddleJ1.w=10; //Largeur
        PaddleJ1.h=100; //Hauteur


        //Définition du rectangle 2 a dessiner
        SDL_Rect PaddleJ2;
        PaddleJ2.x=SCREEN_WIDTH-10;//debut x
        PaddleJ2.y=dep2->y;//debut y
        PaddleJ2.w=10; //Largeur
        PaddleJ2.h=100; //Hauteur


        if ((PaddleJ1.y<=0))
        {
            PaddleJ1.y=0;
        }
        if ((PaddleJ1.y>=SCREEN_HEIGHT-PaddleJ1.h))
        {
            PaddleJ1.y=SCREEN_HEIGHT-PaddleJ1.h;
        }
        if ((PaddleJ2.y<=0))
        {
            PaddleJ2.y=0;
        }
        if ((PaddleJ2.y>=SCREEN_HEIGHT-PaddleJ2.h))
        {
            PaddleJ2.y=SCREEN_HEIGHT-PaddleJ2.h;
        }


        //Définition de la balle a dessiner
        SDL_Rect Ball;
        Ball.x=depBall->x;//debut x
        Ball.y=depBall->y;//debut y
        Ball.w=20; //Largeur
        Ball.h=20; //Hauteur

        verif_collision=check_collision(PaddleJ1,PaddleJ2,Ball);

        if (verif_collision==1)
        {
            sens_w=Droite;
            sens_w=move_BallW(depBall,sens_w);
        }

        if (verif_collision==2)
        {

            sens_w=Gauche;
            sens_w=move_BallW(depBall,sens_w);
        }

        //Draw in texture
        SDL_SetRenderDrawColor(myGame->g_pRenderer,255,255,255,255);
        SDL_SetRenderTarget(myGame->g_pRenderer, myGame->g_ptexture); //on modifie la texture

        SDL_RenderFillRect(myGame->g_pRenderer, &PaddleJ1);
        SDL_RenderFillRect(myGame->g_pRenderer, &PaddleJ2);
        SDL_RenderFillRect(myGame->g_pRenderer, &Ball);
        for(i = 0; i < (SCREEN_HEIGHT/30); i++)
            {
            SDL_RenderFillRect(myGame->g_pRenderer, &filet);
            filet.y = filet.y + 30;
            }
        SDL_SetRenderTarget(myGame->g_pRenderer, NULL);// Dorénavent, on modifie à nouveau le renderer

        SDL_Rect position;//position de la texture dans screen
        position.x = 0;
        position.y = 0;
        SDL_QueryTexture(myGame->g_ptexture, NULL, NULL, &position.w, &position.h);
        SDL_RenderCopy(myGame->g_pRenderer,myGame->g_ptexture,NULL,&position);


         SDL_RenderPresent(myGame->g_pRenderer);

         SDL_SetRenderDrawColor(myGame->g_pRenderer,0,0,0,255);
         SDL_DestroyTexture(myGame->g_ptexture);
         SDL_RenderClear(myGame->g_pRenderer);
}



int check_collision(SDL_Rect PaddleJ1,SDL_Rect PaddleJ2,SDL_Rect Ball) {

	int left_PaddleJ2,left_Ball;
	int right_PaddleJ1,right_Ball;
	int Top_PaddleJ1, Top_PaddleJ2,Top_Ball;
	int Bottom_PaddleJ1, Bottom_PaddleJ2,Bottom_Ball;


	right_PaddleJ1 = PaddleJ1.x + PaddleJ1.w;
	Top_PaddleJ1 = PaddleJ1.y;
	Bottom_PaddleJ1 = PaddleJ1.y + PaddleJ1.h;


	left_PaddleJ2 = PaddleJ2.x;
	Top_PaddleJ2 = PaddleJ2.y;
	Bottom_PaddleJ2 = PaddleJ2.y + PaddleJ2.h;

	left_Ball = Ball.x;
	right_Ball = Ball.x + Ball.w;
	Top_Ball = Ball.y;
	Bottom_Ball = Ball.y + Ball.h;


	if ((right_PaddleJ1 == left_Ball)&&(Top_PaddleJ1 < Top_Ball)&&(Bottom_PaddleJ1 > Bottom_Ball)) {
		return 1;
	}

	if ((left_PaddleJ2 == right_Ball)&&(Top_PaddleJ2 < Top_Ball)&&(Bottom_PaddleJ2 > Bottom_Ball)) {
		return 2;
	}


	return 0;
}



void handleEvents(gameState *state,coordonnees *dep,coordonnees *dep2){


    SDL_Event event;

    if(SDL_PollEvent(&event)){
        switch(event.type){
        case SDL_QUIT:
              state->g_bRunning=0;break;
        case SDL_KEYDOWN:

                        switch (event.key.keysym.sym)
                            {
                                case SDLK_z:  dep->y-=5;break;
                                case SDLK_s: dep->y+=5; break;
                                case SDLK_UP:   dep2->y-=5; break;
                                case SDLK_DOWN:  dep2->y+=5; break;
                                case SDLK_ESCAPE: state->g_bRunning=0;break;
                            }
                            break;

        case SDL_KEYUP:

                            break;
        }

    }


}
