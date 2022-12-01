//Travail de Fernand Ouedraogo et Farida Savadogo pour le compte du projet

//Dernière modification: 16 septembre 2021

//🌍️🌍️ Les prototypes des fonction du tour de Hannoï 🇧🇫️

void EcrireText(SDL_Renderer *renderer,const char text[],SDL_Rect dist,SDL_Color color,int TaillePolice);

void EcrireTextDirect(SDL_Renderer *renderer,const char text[],SDL_Rect dist,SDL_Color color,int TaillePolice);

int NonInterRect(SDL_Rect *R1,SDL_Rect *R2,SDL_Rect *R3);

int Deja(SDL_Rect R1,SDL_Rect R2,int x,int y);

int ok(SDL_Rect R1,SDL_Rect R2);

int ok2(SDL_Rect R1,SDL_Rect R2,SDL_Rect R3);

int ok3(SDL_Rect R1,SDL_Rect R2,SDL_Rect R3,SDL_Rect R4);

int ok4(SDL_Rect R1,SDL_Rect R2,SDL_Rect R3,SDL_Rect R4,SDL_Rect R5);
