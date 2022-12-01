// Travail de Fernand Ouedraogo et Farida Savadogo pour le compte du projet

// Dernière modification: 20 Octobre 2022

// 🌍️🌍️ Les fonction du tour de Hannoï 🇧🇫️

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/*void ViderBuffer(void)
{
   long c;
   while(c!='\n' && c!=EOF) c=getchar();
}*/

//🌍️🌍️ Fonction pour ecrire du text 🌍️🌍️
void EcrireText(
   SDL_Renderer *renderer, const char text[], SDL_Rect dist,
   SDL_Color color, int TaillePolice
)
{
   TTF_Init(); // Charger SDL_ttf
   SDL_Texture *tmp = NULL;
   SDL_Surface *s = NULL;
   TTF_Font *font = NULL;
   
   // Charger la police
   font = TTF_OpenFont("KGDefyingGravity.ttf", TaillePolice); 
   // faire une surface avec le font et le text
   s = TTF_RenderText_Blended(font,text,color);
                  
   tmp = SDL_CreateTextureFromSurface(renderer,s);

   SDL_QueryTexture(tmp, NULL, NULL, &dist.w, &dist.h);
   SDL_FreeSurface(s); //On a plus besoin de la surface
   TTF_CloseFont(font); // On a plus besoin de la police
   SDL_RenderCopy(renderer, tmp, NULL, &dist);
   SDL_DestroyTexture(tmp); //On a plus besoin de la texture
   TTF_Quit(); // Fermer SDL_ttf
}

//🌍️🌍️ Ecrire du text directement 
void EcrireTextDirect(
   SDL_Renderer *renderer, const char text[], SDL_Rect dist,
   SDL_Color color, int TaillePolice)
{
   /* la seule difference avec la fonction précédente est 
   qu'elle prend un constente char */

   TTF_Init();
   SDL_Texture *tmp = NULL;
   SDL_Surface *s = NULL;
   TTF_Font *font = NULL;
   
   font = TTF_OpenFont("Philosopher-Bold.ttf",TaillePolice);
   s = TTF_RenderText_Blended(font,text,color);
                  
   tmp = SDL_CreateTextureFromSurface(renderer,s);
   SDL_QueryTexture(tmp,NULL,NULL,&dist.w,&dist.h);
   SDL_FreeSurface(s);
   TTF_CloseFont(font);
   SDL_RenderCopy(renderer,tmp,NULL,&dist);
   SDL_DestroyTexture(tmp);
   TTF_Quit();
}
//verifier si les trois rectangles ne se touchent pas
int NonInterRect(SDL_Rect *R1,SDL_Rect *R2,SDL_Rect *R3)
{
  if(SDL_HasIntersection(R1, R2) == SDL_TRUE)
    return 0;
  else if(SDL_HasIntersection(R1, R3) == SDL_TRUE)
    return 0;
  else if(SDL_HasIntersection(R2, R3) == SDL_TRUE)
    return 0;
  else
    return 1;
}
//verifier si R1 n'est pas deja où R2 veut se poser
int Deja(SDL_Rect R1,SDL_Rect R2,int x,int y)
{
   if(x+R2.w < R1.x || x > R1.x+R1.w || y+R2.h < R1.y || y > R1.y+R1.h)
       return 1;
   else
       return 0;
}
//Fonction empechant le mouvement de deux rectangles
int ok(SDL_Rect R1,SDL_Rect R2)
{
  if((R1.y==416 || R1.y==400) && (R2.y==416 || R2.y==400))
     return 1;
  else
     return 0;
}

//Fonction empechant le mouvement de deux rectangles
int ok2(SDL_Rect R1,SDL_Rect R2,SDL_Rect R3)
{
  if(
   (R1.y==416 || R1.y==400 || R1.y==384) && 
   (R2.y==416 || R2.y==400 || R2.y==384) && 
   (R3.y==416 || R3.y==400 || R3.y==384))
     return 1;
  else
     return 0;
}

//Fonction empechant le mouvement de deux rectangles
int ok3(SDL_Rect R1, SDL_Rect R2, SDL_Rect R3, SDL_Rect R4)
{
  if(
   (R1.y==416 || R1.y==400 || R1.y==384 || R1.y==368) && 
   (R2.y==416 || R2.y==400 || R2.y==384 || R2.y==368) && 
   (R3.y==416 || R3.y==400 || R3.y==384 || R3.y==368) && 
   (R4.y==416 || R4.y==400 || R4.y==384 || R4.y==368))
     return 1;
  else
     return 0;
}

/* Fonction empechant le mouvement de deux 
rectangles (quand chacun n'est pas a la bonne position)*/
int ok4(SDL_Rect R1, SDL_Rect R2, SDL_Rect R3, SDL_Rect R4, SDL_Rect R5)
{
  if(
   (R1.y==416 || R1.y==400 || R1.y==384 || R1.y==368 || R1.y==352) && 
   (R2.y==416 || R2.y==400 || R2.y==384 || R2.y==368 || R2.y==352) && 
   (R3.y==416 || R3.y==400 || R3.y==384 || R3.y==368 || R3.y==352) && 
   (R4.y==416 || R4.y==400 || R4.y==384 || R4.y==368 || R4.y==352) && 
   (R5.y==416 || R5.y==400 || R5.y==384 || R5.y==368 || R5.y==352))
     return 1;
  else
     return 0;
}
