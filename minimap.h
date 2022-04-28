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
/**
* @struct minimap
* @brief struct for minimap
*/
typedef struct 
{
	SDL_Surface* img_miniature;/*!< image minimap*/
	SDL_Rect  pos_minimap;/*!< pos minimap ecran*/
	SDL_Surface* img_bonhomme;/*!< image dot*/
	SDL_Rect  pos_bonhomme;/*!< pos dot ecran*/
	
}minimap;
/**
* @struct joueur
* @brief struct for joueur
*/
typedef struct
{
	SDL_Surface* img_perso;/*!< image perso*/
	SDL_Rect  pos_perso;/*!< pos perso ecran*/

}joueur;
/**
* @struct Image
* @brief struct for Image
*/
struct Image
{
SDL_Rect pos1; /*!< pos image dans l'ecran*/
SDL_Rect pos2;/*!< la partie d'image qui va etre afficher*/
SDL_Surface *img;/*!< image */
};
typedef struct Image Image;
/**
* @struct text
* @brief struct for text
*/
typedef struct
{
	SDL_Rect position;/*!< pos text dans l'ecran*/
	TTF_Font *font;/*!< font du text*/
	SDL_Surface *surface_texte;/*!< affichage text*/
	SDL_Color text_color;/*!< couleur text*/
	char text[50];/*!< chaine text*/


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

