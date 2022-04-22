#include <stdio.h>
#include "fonctions.h"
int main() {
TTF_Init();
SDL_Init(SDL_INIT_AUDIO |SDL_INIT_VIDEO);
int p=0,op=0,p2=0;
SDL_Surface *screen;
Mix_Music *music,*music2;
Mix_Chunk *son;
Image button_play,button_play_selectionne,button_options,button_options_selectionne,button_quit,button_quit_selectionne,Backg,image_options;
int done=0;
SDL_Event event;
Text t;
screen=SDL_SetVideoMode ( 1914,884,32, SDL_HWSURFACE | SDL_DOUBLEBUF|SDL_RESIZABLE );
if(!screen)
{
printf("unable to set 1536 x 864 video: %s\n", SDL_GetError());
return 1;
}
initBackground(&Backg);
initbutton_Play(&button_play);
initbutton_Play_selectionne(&button_play_selectionne);
initbutton_Options(&button_options);
initbutton_Options_selectionne(&button_options_selectionne);
initbutton_Quit(&button_quit);
initbutton_Quit_selectionne(&button_quit_selectionne);
initimage_options(&image_options);
initText(&t);

while(!done)
{
afficher(Backg,screen);
if(op==1)
afficher(image_options,screen);
else
{
switch(p)
{
case 0:

afficher(button_play,screen);
afficher(button_options,screen);
afficher(button_quit,screen);
displayText(t,screen);
break;
case 1:
afficher(button_play_selectionne,screen);
afficher(button_options,screen);
afficher(button_quit,screen);
displayText(t,screen);
break;
case 2:
afficher(button_play,screen);
afficher(button_options_selectionne,screen);
afficher(button_quit,screen);
displayText(t,screen);
break;
case 3:
afficher(button_play,screen);
afficher(button_options,screen);
afficher(button_quit_selectionne,screen);
displayText(t,screen);
break;
}
}
SDL_Flip(screen);

SDL_PollEvent(&event);
switch(event.type)
{
case SDL_KEYDOWN:
jouer_son_continu2();
switch(event.key.keysym.sym)
{
case SDLK_UP:
if (p==0||p==2)
p=1;
if (p==3)
p=2;
break;
case SDLK_DOWN:
if(p==0||p==2)
p=3;
if(p==1)
p=2;
break;
case SDLK_SPACE:
if(p==3)
done=1;
if(p==2)
op=1;
//if(p==1)//



}

break;
case SDL_MOUSEMOTION:
if(event.motion.x>=750 && event.motion.x<=750+button_play.pos1.w && 
event.motion.y>=100&& event.motion.y<=100+button_play.pos1.h)
jouer_son_bref();
break;
case SDL_MOUSEBUTTONUP||SDL_MOUSEBUTTONDOWN:
if(event.motion.x>=0 && event.motion.x<=0+100 && 
event.motion.y>=100&& event.motion.y<=100+button_play.pos1.h)
jouer_son_bref();
break;
case SDL_QUIT:
done=1;
break;
}
}
liberer(button_play);
liberer(button_play_selectionne);
liberer(button_options);
liberer(button_options_selectionne);
liberer(button_quit);
liberer(button_quit_selectionne);
liberer(Backg);

liberer(image_options);
freeText(t);
TTF_CloseFont(t.font);
TTF_Quit();
Mix_FreeMusic(music);
Mix_FreeChunk(son);
return 0;
}
