#ifndef FONCTIONS_H_
#define FONCTIONS_H_
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <string.h>
#include <SDL/SDL_ttf.h>
#include <time.h>
#define SCREEN_W 1914
#define SCREEN_H 884
typedef struct 
{
	SDL_Surface* img_miniature;
	SDL_Rect  pos_minimap;
	SDL_Surface* img_bonhomme;
	SDL_Rect  pos_bonhomme;
	
}minimap;
typedef struct
{
	SDL_Surface* img_perso;
	SDL_Rect  pos_perso;

}joueur;
struct Image
{
SDL_Rect pos1;
SDL_Rect pos2;
SDL_Surface *img;
};
typedef struct Image Image;
typedef struct
{
	SDL_Rect position;
	TTF_Font *font;
	SDL_Surface *surface_texte;
	SDL_Color text_color;
	char text[50];


}
text;

void initminimap(minimap *m);
void init_Joueur(joueur *j);
void MAJMinimap(SDL_Rect posJoueur,  minimap * m, SDL_Rect camera, int redimensionnement);
void afficher (minimap m, SDL_Surface * screen);
void Liberer (minimap * m);
void sauvegarder( unsigned int score, char nomjoueur[], char nomfichier[]);
void meilleur( char nomfichier[], unsigned int *score, char nomjoueur[]);
void init_text(text *t);
void init_text_saisir(text *t);
void init_text_score(text *t);
void afficher_score(text t,SDL_Surface *screen);
void saisir_nom(text t,SDL_Surface *screen);
void entrer_nom(text t,SDL_Surface *screen,SDL_Event *event, int *saisie);
#endif

