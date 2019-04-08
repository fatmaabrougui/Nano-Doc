#include"enem.h"
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include<time.h>



void deplacement_aleatoire(enemy E,SDL_Surface *screen)
{
SDL_Event event;
int continuer=1;
int tempsPrecedent=0,tempsActuel=0;
int pos;
static int k=0;
char temps[20];
E.positionmax_enemy.x=screen->w / 2 ;
pos=position_aleatoire(E.positionmax_enemy.x,E.positionmin_enemy.x);
    SDL_EnableKeyRepeat(10, 10);
   

        tempsActuel = SDL_GetTicks();



        if (tempsActuel - tempsPrecedent > 30)
        {
           
               if(k==0)

                   {
                     if(E.position_enemy.x<pos)
                          {
                            E.position_enemy.x++;

                          }
                     else k=1;

                   }
              if(k==1)
                  {
                    if(E.position_enemy.x>E.positionmin_enemy.x)
                            E.position_enemy.x--;
                    else
                         k=0;
                  }             
                                    
            tempsPrecedent = tempsActuel;
        }
        SDL_BlitSurface(E.image_enemy, NULL, screen, &E.position_enemy);
        SDL_Flip(screen);
      
}
