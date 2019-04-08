

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include"enemy.h"

void initialis_enemy(enemy *E)
{

	E->spriteleft = IMG_Load("walk-left.png");
	E->spriteright=IMG_Load("walk-right.png");
	E->dst.x = 0;
	E->dst.y = 0;


E->position_enemy.x=0;
E->position_enemy.y=0;
E->position_map.x=0;
E->position_map.y=0;
E->frame.x=0;
E->frame.y=0;
E->frame.w = SPRITE_W;
E->frame.h = SPRITE_H;
E->dst.x=0;
E->dst.y=0;


E->image_enemy=NULL;


E->pos_alea_max_x=0;
E->pos_alea_min_x=0;

E->pos_alea_max_y=0;
E->pos_alea_min_y=0;

E-> pos_max_x=0;
E-> pos_min_x=0;

E-> pos_min_y=0;
E->pos_max_y=0;


}
 void afficher_enemy (enemy E)
{
    SDL_Surface* screen = NULL;

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
    screen = SDL_SetVideoMode(W_Screen, H_Screen, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE | SDL_RESIZABLE );//SDL_HWPALETTE:Mise a jour de la surface

	
    
    SDL_Surface* backg = NULL;
    backg = IMG_Load("index.jpeg");
    SDL_BlitSurface(backg, NULL, screen, NULL);
    SDL_WM_SetCaption("animation enemy", NULL);
    SDL_Flip(screen);

 initialiser_enemy(&E);
}
void animation_enemy_right(enemy E)
{
    
	    SDL_Surface* screen = NULL;

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
    screen = SDL_SetVideoMode(W_Screen, H_Screen, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE | SDL_RESIZABLE );//SDL_HWPALETTE:Mise a jour de la surface

	
    
    SDL_Surface* backg = NULL;
    backg = IMG_Load("index.jpeg");
    SDL_BlitSurface(backg, NULL, screen, NULL);
    SDL_WM_SetCaption("animation enemy", NULL);
    SDL_Flip(screen);

 initialiser_enemy(&E);
//Hide Cursor
	SDL_ShowCursor(SDL_DISABLE);
	int continuer = 1;
	while(continuer)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
                

		int i; int j;

for (j=0;j<1;j++)
{
               
for(i = 0; i<MAX_FRAMES; i++)
		{

                   
                        E.frame.x = i*(Sint16)SPRITE_W;
			E.frame.y =j*(Sint16)SPRITE_H;
			E.frame.w = SPRITE_W;
			E.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(E.spriteright, &E.frame, screen, &E.dst);
                        
			SDL_Flip(screen);
			
                       
                SDL_Delay(500);
	SDL_FreeSurface(E.image_enemy);

		}
	}
	



		switch(event.type)

		{            case SDL_QUIT:
                               continuer = 0;
			    if(event.key.keysym.sym == SDLK_ESCAPE)
			    {
			    	continuer = 0;
			    }
                       


		}

	} 
	SDL_Quit();

}
void animation_enemy_left(enemy E)
{
    
	    SDL_Surface* screen = NULL;

    SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE);
    screen = SDL_SetVideoMode(W_Screen, H_Screen, 32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_HWPALETTE | SDL_RESIZABLE );//SDL_HWPALETTE:Mise a jour de la surface

	
    
    SDL_Surface* backg = NULL;
    backg = IMG_Load("index.jpeg");
    SDL_BlitSurface(backg, NULL, screen, NULL);
    SDL_WM_SetCaption("animation enemy", NULL);
    SDL_Flip(screen);

 initialiser_enemy(&E);
//Hide Cursor
	SDL_ShowCursor(SDL_DISABLE);
	int continuer = 1;
	while(continuer)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
                

		int i; int j;


for (j=0;j<1;j++)
{
for(i = (MAX_FRAMES - 1); i>=0; i--)
		{
			E.frame.x = i*(Sint16)SPRITE_W;
			E.frame.y = j*(Sint16)SPRITE_H;
			E.frame.w = SPRITE_W;
			E.frame.h = SPRITE_H;
			SDL_BlitSurface(backg, NULL, screen, NULL);
			SDL_BlitSurface(E.spriteleft, &E.frame, screen, &E.dst);
			
			SDL_Delay(500);
			SDL_Flip(screen);
SDL_FreeSurface(E.image_enemy);
		}
	}




		switch(event.type)

		{            case SDL_QUIT:
                               continuer = 0;
			    if(event.key.keysym.sym == SDLK_ESCAPE)
			    {
			    	continuer = 0;
			    }
                       


		}

	} 
	SDL_Quit();

}

