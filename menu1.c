#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include"Menu1.h"

int main()
{
Menu m;
SDL_Init(SDL_INIT_VIDEO); 
SDL_Surface *ecran =NULL;
ecran=SDL_SetVideoMode(1200, 720, 32, SDL_HWSURFACE);
background b;
SDL_WM_SetCaption("Nano-Doc", NULL);
b=initialiserBackground("1.png",0,0);
m=InitialiserMenu(b);
AfficherMenu(m,ecran); 
updateMenu(ecran);
Mix_FreeMusic(m.b.musique);
Mix_CloseAudio();
SDL_Quit(); 
return EXIT_SUCCESS;
}
