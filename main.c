// Travail de Fernand Ouedraogo et Farida Savadogo pour le compte du projet

// Dernière modification: 20 Octobre 2022

// 🌍️🌍️ La fonction Principal du tour de Hannoï 🇧🇫️

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h> 
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

#include "fonctionJeu.h"
#include "fonctionJeu.c"

int main(int argc, char *argv[])
{
   // Chargement du mode vidéo
   if(SDL_Init(SDL_INIT_VIDEO) != 0)
   {
       fprintf(stderr,"Error SDL_Init: %s\n", SDL_GetError());
       return EXIT_FAILURE;
   }
   
   if(Mix_OpenAudio(
      MIX_DEFAULT_FREQUENCY,
      MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)
   {
         fprintf(stderr,"Erreur Audio: %s\n",Mix_GetError());
         return EXIT_FAILURE; 
   }      
   
   SDL_Window *ecran = NULL;
   SDL_Texture *texture = NULL,*tmp = NULL;
   SDL_Renderer *rendu = NULL;
   SDL_Surface *surface = NULL,*s = NULL;
   
   //Creation de l'ecran (la fenêtre)
   ecran = SDL_CreateWindow(
      "Tour De Hannoï",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_CENTERED,
      1000,
      520,
      SDL_WINDOW_RESIZABLE);

   if(ecran == NULL)
   {
       fprintf(stderr, "Error window(ecran): %s\n", SDL_GetError());
       return EXIT_FAILURE;
   }
   
   SDL_SetWindowIcon(ecran, IMG_Load("sdl_icone.bmp"));
   
   //Creation du rendu
   rendu = SDL_CreateRenderer(ecran, -1, SDL_RENDERER_ACCELERATED);
   if(rendu == NULL)
   {
       fprintf(stderr,"Error Renderer: %s\n", SDL_GetError());
       return EXIT_FAILURE;
   } 
   //Mettre le rendu en couleur blanc
   if(SDL_SetRenderDrawColor(rendu, 250, 250, 250, 100) != 0)
   {
       fprintf(stderr, "Error Render Color: %s\n", SDL_GetError());
       return EXIT_FAILURE;
   }
   //Effacer l'ecran pour qu'elle soit en blanc
   SDL_RenderClear(rendu);
   
   //Chargement de la surface en image
   surface = IMG_Load("108_Beautifull_Evening.jpg");
   if(surface == NULL)
   {
       fprintf(stderr, "Error Surface: %s\n", SDL_GetError());
       return EXIT_FAILURE;
   }
   //Creation d'une texture à partir de la surface
   texture=SDL_CreateTextureFromSurface(rendu, surface);
   if(texture == NULL)
   {
       fprintf(stderr, "Error window(ecran): %s\n", SDL_GetError());
       return EXIT_FAILURE;
   }
   //On libere la surface
   SDL_FreeSurface(surface);
   
   //Definition de quelques couleur
   SDL_Color blanc={255,255,255,255}, noir={0,0,0,255}, bleu={0,0,255,255};
   //Rectangle pour le titre
   SDL_Rect tour={200,10,0,0},lim;    
   
   int continuer = 1;
   SDL_Event event;
   while(continuer)
   {
      SDL_WaitEvent(&event);
      if(event.type == SDL_QUIT)
        continuer = 0;
      
      //Recuperaton et utilisation de l'état de la souris  
      Uint32 bouton;
      int x,y;
      bouton=SDL_GetMouseState(&x,&y);
      if(x>230 && x<360 && y>155 && y<200)
      {
         //Affichage de rectangle de limite
         lim.x = 230; lim.y = 155; lim.w = 130; lim.h = 45;
         SDL_SetRenderDrawColor(rendu, 250, 250, 250, 250);
         SDL_RenderDrawRect(rendu, &lim);
         SDL_RenderPresent(rendu);
         
         if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
         { 
            jouer(rendu);
         }
      }
      else if(x>230 && x<760 && y>205 && y<250)
      {
         //Affichage de rectangle de limite
         lim.x = 230; lim.y = 205; lim.w = 530; lim.h = 45;
         SDL_SetRenderDrawColor(rendu,250,250,250,250);
         SDL_RenderDrawRect(rendu,&lim);
         SDL_RenderPresent(rendu);
         
         if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
         {
              //jouer3(rendu);
              //Les 3 rectangles pour la sugestion de niveau 
               SDL_Rect d1={50,150,850,200}, d2={100,250,100,50};
               SDL_Rect d3={210,250,100,50};
               SDL_Rect d4={320,250,100,50}, d5={430,250,100,50};
               SDL_Rect d6={540,250,100,50}, d7={650,250,100,50};
               SDL_React d8={760,250,100,50};

               SDL_Rect t1={100,180,0,0}, t2={105,255,0,0};

               SDL_SetRenderDrawColor(rendu,0,0,150,255);
               SDL_RenderFillRect(rendu,&d1);
               SDL_SetRenderDrawColor(rendu,250,250,250,255);
               SDL_RenderFillRect(rendu,&d2);
               SDL_RenderFillRect(rendu,&d3);
               SDL_RenderFillRect(rendu,&d4);
               SDL_RenderFillRect(rendu,&d5);
               SDL_RenderFillRect(rendu,&d6);
               SDL_RenderFillRect(rendu,&d7);
               SDL_RenderFillRect(rendu,&d8);
               SDL_SetRenderDrawColor(rendu,0,0,0,255);

               EcrireTextDirect(rendu, "Etiez-vous a quel niveau ?", t1, noir, 25);
               EcrireTextDirect(rendu,"Niveau 1",t2,noir,25);
               t2.x+=107;
               EcrireTextDirect(rendu,"Niveau 2",t2,noir,25);
               t2.x+=110;
               EcrireTextDirect(rendu,"Niveau 3",t2,noir,25);
               t2.x+=110;
               EcrireTextDirect(rendu,"Niveau 4",t2,noir,25);
               t2.x+=110;
               EcrireTextDirect(rendu,"Niveau 5",t2,noir,25);
               t2.x+=110;
               EcrireTextDirect(rendu,"Niveau 6",t2,noir,25);
               t2.x+=110;
               EcrireTextDirect(rendu,"Niveau 7",t2,noir,25);
               SDL_RenderPresent(rendu);
               
               int c=1;
               SDL_Event e;
               while(c == 1)
               {
                   SDL_WaitEvent(&e);
                   //Recuperaton et utilisation de l'état de la souris  
                   Uint32 bouton;
                   int x,y;
                   bouton=SDL_GetMouseState(&x,&y);
                   if(x>d2.x && x<d2.x+d2.w && y>d2.y && y<d2.y+d2.h)
                   {
                      if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
                      {
                         jouer(rendu);
                         c=0;
                      }
                   }
                   else if(x>d3.x && x<d3.x+d3.w && y>d3.y && y<d3.y+d3.h)
                   {
                      if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
                      {
                         jouer2(rendu);
                         c=0;
                      }
                   }
                   else if(x>d4.x && x<d4.x+d4.w && y>d4.y && y<d4.y+d4.h)
                   {
                      if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
                      {
                         jouer3(rendu);
                         c=0;
                      }
                   }
                   else if(x>d5.x && x<d5.x+d5.w && y>d5.y && y<d5.y+d5.h)
                   {
                      if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
                      {
                         jouer4(rendu);
                         c=0;
                      }
                   }
                   else
                   {
                      if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT)) 
                         c=0;
                   }
               }
         }
      }
      else if(x>230 && x<480 && y>255 && y<300)
      {
         //Affichage de rectangle de limite
         lim.x = 230; lim.y = 255; lim.w = 250; lim.h = 45;
         SDL_SetRenderDrawColor(rendu,250,250,250,250);
         SDL_RenderDrawRect(rendu,&lim);
         SDL_RenderPresent(rendu);
         
         if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
         {
            int v=1;
            SDL_Rect t={50,20,0,0};
            SDL_SetRenderDrawColor(rendu,250,250,250,100);         
            SDL_RenderClear(rendu);

            EcrireTextDirect(
               rendu,
               "    REGLE GENERAL DU JEU DU TOUR DE HANNOI",
               t, bleu, 25);

            t.y+=70;
            EcrireTextDirect(
               rendu,"-> On ne peut deplacer plus d'un disque a la fois",
               t, noir, 25);

            t.y+=35;
            EcrireTextDirect(
               rendu,
               "-> On ne peut placer un disque que sur un autre"
               " plus grand que lui ou une place vide",
               t, noir, 25);

            t.y+=35;
            EcrireTextDirect(
               rendu,
               "-> On suppose que cette derniere regle est respecter"
               " dans la configuration de depart", 
               t, noir, 25);

            t.y+=35;
            EcrireTextDirect(
               rendu,
               "-> Vous aurez un nombre minimal de deplacement pour "
               "gagner a chaque fois",
               t, noir, 25);

            t.y+=35;
            EcrireTextDirect(
               rendu,
               "-> Tapez sur la touche Entrer si vous finissez de lire",
               t, noir, 25);

            SDL_RenderPresent(rendu); 
            while(v==1)
            { 
                 SDL_Event e;
                 SDL_WaitEvent(&e);
                 if(e.type == SDL_QUIT)
                      v=0;
                 if(e.key.keysym.sym==SDLK_RETURN)
                      v=0;
            } 
         }
      }
      else if(x>230 && x<410 && y>305 && y<350)
      {
         //Affichage de rectangle de limite
         lim.x = 230; lim.y = 305; lim.w = 180; lim.h = 45;
         SDL_SetRenderDrawColor(rendu,250,250,250,250);
         SDL_RenderDrawRect(rendu,&lim);
         SDL_RenderPresent(rendu);
         
         if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
         {
            //Les 3 rectangles pour la sugestion de recommencer 
               SDL_Rect d1={200,150,500,200}, d2={250,250,75,50},
               SDL_React d3={350,250,75,50};
               SDL_Rect t1={250,180,0,0},t2={255,255,0,0};

               SDL_SetRenderDrawColor(rendu,250,0,0,255);
               SDL_RenderFillRect(rendu,&d1);
               SDL_SetRenderDrawColor(rendu,0,250,250,255);
               SDL_RenderFillRect(rendu,&d2);
               SDL_RenderFillRect(rendu,&d3);
               SDL_SetRenderDrawColor(rendu,0,0,0,255);

               EcrireTextDirect(rendu,"Etes-vous sure de Quitter ?",t1,noir,25);
               EcrireTextDirect(rendu,"Oui",t2,noir,25);

               t2.x+=100;
               EcrireTextDirect(rendu,"Non",t2,noir,25);
               SDL_RenderPresent(rendu);
               
               int c=1;
               SDL_Event e;
               while(c == 1)
               {
                   SDL_WaitEvent(&e);
                   //Recuperaton et utilisation de l'état de la souris  
                   Uint32 bouton;
                   int x,y;
                   bouton=SDL_GetMouseState(&x,&y);
                   if(x>d2.x && x<d2.x+d2.w && y>d2.y && y<d2.y+d2.h)
                   {
                      if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
                         c=0;
                   }
                   else if(x>d3.x && x<d3.x+d3.w && y>d3.y && y<d3.y+d3.h)
                   {
                      if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
                         goto la;
                   }
               }
            continuer=0;
         }
       }  
       la:
       //Coller l'image à l'ecran
       SDL_RenderCopy(rendu, texture, NULL, NULL);
       
       EcrireText(rendu, "TOUR DE HANNOI", tour, blanc, 100);
       
       SDL_Rect posiText={250, 150, 0, 0};
       EcrireTextDirect(rendu, "Jouer", posiText, blanc, 40);
       posiText.y+=50;
       EcrireTextDirect(rendu, "Continuer au niveau arreter", posiText, blanc, 40);
       posiText.y+=50;
       EcrireTextDirect(rendu, "Instructions", posiText, blanc, 40);
       posiText.y+=50;
       EcrireTextDirect(rendu, "Arreter", posiText, blanc, 40);
       //Signature
       SDL_Rect sig={700,450,0,0};
       EcrireTextDirect(rendu, "Par Fernand et Farida", sig, bleu, 25);
       
       Mix_PauseMusic();

       SDL_RenderPresent(rendu);
     } 
     SDL_DestroyWindow(ecran);
     SDL_DestroyTexture(tmp);
     SDL_DestroyRenderer(rendu); 
     Mix_CloseAudio(); //Fermeture de l'API
     SDL_Quit();
     return EXIT_SUCCESS;
}
