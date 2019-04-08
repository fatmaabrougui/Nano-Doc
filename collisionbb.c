#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "utility.h"
void animation(SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso){
SDL_Surface *image1=NULL;
SDL_Surface *image2=NULL;
SDL_Surface *image3=NULL;
SDL_Surface *image4=NULL;
SDL_Surface *image5=NULL;
SDL_Surface *image6=NULL;
SDL_Surface *image7=NULL;
image1=IMG_Load("1.png");
image2=IMG_Load("2.png");
image3=IMG_Load("3.png");
image4=IMG_Load("4.png");
image5=IMG_Load("5.png");
image6=IMG_Load("6.png");
image7=IMG_Load("7.png");

SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
SDL_BlitSurface(image1,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);

SDL_Delay(20);
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(image2,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);
SDL_Delay(20);
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(image3,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);
SDL_Delay(20);
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(image4,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);
SDL_Delay(20);
SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(image5,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);
SDL_Delay(20);

SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(image6,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);
SDL_Delay(20);

SDL_BlitSurface(imageDeFond,positionFond, ecran, NULL);
      SDL_BlitSurface(image7,NULL, ecran, positionmilieu);
               SDL_Flip(ecran);
SDL_Delay(20);
   SDL_FreeSurface(image3);
   SDL_FreeSurface(image2); 
   SDL_FreeSurface(image1); 
   SDL_FreeSurface(image4); 
   SDL_FreeSurface(image5); 
   SDL_FreeSurface(image6); 
   SDL_FreeSurface(image7);  
}

int collisionbb( SDL_Rect posj , SDL_Rect posobj,SDL_Rect back)
{
int x ; 
if ( ((posj.y+posj.h>=posobj.y)&&(posj.y<=posobj.y+posobj.h)&&(posj.x+posj.w+back.x>=posobj.x)&&(posj.x+back.x<=posobj.x+posobj.w)) )
{
	x=1 ; 
}

else x=0 ; 

return x ;
}

int collisionobjetright(int height[],int debut[],int fin[],int *gravity,SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso,int n){
int i=0;

printf("%d\n",positionmilieu->x+positionFond->x);
while(i<n){
if((positionmilieu->x+positionFond->x>=debut[i])&&(positionmilieu->x+positionFond->x<=fin[i])&&(positionmilieu->y>height[i])){
return 1;
break;
}
i++;
}
return 0;
}
int collisionobjetlefts(int height[],int debut[],int fin[],int *gravity,SDL_Rect *positionmilieu,SDL_Rect *positionFond,SDL_Surface *imageDeFond , SDL_Surface *ecran,SDL_Surface *imageDePerso,int n){
int i=0; 
int x;
printf("%d\n",positionmilieu->x+positionFond->x);
while(i<n){
if((positionmilieu->x+positionFond->x<=fin[i])&&(positionmilieu->y>height[i])){
return 1;
break;
}
i++;
}
return 0;
}
void collisionplatform(int debut[],int fin[],int haut[] ,SDL_Rect posj ,int n ,SDL_Rect back,int *gravity){
int i=0;
while(i<n){
if(((posj.x+back.x)>debut[i])&&((posj.x+back.x)<fin[i])){
if((posj.y)<230){
(*gravity)=haut[i];
printf("gottoit\n");
break;}
}
else if(((posj.x+back.x)<debut[i])||((posj.x+back.x)>fin[i]))
{
(*gravity)=240;
}
 i++;}
}
