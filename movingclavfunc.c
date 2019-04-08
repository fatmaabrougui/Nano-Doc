#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "movingclav.h"
void moving_right(SDL_Rect *positionchar,SDL_Rect *positionbackground,SDL_Surface *imgbackground , SDL_Surface *ecran,SDL_Surface *imageperso,int mvmspeed){
if  (positionchar->x>=516 && positionbackground->x<=3000)
            positionbackground->x += mvmspeed/2;
        else if (positionchar->x<=750) 
            positionchar->x +=mvmspeed;
SDL_BlitSurface(imgbackground,positionbackground, ecran, NULL);
   SDL_BlitSurface(imageperso,NULL, ecran, positionchar);
           SDL_Flip(ecran);
}

void moving_left(SDL_Rect *positionchar,SDL_Rect *positionbackground,SDL_Surface *imgbackground , SDL_Surface *ecran,SDL_Surface *imageperso,int mvmspeed){
if (positionchar->x<=258 && positionbackground->x>=10)
            positionbackground->x -= mvmspeed/2;
      else if (positionchar->x>=0)
      positionchar->x -= mvmspeed;
SDL_BlitSurface(imgbackground,positionbackground, ecran, NULL);
      SDL_BlitSurface(imageperso,NULL, ecran, positionchar);
               SDL_Flip(ecran);

}
