#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"

 #include"Menu1.h"

void animationpressanykeytoenter(SDL_Surface *ecran ){            
char chemin[][8]={"1.png","2.png","3.png","4.png","5.png","11.png","6.png","7.png","8.png","13.png","9.png"};
SDL_Surface *image=NULL,*image1=NULL,*image2=NULL,*image3=NULL,*image4=NULL,*image5=NULL,*image6=NULL,*image7=NULL,*image8=NULL,*image9=NULL,*image10=NULL,*image11=NULL;
image= IMG_Load(chemin[0]);
image2= IMG_Load(chemin[1]);
image3= IMG_Load(chemin[2]);
image4= IMG_Load(chemin[3]);
image5= IMG_Load(chemin[4]);
image6= IMG_Load(chemin[5]);
image7= IMG_Load(chemin[6]);
image8= IMG_Load(chemin[7]);
image9= IMG_Load(chemin[8]);
image10= IMG_Load(chemin[9]);
image11= IMG_Load(chemin[10]);
SDL_BlitSurface(image,NULL, ecran,0 );
                    SDL_Flip(ecran);
                    SDL_Delay(10);
SDL_FreeSurface(image);
SDL_BlitSurface(image2,NULL, ecran, 0);
                    SDL_Flip(ecran);
                    SDL_Delay(10);
SDL_FreeSurface(image2);
SDL_BlitSurface(image3,NULL, ecran,0);
                    SDL_Flip(ecran);
                    SDL_Delay(10);
SDL_FreeSurface(image3);
SDL_BlitSurface(image4,NULL, ecran,0);
                    SDL_Flip(ecran);
                    SDL_Delay(10);
SDL_FreeSurface(image4);
SDL_BlitSurface(image5,NULL, ecran, 0);
                    SDL_Flip(ecran);
                    SDL_Delay(20);
SDL_FreeSurface(image5);
SDL_BlitSurface(image6,NULL, ecran, 0);
                    SDL_Flip(ecran);
                  SDL_Delay(10);
SDL_FreeSurface(image6);
SDL_BlitSurface(image7,NULL, ecran, 0);
                    SDL_Flip(ecran);
                    SDL_Delay(10);        
SDL_FreeSurface(image7);
SDL_BlitSurface(image8,NULL, ecran, 0);
                    SDL_Flip(ecran);
                    SDL_Delay(10);  
SDL_FreeSurface(image8);
SDL_BlitSurface(image9,NULL, ecran, 0);
                    SDL_Flip(ecran);
                   
SDL_Delay(10);
SDL_FreeSurface(image9);
SDL_BlitSurface(image10,NULL, ecran, 0);
                    SDL_Flip(ecran);
                   
                  SDL_Delay(20);
SDL_FreeSurface(image10);
SDL_BlitSurface(image11,NULL, ecran, 0);
                    SDL_Flip(ecran);
                   SDL_Delay(10);
SDL_FreeSurface(image11);      
 }
background initialiserBackground (char* chemin,int x,int y){
background b;
b.fond=IMG_Load(chemin);
b.musique=Mix_LoadMUS("music.mp3");
b.positionFond.x=x;
b.positionFond.y=y;
return b;
}
Menu InitialiserMenu(background b){
Menu m;
m.b=b;
m.but=Mix_LoadMUS("button.wav");
return m;
}
void AfficherMenu(Menu m,SDL_Surface *ecran ){
Mix_AllocateChannels(20);
Mix_PlayMusic(m.b.musique,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME/1);
SDL_BlitSurface(m.b.fond,NULL,ecran,0);
SDL_Flip(ecran);
                    SDL_Delay(10);
}

void updateMenu(SDL_Surface *ecran)
{
Mix_Chunk *but;
int press;
press=1;
int cont;
cont=1;
int i=0;
SDL_Surface *image=NULL,*image1=NULL,*image2=NULL,*image3=NULL;
image= IMG_Load("menu1.png");
image2= IMG_Load("menu2.png");
image3= IMG_Load("menu3.png");
SDL_Event event;
but=Mix_LoadWAV("button.wav");
while(cont){
SDL_WaitEvent(&event);
switch(event.type)
{
case SDL_KEYDOWN:
press=0;
switch(event.key.keysym.sym)
            {

            case SDLK_RETURN: 
if (i==1)
                {

                }
                else if (i==2)
                {
                }
                else if (i==3)
                {
                    cont=0;
                }

                break;

            case SDLK_DOWN:
                i++;
                if(i==4)
                {
                    i=1;
                }
                if(i==1)
                {

                    SDL_BlitSurface(image,NULL, ecran,0);
                    SDL_Flip(ecran);
                  SDL_Delay(1);
     Mix_PlayChannel(1, but, 0);

                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran,0);
                    SDL_Flip(ecran);

                    SDL_Delay(1);
Mix_PlayChannel(1, but, 0);     
           }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran, 0);
                    SDL_Flip(ecran);

                    SDL_Delay(1);
Mix_PlayChannel(1, but, 0);
                }
                break;
            case SDLK_UP: 
                i--;
                if(i<0)
                {
                 	   i=3;
                }
                
                if(i==1)
                {
                    SDL_BlitSurface(image,NULL, ecran,0);
                    SDL_Flip(ecran);

                    SDL_Delay(1);
Mix_PlayChannel(1, but, 0);
                }
                if(i==2)
                {
                    SDL_BlitSurface(image2,NULL, ecran,0);
                    SDL_Flip(ecran);

                    SDL_Delay(1);
Mix_PlayChannel(1, but, 0);
                }
                if(i==3)
                {
                    SDL_BlitSurface(image3,NULL, ecran,0);
                    SDL_Flip(ecran);
                    SDL_Delay(1) ;  
Mix_PlayChannel(1, but, 0);
                }
                break;        
}
}if(press==1)
animationpressanykeytoenter(ecran);
 
}}

