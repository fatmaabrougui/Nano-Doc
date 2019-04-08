#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "movingsouris.h"
#include "utility.h"
void mousemov(SDL_Rect *positionchar,SDL_Rect *positionbackground,SDL_Surface *imgbackground , SDL_Surface *ecran,SDL_Surface *imageperso,int mvmspeed,SDL_Event *event){

int mousex=0,mousey=0;
int a=0;
SDL_GetMouseState(&mousex,&mousey);
if(mousex>positionchar->x){
while((positionchar->x+positionbackground->x)<mousex){


if  (positionchar->x>=516 && positionbackground->x<=3000)
            positionbackground->x += mvmspeed/2;
        else if (positionchar->x<=750)
            positionchar->x +=mvmspeed;
            SDL_BlitSurface(imgbackground,positionbackground, ecran, NULL);
                SDL_BlitSurface(imageperso,NULL, ecran, positionchar);
    SDL_Flip(ecran);
animation(positionchar,positionbackground,imgbackground, ecran,imageperso);
}
}
else
{
while((positionchar->x+positionbackground->x)>mousex){


if (positionchar->x<=258 && positionbackground->x>=10)
            positionbackground->x -= mvmspeed/2; 
      else if(positionchar->x>=10)
      positionchar->x -= mvmspeed;
SDL_BlitSurface(imgbackground,positionbackground, ecran, NULL);
      SDL_BlitSurface(imageperso,NULL, ecran, positionchar);   
    SDL_Flip(ecran);
}}}

