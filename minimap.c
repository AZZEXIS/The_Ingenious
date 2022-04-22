#include "minimap.h"
void initminimap(minimap *m)
{
m->img_miniature=IMG_Load("/home/mohamed_aziz_belkahla/Desktop/game/minimap.png");
m->img_bonhomme=IMG_Load("/home/mohamed_aziz_belkahla/Desktop/game/58afdad6829958a978a4a693.png");

m->pos_minimap.x=0;
m->pos_minimap.y=0;
m->pos_minimap.w=m->img_miniature->w;
m->pos_minimap.h=m->img_miniature->h;

m->pos_bonhomme.x=45;
m->pos_bonhomme.y=92;
m->pos_bonhomme.w=m->img_bonhomme->w;
m->pos_bonhomme.h=m->img_bonhomme->h;
}
void init_Joueur(joueur *j)
{
j->img_perso=IMG_Load("/home/mohamed_aziz_belkahla/Desktop/game/right.png");

j->pos_perso.x=100;
j->pos_perso.y=360;
j->pos_perso.w=j->img_perso->w;
j->pos_perso.h=j->img_perso->h;

}
void init_camera(SDL_Rect *cam)
{
cam->x=0;
cam->y=0;
cam->w=1914;
cam->h=884;
}
void initBackground(Image *Backg)
{
Backg->img=IMG_Load("/home/mohamed_aziz_belkahla/Desktop/game/big map (1).png");
if(Backg->img==NULL)
{
printf("Unable to load Background: %s\n",SDL_GetError());
return;
}
Backg->pos1.x=0;
Backg->pos1.y=295;

Backg->pos2.x=0;
Backg->pos2.y=50;
Backg->pos2.w=(SCREEN_W);
Backg->pos2.h=(SCREEN_H);
}
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
int posJoueurABSx,posJoueurABSy;
posJoueurABSx= posJoueur.x + camera.x;
posJoueurABSy= posJoueur.y + camera.y;
m->pos_bonhomme.x=posJoueurABSx*redimensionnement/100;
m->pos_bonhomme.y=posJoueurABSy*redimensionnement/100;

}
void afficher (minimap m, SDL_Surface * screen)
{
SDL_BlitSurface(m.img_miniature,NULL,screen,&m.pos_minimap);
SDL_BlitSurface(m.img_bonhomme,NULL,screen,&m.pos_bonhomme);
}
void Liberer (minimap * m)
{
SDL_FreeSurface(m->img_miniature);
SDL_FreeSurface(m->img_bonhomme);
}
void sauvegarder( int score, char nomjoueur[], char nomfichier[])
{
FILE *f=NULL;
f=fopen(nomfichier,"w");
if(f!=NULL)
fprintf(f,"%s  %d \n",nomjoueur,score);
else 
printf("erreur ouverture fichier!");
fclose(f);

}
void meilleur( char nomfichier[], int *score, char nomjoueur[])
{
char nom_meilleur_joueur[50];
int meilleur_score;
FILE *f=NULL;
f=fopen("nomfichier","r");
if(f!=NULL)
{
fscanf(f,"%s %d",nom_meilleur_joueur,&meilleur_score);

if(*score>meilleur_score)
{
	meilleur_score=(*score);
	strcpy(nom_meilleur_joueur,nomjoueur);

}


}

}
void init_text_saisir(text *t)
{
t->position.x=40;
t->position.y=50;
t->text_color.r=0;
t->text_color.g=255;
t->text_color.b=255;
t->font=TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeMonoOblique.ttf",70);



}
void init_text(text *t)
{
t->position.x=300;
t->position.y=150;
t->text_color.r=0;
t->text_color.g=255;
t->text_color.b=255;
t->font=TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeMonoOblique.ttf",200);



}
void saisir_nom(text t,SDL_Surface *screen)
{
t.surface_texte=TTF_RenderText_Solid(t.font,"Tapez votre Nom:",t.text_color);
SDL_BlitSurface (t.surface_texte, NULL, screen, &t.position);


}
void entrer_nom(text t,SDL_Surface *screen)
{

t.surface_texte=TTF_RenderText_Solid(t.font,t.text,t.text_color);
SDL_BlitSurface (t.surface_texte, NULL, screen, &t.position);  

}












