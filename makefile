game:menu1.o Menufunctions.o 
	gcc menu1.o Menufunctions.o  -lSDL -lSDL_image -lSDL_mixer -o  game  -g
menu1.o:menu1.c 
	gcc -c menu1.c -g
Menufunctions.o:Menufunctions.c 
	gcc -c Menufunctions.c -g


