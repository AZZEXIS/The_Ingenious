prog:main_minimap_test.o minimap.o
	gcc minimap.o main_minimap_test.o -o prog -g -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main_minimap_test.o:main_minimap_test.c
	gcc -c main_minimap_test.c -g
minimap.o:minimap.c
	gcc -c minimap.c –g
