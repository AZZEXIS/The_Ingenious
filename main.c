#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "picture.c"
#include "perso.c"


int main()
{
//declaration var
    int x=0,z=0,k=1,vol3,vol2,vol1,mute,dt;
    SDL_Event event;
    Mix_Chunk * pressbutton , *cursoron;
    Mix_Music * music;
    Input input;
    Image button_p,button_s,button_c,button_q,button_pl,button_sl,button_cl,button_ql;

    Image button_lvs,button_lvl,button_lms,button_lml,button_lhl,button_lhs,button_lmul,button_lmus;

    Image Backg,creditsbackg,settignsbackg,white;

    Personne p;


    SDL_Surface *screen;
    int done = 1 ;
   
    atexit(SDL_Quit);





//create a window
    screen=SDL_SetVideoMode ( SCREEN_W,SCREEN_H,32, SDL_HWSURFACE | SDL_DOUBLEBUF ) ;
    if(!screen)
    {
        printf("Unable to set 1440x966 : %s \n",SDL_GetError());
        return 1;
    }
    if (Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS,1024)==-1)
    {
        printf("%s",Mix_GetError());
    }

//init des variables


    /*SDL_Init(SDL_INIT_EVERYTHING);
       TTF_Init();
        */
    initlowvbl(&button_lvl);
    initlowvbs(&button_lvs);
    initmediumvbl(&button_lml);
    initmediumvbs(&button_lms);
    inithighvs(&button_lhs);
    inithighvl(&button_lhl);
    initmutevl(&button_lmul);
    initmutevs(&button_lmus);
    initsettignsbackg(&settignsbackg);
    initcreditsbackground(&creditsbackg);
    initquitbuttonl(&button_ql);
    initcreditbuttonl(&button_cl);
    initsettingsbuttonl(&button_sl);
    initplaybuttonl(&button_pl);
    initbackground(&Backg);                          // load files make 1 later
    initplaybutton(&button_p);
    initsettingsbutton(&button_s);
    initcreditbutton(&button_c);
    initquitbutton(&button_q);

    p.x=0;
    p.direction=3;

    initwhite(&white);
    initPerso(&p);
    //textload(&txt);

//audio

    cursoron=Mix_LoadWAV("/home/firas/projetjeu/pics and sound/click.wav");    //click sound ffect
    pressbutton=Mix_LoadWAV("/home/firas/projetjeu/pics and sound/thunder-sound-effect.wav"); //thunder sound effect

    music=Mix_LoadMUS("/home/firas/projetjeu/pics and sound/back music.mp3"); //menu theme song
    Mix_PlayMusic(music,-1);








//play thunder effect   Mix_PlayChannel(-1,pressbutton,0);
//play click sound ffect  Mix_PlayChannel(-1,cursoron,0);


//MENU loop
do{

    while(done==1)
    {




        //// light button 1st try //////////////////////////////////////


 while( SDL_PollEvent(&event))
        {

            switch(event.type)
            {
            case SDL_QUIT:
            {
                done=0;
                break;
            }
   /////////////////////////////////////////////////////////////////////////////////
            case SDL_KEYDOWN:
            {
                if(event.key.keysym.sym == SDLK_DOWN ){x++;z=0;} else if ( event.key.keysym.sym == SDLK_UP ){x--;z=0;if(x==0){x=1;} }        //             SDLK_RETURN

                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    done=0;
                }
                break;}
    /////////////////////////////////////////////////////////////////////////////////

            case SDL_MOUSEMOTION:
            {
             if(event.motion.x >=15 && event.motion.x<=15+296 && event.motion.y>=390&& event.motion.y<=390+100){                   //play button hit box
             x=1;

            }else if(event.motion.x >=15 && event.motion.x<=15+296 && event.motion.y>=510&& event.motion.y<=510+100)              // settigns button hit box
              {
             x=2;

                }else if(event.motion.x >=15 && event.motion.x<=15+296 && event.motion.y>=640&& event.motion.y<=640+100)         //credits button hit box
                   {
            x=3;

                   }else if(event.motion.x >=15 && event.motion.x<=15+296 && event.motion.y>=770&& event.motion.y<=770+100 )      //quit button hit box

                      { x=4;
                              } else {x=0;z=0;}
             break;}

    /////////////////////////////////////////////////////////////////////////////////






        }
        }










           switch(x){

          case 0: afficher(Backg,screen);
                  afficherplaybutton(button_p,screen);
                  affichersettingsbutton(button_s,screen);          // all shadow
                  affichercreditsbutton(button_c,screen);
                  afficherquitbutton(button_q,screen);
                  SDL_Flip(screen);
           break;

          case 1:
               if(z==0){   Mix_PlayChannel(-1,cursoron,0); z=1;}
              afficher(Backg,screen);
              afficherplaybuttonl(button_pl,screen);
              affichersettingsbutton(button_s,screen);            // play light ,rest shadow
              affichercreditsbutton(button_c,screen);
              afficherquitbutton(button_q,screen);
              SDL_Flip(screen);
               if(event.type==SDL_MOUSEBUTTONDOWN || event.key.keysym.sym == SDLK_RETURN) { done =4;}  //enter play page
            break;

          case 2: if(z==0){   Mix_PlayChannel(-1,cursoron,0); z=1;}
              afficher(Backg,screen);
              afficherplaybutton(button_p,screen);
              affichersettingsbuttonl(button_sl ,screen);       //settigns light ,rest shadow
              affichercreditsbutton(button_c,screen);
              afficherquitbutton(button_q,screen);
              SDL_Flip(screen);
               if(event.type==SDL_MOUSEBUTTONDOWN || event.key.keysym.sym == SDLK_RETURN) { done =2;}     //enter settings page

               break;


          case 3:   if(z==0){   Mix_PlayChannel(-1,cursoron,0); z=1;}
               afficher(Backg,screen);
               afficherplaybutton(button_p,screen);
               affichersettingsbutton(button_s,screen);              //credits light ,rest shadow
               affichercreditsbuttonl(button_cl ,screen);
               afficherquitbutton(button_q,screen);
               SDL_Flip(screen);
                    if(event.type==SDL_MOUSEBUTTONDOWN || event.key.keysym.sym == SDLK_RETURN) { done =3;}    //enter credits page

               break;


        case 4:if(z==0){   Mix_PlayChannel(-1,cursoron,0); z=1;}
             afficher(Backg,screen);
             afficherplaybutton(button_p,screen);
             affichersettingsbutton(button_s,screen);              //quit light ,rest shadow
             affichercreditsbutton(button_c,screen);
             afficherquitbuttonl(button_ql,screen);
             if(event.type==SDL_MOUSEBUTTONDOWN || event.key.keysym.sym == SDLK_RETURN) { done =0;}          //press to quit
             SDL_Flip(screen);
               break;





 }






        ///////////////////////////////////////////////////////////////








       





    }

     z=0;
     x=0;
while(done==2)
    {


         /*affichersettignsbackg(settignsbackg,screen);
         SDL_Flip(screen);*/




                 while( SDL_PollEvent(&event))                                            //settigns page display
                      {

            switch(event.type)
            {
              case SDL_QUIT:
            {
                done=0;
                break;
            }

               case SDL_KEYDOWN:
            {
                    if(event.key.keysym.sym == SDLK_ESCAPE){done=1;}
                    break;
             }
              case SDL_MOUSEBUTTONDOWN :
          {if(event.button.button==SDL_BUTTON_LEFT && event.button.x>=794 && event.button.x<=821 && event.button.y>=649&& event.button.y<=794)
				{
					x=0;z=0;
				}
				else if(event.button.button==SDL_BUTTON_LEFT && event.button.x>=743 && event.button.x<=766 && event.button.y>=685&& event.button.y<=770)
				{
					x=1;z=0;
				}
				else if(event.button.button==SDL_BUTTON_LEFT && event.button.x>=692 && event.button.x<=716 && event.button.y>=721&& event.button.y<=768)
				{
					x=2;z=0;
				}
				else if(event.button.button==SDL_BUTTON_LEFT && event.button.x>=605 && event.button.x<=639 && event.button.y>=604&& event.button.y<=763)
				{
					x=3;z=0;
				}

                               else if(event.button.button==SDL_BUTTON_LEFT && event.button.x>=877 && event.button.x<=934 && event.button.y>=117&& event.button.y<=170)
                               {
                                 done=1;
                                 break;
                               }break;

              }


} }



switch(x){


case 0:
if(z==0){   Mix_PlayChannel(-1,cursoron,0);  z=1; }

 vol3 = Mix_VolumeMusic(vol3+30);     // volume up max
       vol3 = Mix_VolumeMusic(-1);



affichersettignsbackg(settignsbackg,screen);
afficherlowvbl(button_lvl ,screen);                    //all light mute shadow
affichermedvbl(button_lml ,screen);
afficherhighvbl(button_lhl ,screen);
affichermutevbs(button_lmus ,screen);
SDL_Flip(screen);

break;



case 1:
if(z==0){   Mix_PlayChannel(-1,cursoron,0);
vol2 = Mix_VolumeMusic(vol2-60);     // volume mid
       vol2 = Mix_VolumeMusic(-1); z=1;}




affichersettignsbackg(settignsbackg,screen);
afficherlowvbl(button_lvl ,screen);                    //low mid light mute high shadow
affichermedvbl(button_lml ,screen);
afficherhighvbs(button_lhs ,screen);
affichermutevbs(button_lmus ,screen);
SDL_Flip(screen);
break;

case 2:

if(z==0){   Mix_PlayChannel(-1,cursoron,0);
vol1 = Mix_VolumeMusic(vol1-100);     // volume low
       vol1 = Mix_VolumeMusic(-1); z=1;}



affichersettignsbackg(settignsbackg,screen);
afficherlowvbl(button_lvl ,screen);
affichermedvbs(button_lms ,screen);                   //low light rest shadow
afficherhighvbs(button_lhs ,screen);
affichermutevbs(button_lmus ,screen);
SDL_Flip(screen);
break;

case 3:
if(z==0){   Mix_PlayChannel(-1,cursoron,0); mute = Mix_VolumeMusic(mute-mute);    // mute
       mute = Mix_VolumeMusic(-1); z=1;}


affichersettignsbackg(settignsbackg,screen);
afficherlowvbs(button_lvs ,screen);
affichermedvbs(button_lms ,screen);                   //mute light rest shadow
afficherhighvbs(button_lhs ,screen);
affichermutevbl(button_lmul ,screen);
SDL_Flip(screen);
break;

 } }











while(done==3)
    {


       affichercreditsbackground(creditsbackg,screen);
         SDL_Flip(screen);




                 while( SDL_PollEvent(&event))
                      {

            switch(event.type)
            {
              case SDL_QUIT:
            {
                done=0;
                break;
            }

                                                                                 // credits page display
               case SDL_KEYDOWN:
            {
                    if(event.key.keysym.sym == SDLK_ESCAPE){done=1;}
                    break;
             }


} } }


while(done==4)
    {



//player
/////////////////////////////////////////////////////////////////////////






        afficherwhite(white,screen);
        afficherPerso(p,screen);
        animerPerso(&p);
        deplacerPerso(screen ,&p ,dt );
        SDL_Flip(screen);

        SDL_PollEvent(&event);
    
        switch (event.type)
        {

            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        done=1;
                    break;

                    case SDLK_LEFT:
                        p.direction=1;
                        
                    break;

                    case SDLK_RIGHT:
                         p.direction=0;

                    break;

                    case SDLK_SPACE:
                        p.direction=4;
                    break;

                    
                }
            break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {

                    case SDLK_LEFT:
                        p.direction=3;
                        p.accel=0;
                    break;

                    case SDLK_RIGHT:
                        p.direction=3;
                        p.accel=0;
                    break;

                    case SDLK_SPACE:
                        p.direction=3;
                        p.accel=0;
                        p.y=0;
                        p.pos2.y=0;
                    break;
	            
                    break;
                }
            break;

        }

//////////////////////////////////////////////////////////////////////////////
        




} 




         }while(done!=0);

}























