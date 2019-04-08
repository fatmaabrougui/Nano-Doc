#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>



SDL_Surface* Init_imagedefond( SDL_Surface *imagedefond ,SDL_Rect *image ,  int x , int y) ;
void Show_imagedefond (SDL_Surface *imagedefond , SDL_Surface *screen ,  SDL_Rect image  ) ;


#endif // JEU_H_INCLUDED
