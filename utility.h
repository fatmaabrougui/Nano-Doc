#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
int collisionbb( SDL_Rect posj , SDL_Rect posobj,SDL_Rect back);
void animation(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso);
int collisionobjetright(int height[],int debut[],int fin[],int *gravity,SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso,int n);
int collisionobjetlefts(int height[],int debut[],int fin[],int *gravity,SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso,int n);
void collisionplatform( int debut[],int fin[],int haut[] ,SDL_Rect posj ,int n ,SDL_Rect back,int *gravity) ; 
#endif
