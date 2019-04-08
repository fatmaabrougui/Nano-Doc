
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
#include<time.h>
#include"object.h"

void initialiser_enemy(enemy* E,int posinit,int start,int end)
{
    E->position_enemy.x = posinit;
    E->position_enemy.y = 250;
    E->image_enemy = IMG_Load("pieuvre.jpeg");

     E->positionmin_enemy.x=start;
  E->positionmax_enemy.x=end;
  E->positionmin_enemy.y=0;
  E->positionmax_enemy.y=0;

}



int position_aleatoire(int positionmax,int positionmin)
{
int pos;
 srand(time(NULL));
pos=rand()%(positionmax-positionmin+1)+positionmin;


return pos;
}




int enemy_haut_bas(enemy E,SDL_Surface*screen)
{
SDL_Event event;

    int continuer = 1;
    int tempsPrecedent = 0, tempsActuel = 0;
    
char temps[20];

  int pos;
static int k=0;

    //E.position_enemy.x = 0;//screen->w / 2 - E.image_enemy->w / 2;
    //E.position_enemy.y = 0;screen->h / 2 - E.image_enemy->h / 2;
     E.positionmax_enemy.y=screen->h/2;
pos=position_aleatoire(E.positionmax_enemy.y,E.positionmin_enemy.y);
    SDL_EnableKeyRepeat(10, 10);

    while (continuer)
    {
        SDL_PollEvent(&event); /* On utilise PollEvent et non WaitEvent pour ne pas bloquer le programme */
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;
        }

        tempsActuel = SDL_GetTicks();




        if (tempsActuel - tempsPrecedent > 30) /* Si 30 ms se sont écoulées depuis le dernier tour de boucle */
        {


         
            
               if(k==0)

                  
                     { 
                            if(E.position_enemy.y<pos)
                          {
                            E.position_enemy.y++;

                          }

                            else k=1;
                     }
                
               if(k==1)

                { 
                            if(E.position_enemy.y>E.positionmin_enemy.y)
                          {
                            E.position_enemy.y--;

                          }
                            else k=0;
                }

           

                                    /* On bouge l'ennemi */
            tempsPrecedent = tempsActuel; /* Le temps "actuel" devient le temps "precedent" pour nos futurs calculs */
        }

        




        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
        SDL_BlitSurface(E.image_enemy, NULL, screen, &E.position_enemy);
         
        SDL_Flip(screen);
    }

    SDL_FreeSurface(E.image_enemy);
    
    SDL_Quit();

   return EXIT_SUCCESS;

}
