#ifndef FONCTIONS_H_
#define FONCTIONS_H_

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>

#define W_Screen 800
#define H_Screen 750


#define SPEED 5


#define SPRITE_H 148
#define SPRITE_W 102
#define MAX_FRAMES 4 



           #define W_BackgImg 259
           #define H_BackgImg 194


typedef struct 
{

SDL_Rect position_enemy;
SDL_Rect position_map;
SDL_Rect frame;
SDL_Rect dst;


SDL_Surface * image_enemy;
SDL_Surface * spriteleft;
SDL_Surface * spriteright;

int pos_alea_max_x;
int pos_alea_min_x;

int pos_alea_max_y;
int pos_alea_min_y;

int pos_max_x;
int pos_min_x;

int pos_max_y;
int pos_min_y;



}enem;
void initialis_enemy(enemy *E);
 void afficher_enemy (enemy E);

void animation_enemy_right(enemy E);
void animation_enemy_left(enemy E);














#endif /* FONCTIONS_H_ */
