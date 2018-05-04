


#include "define.h"


int main(int argc, char *argv[])
{


     game myGame;
     gameState state;
     unsigned int frameLimit = SDL_GetTicks() + 16;
     coordonnees dep;
     coordonnees dep2;
     coordonnees depBall;
     depBall.x=(SCREEN_WIDTH/2)-10;
     depBall.y=(SCREEN_HEIGHT/2)-10;
     dep.x=0,dep.y=0;
     dep2.x=0,dep2.y=0;
     int choix=0;
     SensH sens_h;
     SensW sens_w;
     sens_h=Descente;
     sens_w=Droite;
     state.g_bRunning=1;

        //Create texture for drawing in texture or load picture
        myGame.g_ptexture=SDL_CreateTexture(myGame.g_pRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,SCREEN_WIDTH,SCREEN_HEIGHT);
        while(state.g_bRunning){
                if(choix==0){
                    printf("1:Pong\n");
                    scanf("%i",&choix);
                }
                if (choix==1){
                        //initialise la fenêtre
                        init("Chapter 1 setting up SDL",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN,&myGame);
                                while(state.g_bRunning){
                                    sens_h=move_BallH(&depBall,sens_h);
                                    sens_w=move_BallW(&depBall,sens_w);
                                    handleEvents(&state,&dep,&dep2);
                                    renderPong(&myGame,&dep,&dep2,&depBall,sens_w);
                                }
                }
                 system ("cls");
             // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
            delay(frameLimit);
            frameLimit = SDL_GetTicks() + 16;
        }
        destroy(&myGame);
        SDL_Quit();
    return 0;
}


