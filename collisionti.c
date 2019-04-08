#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "utility.h"
int collisiontrigoinscrit ( SDL_Rect posj , SDL_Rect posobj[],int n ) 
{
SDL_Rect rayon , rayonobj ; 
int x ; 
for(int i=0;i<n;i++){
rayon.x=(posj.x+posj.w)/2 ;
rayon.y=(posj.y+posj.h)/2; 
rayonobj.x=(posobj[i].x+posobj[i].w)/2 ;
rayonobj.y=(posobj[i].y+posobj[i].h)/2 ;
if ((rayon.x>=rayonobj[i].x)&&(rayon.x<=rayonobj[i].x+(posobj.w/2))&&(rayon.y>=posobj[i].y))
x=1 ; 
else 
x=0 ;
}
 return x ; 
}
