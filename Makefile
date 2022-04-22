prog:main.o picture.o perso.o
	gcc perso.o main.o perso.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
perso.o:perso.c
	gcc -c perso.c –g
picture.o:picture.c
	gcc -c picture.c -g	
