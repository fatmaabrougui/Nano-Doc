#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

#include "time.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>


void afficher_chrono()
{

 SDL_Surface *ecran = NULL, *texte = NULL,*image;
    SDL_Rect position,positionecran;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0}, couleurBlanche = {255, 255, 255};
    int continuer = 1;
    int tempsActuel = 0, tempsPrecedent = 0, compteur = 0,fps=0,fpm=0,fph=0;
    char temps[30] = ""; /* Tableau de char suffisamment grand */
   // float delta;
    float dt;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Affichage chronometre", NULL);


image=IMG_Load("s.jpg");
positionecran.x=0;
positionecran.y=0;
positionecran.w=image->w;



    /* Chargement de la police */
    police = TTF_OpenFont("arial.ttf", 25);

    /* Initialisation du temps et du texte */
    tempsActuel = SDL_GetTicks();
    sprintf(temps, "Temps : %d", compteur);
    //texte = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche);
    //texte = TTF_RenderText_Solid(police, temps, couleurNoire);
    texte = TTF_RenderText_Blended(police, temps, couleurNoire);

        tempsActuel = SDL_GetTicks();
          dt=tempsActuel - tempsPrecedent;
         
      if ( dt >= 1000) /* Si 1000 ms au moins se sont écoulées */
        {
          compteur += 1000; /* On rajoute 1000 ms au compteur */

          fps=compteur/1000;
           
               
             if (fps>59)
                 { fpm=(fps/60);
                  // fps=fps-(60*fpm);
                   
                   if(fpm>59)
                      fph=(fpm/60);
                  
                  
                 }
             
           
           

              
            sprintf(temps,"Temps: %d :%d :%d",fph,fpm,fps-(60*fpm)/*compteur*/); /* On écrit dans la chaîne "temps" le nouveau temps */
           SDL_FreeSurface(texte); /* On supprime la surface précédente */


           //texte = TTF_RenderText_Shaded(police, temps, couleurNoire, couleurBlanche); /* On écrit la chaîne temps dans la SDL_Surface */
              // texte = TTF_RenderText_Solid(police, temps, couleurNoire);
             texte = TTF_RenderText_Blended(police, temps, couleurNoire);


            tempsPrecedent = tempsActuel; /* On met à jour le tempsPrecedent */
        }

        position.x =220;
        position.y = 0;

        SDL_BlitSurface(image,NULL,ecran,&positionecran);
        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */  
        SDL_SetColorKey(texte,SDL_SRCCOLORKEY,SDL_MapRGB(texte->format,255,255,255));      
        SDL_Flip(ecran);

    }

    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_Quit();

    //return EXIT_SUCCESS;
}
