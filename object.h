#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
SDL_Surface *image ; 
SDL_Rect position ; 
}Objet; 
typedef struct
{
SDL_Rect  position_enemy;
SDL_Surface * image_enemy;
SDL_Rect positionmax_enemy;
SDL_Rect positionmin_enemy;
}enemy;
void initialiserObj( Objet *obj , char name[] , int x , int y ) ; 
void affichageObj ( Objet obj , SDL_Surface *screen,SDL_Rect *positionbackground) ; 
void initialiser_enemy(enemy* E,int posinit,int start,int end);
int position_aleatoire(int positionmax_enemy,int positionmin_enemy);
void deplacement_aleatoire(enemy  *E,SDL_Surface*screen,SDL_Rect *positionbackground,int x);
int enemy_haut_bas(enemy E,SDL_Surface*screen);

#endif 
