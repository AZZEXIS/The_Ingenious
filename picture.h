#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef Image_H
#define Image_H
#define SCREEN_W 1440
#define SCREEN_H 966
#define LARGEUR_JOUEUR 113
#define HAUTEUR_JOUEUR 200
#define SPEED		30









struct Image{
    
    SDL_Rect posbcl1,posbcl2,posbql1,posbql2,posbpl1,posbpl2,posbsl1,posbsl2,posbp1,posbp2,posbs1,posbs2,posbc1,posbc2,posbq1,posbq2; //buttons position 


    SDL_Rect lowb1,lowb2  ,mediumb1,mediumb2   ,highb1,highb2    ,muteb1,muteb2 ; //volume buttons position 


    SDL_Rect pos1,pos2;

    SDL_Surface *img;
};
typedef struct Image Image ;

///////////////////////////////

struct Personne{

SDL_Rect pos1,pos2;        // pos sprite sheet

SDL_Surface *img;

int direction,x,y,accel;


};
typedef struct Personne Personne ;



struct Input
{	int left,right,up,down,jump,resume,speed;
};
typedef struct Input Input;

////////////////////
void affichermutevbs(Image button_lmus , SDL_Surface *screen);
void affichermutevbl(Image button_lmul , SDL_Surface *screen);

void afficherhighvbl(Image button_lhl , SDL_Surface *screen);
void afficherhighvbs(Image button_lhs , SDL_Surface *screen);

void affichermedvbs(Image button_lms , SDL_Surface *screen);
void affichermedvbl(Image button_lml , SDL_Surface *screen);

void afficherlowvbs(Image button_lvs , SDL_Surface *screen);
void afficherlowvbl(Image button_lvl , SDL_Surface *screen);

void initmutevl(Image *button_lmul);
void initmutevs(Image *button_lmus);

void inithighvl(Image *button_lhl);
void inithighvs(Image *button_lhs);

void initmediumvbl(Image *button_lml);
void initmediumvbl(Image *button_lms);

void initlowvbs(Image *button_lvs);
void initlowvbl(Image *button_lvl);

void affichersettignsbackg(Image settignsbackg,SDL_Surface *screen);
void initsettignsbackg(Image *settignsbackg);
void affichercreditsbackground(Image creditsbackg,SDL_Surface *screen);
void initcreditsbackground(Image *creditsbackg);
void afficherquitbuttonl(Image button_ql , SDL_Surface *screen);
void initquitbuttonl(Image *button_ql);
void affichercreditsbuttonl(Image button_cl , SDL_Surface *screen);
void initcreditbuttonl(Image *button_cl);
void affichersettingsbuttonl(Image button_sl , SDL_Surface *screen);
void initsettingsbuttonl(Image *button_sl);
void afficherplaybuttonl(Image button_pl ,SDL_Surface *screen);
void initplaybuttonl(Image *button_pl);
void initquitbutton(Image *button_q);
void afficherquitbutton(Image button_q , SDL_Surface *screen);
void initcreditbutton(Image *button_c);
void initsettingsbutton(Image *button_s);
void afficherplaybutton(Image button_p ,SDL_Surface *screen) ;
void initplaybutton(Image *button_p);
void affichersettingsbutton(Image button_s , SDL_Surface *screen);
void initbackground(Image*Backg);
void liberer(Image A);
void afficher(Image p ,SDL_Surface *screen);
void affichercreditsbutton(Image button_c , SDL_Surface *screen);



//partie perso

void initPerso(Personne *p);
void afficherPerso(Personne p , SDL_Surface *screen);
void animerPerso(Personne * p);
void deplacerPerso(SDL_Surface *screen , Personne *p , int dt );


void changeAnimation(Personne *p, char *name);

void initwhite(Image *white);
void afficherwhite(Image white,SDL_Surface *screen);

#endif
