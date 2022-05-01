#include "minimap.h"
/**
* @file main_minimap_test.c
* @brief main minimap
* @author The_Ingenious
* @version 0.1
* @date Apr 28, 2022
*
*
*
*/
int main()
{
unsigned int score;
text t,saisir,score_text;
strcpy(t.text,"\0");
SDL_Event event;
int saisie=0,done=0;
minimap m;
joueur j;
char Fichierscore[50]="Fichierscore.txt";
Image backg;
SDL_Rect cam;
SDL_Surface *screen;

screen=SDL_SetVideoMode ( 1914,884,32, SDL_HWSURFACE | SDL_DOUBLEBUF|SDL_RESIZABLE );
if(!screen)
{
printf("unable to set 1914 x 884 video: %s\n", SDL_GetError());
return 1;
}
TTF_Init();
init_text(&t);
init_text_score(&score_text);
init_text_saisir(&saisir);
initBackground(&backg);
initminimap(&m);
init_Joueur(&j);
init_camera(&cam); 
while(!done)
{

SDL_BlitSurface(backg.img,&backg.pos2,screen,&backg.pos1);
SDL_BlitSurface(j.img_perso,NULL,screen,&j.pos_perso);
afficher(m,screen);
entrer_nom(&t,screen,event,&saisie);
t.position.x=0;
t.position.y=0;
MAJMinimap(j.pos_perso, &m,cam,50);

score=SDL_GetTicks();
sprintf(score_text.text, "%d", score);
afficher_text(score_text,screen);
afficher_text(t,screen);
SDL_Flip(screen);

if (saisie==1)
{
while(SDL_PollEvent(&event))
{
	switch(event.type)
	{
		case SDL_QUIT:
		done=1;
		break;
		case SDL_KEYDOWN:
		{
		switch(event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
		done=1;
		break;
		case SDLK_DOWN:
		j.pos_perso.y+=50;
		break;
		case SDLK_UP:
		j.pos_perso.y-=50;
		break;
		case SDLK_RIGHT:
		j.pos_perso.x+=50;
		cam.x++;
		break;
		case SDLK_LEFT:
		j.pos_perso.x-=50;
		cam.x--;
		break;
		}
		}

	}

}
}
}

meilleur(Fichierscore,&score,t.text);
sauvegarder(score,t.text,Fichierscore);



























}
