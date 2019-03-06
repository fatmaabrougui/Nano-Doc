#ifndef Menu1_H_INCLUDED
#define Menu1_H_INCLUDED
#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"
typedef struct 
{
SDL_Surface *fond;
Mix_Music *musique;
SDL_Rect positionFond;
}background;
typedef struct {
background b;
Mix_Music *but;
}Menu;
void animationpressanykeytoenter(SDL_Surface *ecran);
background initialiserBackground (char* chemin,int x,int y);
Menu InitialiserMenu(background b);
void AfficherMenu(Menu m,SDL_Surface *ecran );
void updateMenu(SDL_Surface *ecran);
#endif
					
