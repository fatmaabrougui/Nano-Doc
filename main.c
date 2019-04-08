
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
 #include <stdbool.h>
#include <math.h>
#include "object.h"
#include "time.h"
#include "background.h"
#include "jump.h"
#include "movingsouris.h"
#include "movingclav.h"

#include "score.h"
#include "utility.h"
#include"vie.h"

int main()
{
int boost=0;
vie v;
int col1=0;
int n=0;
int a=0;
int haut[2];
int debut[2];
int fin[2];
debut[0]=1751;
debut[1]=2131;
fin[0]=2068;
fin[1]=2448;
TTF_Font *font;
haut[0]=160;
haut[1]=50;
int start[1]; 
int end[1] ;
int height[1];
int k=1;

int movr=0;
   char text[200];
int movl=0;
start[0]=1286;
end[0]=1559;
height[0]=200;

int jumppp=0;
int mvmspeed=20;
int jumpspeed=5;
int jumph=30;
int continuer=1;
SDL_Color noir = {18,18,255}, rouge = {0,255,0};
 enemy firstenemy;
SDL_Surface *screen= NULL;
SDL_Surface *imageback=NULL;
SDL_Rect positionback ;
Objet personnage,pill;
int vie=5,score=0;
SDL_Init(SDL_INIT_VIDEO);
screen=SDL_SetVideoMode(1000,800,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_WM_SetCaption("Nano-Doc", NULL);
if(screen==NULL){
printf("unable = %s\n",SDL_GetError());
return 1;
}
imageback=Init_imagedefond( imageback ,&positionback ,0,0);
initialiserObj(&personnage,"7.png",400, 240 ) ;
initialiserObj(&pill,"pill1.png",2300, 70 ) ;
n=3;


int gravityforce=240;
if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
{
        printf("%s",Mix_GetError());
    }
    Mix_Music *musique;
    Mix_AllocateChannels(20);
    musique = Mix_LoadMUS("musique.mp3");
    Mix_PlayMusic(musique, -1);
    Mix_VolumeMusic(MIX_MAX_VOLUME / 1);

    SDL_Event event;

    SDL_EnableKeyRepeat(10, 10);
 Show_imagedefond (imageback , screen , positionback ) ;
affichageObj(personnage,screen,&positionback); 
SDL_Flip(screen);
if (TTF_Init() < 0)
    {
        printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());
        exit(1);
    }
    font = loadFont("DFTEH.ttf", 32);
while(continuer==1)

{

sprintf(text, "%d", vie);
    drawString(text, 0, 0, font,screen);
   sprintf(text, "%d", score);
boost=collisionbb(personnage.position,pill.position,positionback);
printf(" pill %d %d char %d %d \n",pill.position.x,pill.position.y,personnage.position.x+positionback.x,personnage.position.y);
if(boost==1){
mvmspeed=50;
jumpspeed=10;
jumph=20;
score+=100;
pill.position.x=0;
}	
    drawString(text, 900,600, font,screen);
movr=collisionobjetright(height,start,end,&gravity,&personnage.position,&positionback,imageback,screen,personnage.image,1);
//movl=collisionobjetlefts(height,start,end,&gravity,&personnage.position,&positionback,imageback,screen,personnage.image,1);
affichageObj(pill,screen,&positionback); 

SDL_PollEvent(&event);
        switch(event.type)
        {
case SDL_QUIT: 
continuer=0;   
case SDL_MOUSEBUTTONUP:
if(event.button.button==SDL_BUTTON_RIGHT)
          {
mousemov(&personnage.position,&positionback,imageback,screen,personnage.image,mvmspeed,&event);
	
}                  
break; 
case SDL_KEYDOWN: 
        switch(event.key.keysym.sym)
        {
case SDLK_RIGHT: 
if(movr==0)
      moving_right(&personnage.position,&positionback,imageback,screen,personnage.image,mvmspeed);
//animation(&personnage.position,&positionback,imageback,screen,personnage.image);
else if(movr==1){
vie--;
personnage.position.x-=20;
}
break;
case SDLK_LEFT:
if(movl==0)
moving_left(&personnage.position,&positionback,imageback,screen,personnage.image,mvmspeed);
 //animation(&personnage.position,&positionback,imageback,screen,personnage.image);
else if(movl==1){
vie--;
personnage.position.x+=20;
}
break;
case SDLK_UP:
a=1; 
break;
}
}if(a==1)
jump(&personnage.position,&positionback,imageback,screen,personnage.image,mvmspeed,jumph,jumpspeed,&jumppp,&a);
collisionplatform(debut,fin,haut,personnage.position ,2 ,positionback,&gravityforce);
gravity(&personnage.position,&positionback,imageback,screen,personnage.image,gravityforce,a);
}
SDL_FreeSurface(imageback);  

SDL_Quit();
return 0;
}






