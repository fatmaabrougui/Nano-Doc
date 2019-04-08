#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "score.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>



SDL_Surface* afficher_objetpng( int x,int y,char nomphoto[] ,SDL_Surface *ecran ){

SDL_Surface *image;
SDL_Rect pous;
image=IMG_Load(nomphoto);
pous.x=x;
pous.y=y;
 
     SDL_SetColorKey(image,SDL_SRCCOLORKEY,SDL_MapRGB(image->format,255,255,255));
             SDL_BlitSurface(image,NULL,ecran,&pous);



return (image);

}





TTF_Font *loadFont(char *name, int size)
{
    // Utilise SDL_TTF pour charger la police à la taille désirée 

    TTF_Font *font = TTF_OpenFont(name, size);

    if (font == NULL)
    {
        printf("Failed to open Font %s: %s\n", name, TTF_GetError());
        exit(1);
    }

    return font;
}



void drawString(char *text, int x, int y, TTF_Font *font, SDL_Surface *ecran){
    SDL_Rect dest;
    SDL_Surface *surface;


    SDL_Color foregroundColor;

    /* On choisit d'écrire le texte en noir */
    foregroundColor.r = 255;
    foregroundColor.g = 25;
    foregroundColor.b = 36;


    /* On utilise SDL_TTF pour générer une SDL_Surface à partir d'une chaîne de caractères (string) */

    surface = TTF_RenderUTF8_Blended(font, text, foregroundColor);


    if (ecran == NULL)
    {
        printf("Couldn't create String %s: %s\n", text, SDL_GetError());

        return;
    }

    /* On blitte cette SDL_Surface à l'écran */

    dest.x = x;
    dest.y = y;
    dest.w = surface->w;
    dest.h = surface->h;

    SDL_BlitSurface(surface, NULL, ecran, &dest);

    /* On libère la SDL_Surface temporaire (pour éviter les fuites de mémoire - cf. chapitre dédié) */
    SDL_FreeSurface(surface);

}


int colliz (SDL_Rect detective, SDL_Rect harboucha)
 {
  int c;
    //On teste pour voir s'il y a  collision, si c'est le cas, on renvoie 1
    if ((detective.x == harboucha.x + harboucha.w) || (detective.x + harboucha.w == harboucha.x) || (detective.y == harboucha.y + harboucha.h)|| (detective.y + detective.h == harboucha.y)) 
    
        c=1;
   else 
   	 c=0 ; 
   	return c;
}
 
 int collize (SDL_Rect detective, SDL_Rect ennemi)
 
 {
  int s;
    //On teste pour voir s'il y a  collision, si c'est le cas, on renvoie 1
    if ((detective.x == ennemi.x + ennemi.w) || (detective.x + ennemi.w == ennemi.x) || (detective.y == ennemi.y + ennemi.h)|| (detective.y + detective.h == ennemi.y)) 
    
       s=1;

   else
    
     s=0 ;

    return s;
}
  



SDL_Surface* afficher_objetx( int x,int y,char nomphoto[] ,SDL_Surface *ecran){

objet OB;
OB.image=SDL_LoadBMP(nomphoto);
OB.pous.x=x;
OB.pous.y=y;
 
     SDL_SetColorKey(OB.image,SDL_SRCCOLORKEY,SDL_MapRGB(OB.image->format,255,255,255));
             SDL_BlitSurface(OB.image,NULL,ecran,&OB.pous);



return (OB.image);

}
