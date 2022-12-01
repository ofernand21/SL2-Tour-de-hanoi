// Travail de Fernand Ouedraogo et Farida Savadogo pour le compte du projet

// Dernière modification: 20 Octobre 2022

// 🌍️🌍️ Les fonction jouer du tour de Hannoï 🇧🇫️

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

#include "fonction.h"
#include "fonction.c"

//💻️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️ Fonction de niveau 4 🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️
void jouer4(SDL_Renderer* renderer)
{
  //Rectangle des 3 tours
  SDL_Rect T1 = {240, 200, 20, 232}, T2 = {490, 200, 20, 232};
  SDL_Rect T3 = {740, 200, 20, 232};
  //Rectangle des 5 disques
  SDL_Rect D1 = {210, 416,  80, 16},  D2 = {215, 400, 70, 16};
  SDL_Rect D3 = {220, 384, 60, 16}, D4 = {225, 368, 50, 16};
  SDL_Rect D5 = {230, 352, 40, 16}, D6 = {235, 336,  30, 16};
  //Couleur
  SDL_Color blanc = {255,255,255,255}, noir = {0,0,0,255}, bleu = {0,0,255,255};

   Mix_Music *musique,*son;
   musique = Mix_LoadMUS("Wiz_Khalifa_-_See_You_Again_ft._Charlie_Puth.mp3");
   son = Mix_LoadMUS("APPLAUDISSEMENTS_-_Bruitage_Gratuit(256k).mp3");
   //Jouer la musique
   Mix_PlayMusic(musique, -1);

  char nbre[4];
  int continuer = 1, deplacement = 0;
  SDL_Event event;

   while(continuer)
   {
        //Gestion du temps
        int heures, minutes, secondes;
        Uint32 temps;
        temps = SDL_GetTicks();
        heures = ((temps/1000)/3600)%24;
        minutes = ((temps/1000)/60)%60;
        secondes = (temps/1000)%60;
        //Conversion du temps en char
        char h[3], min[3], sec[3] ;
        sprintf(h, "%d", heures);
        sprintf(min, "%d", minutes);
        sprintf(sec, "%d", secondes);

        //Rectangle des ecritures
        SDL_Rect text = {860,20,200,40}, r = {855,10,135,40};
        SDL_Rect t = {100,470,0,0}, p = {170,475,30,22};

        debut:
        SDL_PollEvent(&event);

        //Bouger le disque rouge (le plus petit)
        if(event.key.keysym.sym == SDLK_1)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                  if(
                     Deja(D1, D6, x, y) == 1 && Deja(D2, D6, x, y) == 1 && 
                     Deja(D3, D6, x, y) == 1 && Deja(D4, D6, x, y) == 1 && 
                     Deja(D5, D6, x, y) == 1 && ok4(D1, D2, D3, D4, D5) ==1)
                  {
                     D6.x = x;
                     D6.y = y;
                  }
               }
           }
        }

        //Bouger le disque bleu (le 2e plus petit)
        if(event.key.keysym.sym == SDLK_2)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                  // ckeck if D5 not over D6 before move D5
                  if(D6.x != D5.x+5 && D6.y != D5.y-16)
                  {
                     if(
                        Deja(D1, D5, x, y) == 1 && Deja(D2, D5, x, y) == 1 && 
                        Deja(D3, D5, x, y) == 1 && Deja(D4, D5, x, y) == 1 && 
                        Deja(D6, D5, x, y) == 1 && ok4(D1, D2, D3, D4, D6) == 1)
                     {
                        D5.x = x;
                        D5.y = y;
                     }
                  }
                  else if(D6.y == D5.y-16)
                  {
                     if(D6.x != D5.x+5)
                     {
                        D5.x = x;
                        D5.y = y;
                     }
                  }
               }
           }
        }
        //Bouger le disque jaune (le 1er moyen)
        else if(event.key.keysym.sym == SDLK_3)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                 if(
                  D5.x != D4.x+5 && D5.y != D4.y-16 &&
                  D6.x != D4.x+10 && D6.y != D4.y-16)
                 {
                    if(
                     Deja(D1, D4, x, y) == 1 && Deja(D2, D4, x, y) == 1 &&
                     Deja(D3, D4, x, y) == 1 && Deja(D5, D4, x, y) == 1 &&
                     Deja(D6, D4, x, y) == 1 && ok4(D1, D2, D3, D5, D6) == 1)
                    {
                       D4.x = x;
                       D4.y = y;
                    }
                 }
                 else if(D5.y == D4.y-16 && D6.y == D4.y-16)
                 {
                     if(D6.x != D4.x+10 && D5.x != D4.x+5)
                     {
                        D4.x = x;
                        D4.y = y;
                     }
                }
                 else if(D6.y == D4.y-16)
                 {
                     if(D6.x != D4.x+10)
                     {
                        D4.x = x;
                        D4.y = y;
                     }
                }
                else if(D5.y == D4.y-16)
                 {
                     if(D5.x != D4.x+5)
                     {
                        D4.x = x;
                        D4.y = y;
                     }
                }
            }
          }
        }
        //Bouger le disque vert (le moyen grand)
        else if(event.key.keysym.sym == SDLK_4)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                 if(
                  D4.x != D3.x+5 && D4.y != D3.y-16 && D5.x != D3.x+10 && 
                  D5.y != D3.y-16 && D6.x != D3.x+15 && D6.y != D3.y-16)
                 {
                    if
                    (
                     Deja(D1, D3, x, y) == 1 && Deja(D2, D3, x, y) == 1 &&
                     Deja(D4, D3, x, y) == 1 && Deja(D5, D3, x, y) == 1 &&
                     Deja(D6, D3, x, y) == 1 && ok4(D1, D2, D4, D5, D6) ==1)
                    {
                       D3.x = x;
                       D3.y = y;
                    }
                 }
                 else if(D5.y == D3.y-16 && D4.y == D3.y-16)
                 {
                     if(D5.x != D3.x+10 && D4.x != D3.x+5)
                     {
                        D3.x = x;
                        D3.y = y;
                     }
                 }
                 else if(D5.y == D3.y-16 && D6.y == D3.y-16)
                 {
                     if(D5.x != D3.x+10 && D6.x != D3.x+15)
                     {
                        D3.x = x;
                        D3.y = y;
                     }
                }
                else if(D4.y == D3.y-16 && D6.y == D3.y-16)
                 {
                     if(D6.x != D3.x+15 && D4.x != D3.x+5)
                     {
                        D3.x = x;
                        D3.y = y;
                     }
                }
                else if(D5.y == D3.y-16)
                 {
                     if(D5.x != D3.x+10)
                     {
                        D3.x = x;
                        D3.y = y;
                     }
                }
                else if(D4.y == D3.y-16)
                {
                     if(D4.x != D3.x+5)
                     {
                        D3.x = x;
                        D3.y = y;
                     }
                }
                else if(D6.y == D3.y-16)
                 {
                     if(D6.x != D3.x+15)
                     {
                        D3.x = x;
                        D3.y = y;
                     }
                }
            }
          }
        }
        //Bouger le disque orange (le plus grand)
        else if(event.key.keysym.sym == SDLK_5)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                 if(
                  D3.x != D2.x+5 && D3.y != D2.y-16 && D4.x != D2.x+10 &&
                  D4.y != D2.y-16 && D5.x != D2.x+15 && D5.y != D2.y-16 && 
                  D6.x != D2.x+20 && D6.y != D2.y-16)
                 {
                    if(
                     Deja(D1, D2, x, y) == 1 && Deja(D3, D2, x, y) == 1 && 
                     Deja(D4, D2, x, y) == 1 && Deja(D5, D2, x, y) == 1 && 
                     Deja(D6, D2, x, y) == 1 && ok4(D1, D3, D4, D5, D6) == 1)
                    {
                       D2.x = x;
                       D2.y = y;
                    }
                 }
                 else if(D4.y == D2.y-16 && D3.y == D2.y-16)
                 {
                     if(D4.x != D2.x+10 && D3.x != D2.x+5)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D4.y == D2.y-16 && D5.y == D2.y-16)
                 {
                     if(D4.x != D2.x+10 && D5.x != D2.x+15)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D4.y == D2.y-16 && D6.y == D2.y-16)
                 {
                     if(D4.x != D2.x+10 && D6.x != D2.x+20)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D5.y == D2.y-16 && D6.y == D2.y-16)
                 {
                     if(D5.x != D2.x+15 && D6.x != D2.x+20)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D5.y == D2.y-16 && D3.y == D2.y-16)
                 {
                     if(D5.x != D2.x+15 && D3.x != D2.x+5)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D6.y == D2.y-16 && D3.y == D2.y-16)
                 {
                     if(D6.x != D2.x+20 && D3.x != D2.x+5)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                 else if(D4.y == D2.y-16)
                 {
                     if(D4.x != D2.x+10)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D3.y == D2.y-16)
                {
                     if(D3.x != D2.x+5)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D5.y == D2.y-16)
                 {
                     if(D5.x != D2.x+15)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D6.y == D2.y-16)
                 {
                     if(D6.x != D2.x+20)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
            }
          }
        }
        else if(event.key.keysym.sym == SDLK_6)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                 if(
                  D2.x != D1.x+5 && D2.y != D1.y-16 && D3.x != D1.x+10 && 
                  D3.y != D1.y-16 && D4.x != D1.x+15 && D4.y != D1.y-16 && 
                  D5.x != D1.x+20 && D5.y != D1.y-16 && D6.x != D1.x+25 && 
                  D6.y != D1.y-16)
                 {
                    if(
                     Deja(D2, D1, x, y) == 1 && Deja(D2, D3, x, y) == 1 && 
                     Deja(D2, D4, x, y) == 1 && Deja(D2, D5, x, y) == 1 && 
                     Deja(D2, D6, x, y) == 1 && ok4(D2, D3, D4, D5, D6) == 1)
                    {
                       D1.x = x;
                       D1.y = y;
                    }
                 }
                 else if(D3.y == D1.y-16 && D2.y == D1.y-16)
                 {
                     if(D3.x != D1.x+10 && D2.x != D1.x+5)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D3.y == D1.y-16 && D4.y == D1.y-16)
                 {
                     if(D3.x != D1.x+10 && D4.x != D1.x+15)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D3.y == D1.y-16 && D5.y == D1.y-16)
                 {
                     if(D3.x != D1.x+10 && D5.x != D1.x+20)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D3.y == D1.y-16 && D6.y == D1.y-16)
                 {
                     if(D3.x != D1.x+10 && D6.x != D1.x+25)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D4.y == D1.y-16 && D5.y == D1.y-16)
                 {
                     if(D4.x != D1.x+15 && D5.x != D1.x+20)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D4.y == D1.y-16 && D6.y == D1.y-16)
                 {
                     if(D4.x != D1.x+15 && D6.x != D1.x+25)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D4.y == D1.y-16 && D2.y == D1.y-16)
                 {
                     if(D4.x != D1.x+15 && D2.x != D1.x+5)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D5.y == D1.y-16 && D2.y == D1.y-16)
                 {
                     if(D5.x != D1.x+20 && D2.x != D1.x+5)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D5.y == D1.y-16 && D6.y == D1.y-16)
                 {
                     if(D5.x != D1.x+20 && D6.x != D1.x+25)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                 else if(D3.y == D1.y-16)
                 {
                     if(D3.x != D1.x+10)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D2.y == D1.y-16)
                {
                     if(D2.x != D1.x+5)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D4.y == D1.y-16)
                 {
                     if(D4.x != D1.x+15)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D5.y == D1.y-16)
                 {
                     if(D5.x != D1.x+20)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D6.y == D1.y-16)
                 {
                     if(D6.x != D1.x+25)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
            }
          }
        }

       SDL_SetRenderDrawColor(renderer,255,255,255,255);
       SDL_RenderClear(renderer);
       //Tracer la ligne de separation en noir
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawLine(renderer,850,0,850,500);
       //Construire les 3 tours en violet
       SDL_SetRenderDrawColor(renderer,150,100,155,255);
       SDL_RenderFillRect(renderer,&T1);
       SDL_RenderFillRect(renderer,&T2);
       SDL_RenderFillRect(renderer,&T3);
       //Ecrire le text
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Instrutions", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Recommencer", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Solution", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Sortir", text,noir,20);
       //Ecrire le text du bas
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Disque", t,noir,20);
       SDL_RenderDrawRect(renderer,&p);
       p.x+=5, p.y+=1;
       EcrireTextDirect(renderer, "5", p,noir,20);
       t.x+=150;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Deplacements Min:", t,noir,20);
       p.x+=260;p.y-=3;
       EcrireTextDirect(renderer, "63", p,noir,20);
       t.x+=250;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Deplacements:", t,noir,20);



       //🧡️🧡️🧡️🧡️🧡️🧡️pour 1er disque🧡️🧡️🧡️🧡️

       SDL_SetRenderDrawColor(renderer,255,100,10,255);

       if(D1.x>180 && D1.x<250 && D1.y>118 && D1.y<184)
       {
         //on est sur la 1ère tour✅️
         if(
         D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400 && 
         D4.x==225 && D4.y==384 && D5.x==230 && D5.y==368 && 
         D6.x==235 && D6.y==352)
         {
            /* if the 5 others disques (D2, D3, D4, D5, D6) is 
            crowded(entassé) alors D1 peut pas se position sur la tour*/
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(
         D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400 && 
         D4.x==225 && D4.y==384 && D5.x==230 && D5.y==368)
         {
         /*/ if the 4 others disques (D2, D3, D4, D5) 
         is crowded(entassé) D1 n'entre pas */
         SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
         SDL_RenderFillRect(renderer,&D1);
         EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(
            D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400 && 
            D4.x==225 && D4.y==384 && D6.x==235 && D6.y==368)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(
            D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400 && 
            D5.x==230 && D5.y==384 && D6.x==235 && D6.y==368)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(
            D2.x==215 && D2.y==416 && D3.x==220 && 
            D3.y==400 && D4.x==225 && D4.y==384)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(
            D2.x==215 && D2.y==416 && D4.x==225 && D4.y==400 && 
            D5.x==230 && D5.y==384)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(
            D2.x==215 && D2.y==416 && D4.x==225 && D4.y==400 &&
            D6.x==235 && D6.y==384)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "5", D,noir,10);
         }
         else if(
            D2.x==215 && D2.y==416 && D5.x==230 && D5.y==400 && 
            D6.x==235 && D6.y==384)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "5", D,noir,10);
         }
         else if(
            D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400 && 
            D5.x==230 && D5.y==384)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(
            D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400 && 
            D6.x==235 && D6.y==384)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(
            D3.x==220 && D3.y==416 && D5.x==230 && D5.y==400 && 
            D6.x==235 && D6.y==384)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(D3.x==220 && D3.y==416 && D5.x==230 && D5.y==400)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(D3.x==220 && D3.y==416 && D6.x==235 && D6.y==400)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(D2.x==215 && D2.y==416 && D4.x==225 && D4.y==400)
         {
            /* if the 4 others disques (D2, D3, D4, D6) 
            is crowded(entassé) D1 n'entre pas */
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400)
         {
            // if the 4 others disques (D2, D3) is crowded(entassé) D1 n'entre pas
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(D2.x==215 && D2.y==416 && D5.x==230 && D5.y==400)
         {
            // if the 4 others disques (D2, D5) is crowded(entassé) D1 n'entre pas
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(D2.x==215 && D2.y==416 && D6.x==235 && D6.y==400)
         {
            // if the 4 others disques (D2, D6) is crowded(entassé) D1 n'entre pas
            SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D1);
            EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(D4.x==225 && D4.y==416 && D5.x==230 && D5.y==400)
         {
             // if the 4 others disques (D4, D5) is crowded(entassé) D1 n'entre pas
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(D4.x==225 && D4.y==416 && D6.x==235 && D6.y==400)
         {
             // if the 4 others disques (D4, D6) is crowded(entassé) D1 n'entre pas
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(D5.x==230 && D5.y==416 && D6.x==235 && D6.y==400)
         {
             // if the 4 others disques (D4, D6) is crowded(entassé) D1 n'entre pas
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
         }
         else if(D2.x==215 && D2.y==416)
         {
             //si y'a un disque D1 entre pas
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416)
          {
             //si y'a un disque D1 entre pas
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D4.x==225 && D4.y==416)
          {
             //si y'a un disque D1 entre pas
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D5.x==230 && D5.y==416)
          {
             //si y'a un disque D1 entre pas
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D6.x==235 && D6.y==416)
          {
             //si y'a un disque D1 entre pas
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else
          {
             //si y'a un disque D1 entre pas
             D1.x=210 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
             deplacement++;
          }
       }
       else if(D1.x>430 && D1.x<500 && D1.y>118 && D1.y<184)
       {
          //on est sur la 2e tour✅️
          if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384 && D5.x==480 && D5.y==368 && D6.x==485 && D6.y==352)
          {
             //if the 5 others disques (D2, D3, D4, D5, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384 && D5.x==480 && D5.y==368)
          {
             //if the 4 others disques (D2, D3, D4, D5) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384 && D6.x==485 && D6.y==368)
          {
             //if the 4 others disques (D2, D3, D4, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400 && D5.x==480 && D5.y==384 && D6.x==485 && D6.y==368)
          {
             //if the 4 others disques (D2, D3, D4, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384)
          {
             //if the 3 others disques (D2, D3, D4) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400 && D5.x==480 && D5.y==384)
          {
             //if the 3 others disques (D2, D3, D5) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400 && D6.x==485 && D6.y==384)
          {
             //if the 3 others disques (D2, D3, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D4.x==475 && D4.y==400 && D5.x==480 && D5.y==384)
          {
             //if the 3 others disques (D2, D4, D5) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D4.x==475 && D4.y==400 && D6.x==485 && D6.y==384)
          {
             //if the 3 others disques (D2, D4, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D5.x==480 && D5.y==400 && D6.x==485 && D6.y==384)
          {
             //if the 3 others disques (D2, D5, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400 && D5.x==480 && D5.y==384)
          {
             //if the 3 others disques (D3, D4, D5) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400 && D6.x==485 && D6.y==384)
          {
             //if the 3 others disques (D3, D4, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D5.x==480 && D5.y==400 && D6.x==485 && D6.y==384)
          {
             //if the 3 others disques (D3, D4, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400)
          {
             //if the 3 others disques (D2, D3) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D4.x==475 && D4.y==400)
          {
             //if the 2 others disques (D2, D4) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D5.x==480 && D5.y==400)
          {
             //if the 2 others disques (D2, D5) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D6.x==485 && D6.y==400)
          {
             //if the 2 others disques (D2, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400)
          {
             //if the 2 others disques (D3, D4) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D5.x==480 && D5.y==400)
          {
             //if the 2 others disques (D3, D5) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D6.x==485 && D6.y==400)
          {
             //if the 2 others disques (D3, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D4.x==475 && D4.y==416 && D5.x==480 && D5.y==400)
          {
             //if the 2 others disques (D4, D5) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D4.x==475 && D4.y==416 && D6.x==485 && D6.y==400)
          {
             //if the 2 others disques (D4, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D5.x==480 && D5.y==416 && D6.x==485 && D6.y==400)
          {
             //if the 2 others disques (D4, D6) is crowded(entassé) alors D1 peut pas se position sur la tour
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416)
          {
             //D1 se pose pas sur un disque
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D4.x==475 && D4.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D5.x==480 && D5.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D6.x==485 && D6.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else
          {
             D1.x=460 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
             deplacement++;
          }
       }
       else if(D1.x>680 && D1.x<750 && D1.y>118 && D1.y<184)
       {
          //on est sur la 3e tour✅️
          if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384 && D5.x==730 && D5.y==368 && D6.x==735 && D6.y==352)
          {
             // if the disque (D2, D3, D4, D5, D6) is crowded D1 cant pose
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384 && D5.x==730 && D5.y==368)
          {
             // if the disque (D2, D3, D4, D5) is crowded D1 cant pose
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384 && D6.x==735 && D6.y==368)
          {
             // if the disque (D2, D3, D4, D5) is crowded D1 cant pose
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400 && D5.x==730 && D5.y==384 && D6.x==735 && D6.y==368)
          {
             // if the disque (D2, D3, D4, D5) is crowded D1 cant pose
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384)
          {
             // if the disque (D2, D3, D4) is crowded D1 cant pose
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400 && D5.x==730 && D5.y==384)
          {
             // if the disque (D2, D3, D5) is crowded D1 cant pose
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400 && D6.x==735 && D6.y==384)
          {
             // if the disque (D2, D3, D6) is crowded D1 cant pose
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D4.x==725 && D4.y==400 && D5.x==730 && D5.y==384)
          {
             // if the disque (D2, D4, D5) is crowded D1 cant pose
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D4.x==725 && D4.y==400 && D6.x==735 && D6.y==384)
          {
             // if the disque (D2, D4, D6) is crowded D1 cant pose
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D5.x==730 && D5.y==400 && D6.x==735 && D6.y==384)
          {
             // if the disque (D2, D4, D6) is crowded D1 cant pose
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400 && D5.x==730 && D5.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D5.x==730 && D5.y==400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D4.x==725 && D4.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D5.x==730 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D6.x==735 && D6.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D5.x==730 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D6.x==735 && D6.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D4.x==725 && D4.y==416 && D5.x==730 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D4.x==725 && D4.y==416 && D6.x==735 && D6.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D5.x==730 && D5.y==416 && D6.x==735 && D6.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D4.x==725 && D4.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D5.x==730 && D5.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else if(D6.x==735 && D6.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
          }
          else
          {
             D1.x=710 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
             deplacement++;
          }
       }
       else
       {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "6", D,noir,10);
       } //En dehors des 3 tours

       // 💚️💚️💚️💚️💚️💚️💚️Pour le 2e disque 💚️💚️💚️💚️💚️💚️
       SDL_SetRenderDrawColor(renderer,0,250,0,255);
       if(D2.x>198 && D2.x<250 && D2.y>118 && D2.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y==384 && D5.x==230 && D5.y==368 && D6.x==235 && D6.y==352)
          {
             //when we have (D1, D3, D4, D5, D6) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y==384 && D5.x==230 && D5.y==368)
          {
             //when we have (D1, D3, D4, D5) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y==384 && D6.x==235 && D6.y==368)
          {
             //when we have (D1, D3, D4, D6) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y== 384)
          {
             //when we have (D1, D3, D4) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400 && D5.x==230 && D5.y== 384)
          {
             //when we have (D1, D3, D5) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400 && D6.x==235 && D6.y== 384)
          {
             //when we have (D1, D3, D6) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D4.x==225 && D4.y==400 && D5.x==230 && D5.y== 384)
          {
             //when we have (D1, D4, D5) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D4.x==225 && D4.y==400 && D6.x==235 && D6.y== 384)
          {
             //when we have (D1, D4, D6) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D5.x==230 && D5.y==400 && D6.x==235 && D6.y== 384)
          {
             //when we have (D1, D4, D6) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400 && D5.x==230 && D5.y== 384)
          {
             //when we have (D3, D4, D5) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400 && D6.x==235 && D6.y== 384)
          {
             //when we have (D3, D4, D6) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416 && D5.x==230 && D5.y==400 && D6.x==235 && D6.y== 384)
          {
             //when we have (D3, D4, D6) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400)
          {
             //when we have (D1, D3) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D4.x==225 && D4.y==400)
          {
             //when we have (D1, D4) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D5.x==230 && D5.y==400)
          {
             //when we have (D1, D5) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D6.x==235 && D6.y==400)
          {
             //when we have (D1, D6) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400)
          {
             //when we have (D3, D4) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416 && D5.x==230 && D5.y==400)
          {
             //when we have (D3, D5) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416 && D6.x==235 && D6.y==400)
          {
             //when we have (D3, D6) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==225 && D4.y==416 && D5.x==230 && D5.y==400)
          {
             //when we have (D4, D5) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==225 && D4.y==416 && D6.x==235 && D6.y==400)
          {
             //when we have (D4, D6) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D5.x==230 && D5.y==416 && D6.x==235 && D6.y==400)
          {
             //when we have (D4, D6) disque D2 cant pose
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416) //if D3,  D4,  D5 and D6 is where D2 cant pose
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==225 && D4.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D5.x==230 && D5.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D6.x==235 && D6.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416)
          {
             D2.x=215 , D2.y=400;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
             deplacement++;
          }
          else
          {
             D2.x=215 , D2.y=416;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
             deplacement++;
          }
       }
       else if(D2.x>448 && D2.x<500 && D2.y>118 && D2.y<184)
       {
          //on est sur la 2e tour✅️ We search the condition for D2 pose in tour 2
          if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384 && D5.x==480 && D5.y==368 && D6.x==485 && D6.y==352)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384 && D5.x==480 && D5.y==368)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384 && D6.x==485 && D6.y==368)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400 && D5.x==480 && D5.y==384 && D6.x==485 && D6.y==368)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400 && D5.x==480 && D5.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400 && D6.x==485 && D6.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D4.x==475 && D4.y==400 && D5.x==480 && D5.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D4.x==475 && D4.y==400 && D6.x==485 && D6.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D5.x==480 && D5.y==400 && D6.x==485 && D6.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400 && D5.x==480 && D5.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400 && D6.x==485 && D6.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D5.x==480 && D5.y==400 && D6.x==485 && D6.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D4.x==475 && D4.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D5.x==480 && D5.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D6.x==485 && D6.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D5.x==480 && D5.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D6.x==485 && D6.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==475 && D4.y==416 && D5.x==480 && D5.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==475 && D4.y==416 && D6.x==485 && D6.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D5.x==480 && D5.y==416 && D6.x==485 && D6.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==475 && D4.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D5.x==480 && D5.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D6.x==485 && D6.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416)
          {
             D2.x=465 , D2.y=400; // Yes
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
             deplacement++;
          }
          else
          {
             D2.x=465 , D2.y=416; // Yes
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
             deplacement++;
          }
       }
       else if(D2.x>698 && D2.x<750 && D2.y>118 && D2.y<184)
       {
          //on est sur la 3e tour✅️

          if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384 && D5.x==730 && D5.y==368 && D6.x==735 && D6.y==352)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384 && D5.x==730 && D5.y==368)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384 && D6.x==735 && D6.y==368)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400 && D5.x==730 && D5.y==384 && D6.x==735 && D6.y==368)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400 && D5.x==730 && D5.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D4.x==725 && D4.y==400 && D5.x==730 && D5.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D4.x==725 && D4.y==400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D5.x==730 && D5.y==400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400 && D5.x==730 && D5.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D5.x==730 && D5.y==400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D4.x==725 && D4.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D5.x==730 && D5.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D6.x==735 && D6.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D5.x==730 && D5.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D6.x==735 && D6.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==725 && D4.y==416 && D5.x==730 && D5.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==725 && D4.y==416 && D6.x==735 && D6.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D5.x==730 && D5.y==416 && D6.x==735 && D6.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==725 && D4.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D5.x==730 && D5.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D6.x==735 && D6.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2); // No
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416)
          {
             D2.x=715 , D2.y=400; // Yes
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
             deplacement++;
          }
          else
          {
             D2.x=715 , D2.y=416; // Yes
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
             deplacement++;
          }
       }
       else
       {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "5", D,noir,10);
       }//En dehors des 3 tours


       // 💛️💛️💛️💛️💛️💛️ Pour le 3e disque 💛️💛️💛️💛️💛️💛️💛️
       SDL_SetRenderDrawColor(renderer,250,250,0,255);
       //SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
       if(D3.x>226 && D3.x<250 && D3.y>118 && D3.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x==210 && D1.y==416 && D2.x==215 && D2.y==400 && D4.x==225 && D4.y==384 && D5.x==230 && D5.y==368 && D6.x==235 && D6.y==352)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D2.x==215 && D2.y==400 && D4.x==225 && D4.y==384 && D5.x==230 && D5.y==368)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D2.x==215 && D2.y==400 && D4.x==225 && D4.y==384 && D6.x==235 && D6.y==368)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416 && D2.x==215 && D2.y==400 && D5.x==230 && D5.y==384 && D6.x==235 && D6.y==368)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D4.x==225 && D4.y==384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D5.x==230 && D5.y==384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D6.x==235 && D6.y==384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D4.x == 225 && D4.y == 400 && D5.x==230 && D5.y==384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D4.x == 225 && D4.y == 400 && D6.x==235 && D6.y==384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D5.x == 230 && D5.y == 400 && D6.x==235 && D6.y==384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D4.x == 225 && D4.y == 400 && D5.x==230 && D5.y==384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D4.x == 225 && D4.y == 400 && D6.x==235 && D6.y==384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D5.x == 230 && D5.y == 400 && D6.x==235 && D6.y==384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 225 && D4.y == 416 && D5.x == 230 && D5.y == 400 && D6.x==235 && D6.y==384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D4.x == 225 && D4.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D5.x == 230 && D5.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D6.x == 235 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D4.x == 225 && D4.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D5.x == 230 && D5.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D6.x == 235 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 225 && D4.y == 416 && D5.x == 230 && D5.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 225 && D4.y == 416 && D6.x == 235 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D5.x == 230 && D5.y == 416 && D6.x == 235 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 225 && D4.y == 416)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D5.x == 230 && D5.y == 416)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400)
          {
             D3.x=220, D3.y=384; // Yes
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416)
          {
             D3.x=220, D3.y=400; // Yes
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416)
          {
             D3.x=220, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=220, D3.y=416; // Yes
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
       }
       else if(D3.x>466 && D3.x<500 && D3.y>118 && D3.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x==460 && D1.y==416 && D2.x==465 && D2.y==400 && D4.x==475 && D4.y==384 && D5.x==480 && D5.y==368 && D6.x==485 && D6.y==352)
          {
             // cant
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D4.x == 475 && D4.y == 384 && D5.x==480 && D5.y==368)
          {
             // cant
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D4.x == 475 && D4.y == 384 && D6.x==485 && D6.y==368)
          {
             // cant
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D4.x == 475 && D4.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D5.x == 480 && D5.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D6.x == 485 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D4.x == 475 && D4.y == 400 && D5.x == 480 && D5.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D4.x == 475 && D4.y == 400 && D6.x == 485 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D5.x == 480 && D5.y == 400 && D6.x == 485 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D4.x == 475 && D4.y == 400 && D5.x == 480 && D5.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D4.x == 475 && D4.y == 400 && D6.x == 485 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D5.x == 480 && D5.y == 400 && D6.x == 485 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 475 && D4.y == 416 && D5.x == 480 && D5.y == 400 && D6.x == 485 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D4.x == 475 && D4.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D5.x == 480 && D5.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D6.x == 485 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D4.x == 475 && D4.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D5.x == 480 && D5.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D6.x == 485 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 475 && D4.y == 416 && D5.x == 480 && D5.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 475 && D4.y == 416 && D6.x == 485 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D5.x == 480 && D5.y == 416 && D6.x == 485 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 475 && D4.y == 416)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D5.x == 480 && D5.y == 416)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D6.x == 485 && D6.y == 416)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // cant
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D2.x == 465 && D2.y == 400)
          {
             D3.x=470, D3.y=384;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // can
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else if(D1.x==460 && D1.y==416)
          {
             D3.x=470, D3.y=400; // can
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else if(D2.x==465 && D2.y==416)
          {
             D3.x=470, D3.y=400; // can
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=470, D3.y=416; // can
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
       }
       else if(D3.x>716 && D3.x<750 && D3.y>118 && D3.y<184)
       {
          //on est sur la 3e tour✅️
          if(D1.x==710 && D1.y==416 && D2.x==715 && D2.y==400 && D4.x==725 && D4.y==384 && D5.x==730 && D5.y==368 && D6.x==735 && D6.y==352)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D4.x == 725 && D4.y==384 && D5.x==730 && D5.y==368)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D4.x == 725 && D4.y==384 && D5.x==735 && D6.y==368)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D5.x == 730 && D5.y==384 && D5.x==735 && D6.y==368)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D4.x == 725 && D4.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D5.x == 730 && D5.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D6.x == 735 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y==400 && D5.x==730 && D5.y==384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y == 400 && D6.x == 735 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D5.x == 730 && D5.y == 400 && D6.x == 735 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D4.x == 725 && D4.y == 400 && D5.x == 730 && D5.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D4.x == 725 && D4.y == 400 && D6.x == 735 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D5.x == 730 && D5.y == 400 && D6.x == 735 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 725 && D4.y == 416 && D5.x == 730 && D5.y == 400 && D6.x == 735 && D6.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D5.x == 730 && D5.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D6.x == 735 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D4.x == 725 && D4.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D5.x == 730 && D5.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D6.x == 735 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 725 && D4.y == 416 && D5.x == 730 && D5.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 725 && D4.y == 416 && D6.x == 735 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D5.x == 730 && D5.y == 416 && D6.x == 735 && D6.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D4.x == 725 && D4.y == 416)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D5.x == 730 && D5.y == 416)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D6.x == 730 && D6.y == 416)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3); // No
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D2.x == 715 && D2.y == 400)
          {
             D3.x=720, D3.y=384; // Yes
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else if(D1.x==710 && D1.y==416)
          {
             D3.x=720, D3.y=400; // Yes
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else if(D2.x==715 && D2.y==416)
          {
             D3.x=720, D3.y=400; // Yes
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=720, D3.y=416; // Yes
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
       }
       else
       {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "4", D,noir,10);
       }

       // 💙️💙️💙️💙️💙️💙️ Pour le 4e disque 💙️💙️💙️💙️💙️💙️💙️

       SDL_SetRenderDrawColor(renderer,0,0,250,255);
       //SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
       if(D4.x>226 && D4.x<250 && D4.y>118 && D4.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x==210 && D1.y==416 && D2.x==215 && D2.y==400 && D3.x==220 && D3.y==384 && D5.x==230 && D5.y==368 && D6.x==235 && D6.y==352)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384 && D5.x==230 && D5.y==368)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384 && D6.x==235 && D6.y==368)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D5.x == 230 && D5.y == 384 && D6.x==235 && D6.y==368)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D5.x == 230 && D5.y == 384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D6.x == 235 && D6.y == 384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400 && D5.x==230 && D5.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D5.x == 230 && D5.y == 400 && D6.x == 235 && D6.y == 384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400 && D5.x==230 && D5.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400 && D6.x==235 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D5.x == 230 && D5.y == 400 && D6.x==235 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D5.x == 230 && D5.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D6.x == 235 && D6.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D5.x == 230 && D5.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D6.x == 235 && D6.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D3.x == 220 && D3.y == 416 && D5.x == 230 && D5.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D3.x == 220 && D3.y == 416 && D6.x == 235 && D6.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384)
          {
             D4.x = 225, D4.y = 368; // yes now
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400)
          {
             D4.x = 225, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // yes
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D4.x = 225, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // yes
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D4.x = 225, D4.y = 384; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416)
          {
             D4.x=225, D4.y=400;  // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416)
          {
             D4.x=225, D4.y=400; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 220 && D3.y == 416)
          {
             D4.x=225, D4.y=400; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D5.x == 230 && D5.y == 416)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // yes
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }

          else
          {
             D4.x=225, D4.y=416; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
       }
       else if(D4.x>466 && D4.x<500 && D4.y>118 && D4.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x==460 && D1.y==416 && D2.x==465 && D2.y==400 && D3.x==470 && D3.y==384 && D5.x==480 && D5.y==368 && D6.x==485 && D6.y==352)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384 && D5.x==480 && D5.y==368)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384 && D6.x==485 && D6.y==368)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D5.x==480 && D5.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; //No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D6.x==485 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; //No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400 && D5.x==480 && D5.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400 && D6.x==485 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D5.x == 480 && D5.y == 400 && D6.x==485 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400 && D5.x==480 && D5.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400 && D6.x==485 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D5.x == 480 && D5.y == 400 && D6.x==485 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384)
          {
             D4.x = 475, D4.y = 368; // yes now
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D5.x == 480 && D5.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D5.x == 480 && D5.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D3.x == 470 && D3.y == 416 && D5.x == 480 && D5.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D3.x == 470 && D3.y == 416 && D6.x == 485 && D6.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D5.x == 485 && D5.y == 416 && D6.x == 485 && D6.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400)
          {
             D4.x = 475, D4.y = 384; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400)
          {
             D4.x = 475, D4.y = 384; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400)
          {
             D4.x = 475, D4.y = 384; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D5.x==480 && D5.y==416)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D6.x==485 && D6.y==416)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416)
          {
             D4.x=475, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D2.x==465 && D2.y==416)
          {
             D4.x=475, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D3.x==470 && D3.y==416)
          {
             D4.x=475, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else
          {
             D4.x=475, D4.y=416;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
       }
       else if(D4.x>716 && D4.x<750 && D4.y>118 && D4.y<184)
       {
          //on est sur la 3e tour✅️
          if(D1.x==710 && D1.y==416 && D2.x==715 && D2.y==400 && D3.x==720 && D3.y==384 && D5.x==730 && D5.y==368 && D6.x==735 && D6.y==352)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384 && D5.x==730 && D5.y==368)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384 && D6.x==735 && D6.y==368)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D5.x==730 && D5.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4); // No
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400 && D5.x==730 && D5.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D5.x == 730 && D5.y == 400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400 && D5.x==730 && D5.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D5.x == 730 && D5.y == 400 && D6.x==735 && D6.y==384)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384)
          {
             D4.x = 725, D4.y = 368; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D5.x == 730 && D5.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D6.x == 735 && D6.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D5.x == 730 && D5.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D6.x == 735 && D6.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D3.x == 720 && D3.y == 416 && D5.x == 730 && D5.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D3.x == 720 && D3.y == 416 && D6.x == 735 && D6.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D5.x == 730 && D5.y == 416 && D6.x == 735 && D6.y == 400)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400)
          {
             D4.x = 725, D4.y = 384; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400)
          {
             D4.x = 725, D4.y = 384; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400)
          {
             D4.x = 725, D4.y = 384; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D5.x==730 && D5.y==416)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D6.x==735 && D6.y==416)
          {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416)
          {
             D4.x=725, D4.y=400; // yes
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D2.x==715 && D2.y==416)
          {
             D4.x=725, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D3.x==720 && D3.y==416)
          {
             D4.x=725, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else
          {
             D4.x=725, D4.y=416;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
       }
       else
       {
          SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
          SDL_RenderFillRect(renderer,&D4);
          EcrireTextDirect(renderer, "3", D,noir,10);
       }
           //En dehors des 3 tours


       // ❤️❤️❤️❤️❤️❤️ Pour le 5e disque ❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️

       SDL_SetRenderDrawColor(renderer,250,0,0,255);

       if(D5.x>226 && D5.x<250 && D5.y>118 && D5.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x==210 && D1.y==416 && D2.x==215 && D2.y==400 && D3.x==220 && D3.y==384 && D4.x==225 && D4.y==368 && D6.x==235 && D6.y==352)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5); // Yes
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384 && D4.x == 225 && D4.y == 368)
          {
             D5.x = 230, D5.y = 352; // Yes
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384 && D6.x == 235 && D6.y == 368)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0}; // No
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D4.x == 225 && D4.y == 384 && D6.x == 235 && D6.y == 368)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5); // No
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400 && D4.x == 225 && D4.y == 384 && D6.x == 235 && D6.y == 368)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5); // No
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384)
          {
             D5.x = 230, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D4.x == 225 && D4.y == 384)
          {
             D5.x = 230, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D6.x == 235 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400 && D4.x == 225 && D4.y == 384)
          {
             D5.x = 230, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400 && D6.x == 235 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400 && D4.x == 225 && D4.y == 384)
          {
             D5.x = 230, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400 && D6.x == 235 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D4.x == 225 && D4.y == 400 && D6.x == 235 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D3.x == 220 && D3.y == 416 && D4.x == 225 && D4.y == 400 && D6.x == 235 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D4.x == 225 && D4.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D6.x == 235 && D6.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D4.x == 225 && D4.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D6.x == 235 && D6.y == 400)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D3.x == 220 && D3.y == 416 && D4.x == 225 && D4.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 220 && D3.y == 416 && D6.x == 235 && D6.y == 400)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D4.x == 225 && D4.y == 416 && D6.x == 235 && D6.y == 400)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 210 && D1.y == 416)
          {
             D5.x=230, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416)
          {
             D5.x=230, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 220 && D3.y == 416)
          {
             D5.x=230, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D4.x == 225 && D4.y == 416)
          {
             D5.x=230, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D6.x == 235 && D6.y == 416)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else
          {
             D5.x=230, D5.y=416;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
       }
       else if(D5.x>466 && D5.x<500 && D5.y>118 && D5.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x==460 && D1.y==416 && D2.x==465 && D2.y==400 && D3.x==470 && D3.y==384 && D4.x==475 && D4.y==368 && D6.x==485 && D6.y==352)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384 && D4.x==475 && D4.y==368)
          {
             D5.x = 480, D5.y = 352;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384 && D6.x==485 && D6.y==368)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D4.x == 475 && D4.y == 384 && D6.x==485 && D6.y==368)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384)
          {
             D5.x = 480, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D4.x == 475 && D4.y == 384)
          {
             D5.x = 480, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D6.x == 485 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400 && D4.x == 475 && D4.y == 384)
          {
             D5.x = 480, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400 && D6.x == 485 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D4.x == 475 && D4.y == 400 && D6.x == 485 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400 && D4.x == 475 && D4.y == 384)
          {
             D5.x = 480, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400 && D6.x == 485 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D4.x == 475 && D4.y == 400 && D6.x == 485 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D4.x == 475 && D4.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D6.x == 485 && D6.y == 400)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D4.x == 475 && D4.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D6.x == 485 && D6.y == 400)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D3.x == 470 && D3.y == 416 && D4.x == 475 && D4.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 470 && D3.y == 416 && D6.x == 485 && D6.y == 400)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D4.x == 475 && D4.y == 416 && D6.x == 485 && D6.y == 400)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416)
          {
             D5.x=480, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x==465 && D2.y==416)
          {
             D5.x=480, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x==470 && D3.y==416)
          {
             D5.x=480, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D4.x==475 && D4.y==416)
          {
             D5.x=480, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D6.x==485 && D6.y==416)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else
          {
             D5.x=480, D5.y=416;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
       }
       else if(D5.x>716 && D5.x<750 && D5.y>118 && D5.y<184)
       {
          //on est sur la 3e tour✅️
          if(D1.x==710 && D1.y==416 && D2.x==715 && D2.y==400 && D3.x==720 && D3.y==384 && D4.x==725 && D4.y==368 && D6.x==735 && D6.y==352)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384 && D4.x==725 && D4.y==368)
          {
             D5.x = 730, D5.y = 352;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384 && D6.x==735 && D6.y==368)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D4.x == 725 && D4.y == 384 && D6.x==735 && D6.y==368)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384)
          {
             D5.x = 730, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D4.x == 725 && D4.y == 384)
          {
             D5.x = 730, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D6.x == 735 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400 && D4.x == 725 && D4.y == 384)
          {
             D5.x = 730, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400 && D6.x == 735 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y == 400 && D6.x == 735 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400 && D4.x == 725 && D4.y == 384)
          {
             D5.x = 730, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400 && D6.x == 735 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D3.x == 720 && D3.y == 416 && D4.x == 725 && D4.y == 400 && D6.x == 735 && D6.y == 384)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D6.x == 735 && D5.y == 400)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D4.x == 725 && D4.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D6.x == 735 && D6.y == 400)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D3.x == 720 && D3.y == 416 && D4.x == 725 && D4.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 720 && D3.y == 416 && D6.x == 735 && D6.y == 400)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D4.x == 725 && D4.y == 416 && D6.x == 735 && D6.y == 400)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416)
          {
             D5.x=730, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x==715 && D2.y==416)
          {
             D5.x=730, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x==720 && D3.y==416)
          {
             D5.x=730, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D4.x==725 && D4.y==416)
          {
             D5.x=730, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D6.x==735 && D6.y==416)
          {
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else
          {
             D5.x=730, D5.y=416;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
       }
       else
       {
        SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
        SDL_RenderFillRect(renderer,&D5);
        EcrireTextDirect(renderer, "2", D,noir,10);//En dehors des 3 tours
       }

       // ❤️❤️❤️❤️❤️❤️ Pour le 6e disque ❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️

       SDL_SetRenderDrawColor(renderer,10,100,100,255);

       if(D6.x>226 && D6.x<250 && D6.y>118 && D6.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x==210 && D1.y==416 && D2.x==215 && D2.y==400 && D3.x==220 && D3.y==384 && D4.x==225 && D4.y==368 && D5.x==230 && D5.y==352)
          {
             D6.x = 235, D6.y = 336;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x==210 && D1.y==416 && D2.x==215 && D2.y==400 && D3.x==220 && D3.y==384 && D4.x==225 && D4.y==368)
          {
             D6.x = 235, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x==210 && D1.y==416 && D2.x==215 && D2.y==400 && D3.x==220 && D3.y==384 && D5.x==230 && D5.y==368)
          {
             D6.x = 235, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x==210 && D1.y==416 && D2.x==215 && D2.y==400 && D4.x==225 && D4.y==384 && D5.x==230 && D5.y==368)
          {
             D6.x = 235, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y==384 && D5.x==230 && D5.y==368)
          {
             D6.x = 235, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y==384 && D5.x==230 && D5.y==368)
          {
             D6.x = 235, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384)
          {
             D6.x = 235, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D4.x == 225 && D4.y == 384)
          {
             D6.x = 235, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D5.x == 230 && D5.y == 384)
          {
             D6.x = 235, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400 && D4.x == 225 && D4.y == 384)
          {
             D6.x = 235, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400 && D5.x == 230 && D5.y == 384)
          {
             D6.x = 235, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D4.x == 225 && D4.y == 400 && D5.x == 230 && D5.y == 384)
          {
             D6.x = 235, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400 && D4.x == 225 && D4.y == 384)
          {
             D6.x = 235, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400 && D5.x == 230 && D5.y == 384)
          {
             D6.x = 235, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D4.x == 225 && D4.y == 400 && D5.x == 230 && D5.y == 384)
          {
             D6.x = 235, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 220 && D3.y == 416 && D4.x == 225 && D4.y == 400 && D5.x == 230 && D5.y == 384)
          {
             D6.x = 235, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400)
          {
             D6.x = 235, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D6.x = 235, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D4.x == 225 && D4.y == 400)
          {
             D6.x = 235, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D5.x == 230 && D5.y == 400)
          {
             D6.x = 235, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D6.x = 235, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D4.x == 225 && D4.y == 400)
          {
             D6.x = 235, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D5.x == 230 && D5.y == 400)
          {
             D6.x = 235, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 220 && D3.y == 416 && D4.x == 225 && D4.y == 400)
          {
             D6.x = 235, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 220 && D3.y == 416 && D5.x == 230 && D5.y == 400)
          {
             D6.x = 235, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D4.x == 225 && D4.y == 416 && D5.x == 230 && D5.y == 400)
          {
             D6.x = 235, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416)
          {
             D6.x=235, D6.y=400;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416)
          {
             D6.x=235, D6.y=400;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 220 && D3.y == 416)
          {
             D6.x=235, D6.y=400;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D4.x == 225 && D4.y == 416)
          {
             D6.x=235, D6.y=400;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D5.x == 230 && D5.y == 416)
          {
             D6.x=235, D6.y=400;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else
          {
             D6.x=235, D6.y=416;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else if(D6.x>466 && D6.x<500 && D6.y>118 && D6.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x==460 && D1.y==416 && D2.x==465 && D2.y==400 && D3.x==470 && D3.y==384 && D4.x==475 && D4.y==368 && D5.x==480 && D5.y==352)
          {
             D6.x = 485, D6.y = 336;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384 && D4.x==475 && D4.y==368)
          {
             D6.x = 485, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384 && D5.x==480 && D5.y==368)
          {
             D6.x = 485, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D4.x == 475 && D4.y == 384 && D5.x==480 && D5.y==368)
          {
             D6.x = 485, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400 && D4.x == 475 && D4.y == 384 && D5.x==480 && D5.y==368)
          {
             D6.x = 485, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400 && D4.x == 475 && D4.y == 384 && D5.x==480 && D5.y==368)
          {
             D6.x = 485, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384)
          {
             D6.x = 485, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D4.x == 475 && D4.y == 384)
          {
             D6.x = 485, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D5.x == 480 && D5.y == 384)
          {
             D6.x = 485, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400 && D4.x == 475 && D4.y == 384)
          {
            D6.x = 485, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400 && D5.x == 480 && D5.y == 384)
          {
            D6.x = 485, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D4.x == 475 && D4.y == 400 && D5.x == 480 && D5.y == 384)
          {
            D6.x = 485, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400 && D4.x == 475 && D4.y == 384)
          {
            D6.x = 485, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400 && D5.x == 480 && D5.y == 384)
          {
            D6.x = 485, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D4.x == 475 && D4.y == 400 && D5.x == 480 && D5.y == 384)
          {
            D6.x = 485, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D3.x == 470 && D3.y == 416 && D4.x == 475 && D4.y == 400 && D5.x == 480 && D5.y == 384)
          {
            D6.x = 485, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400)
          {
             D6.x = 485, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400)
          {
            D6.x = 485, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D4.x == 475 && D4.y == 400)
          {
            D6.x = 485, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D5.x == 480 && D5.y == 400)
          {
            D6.x = 485, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400)
          {
            D6.x = 485, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D4.x == 475 && D4.y == 400)
          {
            D6.x = 485, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D5.x == 480 && D5.y == 400)
          {
            D6.x = 485, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D3.x == 470 && D3.y == 416 && D4.x == 475 && D4.y == 400)
          {
            D6.x = 485, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D3.x == 470 && D3.y == 416 && D5.x == 480 && D5.y == 400)
          {
            D6.x = 485, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D4.x == 475 && D4.y == 416 && D5.x == 480 && D5.y == 400)
          {
            D6.x = 485, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x==460 && D1.y==416)
          {
             D6.x=485, D6.y=400;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x==465 && D2.y==416)
          {
            D6.x=485, D6.y=400;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D3.x==470 && D3.y==416)
          {
            D6.x=485, D6.y=400;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D4.x==475 && D4.y==416)
          {
            D6.x=485, D6.y=400;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D5.x==480 && D5.y==416)
          {
            D6.x=485, D6.y=400;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else
          {
             D6.x=485, D6.y=416;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else if(D6.x>716 && D6.x<750 && D6.y>118 && D6.y<184)
       {
          //on est sur la 3e tour✅️
          if(D1.x==710 && D1.y==416 && D2.x==715 && D2.y==400 && D3.x==720 && D3.y==384 && D4.x==725 && D4.y==368 && D5.x==730 && D5.y==352)
          {
             D6.x = 735, D6.y = 336;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384 && D4.x==725 && D4.y==368)
          {
             D6.x = 735, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384 && D5.x==730 && D5.y==368)
          {
             D6.x = 735, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D4.x == 725 && D4.y == 384 && D5.x==730 && D5.y==368)
          {
             D6.x = 735, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400 && D4.x == 725 && D4.y == 384 && D5.x==730 && D5.y==368)
          {
             D6.x = 735, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400 && D4.x == 725 && D4.y == 384 && D5.x==730 && D5.y==368)
          {
             D6.x = 735, D6.y = 352;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384)
          {
             D6.x = 735, D6.y = 368;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D4.x == 725 && D4.y == 384)
          {
            D6.x = 735, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D5.x == 730 && D5.y == 384)
          {
            D6.x = 735, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400 && D4.x == 725 && D4.y == 384)
          {
            D6.x = 735, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400 && D5.x == 730 && D5.y == 384)
          {
            D6.x = 735, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y == 400 && D5.x == 730 && D5.y == 384)
          {
            D6.x = 735, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400 && D4.x == 725 && D4.y == 384)
          {
            D6.x = 735, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400 && D5.x == 730 && D5.y == 384)
          {
            D6.x = 735, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D4.x == 725 && D4.y == 400 && D5.x == 730 && D5.y == 384)
          {
            D6.x = 735, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D3.x == 720 && D3.y == 416 && D4.x == 725 && D4.y == 400 && D5.x == 730 && D5.y == 384)
          {
            D6.x = 735, D6.y = 368;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400)
          {
             D6.x = 735, D6.y = 384;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400)
          {
            D6.x = 735, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y == 400)
          {
            D6.x = 735, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D5.x == 730 && D5.y == 400)
          {
            D6.x = 735, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400)
          {
            D6.x = 735, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D4.x == 725 && D4.y == 400)
          {
            D6.x = 735, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D5.x == 730 && D5.y == 400)
          {
            D6.x = 735, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D3.x == 720 && D3.y == 416 && D4.x == 725 && D4.y == 400)
          {
            D6.x = 735, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D3.x == 720 && D3.y == 416 && D5.x == 730 && D5.y == 400)
          {
            D6.x = 735, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D4.x == 725 && D4.y == 416 && D5.x == 730 && D5.y == 400)
          {
            D6.x = 735, D6.y = 384;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D1.x==710 && D1.y==416)
          {
             D6.x=735, D6.y=400;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x==715 && D2.y==416)
          {
            D6.x=735, D6.y=400;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D3.x==720 && D3.y==416)
          {
            D6.x=735, D6.y=400;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D4.x==725 && D4.y==416)
          {
            D6.x=735, D6.y=400;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else if(D5.x==730 && D5.y==416)
          {
            D6.x=735, D6.y=400;
            SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
            SDL_RenderFillRect(renderer,&D6);
            EcrireTextDirect(renderer, "1", D,noir,10);
            deplacement++;
          }
          else
          {
             D6.x=735, D6.y=416;
             SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D6);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else
       {
        SDL_Rect D = {D6.x+15,D6.y+6, 0,0};
        SDL_RenderFillRect(renderer,&D6);
        EcrireTextDirect(renderer, "1", D,noir,10);//En dehors des 3 tours
       }
       // Affichage du deplacement
       sprintf(nbre, "%d", deplacement);
       p.x+=220;p.y-=2;
       EcrireTextDirect(renderer,nbre,p,noir,20);
       //Affichage du temps
      SDL_Rect posiTemps = {50,5,0,0};
      EcrireTextDirect(renderer, "Temps: ", posiTemps,noir,30);
      posiTemps.x+=100;
      EcrireTextDirect(renderer,h,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "h", posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer,min,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "min", posiTemps,noir,30);
      posiTemps.x+=80;
      EcrireTextDirect(renderer,sec,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "sec", posiTemps,noir,30);

       la:
       SDL_RenderPresent(renderer);

       if(D1.x==710 && D1.y==416 && D2.x==715 && D2.y==400 && D3.x==720 && D3.y==384 && D4.x==725 && D4.y==368 && D5.x==730 && D5.y==352 && D6.x==735 && D6.y==336)
       {
           //Jouer le son
           Mix_PlayMusic(son, 1);

           SDL_Texture *texture=NULL;
           SDL_Surface *surface=NULL;
           SDL_Rect d = {420,180,0,0};
           surface=IMG_Load("bravo.jpg");
           texture=SDL_CreateTextureFromSurface(renderer,surface);
           SDL_FreeSurface(surface);
           SDL_QueryTexture(texture,NULL,NULL,&d.w,&d.h);
           SDL_RenderCopy(renderer,texture,NULL,&d);
           SDL_RenderPresent(renderer);
           SDL_DestroyTexture(texture);
           SDL_Delay(5000);
           Mix_FreeMusic(son); //Libération de la musique
           Mix_FreeMusic(musique); //Libération de la musique

           SDL_Event suite;
           int v = 1;
           while(v==1)
           {
               SDL_WaitEvent(&suite);
               if(suite.type == SDL_QUIT)
                  v=0;
               //Recuperaton et utilisation de l'état de la souris
               Uint32 bouton;
               int x, y;
               bouton=SDL_GetMouseState(&x, &y);

               SDL_Rect r = {200,50,0,0},  rr1 = {400,170,0,0},  rr2 = {400,220,0,0},  rr3 = {400,270,0,0};
               SDL_Rect r1 = {390,165,150,40}, r2 = {390,215,200,40}, r3 = {390,265,100,40};

               if(x>r1.x && x<r1.x+r1.w && y>r1.y && y<r1.y+r1.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r1);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                    goto rejouer;
               }
               else if(x>r2.x && x<r2.x+r2.w && y>r2.y && y<r2.y+r2.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r2);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                 {
                    jouer4(renderer);
                    v = 0;
                 }
               }
               else if(x>r3.x && x<r3.x+r3.w && y>r3.y && y<r3.y+r3.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r3);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                    v = 0;
               }
               SDL_Texture *txture = NULL;
               SDL_Surface *victoire = NULL;
               victoire = IMG_Load("2dc8h1u.jpg");
               txture = SDL_CreateTextureFromSurface(renderer, victoire);
               SDL_FreeSurface(victoire);
               SDL_RenderCopy(renderer,txture,NULL,NULL); // Affichage de l'image

               EcrireTextDirect(renderer, "Felicitation vous avez reuissi la partie", r,blanc,40);
               r.x += 200; r.y += 70;
               EcrireTextDirect(renderer, "Nombre de mouvement:  ", r,blanc,30);
               r.x += 350; r.y += 7;
               EcrireTextDirect(renderer,nbre,r,noir,20);
               EcrireTextDirect(renderer, "Rejouer", rr1, blanc,25);
               EcrireTextDirect(renderer, "Niveau suivant", rr2,blanc,25);
               EcrireTextDirect(renderer, "Sortir", rr3,blanc,25);
               SDL_RenderPresent(renderer);
           }
           continuer=0;//break;
       }
       int x, y;
       Uint32 bouton;
       bouton=SDL_GetMouseState(&x, &y);
       if(x>855 && x<990 && y>10 && y<50)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               int v=1;
               SDL_Rect t = {50,20,0,0};
               SDL_SetRenderDrawColor(renderer,255,255,255,255);
               SDL_RenderClear(renderer);
               EcrireTextDirect(renderer, "  INSTRUCTION POUR LE DEPLACEMENT DES DISQUES", t,bleu,25);
               t.y+=70;
               EcrireTextDirect(renderer, "-> Tapez 1 puis bouger la souris pour deplacer le disque gris", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 2 puis bouger la souris pour deplacer le disque rouge", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 3 puis bouger la souris pour deplacer le disque bleu", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 4 puis bouger la souris pour deplacer le disque jaune", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 5 puis bouger la souris pour deplacer le disque vert", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 6 puis bouger la souris pour deplacer le disque orange", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Vous gagnerai si les 5 disques se trouvent au niveau de la 3e tour", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez sur la touche Entrer si vous finissez de lire", t,noir,25);
               SDL_RenderPresent(renderer);
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
       else if(x>855 && x<990 && y>60 && y<100)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               //Les 3 rectangles pour la sugestion de recommencer
               SDL_Rect d1 = {200,150,500,200}, d2 = {250,250,75,50}, d3 = {350,250,75,50};
               SDL_Rect t1 = {250,180,0,0}, t2 = {255,255,0,0};
               SDL_SetRenderDrawColor(renderer,250,250,0,255);
               SDL_RenderFillRect(renderer,&d1);
               SDL_SetRenderDrawColor(renderer,0,250,250,255);
               SDL_RenderFillRect(renderer,&d2);
               SDL_RenderFillRect(renderer,&d3);
               SDL_SetRenderDrawColor(renderer,0,0,0,255);
               EcrireTextDirect(renderer, "Etes-vous sure de recommencer ?", t1, noir,25);
               EcrireTextDirect(renderer, "Oui", t2,noir,25);
               t2.x+=100;
               EcrireTextDirect(renderer, "Non", t2,noir,25);
               SDL_RenderPresent(renderer);

               int c=1;
               SDL_Event e;
               while(c == 1)
               {
                   SDL_WaitEvent(&e);
                   //Recuperaton et utilisation de l'état de la souris
                   Uint32 bouton;
                   int x, y;
                   bouton=SDL_GetMouseState(&x, &y);
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
               rejouer:
               //Rectangle des 3 tours reinitialiser
               T1.x = 240; T1.y = 200; T1.w = 20; T1.h = 232;
               T2.x = 490; T2.y = 200; T2.w = 20; T2.h = 232;
               T3.x = 740; T3.y = 200; T3.w = 20; T3.h = 232;
               //Rectangle des 3 disques reinitialiser
               D1.x = 210; D1.y = 416; D1.w = 80; D1.h = 16;
               D2.x = 215; D2.y = 400; D2.w = 70; D2.h = 16;
               D3.x = 220; D3.y = 384; D3.w = 60; D3.h = 16;
               D4.x = 225; D4.y = 368; D4.w = 50; D4.h = 16;
               D5.x = 230; D5.y = 352; D5.w = 40; D5.h = 16;
               D6.x = 235; D6.y = 336; D6.w = 30; D6.h = 16;
               //Couleur
               SDL_Color blanc = {255,255,255,255}, noir = {0,0,0,255};

               text.x = 860; text.y = 20; text.w = 200; text.h = 40;
               r.x = 855; r.y = 10; r.w = 135; r.h = 40;
               t.x = 250; t.y = 470; t.w = 0; t.h = 0;
               p.x = 320; p.y = 475; p.w = 30; p.h = 22;
               goto debut;
           }
       }
       else if(x > 855 && x < 990 && y > 110 && y < 150)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               int v=1;
               SDL_Rect d = {300,0,400,450};
               SDL_Surface *s=NULL;
               SDL_Texture *t=NULL;
               SDL_SetRenderDrawColor(renderer,255,255,255,255);
               SDL_RenderClear(renderer);
               s=IMG_Load("solution4.jpg");
               t=SDL_CreateTextureFromSurface(renderer,s);
               SDL_FreeSurface(s);
               //SDL_QueryTexture(t,NULL,NULL,&d.w,&d.h);
               SDL_RenderCopy(renderer,t,NULL,&d);
               SDL_DestroyTexture(t);
               SDL_RenderPresent(renderer);
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
       else if(x>855 && x<990 && y>160 && y<200)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               //Les 3 rectangles pour la sugestion de recommencer
               SDL_Rect d1 = {200,150,500,200}, d2 = {250,250,75,50}, d3 = {350,250,75,50};
               SDL_Rect t1 = {250,180,0,0}, t2 = {255,255,0,0};
               SDL_SetRenderDrawColor(renderer,250,250,0,255);
               SDL_RenderFillRect(renderer,&d1);
               SDL_SetRenderDrawColor(renderer,0,250,250,255);
               SDL_RenderFillRect(renderer,&d2);
               SDL_RenderFillRect(renderer,&d3);
               SDL_SetRenderDrawColor(renderer,0,0,0,255);
               EcrireTextDirect(renderer, "Etes-vous sure de Sortir ?", t1, noir,25);
               EcrireTextDirect(renderer, "Oui", t2,noir,25);
               t2.x+=100;
               EcrireTextDirect(renderer, "Non", t2,noir,25);
               SDL_RenderPresent(renderer);

               int c=1;
               SDL_Event e;
               while(c == 1)
               {
                   SDL_WaitEvent(&e);
                   //Recuperaton et utilisation de l'état de la souris
                   Uint32 bouton;
                   int x, y;
                   bouton=SDL_GetMouseState(&x, &y);
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
               continuer=0;break;
           }
       }
  }
}


//💻️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️ Fonction de niveau 3 🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️🇧🇫️
void jouer3(SDL_Renderer* renderer)
{
  //Rectangle des 3 tours
  SDL_Rect T1 = {240,200,20,232}, T2 = {490,200,20,232}, T3 = {740,200,20,232};
  //Rectangle des 5 disques
  SDL_Rect D1 = {210,416, 80,16}, D2 = {215,400,70,16}, D3 = {220,384,60,16}, D4 = {225,368,50,16}, D5 = {230,352,40,16};
  //Couleur
  SDL_Color blanc = {255,255,255,255}, noir = {0,0,0,255}, bleu = {0,0,255,255};

   Mix_Music *musique,*son;
   musique = Mix_LoadMUS("Wiz_Khalifa_-_See_You_Again_ft._Charlie_Puth.mp3");
   son = Mix_LoadMUS("APPLAUDISSEMENTS_-_Bruitage_Gratuit(256k).mp3");
   //Jouer la musique
   Mix_PlayMusic(musique,-1);

  char nbre[4];
  int continuer=1, deplacement=0;
  SDL_Event event;

   while(continuer)
   {
        //Gestion du temps
        int heures, minutes, secondes;
        Uint32 temps;
        temps = SDL_GetTicks();
        heures = ((temps/1000)/3600)%24;
        minutes = ((temps/1000)/60)%60;
        secondes= (temps/1000)%60;
        //Conversion du temps en char
        char h[3], min[3], sec[3] ;
        sprintf(h, "%d", heures);
        sprintf(min, "%d", minutes);
        sprintf(sec, "%d", secondes);

        //Rectangle des ecritures
        SDL_Rect text = {860,20,200,40}, r = {855,10,135,40}, t = {100,470,0,0}, p = {170,475,30,22};

        debut:
        SDL_PollEvent(&event);

        //Bouger le disque rouge (le plus petit)
        if(event.key.keysym.sym == SDLK_1)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                  if(Deja(D2, D5, x, y) == 1 && Deja(D1, D5, x, y) == 1 && Deja(D3, D5, x, y) == 1 && Deja(D4, D5, x, y) == 1 && ok3(D1, D2, D3, D4) ==1)
                  {
                     D5.x = x;
                     D5.y = y;
                  }
               }
           }
        }

        //Bouger le disque bleu (le 2e plus petit)
        if(event.key.keysym.sym == SDLK_2)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                  if(D5.x != D4.x+5 && D5.y != D4.y-16)
                  {
                     if(Deja(D1, D4, x, y) == 1 && Deja(D3, D4, x, y) == 1 && Deja(D2, D4, x, y) == 1 && Deja(D5, D4, x, y) == 1 && ok3(D1, D2, D3, D5) == 1)
                     {
                        D4.x = x;
                        D4.y = y;
                     }
                  }
                  else if(D5.y == D4.y-16)
                  {
                     if(D5.x != D4.x+5)
                     {
                        D4.x = x;
                        D4.y = y;
                     }
                  }
               }
           }
        }
        //Bouger le disque jaune (le 1er moyen)
        else if(event.key.keysym.sym == SDLK_3)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                 if(D4.x != D3.x+5 && D4.y != D3.y-16 && D5.x != D3.x+10 && D5.y != D3.y-16)
                 {
                    if(Deja(D1, D3, x, y) == 1 && Deja(D2, D3, x, y) == 1 && Deja(D4, D3, x, y) == 1 && Deja(D5, D3, x, y) == 1 && ok3(D1, D2, D4, D5) == 1)
                    {
                       D3.x = x;
                       D3.y = y;
                    }
                 }
                 else if(D5.y == D3.y-16 && D4.y == D3.y-16)
                 {
                     if(D5.x != D3.x+10 && D4.x != D3.x+5)
                     {
                        D3.x = x;
                        D3.y = y;
                     }
                }
                 else if(D5.y == D3.y-16)
                 {
                     if(D5.x != D3.x+10)
                     {
                        D3.x = x;
                        D3.y = y;
                     }
                }
                else if(D4.y == D3.y-16)
                 {
                     if(D4.x != D3.x+5)
                     {
                        D3.x = x;
                        D3.y = y;
                     }
                }
            }
          }
        }
        //Bouger le disque vert (le moyen grand)
        else if(event.key.keysym.sym == SDLK_4)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                 if(D3.x != D2.x+5 && D3.y != D2.y-16 && D4.x != D2.x+10 && D4.y != D2.y-16 && D5.x != D2.x+15 && D5.y != D2.y-16)
                 {
                    if(Deja(D1, D2, x, y) == 1 && Deja(D3, D2, x, y) == 1 && Deja(D4, D2, x, y) == 1 && Deja(D5, D2, x, y) == 1 && ok3(D1, D3, D4, D5) ==1)
                    {
                       D2.x = x;
                       D2.y = y;
                    }
                 }
                 else if(D4.y == D2.y-16 && D3.y == D2.y-16)
                 {
                     if(D4.x != D2.x+10 && D3.x != D2.x+5)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                 }
                 else if(D4.y == D2.y-16 && D5.y == D2.y-16)
                 {
                     if(D4.x != D2.x+10 && D5.x != D2.x+15)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D3.y == D2.y-16 && D5.y == D2.y-16)
                 {
                     if(D5.x != D2.x+15 && D3.x != D2.x+5)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D4.y == D2.y-16)
                 {
                     if(D4.x != D2.x+10)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D3.y == D2.y-16)
                {
                     if(D3.x != D2.x+5)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D5.y == D2.y-16)
                 {
                     if(D5.x != D2.x+15)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
            }
          }
        }
        //Bouger le disque orange (le plus grand)
        else if(event.key.keysym.sym == SDLK_5)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                 if(D2.x != D1.x+5 && D2.y != D1.y-16 && D3.x != D1.x+10 && D3.y != D1.y-16 && D4.x != D1.x+15 && D4.y != D1.y-16 && D5.x != D1.x+20 && D5.y != D1.y-16)
                 {
                    if(Deja(D2, D1, x, y) == 1 && Deja(D3, D1, x, y) == 1 && Deja(D4, D1, x, y) == 1 && Deja(D5, D1, x, y) == 1 && ok3(D2, D3, D4, D5) == 1)
                    {
                       D1.x = x;
                       D1.y = y;
                    }
                 }
                 else if(D3.y == D1.y-16 && D2.y == D1.y-16)
                 {
                     if(D3.x != D1.x+10 && D2.x != D1.x+5)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D3.y == D1.y-16 && D4.y == D1.y-16)
                 {
                     if(D3.x != D1.x+10 && D4.x != D1.x+15)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D3.y == D1.y-16 && D5.y == D1.y-16)
                 {
                     if(D3.x != D1.x+10 && D5.x != D1.x+20)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D4.y == D1.y-16 && D5.y == D1.y-16)
                 {
                     if(D4.x != D1.x+15 && D5.x != D1.x+20)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D4.y == D1.y-16 && D2.y == D1.y-16)
                 {
                     if(D4.x != D1.x+15 && D2.x != D1.x+5)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D5.y == D1.y-16 && D2.y == D1.y-16)
                 {
                     if(D5.x != D1.x+20 && D2.x != D1.x+5)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                 else if(D3.y == D1.y-16)
                 {
                     if(D3.x != D1.x+10)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D2.y == D1.y-16)
                {
                     if(D2.x != D1.x+5)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D4.y == D1.y-16)
                 {
                     if(D4.x != D1.x+15)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D5.y == D1.y-16)
                 {
                     if(D5.x != D1.x+20)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
            }
          }
        }

       SDL_SetRenderDrawColor(renderer,255,255,255,255);
       SDL_RenderClear(renderer);
       //Tracer la ligne de separation en noir
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawLine(renderer,850,0,850,500);
       //Construire les 3 tours en violet
       SDL_SetRenderDrawColor(renderer,150,100,155,255);
       SDL_RenderFillRect(renderer,&T1);
       SDL_RenderFillRect(renderer,&T2);
       SDL_RenderFillRect(renderer,&T3);
       //Ecrire le text
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Instrutions", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Recommencer", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Solution", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Sortir", text,noir,20);
       //Ecrire le text du bas
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Disque", t,noir,20);
       SDL_RenderDrawRect(renderer,&p);
       p.x+=5, p.y+=1;
       EcrireTextDirect(renderer, "5", p,noir,20);
       t.x+=150;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Deplacements Min:", t,noir,20);
       p.x+=260;p.y-=3;
       EcrireTextDirect(renderer, "31", p,noir,20);
       t.x+=250;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Deplacements:", t,noir,20);



       //🧡️🧡️🧡️🧡️🧡️🧡️pour 1er disque🧡️🧡️🧡️🧡️

       SDL_SetRenderDrawColor(renderer,255,100,10,255);

       if(D1.x>180 && D1.x<250 && D1.y>118 && D1.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y==384 && D5.x==230 && D5.y==368)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400 && D5.x==230 && D5.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==215 && D2.y==416 && D4.x==225 && D3.y==400 && D5.x==230 && D5.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400 && D5.x==230 && D5.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==215 && D2.y==416 && D4.x==225 && D4.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==215 && D2.y==416 && D5.x==230 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416 && D5.x==230 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==225 && D4.y==416 && D5.x==230 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==215 && D2.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==225 && D4.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D5.x==230 && D5.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else
          {
             D1.x=210 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
             deplacement++;
          }
       }
       else if(D1.x>430 && D1.x<500 && D1.y>118 && D1.y<184)
       {
          //on est sur la 2e tour✅️
          if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384 && D5.x==480 && D5.y==368)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D4.x==475 && D4.y==400 && D5.x==480 && D5.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400 && D5.x==480 && D5.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D4.x==475 && D4.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416 && D5.x==480 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416 && D5.x==480 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==475 && D4.y==416 && D5.x==480 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==475 && D4.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D5.x==480 && D5.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else
          {
             D1.x=460 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
             deplacement++;
          }
       }
       else if(D1.x>680 && D1.x<750 && D1.y>118 && D1.y<184)
       {
          //on est sur la 3e tour✅️
          if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384 && D5.x==730 && D5.y==368)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D4.x==725 && D4.y==400 && D5.x==730 && D5.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400 && D5.x==730 && D5.y==384)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D4.x==725 && D4.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416 && D5.x==730 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416 && D5.x==730 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D4.x==725 && D4.y==416 && D5.x==730 && D5.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
           }
          else if(D3.x==720 && D3.y==416)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
           }
          else if(D4.x==725 && D4.y==416)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
           }
          else if(D5.x==730 && D5.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
           }
          else
          {
             D1.x=710 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
             deplacement++;
          }
       }
       else
        {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "5", D,noir,10);
        } //En dehors des 3 tours

       // 💚️💚️💚️💚️💚️💚️💚️Pour le 2e disque 💚️💚️💚️💚️💚️💚️
       SDL_SetRenderDrawColor(renderer,0,250,0,255);
       if(D2.x>198 && D2.x<250 && D2.y>118 && D2.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y==384 && D5.x==230 && D5.y== 368)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y==384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400 && D5.x==230 && D5.y== 384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==210 && D1.y==416 && D4.x==225 && D4.y==400 && D5.x==230 && D5.y== 384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400 && D5.x==230 && D5.y== 384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==210 && D1.y==416 && D4.x==225 && D4.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==210 && D1.y==416 && D5.x==230 && D5.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==220 && D3.y==416 && D5.x==230 && D5.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }

          else if(D4.x==225 && D4.y==416 && D5.x==230 && D5.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==220 && D3.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D4.x==225 && D4.y==416)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D5.x==230 && D5.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==210 && D1.y==416)
          {
             D2.x=215 , D2.y=400;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else
          {
             D2.x=215 , D2.y=416;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
       }
       else if(D2.x>448 && D2.x<500 && D2.y>118 && D2.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384 && D5.x==480 && D5.y==368)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400 && D5.x==480 && D5.y==384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==460 && D1.y==416 && D4.x==475 && D4.y==400 && D5.x==480 && D5.y==384)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400 && D5.x==480 && D5.y==384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==460 && D1.y==416 && D4.x==475 && D4.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==460 && D1.y==416 && D5.x==480 && D5.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==470 && D3.y==416 && D5.x==480 && D5.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D4.x==475 && D4.y==416 && D5.x==480 && D5.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D4.x==475 && D4.y==416)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }

          else if(D3.x==470 && D3.y==416)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D5.x==480 && D5.y==416)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }

          else if(D1.x==460 && D1.y==416)
          {
             D2.x=465 , D2.y=400;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else
          {
             D2.x=465 , D2.y=416;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
       }
       else if(D2.x>698 && D2.x<750 && D2.y>118 && D2.y<184)
       {
          //on est sur la 3e tour✅️

          if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384 && D5.x==730 && D5.y==368)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400 && D5.x==730 && D5.y==384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==710 && D1.y==416 && D4.x==725 && D4.y==400 && D5.x==730 && D5.y==384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400 && D5.x==730 && D5.y==384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }

          else if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==710 && D1.y==416 && D5.x==730 && D5.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D1.x==710 && D1.y==416 && D4.x==725 && D4.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==720 && D3.y==416 && D5.x==730 && D5.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
         else if(D4.x==725 && D4.y==416 && D5.x==730 && D5.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==720 && D3.y==416)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D4.x==725 && D4.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D5.x==730 && D5.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416)
          {
             D2.x=715 , D2.y=400;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
          else
          {
             D2.x=715 , D2.y=416;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
       }
       else
       {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "4", D,noir,10);
       }//En dehors des 3 tours


       // 💛️💛️💛️💛️💛️💛️ Pour le 3e disque 💛️💛️💛️💛️💛️💛️💛️
       SDL_SetRenderDrawColor(renderer,250,250,0,255);
       //SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
       if(D3.x>226 && D3.x<250 && D3.y>118 && D3.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D4.x == 225 && D4.y == 384 && D5.x==230 && D5.y==368)
            {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D4.x==225 && D4.y==384)
            {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 210 && D1.y == 416 && D4.x == 225 && D4.y == 400 && D5.x==230 && D5.y==384)
            {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 210 && D1.y == 416 && D4.x == 225 && D4.y == 400 && D5.x==230 && D5.y==384)
            {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D2.x == 215 && D2.y == 416 && D4.x == 225 && D4.y == 400 && D5.x==230 && D5.y==384)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }

          else if(D1.x == 210 && D1.y == 416 && D4.x == 225 && D4.y == 400)
            {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }

          else if(D1.x == 210 && D1.y == 416 && D5.x == 230 && D5.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D2.x == 215 && D2.y == 416 && D4.x == 225 && D4.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D2.x == 215 && D2.y == 416 && D5.x == 230 && D5.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D4.x == 225 && D4.y == 416 && D5.x == 230 && D5.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D4.x == 225 && D4.y == 416)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D5.x == 230 && D5.y == 416)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400)
          {
             D3.x=220, D3.y=384;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416)
          {
             D3.x=220, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416)
          {
             D3.x=220, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=220, D3.y=416;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
       }
       else if(D3.x>466 && D3.x<500 && D3.y>118 && D3.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D4.x == 475 && D4.y == 384 && D5.x==480 && D5.y==368)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D4.x == 475 && D4.y == 384)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D5.x == 480 && D5.y == 384)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 460 && D1.y == 416 && D4.x == 475 && D4.y == 400 && D5.x == 480 && D5.y == 384)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D2.x == 465 && D2.y == 416 && D4.x == 475 && D4.y == 400 && D5.x == 480 && D5.y == 384)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 460 && D1.y == 416 && D4.x == 475 && D4.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 460 && D1.y == 416 && D5.x == 480 && D5.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D2.x == 465 && D2.y == 416 && D4.x == 475 && D4.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D2.x == 465 && D2.y == 416 && D5.x == 480 && D5.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D4.x == 475 && D4.y == 416 && D5.x == 480 && D5.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D4.x == 475 && D4.y == 416)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D5.x == 480 && D5.y == 416)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x==460 && D1.y==416 && D2.x == 465 && D2.y == 400)
          {
             D3.x=470, D3.y=384;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D1.x==460 && D1.y==416)
          {
             D3.x=470, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D2.x==465 && D2.y==416)
          {
             D3.x=470, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=470, D3.y=416;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
       }
       else if(D3.x>716 && D3.x<750 && D3.y>118 && D3.y<184)
       {
          //on est sur la 3e tour✅️
          if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D4.x == 725 && D4.y==384 && D5.x==730 && D5.y==368)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D4.x == 725 && D4.y == 384)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
           else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y==400 && D5.x==730 && D5.y==384)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y == 400 && D5.x == 730 && D5.y == 384)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D2.x == 715 && D2.y == 416 && D4.x == 725 && D4.y == 400 && D5.x == 730 && D5.y == 384)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x == 710 && D1.y == 416 && D5.x == 730 && D5.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D2.x == 715 && D2.y == 416 && D4.x == 725 && D4.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D2.x == 715 && D2.y == 416 && D5.x == 730 && D5.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D4.x == 725 && D4.y == 416 && D5.x == 730 && D5.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D4.x == 725 && D4.y == 416)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D5.x == 730 && D5.y == 416)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x==710 && D1.y==416 && D2.x == 715 && D2.y == 400)
          {
             D3.x=720, D3.y=384;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D1.x==710 && D1.y==416)
          {
             D3.x=720, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else if(D2.x==715 && D2.y==416)
          {
             D3.x=720, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=720, D3.y=416;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
       }
       else
         {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "3", D,noir,10);
         }

       // 💙️💙️💙️💙️💙️💙️ Pour le 4e disque 💙️💙️💙️💙️💙️💙️💙️

       SDL_SetRenderDrawColor(renderer,0,0,250,255);
       //SDL_SetRenderDrawBlendMode(renderer,SDL_BLENDMODE_BLEND);
       if(D4.x>226 && D4.x<250 && D4.y>118 && D4.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384 && D5.x==230 && D5.y==368)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D5.x==230 && D5.y==384)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400 && D5.x==230 && D5.y==384)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400 && D5.x==230 && D5.y==384)
            {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 210 && D1.y == 416 && D5.x == 230 && D5.y == 400)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D2.x == 215 && D2.y == 416 && D5.x == 230 && D5.y == 400)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }

          else if(D3.x == 220 && D3.y == 416 && D5.x == 230 && D5.y == 400)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384)
          {
             D4.x = 225, D4.y = 368;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400)
          {
             D4.x = 225, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D4.x = 225, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D4.x = 225, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416)
          {
             D4.x=225, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416)
          {
             D4.x=225, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 220 && D3.y == 416)
          {
             D4.x=225, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D5.x == 230 && D5.y == 416)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }

          else
          {
             D4.x=225, D4.y=416;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
       }
       else if(D4.x>466 && D4.x<500 && D4.y>118 && D4.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384 && D5.x==480 && D5.y==368)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }

          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D5.x==480 && D5.y==384)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }

          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400 && D5.x==480 && D5.y==384)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400 && D5.x==480 && D5.y==384)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384)
          {
             D4.x = 475, D4.y = 368;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D5.x == 480 && D5.y == 400)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D2.x == 465 && D2.y == 416 && D5.x == 480 && D5.y == 400)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D3.x == 470 && D3.y == 416 && D5.x == 480 && D5.y == 400)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400)
          {
             D4.x = 475, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400)
          {
             D4.x = 475, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400)
          {
             D4.x = 475, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D5.x==480 && D5.y==416)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }

          else if(D1.x==460 && D1.y==416)
          {
             D4.x=475, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x==465 && D2.y==416)
          {
             D4.x=475, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x==470 && D3.y==416)
          {
             D4.x=475, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else
          {
             D4.x=475, D4.y=416;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
       }
       else if(D4.x>716 && D4.x<750 && D4.y>118 && D4.y<184)
       {
          //on est sur la 3e tour✅️
          if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384 && D5.x==730 && D5.y==368)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D5.x==730 && D5.y==384)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400 && D5.x==730 && D5.y==384)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400 && D5.x==730 && D5.y==384)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384)
          {
             D4.x = 725, D4.y = 368;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D5.x == 730 && D5.y == 400)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }

          else if(D2.x == 715 && D2.y == 416 && D5.x == 730 && D5.y == 400)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D3.x == 720 && D3.y == 416 && D5.x == 730 && D5.y == 400)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400)
          {
             D4.x = 725, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400)
          {
             D4.x = 725, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400)
          {
             D4.x = 725, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D5.x==730 && D5.y==416)
           {
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x==710 && D1.y==416)
          {
             D4.x=725, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x==715 && D2.y==416)
          {
             D4.x=725, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x==720 && D3.y==416)
          {
             D4.x=725, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else
          {
             D4.x=725, D4.y=416;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
       }
       else
       {
          SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
          SDL_RenderFillRect(renderer,&D4);
          EcrireTextDirect(renderer, "2", D,noir,10);
       }
           //En dehors des 3 tours


       // ❤️❤️❤️❤️❤️❤️ Pour le 5e disque ❤️❤️❤️❤️❤️❤️❤️❤️❤️❤️

       SDL_SetRenderDrawColor(renderer,250,0,0,255);

       if(D5.x>226 && D5.x<250 && D5.y>118 && D5.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384 && D4.x == 225 && D4.y == 368)
          {
             D5.x = 230, D5.y = 352;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384)
          {
             D5.x = 230, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D4.x == 225 && D4.y == 384)
          {
             D5.x = 230, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400 && D4.x == 225 && D4.y == 384)
          {
             D5.x = 230, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400 && D4.x == 225 && D4.y == 384)
          {
             D5.x = 230, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D4.x == 225 && D4.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
          }
          else if(D2.x == 215 && D2.y == 416 && D4.x == 225 && D4.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 220 && D3.y == 416 && D4.x == 225 && D4.y == 400)
          {
             D5.x = 230, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416)
          {
             D5.x=230, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416)
          {
             D5.x=230, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 220 && D3.y == 416)
          {
             D5.x=230, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D4.x == 225 && D4.y == 416)
          {
             D5.x=230, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else
          {
             D5.x=230, D5.y=416;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else if(D5.x>466 && D5.x<500 && D5.y>118 && D5.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384 && D4.x==475 && D4.y==368)
          {
             D5.x = 480, D5.y = 352;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384)
          {
             D5.x = 480, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D4.x == 475 && D4.y == 384)
          {
             D5.x = 480, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400 && D4.x == 475 && D4.y == 384)
          {
             D5.x = 480, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400 && D4.x == 475 && D4.y == 384)
          {
             D5.x = 480, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D4.x == 475 && D4.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D4.x == 475 && D4.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 470 && D3.y == 416 && D4.x == 475 && D4.y == 400)
          {
             D5.x = 480, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x==460 && D1.y==416)
          {
             D5.x=480, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x==465 && D2.y==416)
          {
             D5.x=480, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x==470 && D3.y==416)
          {
             D5.x=480, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D4.x==475 && D4.y==416)
          {
             D5.x=480, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else
          {
             D5.x=480, D5.y=416;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else if(D5.x>716 && D5.x<750 && D5.y>118 && D5.y<184)
       {
          //on est sur la 3e tour✅️
          if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384 && D4.x==725 && D4.y==368)
          {
             D5.x = 730, D5.y = 352;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384)
          {
             D5.x = 730, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D4.x == 725 && D4.y == 384)
          {
             D5.x = 730, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400 && D4.x == 725 && D4.y == 384)
          {
             D5.x = 730, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400 && D4.x == 725 && D4.y == 384)
          {
             D5.x = 730, D5.y = 368;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D4.x == 725 && D4.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 720 && D3.y == 416 && D4.x == 725 && D4.y == 400)
          {
             D5.x = 730, D5.y = 384;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x==710 && D1.y==416)
          {
             D5.x=730, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x==715 && D2.y==416)
          {
             D5.x=730, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x==720 && D3.y==416)
          {
             D5.x=730, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D4.x==725 && D4.y==416)
          {
             D5.x=730, D5.y=400;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else
          {
             D5.x=730, D5.y=416;
             SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D5);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else
       {
        SDL_Rect D = {D5.x+15,D5.y+6, 0,0};
        SDL_RenderFillRect(renderer,&D5);
        EcrireTextDirect(renderer, "1", D,noir,10);//En dehors des 3 tours
       }
       // Affichage du deplacement
       sprintf(nbre, "%d", deplacement);
       p.x+=220;p.y-=2;
       EcrireTextDirect(renderer,nbre,p,noir,20);
       //Affichage du temps
      SDL_Rect posiTemps = {50,5,0,0};
      EcrireTextDirect(renderer, "Temps: ", posiTemps,noir,30);
      posiTemps.x+=100;
      EcrireTextDirect(renderer,h,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "h", posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer,min,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "min", posiTemps,noir,30);
      posiTemps.x+=80;
      EcrireTextDirect(renderer,sec,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "sec", posiTemps,noir,30);

       la:
       SDL_RenderPresent(renderer);

       if(D1.x==710 && D1.y==416 && D2.x==715 && D2.y==400 && D3.x==720 && D3.y==384 && D4.x==725 && D4.y==368 && D5.x==730 && D5.y==352)
       {
           //Jouer le son
           Mix_PlayMusic(son, 1);

           SDL_Texture *texture=NULL;
           SDL_Surface *surface=NULL;
           SDL_Rect d = {420,180,0,0};
           surface=IMG_Load("bravo.jpg");
           texture=SDL_CreateTextureFromSurface(renderer,surface);
           SDL_FreeSurface(surface);
           SDL_QueryTexture(texture,NULL,NULL,&d.w,&d.h);
           SDL_RenderCopy(renderer,texture,NULL,&d);
           SDL_RenderPresent(renderer);
           SDL_DestroyTexture(texture);
           SDL_Delay(4000);
           Mix_FreeMusic(son); //Libération de la musique
           Mix_FreeMusic(musique); //Libération de la musique

           SDL_Event suite;
           int v = 1;
           while(v==1)
           {
               SDL_WaitEvent(&suite);
               if(suite.type == SDL_QUIT)
                  v=0;
               //Recuperaton et utilisation de l'état de la souris
               Uint32 bouton;
               int x, y;
               bouton=SDL_GetMouseState(&x, &y);

               SDL_Rect r = {200,50,0,0},  rr1 = {400,170,0,0},  rr2 = {400,220,0,0},  rr3 = {400,270,0,0};
               SDL_Rect r1 = {390,165,150,40}, r2 = {390,215,200,40}, r3 = {390,265,100,40};

               if(x>r1.x && x<r1.x+r1.w && y>r1.y && y<r1.y+r1.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r1);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                    goto rejouer;
               }
               else if(x>r2.x && x<r2.x+r2.w && y>r2.y && y<r2.y+r2.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r2);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                 {
                    jouer4(renderer);
                    v = 0;
                 }
               }
               else if(x>r3.x && x<r3.x+r3.w && y>r3.y && y<r3.y+r3.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r3);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                    v = 0;
               }
               SDL_Texture *txture = NULL;
               SDL_Surface *victoire = NULL;
               victoire = IMG_Load("2dc8h1u.jpg");
               txture = SDL_CreateTextureFromSurface(renderer, victoire);
               SDL_FreeSurface(victoire);
               SDL_RenderCopy(renderer,txture,NULL,NULL); // Affichage de l'image

               EcrireTextDirect(renderer, "Felicitation vous avez reuissi la partie", r,blanc,40);
               r.x += 200; r.y += 70;
               EcrireTextDirect(renderer, "Nombre de mouvement:  ", r,blanc,30);
               r.x += 350; r.y += 7;
               EcrireTextDirect(renderer,nbre,r,noir,20);
               EcrireTextDirect(renderer, "Rejouer", rr1, blanc,25);
               EcrireTextDirect(renderer, "Niveau suivant", rr2,blanc,25);
               EcrireTextDirect(renderer, "Sortir", rr3,blanc,25);
               SDL_RenderPresent(renderer);
           }
           continuer=0;//break;
       }
       int x, y;
       Uint32 bouton;
       bouton=SDL_GetMouseState(&x, &y);
       if(x>855 && x<990 && y>10 && y<50)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               int v=1;
               SDL_Rect t = {50,20,0,0};
               SDL_SetRenderDrawColor(renderer,255,255,255,255);
               SDL_RenderClear(renderer);
               EcrireTextDirect(renderer, "  INSTRUCTION POUR LE DEPLACEMENT DES DISQUES", t,bleu,25);
               t.y+=70;
               EcrireTextDirect(renderer, "-> Tapez 1 puis bouger la souris pour deplacer le disque rouge", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 2 puis bouger la souris pour deplacer le disque bleu", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 3 puis bouger la souris pour deplacer le disque jaune", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 4 puis bouger la souris pour deplacer le disque vert", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 5 puis bouger la souris pour deplacer le disque orange", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Vous gagnerai si les 5 disques se trouvent au niveau de la 3e tour", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez sur la touche Entrer si vous finissez de lire", t,noir,25);
               SDL_RenderPresent(renderer);
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
       else if(x>855 && x<990 && y>60 && y<100)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               //Les 3 rectangles pour la sugestion de recommencer
               SDL_Rect d1 = {200,150,500,200}, d2 = {250,250,75,50}, d3 = {350,250,75,50};
               SDL_Rect t1 = {250,180,0,0}, t2 = {255,255,0,0};
               SDL_SetRenderDrawColor(renderer,250,250,0,255);
               SDL_RenderFillRect(renderer,&d1);
               SDL_SetRenderDrawColor(renderer,0,250,250,255);
               SDL_RenderFillRect(renderer,&d2);
               SDL_RenderFillRect(renderer,&d3);
               SDL_SetRenderDrawColor(renderer,0,0,0,255);
               EcrireTextDirect(renderer, "Etes-vous sure de recommencer ?", t1, noir,25);
               EcrireTextDirect(renderer, "Oui", t2,noir,25);
               t2.x+=100;
               EcrireTextDirect(renderer, "Non", t2,noir,25);
               SDL_RenderPresent(renderer);

               int c=1;
               SDL_Event e;
               while(c == 1)
               {
                   SDL_WaitEvent(&e);
                   //Recuperaton et utilisation de l'état de la souris
                   Uint32 bouton;
                   int x, y;
                   bouton=SDL_GetMouseState(&x, &y);
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
               rejouer:
               //Rectangle des 3 tours reinitialiser
               T1.x=240; T1.y=200; T1.w=20; T1.h=232;
               T2.x=490; T2.y=200; T2.w=20; T2.h=232;
               T3.x=740; T3.y=200; T3.w=20; T3.h=232;
               //Rectangle des 3 disques reinitialiser
                D1.x=210; D1.y=416; D1.w=80; D1.h=16;
                D2.x=215; D2.y=400; D2.w=70; D2.h=16;
                D3.x=220; D3.y=384; D3.w=60; D3.h=16;
                D4.x=225; D4.y=368; D4.w=50; D4.h=16;
                D5.x=230; D5.y=352; D5.w=40; D5.h=16;
               //Couleur
               SDL_Color blanc = {255,255,255,255}, noir = {0,0,0,255};

               text.x=860; text.y=20; text.w=200; text.h=40;
               r.x=855; r.y=10; r.w=135; r.h=40;
               t.x=250; t.y=470; t.w=0; t.h=0;
               p.x=320; p.y=475; p.w=30; p.h=22;
               goto debut;
           }
       }
       else if(x>855 && x<990 && y>110 && y<150)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               int v=1;
               SDL_Rect d = {300,0,400,450};
               SDL_Surface *s=NULL;
               SDL_Texture *t=NULL;
               SDL_SetRenderDrawColor(renderer,255,255,255,255);
               SDL_RenderClear(renderer);
               s=IMG_Load("solution4.jpg");
               t=SDL_CreateTextureFromSurface(renderer,s);
               SDL_FreeSurface(s);
               //SDL_QueryTexture(t,NULL,NULL,&d.w,&d.h);
               SDL_RenderCopy(renderer,t,NULL,&d);
               SDL_DestroyTexture(t);
               SDL_RenderPresent(renderer);
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
       else if(x>855 && x<990 && y>160 && y<200)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               //Les 3 rectangles pour la sugestion de recommencer
               SDL_Rect d1 = {200,150,500,200}, d2 = {250,250,75,50}, d3 = {350,250,75,50};
               SDL_Rect t1 = {250,180,0,0}, t2 = {255,255,0,0};
               SDL_SetRenderDrawColor(renderer,250,250,0,255);
               SDL_RenderFillRect(renderer,&d1);
               SDL_SetRenderDrawColor(renderer,0,250,250,255);
               SDL_RenderFillRect(renderer,&d2);
               SDL_RenderFillRect(renderer,&d3);
               SDL_SetRenderDrawColor(renderer,0,0,0,255);
               EcrireTextDirect(renderer, "Etes-vous sure de Sortir ?", t1, noir,25);
               EcrireTextDirect(renderer, "Oui", t2,noir,25);
               t2.x+=100;
               EcrireTextDirect(renderer, "Non", t2,noir,25);
               SDL_RenderPresent(renderer);

               int c=1;
               SDL_Event e;
               while(c == 1)
               {
                   SDL_WaitEvent(&e);
                   //Recuperaton et utilisation de l'état de la souris
                   Uint32 bouton;
                   int x, y;
                   bouton=SDL_GetMouseState(&x, &y);
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
               continuer=0;break;
           }
       }
  }
}


//Fonction de niveau 2
void jouer2(SDL_Renderer* renderer)
{
  //Rectangle des 3 tours
  SDL_Rect T1 = {240,200,20,232}, T2 = {490,200,20,232}, T3 = {740,200,20,232};
  //Rectangle des 3 disques
  SDL_Rect D1 = {210,416, 80,16}, D2 = {215,400,70,16}, D3 = {220,384,60,16}, D4 = {225,368,50,16};
  //Couleur
  SDL_Color blanc = {255,255,255,255}, noir = {0,0,0,255}, bleu = {0,0,255,255};

  Mix_Music *musique,*son;
  musique = Mix_LoadMUS("you_ll_never_walk_alone_liverpool-with_lyrics_mp3_41027.mp3");
  son = Mix_LoadMUS("APPLAUDISSEMENTS_-_Bruitage_Gratuit(256k).mp3");
  //Jouer la musique
  Mix_PlayMusic(musique,-1);

  char nbre[4];
  int continuer=1, deplacement=0;
  SDL_Event event;

   while(continuer)
   {
        //Gestion du temps
        int heures, minutes, secondes;
        Uint32 temps;
        temps = SDL_GetTicks();
        heures = ((temps/1000)/3600)%24;
        minutes = ((temps/1000)/60)%60;
        secondes= (temps/1000)%60;
        //Conversion du temps en char
        char h[3], min[3], sec[3] ;
        sprintf(h, "%d", heures);
        sprintf(min, "%d", minutes);
        sprintf(sec, "%d", secondes);

        //Rectangle des ecritures
        SDL_Rect text = {860,20,200,40}, r = {855,10,135,40}, t = {100,470,0,0}, p = {170,475,30,22};

        debut:
        SDL_PollEvent(&event);

        //Bouger le disque rouge (le plus petit)
        if(event.key.keysym.sym == SDLK_1)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                  if(Deja(D2, D4, x, y) == 1 && Deja(D1, D4, x, y) == 1 && Deja(D3, D4, x, y) == 1 && ok2(D1, D2, D3) == 1)
                  {
                     D4.x = x;
                     D4.y = y;
                  }
               }
           }
        }

        //Bouger le disque bleu (le 2e plus petit)
        if(event.key.keysym.sym == SDLK_2)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                  if(D4.x != D3.x+5 && D4.y != D3.y-16)
                  {
                     if(Deja(D2, D3, x, y) == 1 && Deja(D1, D3, x, y) == 1 && Deja(D4, D3, x, y) == 1 && ok2(D1, D2, D4) == 1)
                     {
                        D3.x = x;
                        D3.y = y;
                     }
                  }
                  else if(D4.y == D3.y-16)
                  {
                     if(D4.x != D3.x+5)
                     {
                        D3.x = x;
                        D3.y = y;
                     }
                  }
               }
           }
        }
        //Bouger le disque vert (le moyen)
        else if(event.key.keysym.sym == SDLK_3)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                 if(D3.x != D2.x+5 && D3.y != D2.y-16 && D4.x != D2.x+10 && D4.y != D2.y-16)
                 {
                    if(Deja(D3, D2, x, y) == 1 && Deja(D4, D2, x, y) == 1 && Deja(D1, D2, x, y) == 1 && ok2(D1, D3, D4) == 1)
                    {
                       D2.x = x;
                       D2.y = y;
                    }
                 }
                 else if(D4.y == D2.y-16 && D3.y != D2.y-16)
                 {
                     if(D4.x != D2.x+10)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
                else if(D3.y == D2.y-16 && D4.y != D2.y-16)
                 {
                     if(D3.x != D2.x+5)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                }
            }
          }
        }
        //Bouger le disque jaune (le plus grand)
        else if(event.key.keysym.sym == SDLK_4)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                 if(D2.x != D1.x+5 && D2.y != D1.y-16 && D3.x != D1.x+10 && D3.y != D1.y-16 && D4.x != D1.x+15 && D4.y != D1.y-16)
                 {
                    if(Deja(D2, D1, x, y) == 1 && Deja(D3, D1, x, y) == 1 && Deja(D4, D1, x, y) == 1 && ok2(D2, D3, D4) == 1)
                    {
                       D1.x = x;
                       D1.y = y;
                    }
                 }
                 else if(D3.y == D1.y-16 && D2.y != D1.y-16 && D4.y != D1.y-16)
                 {
                     if(D3.x != D1.x+10)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D2.y == D1.y-16 && D3.y != D1.y-16 && D4.y != D1.y-16)
                {
                     if(D2.x != D1.x+5)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
                else if(D4.y == D1.y-16 && D2.y != D1.y-16 && D3.y != D1.y-16)
                 {
                     if(D4.x != D1.x+15)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
                }
            }
          }
        }

       SDL_SetRenderDrawColor(renderer,255,255,255,255);
       SDL_RenderClear(renderer);
       //Tracer la ligne de separation en noir
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawLine(renderer,850,0,850,500);
       //Construire les 3 tours en violet
       SDL_SetRenderDrawColor(renderer,150,100,155,255);
       SDL_RenderFillRect(renderer,&T1);
       SDL_RenderFillRect(renderer,&T2);
       SDL_RenderFillRect(renderer,&T3);
       //Ecrire le text
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Instrutions", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Recommencer", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Solution", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Sortir", text,noir,20);
       //Ecrire le text du bas
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Disque", t,noir,20);
       SDL_RenderDrawRect(renderer,&p);
       p.x+=5, p.y+=1;
       EcrireTextDirect(renderer, "4", p,noir,20);
       t.x+=150;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Deplacements Min:", t,noir,20);
       p.x+=260;p.y-=2;
       EcrireTextDirect(renderer, "15", p,noir,20);
       t.x+=250;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Deplacements:", t,noir,20);


       //🧡️🧡️🧡️🧡️🧡️🧡️🧡️ pour 1er disque 🧡️🧡️🧡️🧡️🧡️🧡️🧡️

       SDL_SetRenderDrawColor(renderer,255,100,10,255);

       if(D1.x>180 && D1.x<250 && D1.y>118 && D1.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y==384)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D2.x==215 && D2.y==416 && D4.x==225 && D4.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D2.x==215 && D2.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D4.x==225 && D4.y==416)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else
          {
             D1.x=210 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
       }
       else if(D1.x>430 && D1.x<500 && D1.y>118 && D1.y<184)
       {
          //on est sur la 2e tour✅️
          if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384)
            {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D2.x==465 && D2.y==416 && D4.x==475 && D4.y==400)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D2.x==465 && D2.y==416)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==470 && D3.y==416)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D4.x==475 && D4.y==416)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else
          {
             D1.x=460 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
       }
       else if(D1.x>680 && D1.x<750 && D1.y>118 && D1.y<184)
       {
          //on est sur la 3e tour✅️
          if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D2.x==715 && D2.y==416 && D4.x==725 && D4.y==400)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D2.x==715 && D2.y==416)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D3.x==720 && D3.y==416)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else if(D4.x==725 && D4.y==416)
           {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
           }
          else
          {
             D1.x=710 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
             deplacement++;
          }
       }
       else
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "4", D,noir,10);
          } //En dehors des 3 tours


       //💚️💚️💚️💚️💚️💚️💚️💚️ Pour le 2e disque 💚️💚️💚️💚️💚️💚️💚️💚️

       SDL_SetRenderDrawColor(renderer,0,250,0,255);
       if(D2.x>198 && D2.x<250 && D2.y>118 && D2.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400 && D4.x==225 && D4.y==384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x==210 && D1.y==416 && D4.x==225 && D4.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D3.x==220 && D3.y==416 && D4.x==225 && D4.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D3.x==220 && D3.y==416)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D4.x==225 && D4.y==416)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x==210 && D1.y==416)
          {
             D2.x=215 , D2.y=400;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else
          {
             D2.x=215 , D2.y=416;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
       }
       else if(D2.x>448 && D2.x<500 && D2.y>118 && D2.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400 && D4.x==475 && D4.y==384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x==460 && D1.y==416 && D4.x==475 && D4.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D3.x==470 && D3.y==416 && D4.x==475 && D4.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D3.x==470 && D3.y==416)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D4.x==475 && D4.y==416)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x==460 && D1.y==416)
          {
             D2.x=465 , D2.y=400;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else
          {
             D2.x=465 , D2.y=416;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
       }
       else if(D2.x>698 && D2.x<750 && D2.y>118 && D2.y<184)
       {
          //on est sur la 3e tour✅️

          if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400 && D4.x==725 && D4.y==384)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x==710 && D1.y==416 && D4.x==725 && D4.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D3.x==720 && D3.y==416 && D4.x==725 && D4.y==400)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D3.x==720 && D3.y==416)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D4.x==725 && D4.y==416)
           {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
           }
          else if(D1.x==710 && D1.y==416)
          {
             D2.x=715 , D2.y=400;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
          else
          {
             D2.x=715 , D2.y=416;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
       }
       else
         {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "3", D,noir,10);
         }
    //En dehors des 3 tours

       //💙️💙️💙️💙️💙️💙️💙️💙️ Pour le 3e disque 💙️💙️💙️💙️💙️💙️💙️💙️

       SDL_SetRenderDrawColor(renderer,250,0,0,255);

       if(D3.x>226 && D3.x<250 && D3.y>118 && D3.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D4.x == 225 && D4.y == 384)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 210 && D1.y == 416 && D4.x == 225 && D4.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D2.x == 215 && D2.y == 416 && D4.x == 225 && D4.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D4.x == 225 && D4.y == 416)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
           }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400)
          {
             D3.x=220, D3.y=384;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416)
          {
             D3.x=220, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416)
          {
             D3.x=220, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=220, D3.y=416;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
       }
       else if(D3.x>466 && D3.x<500 && D3.y>118 && D3.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D4.x == 475 && D4.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 460 && D1.y == 416 && D4.x == 475 && D4.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D2.x == 465 && D2.y == 416 && D4.x == 475 && D4.y == 400)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D4.x == 475 && D4.y == 416)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416 && D2.x == 465 && D2.y == 400)
          {
             D3.x=470, D3.y=384;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x==460 && D1.y==416)
          {
             D3.x=470, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x==465 && D2.y==416)
          {
             D3.x=470, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=470, D3.y=416;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
       }
       else if(D3.x>716 && D3.x<750 && D3.y>118 && D3.y<184)
       {
          //on est sur la 3e tour✅️
          if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D4.x == 725 && D4.y == 384)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x == 710 && D1.y == 416 && D4.x == 725 && D4.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D2.x == 715 && D2.y == 416 && D4.x == 725 && D4.y == 400)
           {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D4.x == 725 && D4.y == 384)
          {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416 && D2.x == 715 && D2.y == 400)
          {
             D3.x=720, D3.y=384;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D1.x==710 && D1.y==416)
          {
             D3.x=720, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D2.x==715 && D2.y==416)
          {
             D3.x=720, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=720, D3.y=416;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
       }
       else
         {
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "2", D,noir,10);
         }


       //❤️❤️❤️❤️❤️❤️❤️❤️ Pour le 4e disque ❤️❤️❤️❤️❤️❤️❤️❤️❤️

       SDL_SetRenderDrawColor(renderer,0,0,250,255);

       if(D4.x>226 && D4.x<250 && D4.y>118 && D4.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400 && D3.x == 220 && D3.y == 384)
          {
             D4.x = 225, D4.y = 368;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400)
          {
             D4.x = 225, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D4.x = 225, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416 && D3.x == 220 && D3.y == 400)
          {
             D4.x = 225, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416)
          {
             D4.x=225, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416)
          {
             D4.x=225, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x == 220 && D3.y == 416)
          {
             D4.x=225, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else
          {
             D4.x=225, D4.y=416;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else if(D4.x>466 && D4.x<500 && D4.y>118 && D4.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400 && D3.x == 470 && D3.y == 384)
          {
             D4.x = 475, D4.y = 368;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400)
          {
             D4.x = 475, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 460 && D1.y == 416 && D3.x == 470 && D3.y == 400)
          {
             D4.x = 475, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 465 && D2.y == 416 && D3.x == 470 && D3.y == 400)
          {
             D4.x = 475, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x==460 && D1.y==416)
          {
             D4.x=475, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x==465 && D2.y==416)
          {
             D4.x=475, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x==470 && D3.y==416)
          {
             D4.x=475, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else
          {
             D4.x=475, D4.y=416;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else if(D4.x>716 && D4.x<750 && D4.y>118 && D4.y<184)
       {
          //on est sur la 3e tour✅️
          if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400 && D3.x == 720 && D3.y == 384)
          {
             D4.x = 725, D4.y = 368;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400)
          {
             D4.x = 725, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 710 && D1.y == 416 && D3.x == 720 && D3.y == 400)
          {
             D4.x = 725, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 715 && D2.y == 416 && D3.x == 720 && D3.y == 400)
          {
             D4.x = 725, D4.y = 384;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x==710 && D1.y==416)
          {
             D4.x=725, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x==715 && D2.y==416)
          {
             D4.x=725, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D3.x==720 && D3.y==416)
          {
             D4.x=725, D4.y=400;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else
          {
             D4.x=725, D4.y=416;
             SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D4);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else
       {
        SDL_Rect D = {D4.x+20,D4.y+6, 0,0};
        SDL_RenderFillRect(renderer,&D4);
        EcrireTextDirect(renderer, "1", D,noir,10);//En dehors des 3 tours
       }
       // Affichage du deplacement
       sprintf(nbre, "%d", deplacement);
       p.x+=220;p.y-=2;
       EcrireTextDirect(renderer,nbre,p,noir,20);
       //Affichage du temps
      SDL_Rect posiTemps = {50,5,0,0};
      EcrireTextDirect(renderer, "Temps: ", posiTemps,noir,30);
      posiTemps.x+=100;
      EcrireTextDirect(renderer,h,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "h", posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer,min,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "min", posiTemps,noir,30);
      posiTemps.x+=80;
      EcrireTextDirect(renderer,sec,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "sec", posiTemps,noir,30);

       la:
       SDL_RenderPresent(renderer);

       if(D1.x==710 && D1.y==416 && D2.x==715 && D2.y==400 && D3.x==720 && D3.y==384 && D4.x==725 && D4.y==368)
       {
           Mix_PlayMusic(son,1);

           SDL_Texture *texture=NULL;
           SDL_Surface *surface=NULL;
           SDL_Rect d = {420,180,0,0};
           surface=IMG_Load("bravo.jpg");
           texture=SDL_CreateTextureFromSurface(renderer,surface);
           SDL_FreeSurface(surface);
           SDL_QueryTexture(texture,NULL,NULL,&d.w,&d.h);
           SDL_RenderCopy(renderer,texture,NULL,&d);
           SDL_RenderPresent(renderer);
           SDL_DestroyTexture(texture);
           SDL_Delay(5000);
           Mix_FreeMusic(son); //Libération du son
           Mix_FreeMusic(musique); //Libération de la musique

           SDL_Color jaune = {255,255,0,255};
           SDL_Event suite;
           int v = 1;
           while(v==1)
           {
               SDL_WaitEvent(&suite);
               if(suite.type == SDL_QUIT)
                  v=0;
               //Recuperaton et utilisation de l'état de la souris
               Uint32 bouton;
               int x, y;
               bouton=SDL_GetMouseState(&x, &y);

               SDL_Rect r = {200,50,0,0},  rr1 = {400,170,0,0},  rr2 = {400,220,0,0},  rr3 = {400,270,0,0};
               SDL_Rect r1 = {390,165,150,40}, r2 = {390,215,200,40}, r3 = {390,265,100,40};

               if(x>r1.x && x<r1.x+r1.w && y>r1.y && y<r1.y+r1.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r1);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                    goto rejouer;
               }
               else if(x>r2.x && x<r2.x+r2.w && y>r2.y && y<r2.y+r2.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r2);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                 {
                    jouer3(renderer);
                    v = 0;
                 }
               }
               else if(x>r3.x && x<r3.x+r3.w && y>r3.y && y<r3.y+r3.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r3);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                    v = 0;
               }
               SDL_Texture *txture = NULL;
               SDL_Surface *victoire = NULL;
               victoire = IMG_Load("040.jpg");
               txture = SDL_CreateTextureFromSurface(renderer, victoire);
               SDL_FreeSurface(victoire);
               SDL_RenderCopy(renderer,txture,NULL,NULL); // Affichage de l'image

               EcrireTextDirect(renderer, "Felicitation vous avez reuissi la partie", r,blanc,40);
               r.x += 200; r.y += 70;
               EcrireTextDirect(renderer, "Nombre de mouvement:  ", r,blanc,30);
               r.x += 350; r.y += 7;
               EcrireTextDirect(renderer,nbre,r,jaune,20);
               EcrireTextDirect(renderer, "Rejouer", rr1, blanc,25);
               EcrireTextDirect(renderer, "Niveau suivant", rr2,blanc,25);
               EcrireTextDirect(renderer, "Sortir", rr3,blanc,25);
               SDL_RenderPresent(renderer);
           }
           continuer=0;//break;
       }
       int x, y;
       Uint32 bouton;
       bouton=SDL_GetMouseState(&x, &y);
       if(x>855 && x<990 && y>10 && y<50)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               int v=1;
               SDL_Rect t = {50,20,0,0};
               SDL_SetRenderDrawColor(renderer,255,255,255,255);
               SDL_RenderClear(renderer);
               EcrireTextDirect(renderer, "  INSTRUCTION POUR LE DEPLACEMENT DES DISQUES", t,bleu,25);
               t.y+=70;
               EcrireTextDirect(renderer, "-> Tapez 1 puis bouger la souris pour deplacer le disque rouge", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 2 puis bouger la souris pour deplacer le disque bleu", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 3 puis bouger la souris pour deplacer le disque vert", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 4 puis bouger la souris pour deplacer le disque orange", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Vous gagnerai si les 4 disques se trouvent au niveau de la 3e tour", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez sur la touche Entrer si vous finissez de lire", t,noir,25);
               SDL_RenderPresent(renderer);
               while(v==1)
               {
                   SDL_Event e;
                   SDL_WaitEvent(&e);
                   if(e.type == SDL_QUIT)
                      v=0;
                   if(e.key.keysym.sym == SDLK_RETURN)
                      v=0;
               }
           }
       }
       else if(x>855 && x<990 && y>60 && y<100)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               //Les 3 rectangles pour la sugestion de recommencer
               SDL_Rect d1 = {200,150,500,200}, d2 = {250,250,75,50}, d3 = {350,250,75,50};
               SDL_Rect t1 = {250,180,0,0}, t2 = {255,255,0,0};
               SDL_SetRenderDrawColor(renderer,250,250,0,255);
               SDL_RenderFillRect(renderer,&d1);
               SDL_SetRenderDrawColor(renderer,0,250,250,255);
               SDL_RenderFillRect(renderer,&d2);
               SDL_RenderFillRect(renderer,&d3);
               SDL_SetRenderDrawColor(renderer,0,0,0,255);
               EcrireTextDirect(renderer, "Etes-vous sure de recommencer ?", t1, noir,25);
               EcrireTextDirect(renderer, "Oui", t2,noir,25);
               t2.x+=100;
               EcrireTextDirect(renderer, "Non", t2,noir,25);
               SDL_RenderPresent(renderer);

               int c=1;
               SDL_Event e;
               while(c == 1)
               {
                   SDL_WaitEvent(&e);
                   //Recuperaton et utilisation de l'état de la souris
                   Uint32 bouton;
                   int x, y;
                   bouton=SDL_GetMouseState(&x, &y);
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
               rejouer:
               //Rectangle des 3 tours reinitialiser
               T1.x=240; T1.y=200; T1.w=20; T1.h=232;
               T2.x=490; T2.y=200; T2.w=20; T2.h=232;
               T3.x=740; T3.y=200; T3.w=20; T3.h=232;
               //Rectangle des 3 disques reinitialiser
                D1.x=210; D1.y=416; D1.w=80; D1.h=16;
                D2.x=215; D2.y=400; D2.w=70; D2.h=16;
                D3.x=220; D3.y=384; D3.w=60; D3.h=16;
                D4.x=225; D4.y=368; D4.w=50; D4.h=16;
               //Couleur
               SDL_Color blanc = {255,255,255,255}, noir = {0,0,0,255};

               text.x=860; text.y=20; text.w=200; text.h=40;
               r.x=855; r.y=10; r.w=135; r.h=40;
               t.x=250; t.y=470; t.w=0; t.h=0;
               p.x=320; p.y=475; p.w=30; p.h=22;
               goto debut;
           }
       }
       else if(x>855 && x<990 && y>110 && y<150)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               int v=1;
               SDL_Rect d = {300,0,400,450};
               SDL_Surface *s=NULL;
               SDL_Texture *t=NULL;
               SDL_SetRenderDrawColor(renderer,255,255,255,255);
               SDL_RenderClear(renderer);
               s=IMG_Load("solution4.jpg");
               t=SDL_CreateTextureFromSurface(renderer,s);
               SDL_FreeSurface(s);
               //SDL_QueryTexture(t,NULL,NULL,&d.w,&d.h);
               SDL_RenderCopy(renderer,t,NULL,&d);
               SDL_DestroyTexture(t);
               SDL_RenderPresent(renderer);
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
       else if(x>855 && x<990 && y>160 && y<200)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               //Les 3 rectangles pour la sugestion de recommencer
               SDL_Rect d1 = {200,150,500,200}, d2 = {250,250,75,50}, d3 = {350,250,75,50};
               SDL_Rect t1 = {250,180,0,0}, t2 = {255,255,0,0};
               SDL_SetRenderDrawColor(renderer,250,250,0,255);
               SDL_RenderFillRect(renderer,&d1);
               SDL_SetRenderDrawColor(renderer,0,250,250,255);
               SDL_RenderFillRect(renderer,&d2);
               SDL_RenderFillRect(renderer,&d3);
               SDL_SetRenderDrawColor(renderer,0,0,0,255);
               EcrireTextDirect(renderer, "Etes-vous sure de Sortir ?", t1, noir,25);
               EcrireTextDirect(renderer, "Oui", t2,noir,25);
               t2.x+=100;
               EcrireTextDirect(renderer, "Non", t2,noir,25);
               SDL_RenderPresent(renderer);

               int c=1;
               SDL_Event e;
               while(c == 1)
               {
                   SDL_WaitEvent(&e);
                   //Recuperaton et utilisation de l'état de la souris
                   Uint32 bouton;
                   int x, y;
                   bouton=SDL_GetMouseState(&x, &y);
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
               continuer=0;break;
           }
       }
  }
}

//Fonction de niveau 1
void jouer(SDL_Renderer* renderer)
{
  //Rectangle des 3 tours
  SDL_Rect T1 = {240,200,20,232}, T2 = {490,200,20,232}, T3 = {740,200,20,232};
  //Rectangle des 3 disques
  SDL_Rect D1 = {210,416, 80,16}, D2 = {215,400,70,16}, D3 = {220,384,60,16};
  //Couleur
  SDL_Color blanc = {255,255,255,255}, noir = {0,0,0,255}, bleu = {0,0,255,255};

  Mix_Music *musique,*son;
  musique = Mix_LoadMUS("You Raise Me Up.mp3");
  son = Mix_LoadMUS("APPLAUDISSEMENTS_-_Bruitage_Gratuit(256k).mp3");
  //Jouer la musique
  Mix_PlayMusic(musique,-1);

  char nbre[4];
  int continuer=1, deplacement=0;
  SDL_Event event;

   while(continuer)
   {
        //Gestion du temps
        int heures, minutes, secondes;
        Uint32 temps;
        temps = SDL_GetTicks();
        heures = ((temps/1000)/3600)%24;
        minutes = ((temps/1000)/60)%60;
        secondes= (temps/1000)%60;
        //Conversion du temps en char
        char h[3], min[3], sec[3] ;
        sprintf(h, "%d", heures);
        sprintf(min, "%d", minutes);
        sprintf(sec, "%d", secondes);

        //Rectangle des ecritures
        SDL_Rect text = {860,20,200,40}, r = {855,10,135,40}, t = {100,470,0,0}, p = {170,475,30,22};

        debut:
        SDL_PollEvent(&event);

        //Bouger le disque rouge (le plus petit)
        if(event.key.keysym.sym == SDLK_1)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                  if(Deja(D2, D3, x, y) == 1 && Deja(D1, D3, x, y) == 1 && ok(D1, D2) == 1)
                  {
                     D3.x = x;
                     D3.y = y;
                  }
               }
           }
        }
        //Bouger le disque vert (le moyen)
        else if(event.key.keysym.sym == SDLK_2)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                  if(D3.x != D2.x+5 && D3.y != D2.y-16)
                  {
                     if(Deja(D1, D2, x, y) == 1 && Deja(D3, D2, x, y) == 1 && ok(D1, D3) == 1)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                  }
                  else if(D3.y == D2.y-16)
                  {
                     if(D3.x != D2.x+5)
                     {
                        D2.x = x;
                        D2.y = y;
                     }
                  }
               }
            }
        }
        //Bouger le disque bleu (le plus grand)
        else if(event.key.keysym.sym == SDLK_3)
        {
            SDL_Event e;
            SDL_WaitEvent(&e);
            if (e.type == SDL_MOUSEMOTION)
            {
               int x = e.motion.x,  y = e.motion.y;
               if(x>150 && x<800 && y>100 && y<250)
               {
                 if(D2.x != D1.x+5 && D2.y != D1.y-16 && D3.x != D1.x+10 && D3.y != D1.y-16)
                 {
                    if(Deja(D2, D1, x, y) == 1 && Deja(D3, D1, x, y) == 1 && ok(D2, D3) == 1)
                    {
                       D1.x = x;
                       D1.y = y;
                    }
                 }
                 else if(D3.y == D1.y-16 && D2.y != D1.y-16)
                 {
                     if(D3.x != D1.x+10)
                     {
                        D1.x = x;
                        D1.y = y;
                     }
               }
            }
          }
        }

       SDL_SetRenderDrawColor(renderer,255,255,255,255);
       SDL_RenderClear(renderer);
       //Tracer la ligne de separation en noir
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawLine(renderer,850,0,850,500);
       //Construire les 3 tours en violet
       SDL_SetRenderDrawColor(renderer,150,100,155,255);
       SDL_RenderFillRect(renderer,&T1);
       SDL_RenderFillRect(renderer,&T2);
       SDL_RenderFillRect(renderer,&T3);
       //Ecrire le text du bas
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Disque", t,noir,20);
       SDL_RenderDrawRect(renderer,&p);
       p.x+=5, p.y+=1;
       EcrireTextDirect(renderer, "3", p,noir,20);
       t.x+=150;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Deplacements Min:", t,noir,20);
       p.x+=260;p.y-=5;
       EcrireTextDirect(renderer, "7", p,noir,20);
       t.x+=250;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       EcrireTextDirect(renderer, "Deplacements:", t,noir,20);

       //💙️💙️💙️💙️💙️💙️💙️💙️ pour 1er disque 💙️💙️💙️ 💙️💙️💙️

       SDL_SetRenderDrawColor(renderer,0,0,250,255);

       if(D1.x>180 && D1.x<250 && D1.y>118 && D1.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D2.x==215 && D2.y==416 && D3.x==220 && D3.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x==215 && D2.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D3.x==220 && D3.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else
          {
             D1.x=210 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
       }
       else if(D1.x>430 && D1.x<500 && D1.y>118 && D1.y<184)
       {
          //on est sur la 2e tour✅️
          if(D2.x==465 && D2.y==416 && D3.x==470 && D3.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x==465 && D2.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D3.x==470 && D3.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else
          {
             D1.x=460 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
       }
       else if(D1.x>680 && D1.x<750 && D1.y>118 && D1.y<184)
       {
          //on est sur la 3e tour✅️
          if(D2.x==715 && D2.y==416 && D3.x==720 && D3.y==400)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D2.x==715 && D2.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else if(D3.x==720 && D3.y==416)
          {
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
          }
          else
          {
             D1.x=710 , D1.y=416;
             SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D1);
             EcrireTextDirect(renderer, "3", D,noir,10);
             deplacement++;
          }
       }
       else
       {
          SDL_Rect D = {D1.x+35,D1.y+6, 0,0};
          SDL_RenderFillRect(renderer,&D1); //En dehors des 3 tours
          EcrireTextDirect(renderer, "3", D,noir,10);
       }


       //💚️💚️💚️💚️💚️💚️💚️💚️💚️ Pour le 2e disque 💚️💚️💚️💚️💚️💚️💚️💚️💚️

       SDL_SetRenderDrawColor(renderer,0,250,0,255);

       if(D2.x>198 && D2.x<250 && D2.y>118 && D2.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x==210 && D1.y==416 && D3.x==220 && D3.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x==210 && D1.y==416)
          {
             D2.x=215 , D2.y=400;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x==220 && D3.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else
          {
             D2.x=215 , D2.y=416;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
     }
       else if(D2.x>448 && D2.x<500 && D2.y>118 && D2.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x==460 && D1.y==416 && D3.x==470 && D3.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x==460 && D1.y==416)
          {
             D2.x=465 , D2.y=400;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x==470 && D3.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else
          {
             D2.x=465 , D2.y=416;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
       }
       else if(D2.x>698 && D2.x<750 && D2.y>118 && D2.y<184)
       {
          //on est sur la 3e tour✅️
          if(D1.x==710 && D1.y==416 && D3.x==720 && D3.y==400)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else if(D1.x==710 && D1.y==416)
          {
             D2.x=715 , D2.y=400;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
          else if(D3.x==720 && D3.y==416)
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
          }
          else
          {
             D2.x=715 , D2.y=416;
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
             deplacement++;
          }
       }
       else
          {
             SDL_Rect D = {D2.x+30,D2.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D2);
             EcrireTextDirect(renderer, "2", D,noir,10);
          };//En dehors des 3 tours

       //❤️❤️❤️❤️❤️❤️❤️ Pour le 3e disque ❤️❤️❤️❤️❤️❤️❤️❤️❤️

       SDL_SetRenderDrawColor(renderer,250,0,0,255);

       if(D3.x>226 && D3.x<250 && D3.y>118 && D3.y<184)
       {
          //on est sur la 1ère tour✅️
          if(D1.x == 210 && D1.y == 416 && D2.x == 215 && D2.y == 400)
          {
             D3.x = 220, D3.y = 384;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x == 210 && D1.y == 416)
          {
             D3.x=220, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x == 215 && D2.y == 416)
          {
             D3.x=220, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=220, D3.y=416;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else if(D3.x>466 && D3.x<500 && D3.y>118 && D3.y<184)
       {
          //on est sur la 2e tour✅️
          if(D1.x == 460 && D1.y == 416 && D2.x == 465 && D2.y == 400)
          {
             D3.x = 470, D3.y = 384;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x==460 && D1.y==416)
          {
             D3.x=470, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x==465 && D2.y==416)
          {
             D3.x=470, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=470, D3.y=416;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else if(D3.x>716 && D3.x<750 && D3.y>118 && D3.y<184)
       {
          //on est sur la 3e tour✅️
          if(D1.x == 710 && D1.y == 416 && D2.x == 715 && D2.y == 400)
          {
             D3.x = 720, D3.y = 384;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D1.x==710 && D1.y==416)
          {
             D3.x=720, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else if(D2.x==715 && D2.y==416)
          {
             D3.x=720, D3.y=400;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
          else
          {
             D3.x=720, D3.y=416;
             SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
             SDL_RenderFillRect(renderer,&D3);
             EcrireTextDirect(renderer, "1", D,noir,10);
             deplacement++;
          }
       }
       else
       {
        SDL_Rect D = {D3.x+25,D3.y+6, 0,0};
        SDL_RenderFillRect(renderer,&D3);
        EcrireTextDirect(renderer, "1", D,noir,10);;//En dehors des 3 tours
       }
       // Affichage du deplacement
       sprintf(nbre, "%d", deplacement);
       p.x+=220;p.y-=2;
       EcrireTextDirect(renderer,nbre,p,noir,20);
      //Affichage du temps
      SDL_Rect posiTemps = {50,5,0,0};
      EcrireTextDirect(renderer, "Temps: ", posiTemps,noir,30);
      posiTemps.x+=100;
      EcrireTextDirect(renderer,h,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "h", posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer,min,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "min", posiTemps,noir,30);
      posiTemps.x+=80;
      EcrireTextDirect(renderer,sec,posiTemps,noir,30);
      posiTemps.x+=50;
      EcrireTextDirect(renderer, "sec", posiTemps,noir,30);

      //Ecrire le text
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Instrutions", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Recommencer", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Solution", text,noir,20);
       text.y+=50; r.y+=50;
       SDL_SetRenderDrawColor(renderer,0,0,0,255);
       SDL_RenderDrawRect(renderer,&r);
       EcrireTextDirect(renderer, "Sortir", text,noir,20);

       la:
       SDL_RenderPresent(renderer);

       if(D1.x==710 && D1.y==416 && D2.x==715 && D2.y==400 && D3.x==720 && D3.y==384)
       {
           Mix_PlayMusic(son, 1);

           SDL_Texture *texture=NULL;
           SDL_Surface *surface=NULL;
           SDL_Rect d = {420,180,0,0};
           surface=IMG_Load("bravo.jpg");
           texture=SDL_CreateTextureFromSurface(renderer,surface);
           SDL_FreeSurface(surface);
           SDL_QueryTexture(texture,NULL,NULL,&d.w,&d.h);
           SDL_RenderCopy(renderer,texture,NULL,&d);
           SDL_RenderPresent(renderer);
           SDL_DestroyTexture(texture);
           SDL_Delay(5000);
           Mix_FreeMusic(son); //Libération de la musique
           Mix_FreeMusic(musique); //Libération de la musique
           temps = 0;
           SDL_Event suite;
           int v = 1;
           while(v==1)
           {
               SDL_WaitEvent(&suite);
               if(suite.type == SDL_QUIT)
                  v=0;
               //Recuperaton et utilisation de l'état de la souris
               Uint32 bouton;
               int x, y;
               bouton=SDL_GetMouseState(&x, &y);

               SDL_Rect r = {200,50,0,0},  rr1 = {400,170,0,0},  rr2 = {400,220,0,0},  rr3 = {400,270,0,0};
               SDL_Rect r1 = {390,165,150,40}, r2 = {390,215,200,40}, r3 = {390,265,100,40};

               if(x>r1.x && x<r1.x+r1.w && y>r1.y && y<r1.y+r1.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r1);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                    goto rejouer;
               }
               else if(x>r2.x && x<r2.x+r2.w && y>r2.y && y<r2.y+r2.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r2);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                 {
                    jouer2(renderer);
                    v = 0;
                 }
               }
               else if(x>r3.x && x<r3.x+r3.w && y>r3.y && y<r3.y+r3.h)
               {
                 //Affichage de rectangle de limite
                 SDL_SetRenderDrawColor(renderer,250,250,250,250);
                 SDL_RenderDrawRect(renderer,&r3);
                 SDL_RenderPresent(renderer);
                 if(bouton && SDL_BUTTON(SDL_BUTTON_LEFT))
                    v = 0;
               }
               SDL_Texture *txture = NULL;
               SDL_Surface *victoire = NULL;
               victoire = IMG_Load("3d_33.jpg");
               txture = SDL_CreateTextureFromSurface(renderer, victoire);
               SDL_FreeSurface(victoire);
               SDL_RenderCopy(renderer,txture,NULL,NULL); // Affichage de l'image

               EcrireTextDirect(renderer, "Felicitation vous avez reuissi la partie", r,bleu,40);
               r.x += 200; r.y += 70;
               EcrireTextDirect(renderer, "Nombre de mouvement:  ", r,bleu,30);
               r.x += 350; r.y += 7;
               EcrireTextDirect(renderer,nbre,r,blanc,20);
               EcrireTextDirect(renderer, "Rejouer", rr1, bleu,25);
               EcrireTextDirect(renderer, "Niveau suivant", rr2,bleu,25);
               EcrireTextDirect(renderer, "Sortir", rr3,bleu,25);
               SDL_RenderPresent(renderer);
           }
           continuer=0;//break;
       }
       int x, y;
       Uint32 bouton;
       bouton=SDL_GetMouseState(&x, &y);
       if(x>855 && x<990 && y>10 && y<50)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               int v=1;
               SDL_Rect t = {50,20,0,0};
               SDL_SetRenderDrawColor(renderer,255,255,255,255);
               SDL_RenderClear(renderer);
               EcrireTextDirect(renderer, "  INSTRUCTION POUR LE DEPLACEMENT DES DISQUES", t,bleu,25);
               t.y+=70;
               EcrireTextDirect(renderer, "-> Tapez 1 puis bouger la souris pour deplacer le disque rouge", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 2 puis bouger la souris pour deplacer le disque vert", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez 3 puis bouger la souris pour deplacer le disque bleu", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Vous gagnerai si les 3 disques se trouvent au niveau de la 3e tour", t,noir,25);
               t.y+=35;
               EcrireTextDirect(renderer, "-> Tapez sur la touche Entrer si vous finissez de lire", t,noir,25);
               SDL_RenderPresent(renderer);
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
       else if(x>855 && x<990 && y>60 && y<100)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               //Les 3 rectangles pour la sugestion de recommencer
               SDL_Rect d1 = {200,150,500,200}, d2 = {250,250,75,50}, d3 = {350,250,75,50};
               SDL_Rect t1 = {250,180,0,0}, t2 = {255,255,0,0};
               SDL_SetRenderDrawColor(renderer,250,250,0,255);
               SDL_RenderFillRect(renderer,&d1);
               SDL_SetRenderDrawColor(renderer,0,250,250,255);
               SDL_RenderFillRect(renderer,&d2);
               SDL_RenderFillRect(renderer,&d3);
               SDL_SetRenderDrawColor(renderer,0,0,0,255);
               EcrireTextDirect(renderer, "Etes-vous sure de recommencer ?", t1, noir,25);
               EcrireTextDirect(renderer, "Oui", t2,noir,25);
               t2.x+=100;
               EcrireTextDirect(renderer, "Non", t2,noir,25);
               SDL_RenderPresent(renderer);

               int c=1;
               SDL_Event e;
               while(c == 1)
               {
                   SDL_WaitEvent(&e);
                   //Recuperaton et utilisation de l'état de la souris
                   Uint32 bouton;
                   int x, y;
                   bouton=SDL_GetMouseState(&x, &y);
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
               rejouer:
               //Rectangle des 3 tours reinitialiser
               T1.x=240; T1.y=200; T1.w=20; T1.h=232;
               T2.x=490; T2.y=200; T2.w=20; T2.h=232;
               T3.x=740; T3.y=200; T3.w=20; T3.h=232;
               //Rectangle des 3 disques reinitialiser
                D1.x=210; D1.y=416; D1.w=80; D1.h=16;
                D2.x=215; D2.y=400; D2.w=70; D2.h=16;
                D3.x=220; D3.y=384; D3.w=60; D3.h=16;
               //Couleur
               SDL_Color blanc = {255,255,255,255}, noir = {0,0,0,255};

               text.x=860; text.y=20; text.w=200; text.h=40;
               r.x=855; r.y=10; r.w=135; r.h=40;
               t.x=250; t.y=470; t.w=0; t.h=0;
               p.x=320; p.y=475; p.w=30; p.h=22;
               goto debut;
           }
       }
       else if(x>855 && x<990 && y>110 && y<150)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               int v=1;
               SDL_Rect d = {300,0,400,450};
               SDL_Surface *s=NULL;
               SDL_Texture *t=NULL;
               SDL_SetRenderDrawColor(renderer,255,255,255,255);
               SDL_RenderClear(renderer);
               s=IMG_Load("final_5f3160cf682c72.43366420.png");
               t=SDL_CreateTextureFromSurface(renderer,s);
               SDL_FreeSurface(s);
               //SDL_QueryTexture(t,NULL,NULL,&d.w,&d.h);
               SDL_RenderCopy(renderer,t,NULL,&d);
               SDL_DestroyTexture(t);
               SDL_RenderPresent(renderer);
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
       else if(x>855 && x<990 && y>160 && y<200)
       {
           if(bouton & SDL_BUTTON(SDL_BUTTON_LEFT))
           {
               //Les 3 rectangles pour la sugestion de recommencer
               SDL_Rect d1 = {200,150,500,200}, d2 = {250,250,75,50}, d3 = {350,250,75,50};
               SDL_Rect t1 = {250,180,0,0}, t2 = {255,255,0,0};
               SDL_SetRenderDrawColor(renderer,250,250,0,255);
               SDL_RenderFillRect(renderer,&d1);
               SDL_SetRenderDrawColor(renderer,0,250,250,255);
               SDL_RenderFillRect(renderer,&d2);
               SDL_RenderFillRect(renderer,&d3);
               SDL_SetRenderDrawColor(renderer,0,0,0,255);
               EcrireTextDirect(renderer, "Etes-vous sure de Sortir ?", t1, noir,25);
               EcrireTextDirect(renderer, "Oui", t2,noir,25);
               t2.x+=100;
               EcrireTextDirect(renderer, "Non", t2,noir,25);
               SDL_RenderPresent(renderer);

               int c=1;
               SDL_Event e;
               while(c == 1)
               {
                   SDL_WaitEvent(&e);
                   //Recuperaton et utilisation de l'état de la souris
                   Uint32 bouton;
                   int x, y;
                   bouton=SDL_GetMouseState(&x, &y);
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
               continuer=0;break;
           }
       }
  }
}
