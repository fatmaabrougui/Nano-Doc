game:main.o backgroundfunc.o AffichageObj.o InitObjet.o movingclavfunc.o movingsourisfunc.o jump.o   collisionbb.o score.o  vie.o
	gcc main.o backgroundfunc.o score.o jump.o  vie.o movingsourisfunc.o  AffichageObj.o InitObjet.o collisionbb.o movingclavfunc.o -o game -lSDL  -lSDL_ttf -lSDL_image -lSDL_mixer -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -g
backgroundfunc.o:backgroundfunc.c
	gcc -c backgroundfunc.c -lSDL -lSDL_image -lSDL_mixer -g
AffichageObj.o:AffichageObj.c
	gcc -c AffichageObj.c -lSDL -lSDL_image -g
InitObjet.o:InitObjet.c 
	gcc -c InitObjet.c -lSDL -lSDL_image -g  

movingclavfunc.o:movingclavfunc.c
	gcc -c movingclavfunc.c -lSDL -lSDL_image -lSDL_mixer -g
movingsourisfunc.o:movingsourisfunc.c
	gcc -c movingsourisfunc.c -lSDL -lSDL_image -lSDL_mixer -g
jump.o:	jump.c
	gcc -c jump.c -lSDL -lSDL_image -lSDL_mixer -g
collisionbb.o:collisionbb.c 
	gcc -c collisionbb.c -lSDL -lSDL_image -g  
score.o:score.c 
	gcc -c score.c  -lSDL -lSDL_image -lSDL_mixer  -lSDL_ttf -g
vie.o:vie.c
	gcc -c vie.c -lSDL -lSDL_image -g
chrono.o:chrono.c 
	gcc -c chrono.c  -lSDL -lSDL_image -lSDL_mixer  -lSDL_ttf -g



