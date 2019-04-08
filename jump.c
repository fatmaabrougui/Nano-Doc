#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "jump.h"

void jump(SDL_Rect *positionchar,SDL_Rect *positionbackground,SDL_Surface *imgbackground , SDL_Surface *ecran,SDL_Surface *imageperso,int mvmspeed,int jumpheight,int jumpspeed,int *i,int *a){
if((*i)<jumpheight){
positionchar->y-=jumpspeed;
SDL_BlitSurface(imgbackground,positionbackground, ecran, NULL);
      SDL_BlitSurface(imageperso,NULL, ecran, positionchar);
               SDL_Flip(ecran);
(*i)++;
}else if((*i)==jumpheight){
(*a)=0;
(*i)=0;
}
}
void gravity(SDL_Rect *positionchar,SDL_Rect *positionbackground,SDL_Surface *imgbackground , SDL_Surface *ecran,SDL_Surface *imageperso,int gravity,int a){
if(a==0){
 while(positionchar->y<gravity){
positionchar->y+=10;
SDL_BlitSurface(imgbackground,positionbackground, ecran, NULL);
      SDL_BlitSurface(imageperso,NULL, ecran, positionchar);
               SDL_Flip(ecran);
}
}}
