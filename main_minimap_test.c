#include "minimap.h"
int main()
{
text t,saisir;
SDL_Event event;
int saisie=0,done=0;
minimap m;
joueur j;
char nom[50], Fichierscore[50];
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
init_text_saisir(&saisir);
initBackground(&backg);
initminimap(&m);
init_Joueur(&j);
init_camera(&cam); 
while(!done)
{
if(saisie==0)

//entrer_nom(t,screen);//
while(SDL_PollEvent(&event))
{
	switch(event.type)
	{
		
		case SDL_KEYDOWN:
		{
		
		switch(event.key.keysym.sym)
		{
		
		case SDLK_RETURN:
		saisie=1;
		break;
		}
		}

	}

}
    
SDL_BlitSurface(backg.img,&backg.pos2,screen,&backg.pos1);
SDL_BlitSurface(j.img_perso,NULL,screen,&j.pos_perso);
afficher(m,screen);
saisir_nom(saisir,screen);

SDL_Flip(screen);
//MAJMinimap(j.pos_perso, &m,cam,60);
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
unsigned int score;
score=SDL_GetTicks();
//meilleur(Fichierscore,score,nom);
//sauvegarder(score,nom,Fichierscore);


























}
