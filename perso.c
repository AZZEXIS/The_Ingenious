#include "picture.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>




void initPerso(Personne *p)
{
      
      

    p->img=IMG_Load("/home/firas/projetjeu/pics and sound/perso/right.png");
    if (p->img == NULL)
    {
        printf("unable to load the sprite sheet pic %s \n",SDL_GetError());
        return;
                                                                                      //sprite sheet load
    }
    


    p->pos1.x=500;     //pos perso
    p->pos1.y=433;


    p->pos2.x=0;
    p->pos2.y=0;       //pos sprite
    p->pos2.w=LARGEUR_JOUEUR;
    p->pos2.h=400;
    p->direction=0;
    p->x=0;
    p->y=0;
    p->accel=0;



}


void afficherPerso(Personne p , SDL_Surface *screen)
{
    SDL_BlitSurface(p.img,&p.pos2,screen,&p.pos1);                         //display sprite sheet
}


          
void animerPerso(Personne * p)
{

if(p->direction == 0 || p->x == 0){
if(p->pos2.x<600){  p->pos2.x+=113;SDL_Delay(100); }else{p->pos2.x=0;SDL_Delay(100);}
}else if (p->direction == 1 || p->x == 1){
if(p->pos2.x>40){  p->pos2.x-=113;SDL_Delay(100); }else{p->pos2.x=679;SDL_Delay(100);}

}

}

//////////////////////////////////////////////////////////////////////////////////////////////////


void deplacerPerso(SDL_Surface *screen , Personne *p , int dt )
{


if(p->direction==0){
p->x=0;
changeAnimation(p,"/home/firas/projetjeu/pics and sound/perso/forward.png");
if(p->accel<SPEED){

p->pos1.x+=p->accel;
p->accel+=3;
}else{
p->pos1.x+=SPEED;
}
if(p->pos1.x+LARGEUR_JOUEUR>=SCREEN_W)
 		{	p->pos1.x=SCREEN_W-LARGEUR_JOUEUR;
 		}

if(p->direction != 0)
		{	p->direction = 0;
			
			
		}


}else if (p->direction==1){
p->x=1;
changeAnimation(p,"/home/firas/projetjeu/pics and sound/perso/backwards.png");
if(p->accel<SPEED){

p->pos1.x-=p->accel;
p->accel+=3;
}else{
p->pos1.x-=SPEED;
}
if(p->pos1.x<0)
		{ 
			p->pos1.x=0;
		}

if(p->direction != 1)
		{	p->direction = 1;
			


}

}else if (p->direction==3){

if(p->x==0){

changeAnimation(p,"/home/firas/projetjeu/pics and sound/perso/right.png");

}else if (p->x==1){


changeAnimation(p,"/home/firas/projetjeu/pics and sound/perso/left.png");

}
if(p->direction != 3)
		{	p->direction = 3;
			


}
}else if (p->direction == 4){
if(p->x==0){
changeAnimation(p,"/home/firas/projetjeu/pics and sound/perso/JumpRight.png");
if(p->y==0){
if(p->pos2.y<60){p->pos2.y+=200;}
p->pos1.x+=100;
p->y+=1;
}

}else if (p->x==1){

changeAnimation(p,"/home/firas/projetjeu/pics and sound/perso/JumpLeft.png");
if(p->y==0){
if(p->pos2.y<100){p->pos2.y+=200;}
p->pos1.x-=100;
p->y+=1;
}


}
}}

///////////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////

void changeAnimation(Personne *p, char *name)
{
    //On libère l'animation précédente
    if (p->img != NULL)
    {
        SDL_FreeSurface(p->img);
    }
    //On charge la nouvelle
    p->img = IMG_Load(name);




}





