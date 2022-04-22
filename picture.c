#include "picture.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>


/////////////////////////////////////////////////////////////////////////////

void initsettignsbackg(Image *settignsbackg)
{
    settignsbackg->img=IMG_Load("/home/firas/projetjeu/pics and sound/settings background.png");
    if (settignsbackg->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;                                                                              
                                                                                      //settigns background load
    }

    settignsbackg->pos1.x=0;
    settignsbackg->pos1.y=0;
    settignsbackg->pos2.x=0;
    settignsbackg->pos2.y=0;
    settignsbackg->pos2.w=(SCREEN_W);
    settignsbackg->pos2.h=(SCREEN_H);
}

/////////////////////////////////////////////////////////////////////////////











void initcreditsbackground(Image *creditsbackg)
{
    creditsbackg->img=IMG_Load("/home/firas/projetjeu/pics and sound/credits background.png");
    if (creditsbackg->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;                                                                                 //credits background load
    }

    creditsbackg->pos1.x=0;
    creditsbackg->pos1.y=0;
    creditsbackg->pos2.x=0;
    creditsbackg->pos2.y=0;
    creditsbackg->pos2.w=(SCREEN_W);
    creditsbackg->pos2.h=(SCREEN_H);
}



void initbackground(Image *Backg)
{
    Backg->img=IMG_Load("/home/firas/projetjeu/pics and sound/pic 1.png");
    if (Backg->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;                                                                                 //background load
    }

    Backg->pos1.x=0;
    Backg->pos1.y=0;
    Backg->pos2.x=0;
    Backg->pos2.y=0;
    Backg->pos2.w=(SCREEN_W);
    Backg->pos2.h=(SCREEN_H);
}



///////////////////////////////

void initwhite(Image *white)
{
    white->img=IMG_Load("/home/firas/projetjeu/pics and sound/white screen.png");
    if (white->img == NULL)
    {
        printf("unable to load the white pic %s \n",SDL_GetError());
        return;                                                                                 //white screen load       **********************************
    }

    white->pos1.x=0;
    white->pos1.y=0;
    white->pos2.x=0;
    white->pos2.y=0;
    white->pos2.w=(SCREEN_W);
    white->pos2.h=(SCREEN_H);
}

void afficherwhite(Image white,SDL_Surface *screen)
{
    SDL_BlitSurface(white.img,&white.pos2,screen,&white.pos1);                         //display white pic    ********************************
}

////////



void initmutevs(Image *button_lmus)
{
    button_lmus->img=IMG_Load("/home/firas/projetjeu/pics and sound/volume pics/mute shadow.png");
    if (button_lmus->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //mute vl shadow button load
  
    button_lmus->muteb1.x=605;
    button_lmus->muteb1.y=720; 
    button_lmus->muteb2.x=0;
    button_lmus->muteb2.y=0;
    button_lmus->muteb2.w=(SCREEN_W);
    button_lmus->muteb2.h=(SCREEN_H);
}



void initmutevl(Image *button_lmul)
{
    button_lmul->img=IMG_Load("/home/firas/projetjeu/pics and sound/volume pics/mute light.png");
    if (button_lmul->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //mute vl light button load
  
    button_lmul->muteb1.x=605;
    button_lmul->muteb1.y=720; 
    button_lmul->muteb2.x=0;
    button_lmul->muteb2.y=0;
    button_lmul->muteb2.w=(SCREEN_W);
    button_lmul->muteb2.h=(SCREEN_H);
}


////////


void inithighvl(Image *button_lhl)
{
    button_lhl->img=IMG_Load("/home/firas/projetjeu/pics and sound/volume pics/high volume light.png");
    if (button_lhl->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //high vl light button load
  
    button_lhl->highb1.x=794;
    button_lhl->highb1.y=649; 
    button_lhl->highb2.x=0;
    button_lhl->highb2.y=0;
    button_lhl->highb2.w=(SCREEN_W);
    button_lhl->highb2.h=(SCREEN_H);
}





void inithighvs(Image *button_lhs)
{
    button_lhs->img=IMG_Load("/home/firas/projetjeu/pics and sound/volume pics/high volume shadow.png");
    if (button_lhs->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //high vl shadow button load
  
    button_lhs->highb1.x=794;
    button_lhs->highb1.y=649; 
    button_lhs->highb2.x=0;
    button_lhs->highb2.y=0;
    button_lhs->highb2.w=(SCREEN_W);
    button_lhs->highb2.h=(SCREEN_H);
}
















///////



void initmediumvbs(Image *button_lms)
{
    button_lms->img=IMG_Load("/home/firas/projetjeu/pics and sound/volume pics/meduim volume shadow.png");
    if (button_lms->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //med vl shadow button load
  
    button_lms->mediumb1.x=743;
    button_lms->mediumb1.y=685; 
    button_lms->mediumb2.x=0;
    button_lms->mediumb2.y=0;
    button_lms->mediumb2.w=(SCREEN_W);
    button_lms->mediumb2.h=(SCREEN_H);
}



void initmediumvbl(Image *button_lml)
{
    button_lml->img=IMG_Load("/home/firas/projetjeu/pics and sound/volume pics/medium volume light.png");
    if (button_lml->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //med vl light button load
  
    button_lml->mediumb1.x=743;
    button_lml->mediumb1.y=685; 
    button_lml->mediumb2.x=0;
    button_lml->mediumb2.y=0;
    button_lml->mediumb2.w=(SCREEN_W);
    button_lml->mediumb2.h=(SCREEN_H);
}




///////


void initlowvbs(Image *button_lvs)
{
    button_lvs->img=IMG_Load("/home/firas/projetjeu/pics and sound/volume pics/low volume shadow.png");
    if (button_lvs->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //low vl shadow button load
  
    button_lvs->lowb1.x=692;
    button_lvs->lowb1.y=721; 
    button_lvs->lowb2.x=0;
    button_lvs->lowb2.y=0;
    button_lvs->lowb2.w=(SCREEN_W);
    button_lvs->lowb2.h=(SCREEN_H);
}


void initlowvbl(Image *button_lvl)
{
    button_lvl->img=IMG_Load("/home/firas/projetjeu/pics and sound/volume pics/low volume light.png");
    if (button_lvl->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //low vl light button load
  
    button_lvl->lowb1.x=692;
    button_lvl->lowb1.y=721; 
    button_lvl->lowb2.x=0;
    button_lvl->lowb2.y=0;
    button_lvl->lowb2.w=(SCREEN_W);
    button_lvl->lowb2.h=(SCREEN_H);
}


/////////





















void initsettingsbutton(Image *button_s)
{
    button_s->img=IMG_Load("/home/firas/projetjeu/pics and sound/shadow settigns button.png");
    if (button_s->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //settigns button load
  
    button_s->posbs1.x=15;
    button_s->posbs1.y=510; 
    button_s->posbs2.x=0;
    button_s->posbs2.y=0;
    button_s->posbs2.w=(SCREEN_W);
    button_s->posbs2.h=(SCREEN_H);
}


void initcreditbutton(Image *button_c)
{
    button_c->img=IMG_Load("/home/firas/projetjeu/pics and sound/shadow credits button.png");
    if (button_c->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //credit button load
  
    button_c->posbc1.x=15;
    button_c->posbc1.y=640; 
    button_c->posbc2.x=0;
    button_c->posbc2.y=0;
    button_c->posbc2.w=(SCREEN_W);
    button_c->posbc2.h=(SCREEN_H);
}


void initplaybutton(Image *button_p)
{
    button_p->img=IMG_Load("/home/firas/projetjeu/pics and sound/shadow play button.png");
    if (button_p->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //playbutton load

    button_p->posbp1.x=15;
    button_p->posbp1.y=380; 
    button_p->posbp2.x=0;
    button_p->posbp2.y=0;
    button_p->posbp2.w=(SCREEN_W);
    button_p->posbp2.h=(SCREEN_H);
}




void initquitbutton(Image *button_q)
{
    button_q->img=IMG_Load("/home/firas/projetjeu/pics and sound/shadow quit button.png");
    if (button_q->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //quitbutton load

    button_q->posbq1.x=15;
    button_q->posbq1.y=770; 
    button_q->posbq2.x=0;
    button_q->posbq2.y=0;
    button_q->posbq2.w=(SCREEN_W);
    button_q->posbq2.h=(SCREEN_H);
}
///////////////////////////////////////////////////////////////////////////////


void initplaybuttonl(Image *button_pl)
{
    button_pl->img=IMG_Load("/home/firas/projetjeu/pics and sound/light play button.png");
    if (button_pl->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //playbutton load light

    button_pl->posbpl1.x=14;
    button_pl->posbpl1.y=380; 
    button_pl->posbpl2.x=0;
    button_pl->posbpl2.y=0;
    button_pl->posbpl2.w=(SCREEN_W);
    button_pl->posbpl2.h=(SCREEN_H);
}


void initsettingsbuttonl(Image *button_sl)
{
    button_sl->img=IMG_Load("/home/firas/projetjeu/pics and sound/light settings button.png");
    if (button_sl->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //settigns button load light
  
    button_sl->posbsl1.x=15;
    button_sl->posbsl1.y=510; 
    button_sl->posbsl2.x=0;
    button_sl->posbsl2.y=0;
    button_sl->posbsl2.w=(SCREEN_W);
    button_sl->posbsl2.h=(SCREEN_H);
}


void initcreditbuttonl(Image *button_cl)
{
    button_cl->img=IMG_Load("/home/firas/projetjeu/pics and sound/light credits button.png");
    if (button_cl->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //credit button load light
  
    button_cl->posbcl1.x=15;
    button_cl->posbcl1.y=640; 
    button_cl->posbcl2.x=0;
    button_cl->posbcl2.y=0;
    button_cl->posbcl2.w=(SCREEN_W);
    button_cl->posbcl2.h=(SCREEN_H);
}

void initquitbuttonl(Image *button_ql)
{
    button_ql->img=IMG_Load("/home/firas/projetjeu/pics and sound/light quit button.png");
    if (button_ql->img == NULL)
    {
        printf("unable to load the background pic %s \n",SDL_GetError());
        return;
    }                                                                                       //quitbutton load light

    button_ql->posbql1.x=15;
    button_ql->posbql1.y=770; 
    button_ql->posbql2.x=0;
    button_ql->posbql2.y=0;
    button_ql->posbql2.w=(SCREEN_W);
    button_ql->posbql2.h=(SCREEN_H);
}

/////////////////////////////////////////////////////////////////////////////





void liberer(Image A)
{
    SDL_FreeSurface(A.img);    
}


/////////////////////////////////////////////////////////////////////////////


void affichersettignsbackg(Image settignsbackg,SDL_Surface *screen)
{
    SDL_BlitSurface(settignsbackg.img,&settignsbackg.pos2,screen,&settignsbackg.pos1);                         //display settigns background pic
}






void affichercreditsbackground(Image creditsbackg,SDL_Surface *screen)
{
    SDL_BlitSurface(creditsbackg.img,&creditsbackg.pos2,screen,&creditsbackg.pos1);                         //display credits background pic
}




void afficher(Image backg,SDL_Surface *screen)
{
    SDL_BlitSurface(backg.img,&backg.pos2,screen,&backg.pos1);                         //display background pic
}




void afficherplaybutton(Image button_p ,SDL_Surface *screen)

{
    SDL_BlitSurface(button_p.img,&button_p.posbp2,screen,&button_p.posbp1);          //display playbutton pic 


}

void afficherplaybuttonl(Image button_pl ,SDL_Surface *screen)

{
    SDL_BlitSurface(button_pl.img,&button_pl.posbpl2,screen,&button_pl.posbpl1);          //display playbutton pic light


}


void affichersettingsbutton(Image button_s , SDL_Surface *screen)
{
    SDL_BlitSurface(button_s.img,&button_s.posbs2,screen,&button_s.posbs1);        //display settigns pic
 

}

void affichersettingsbuttonl(Image button_sl , SDL_Surface *screen)
{
    SDL_BlitSurface(button_sl.img,&button_sl.posbsl2,screen,&button_sl.posbsl1);        //display settigns pic light
 

}

void affichercreditsbutton(Image button_c , SDL_Surface *screen)
{
    SDL_BlitSurface(button_c.img,&button_c.posbc2,screen,&button_c.posbc1);        //display credits pic
 

}

void affichercreditsbuttonl(Image button_cl , SDL_Surface *screen)
{
    SDL_BlitSurface(button_cl.img,&button_cl.posbcl2,screen,&button_cl.posbcl1);        //display credits pic light
 

}

void afficherquitbutton(Image button_q , SDL_Surface *screen)
{
    SDL_BlitSurface(button_q.img,&button_q.posbq2,screen,&button_q.posbq1);        //display Quit pic
}


void afficherquitbuttonl(Image button_ql , SDL_Surface *screen)
{
    SDL_BlitSurface(button_ql.img,&button_ql.posbql2,screen,&button_ql.posbql1);        //display Quit pic light
}


//
void afficherlowvbl(Image button_lvl , SDL_Surface *screen)
{
    SDL_BlitSurface(button_lvl.img,&button_lvl.lowb2,screen,&button_lvl.lowb1);        //display low v light pic 
}


void afficherlowvbs(Image button_lvs , SDL_Surface *screen)
{
    SDL_BlitSurface(button_lvs.img,&button_lvs.lowb2,screen,&button_lvs.lowb1);        //display low v shadow pic 
}


//

void affichermedvbl(Image button_lml , SDL_Surface *screen)
{
    SDL_BlitSurface(button_lml.img,&button_lml.mediumb2,screen,&button_lml.mediumb1);        //display meduim v light pic 
}


void affichermedvbs(Image button_lms , SDL_Surface *screen)
{
    SDL_BlitSurface(button_lms.img,&button_lms.mediumb2,screen,&button_lms.mediumb1);        //display meduim v shadow pic 
}


//

void afficherhighvbs(Image button_lhs , SDL_Surface *screen)
{
    SDL_BlitSurface(button_lhs.img,&button_lhs.highb2,screen,&button_lhs.highb1);        //display high v shadow pic 
}


void afficherhighvbl(Image button_lhl , SDL_Surface *screen)
{
    SDL_BlitSurface(button_lhl.img,&button_lhl.highb2,screen,&button_lhl.highb1);        //display high v light pic 
}

//


void affichermutevbl(Image button_lmul , SDL_Surface *screen)
{
    SDL_BlitSurface(button_lmul.img,&button_lmul.muteb2,screen,&button_lmul.muteb1);        //display mute v light pic 
}


void affichermutevbs(Image button_lmus , SDL_Surface *screen)
{
    SDL_BlitSurface(button_lmus.img,&button_lmus.muteb2,screen,&button_lmus.muteb1);        //display mute v shadow pic 
}













