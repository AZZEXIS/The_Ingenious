#include "minimap.h"
/**
* @file minimap.c
* @brief tache minimap
* @author The Ingenious
* @version 0.1
* @date Apr 28, 2022
*
* 
*
*/
/**
* @brief To initialize minimap .
* @param *m the minimap
* @return Nothing
*/
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
/**
* @brief To initialize joueur j .
* @param *j joueur
* @return Nothing
*/
void init_Joueur(joueur *j)
{
j->img_perso=IMG_Load("/home/mohamed_aziz_belkahla/Desktop/game/right.png");

j->pos_perso.x=100;
j->pos_perso.y=360;
j->pos_perso.w=j->img_perso->w;
j->pos_perso.h=j->img_perso->h;

}
/**
* @brief To initialize cam .
* @param SDL_Rect *cam
* @return Nothing
*/
void init_camera(SDL_Rect *cam)
{
cam->x=0;
cam->y=0;
cam->w=1914;
cam->h=884;
}
/**
* @brief To initialize background.
* @param Image *Backg
* @return Nothing
*/
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
/**
* @brief To move the dot according to the player position.
* @param SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement
* @return Nothing
*/
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement)
{
int posJoueurABSx,posJoueurABSy;
posJoueurABSx= posJoueur.x + camera.x;
posJoueurABSy= posJoueur.y + camera.y;
m->pos_bonhomme.x=posJoueurABSx*redimensionnement/100;
m->pos_bonhomme.y=posJoueurABSy*redimensionnement/100-80;

}
/**
* @brief To show minimap .
* @param minimap m, SDL_Surface * screen
* @return Nothing
*/
void afficher (minimap m, SDL_Surface * screen)
{
SDL_BlitSurface(m.img_miniature,NULL,screen,&m.pos_minimap);
SDL_BlitSurface(m.img_bonhomme,NULL,screen,&m.pos_bonhomme);
}
/**
* @brief liberer minimap
* @param minimap *m
* @return Nothing
*/
void Liberer (minimap * m)
{
SDL_FreeSurface(m->img_miniature);
SDL_FreeSurface(m->img_bonhomme);
}
/**
* @brief sauvegarder score dans fichier
* @param unsigned int score, char nomjoueur[], char nomfichier[]
* @return Nothing
*/
void sauvegarder( unsigned int score, char nomjoueur[], char nomfichier[])
{
FILE *f=NULL;
f=fopen(nomfichier,"w");
if(f!=NULL)
fprintf(f,"%s %d ",nomjoueur,score);
else 
printf("erreur ouverture fichier!");
fclose(f);

}
/**
* @brief sauvegarder meilleur score dans fichier
* @param char nomfichier[], unsigned int *score, char nomjoueur[]
* @return Nothing
*/
void meilleur( char nomfichier[], unsigned int *score, char nomjoueur[])
{
FILE* f= NULL;
    char chaine[50] = "";
 unsigned int x;
 char ch[50];
    f= fopen(nomfichier, "r");
 
    if (f != NULL)
    {
        while (fgets(chaine, 50, f) != NULL)
        {
            sscanf(chaine,"%s %d",ch,&x);
        if(x>*score)
        {
        (*score)=x;
        strcpy(nomjoueur,ch);
        }
        }
        fclose(f);
    }

}
/**
* @brief initialize text_saisir
* @param text *t
* @return Nothing
*/
void init_text_saisir(text *t)
{
t->position.x=40;
t->position.y=50;
t->text_color.r=0;
t->text_color.g=255;
t->text_color.b=255;
t->font=TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeMonoOblique.ttf",70);



}
/**
* @brief initialize nom
* @param text *t
* @return Nothing
*/
void init_text(text *t)
{
t->position.x=600;
t->position.y=150;
t->text_color.r=0;
t->text_color.g=255;
t->text_color.b=255;
t->font=TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeMonoOblique.ttf",70);



}
/**
* @brief initialize score
* @param text *t
* @return Nothing
*/
void init_text_score(text *t)
{
t->position.x=900;
t->position.y=20;
t->text_color.r=0;
t->text_color.g=255;
t->text_color.b=255;
t->font=TTF_OpenFont("/usr/share/fonts/truetype/freefont/FreeMonoOblique.ttf",45);



}
/**
* @brief affichage nom
* @param text t,SDL_Surface *screen
* @return Nothing
*/
void saisir_nom(text t,SDL_Surface *screen)
{
t.surface_texte=TTF_RenderText_Solid(t.font,"Tapez votre Nom:",t.text_color);
SDL_BlitSurface (t.surface_texte, NULL, screen, &t.position);


}
/**
* @brief affichage score
* @param text t,SDL_Surface *screen
* @return Nothing
*/
void afficher_text(text t,SDL_Surface *screen)
{
t.surface_texte=TTF_RenderText_Solid(t.font,t.text,t.text_color);
SDL_BlitSurface (t.surface_texte, NULL, screen, &t.position);


}
/**
* @brief saisie nom
* @param text t,SDL_Surface *screen,SDL_Event *event, int *saisie
* @return Nothing
*/
void entrer_nom(text* t,SDL_Surface *screen,SDL_Event event, int *saisie)
{
while(*saisie==0)
{	
	text saisir;
	minimap m;
	init_text_saisir(&saisir);
	initminimap(&m);
	afficher(m,screen);
	saisir_nom(saisir,screen);
	t->surface_texte=TTF_RenderText_Solid(t->font,t->text,t->text_color);
	 SDL_BlitSurface(t->surface_texte, NULL, screen, &t->position);  
	SDL_Flip(screen);
	SDL_WaitEvent(&event);
switch(event.type)
	{
case SDL_KEYDOWN:
{
            switch(event.key.keysym.sym)
            {
            case SDLK_a:
           
strcat(t->text,"a");

                break ;
               
            case SDLK_z:
strcat(t->text,"z");

                break ;
               
            case SDLK_e:
strcat(t->text,"e");

                break ;
               
            case SDLK_r:
strcat(t->text,"r");

                break ;
               
            case SDLK_t:
strcat(t->text,"t");

                break ;
               
            case SDLK_y:
strcat(t->text,"y");

                break ;
               
            case SDLK_u:
strcat(t->text,"u");

                break ;
               
            case SDLK_i:
strcat(t->text,"i");

                break ;
               
            case SDLK_o:
strcat(t->text,"o");

                break ;
               
            case SDLK_p:
strcat(t->text,"p");

                break ;
                           
               
            case SDLK_q:
strcat(t->text,"q");

                break ;
               
            case SDLK_s:
strcat(t->text,"s");

                break ;
               
            case SDLK_d:
strcat(t->text,"d");

                break ;
               
            case SDLK_f:
strcat(t->text,"f");

                break ;
               
            case SDLK_g:
strcat(t->text,"g");

                break ;
               
            case SDLK_h:
strcat(t->text,"h");

                break ;
               
            case SDLK_j:
strcat(t->text,"j");

                break ;
               
            case SDLK_l:
strcat(t->text,"l");

                break ;
               
            case SDLK_m:
strcat(t->text,"m");
break;
            case SDLK_k:
strcat(t->text,"k");

       break;  
            case SDLK_w:
           
strcat(t->text,"w");

                break ;
               
            case SDLK_x:
strcat(t->text,"x");

                break ;
               
            case SDLK_c:
strcat(t->text,"c");

                break ;
               
            case SDLK_v:
strcat(t->text,"v");

                break ;
               
            case SDLK_b:
strcat(t->text,"b");

                break ;
               
            case SDLK_n:
strcat(t->text,"n");

                break ;
               
            case SDLK_SPACE:
strcat(t->text," ");

                break ;
               
            case SDLK_RETURN:
(*saisie)=1;

                break ;
                         case SDLK_BACKSPACE:
                         t->text[strlen(t->text)-1]='\0';

                break ;
                  }
                  
                  
                  }
                   
                   }
                   }



}

 










