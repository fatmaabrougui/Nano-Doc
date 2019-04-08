#ifndef FONCTION_H_
#define FONCTION_H_
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL.h>
#include <SDL/SDL_image.h>
void jump(SDL_Rect *positionchar,SDL_Rect *positionbackground,SDL_Surface *imgbackground , SDL_Surface *ecran,SDL_Surface *imageperso,int mvmspeed,int jumpheight,int jumpspeed,int *i,int *a);
void gravity(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso,int gravity,int a);
#endif
