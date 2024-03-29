#include <iostream>
#include <SDL2/SDL.h>
#include <iostream>
using namespace std;

/* 
pour run le code : dans le terminal écrire 
le texte présent dans le Makefile :) 
puis lancer le .exe
*/

/* 
ou encore, pour run : 
g++ -I source/include -L source/lib -o test test.cpp -lmingw32 -lSDL2main -lSDL2

dans le terminal
*/

/* 
les coordonnées en SDL2 sont de la formes x vers la droite et y vers le bas 
avec (0,0) en haut à gauche
*/

const int WIDTH = 800, HEIGHT = 600;

int main( int argc, char *argv[])
{   /* initialisation - création de la fenêtre - vérification de la création de la fenêtre */
    SDL_Init( SDL_INIT_EVERYTHING ); 
    SDL_Window *window = SDL_CreateWindow( "Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (NULL == window)
    {
        std::cout << "Could not create window" << SDL_GetError() << std::endl;
        return(1);
    }

   // Création du renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Erreur lors de la création du renderer : %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Effacer l'écran en blanc
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    cout << "l'écran est sensé être blanc pr les 5 prochaines secondes";
    SDL_Delay(5000);

    // Afficher un rectangle rouge
    // Coordonnées initiales du rectangle rouge
    int rectX = 100;
    int rectY = 100;
    SDL_Rect rect = {rectX, rectY, 3, 3};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

     // Mettre à jour l'écran
    SDL_RenderPresent(renderer);

    // Boucle while afin d'update la position des rectangles :
    // Variables pour suivre le temps écoulé
    Uint32 startTime = SDL_GetTicks(); // Temps de départ en millisecondes
    while (SDL_GetTicks() - startTime < 10000) 
        { 
        // Effacer l'écran en noir
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        // Mettre à jour les coordonnées du rectangle
        rectX += 1; // Déplacer le rectangle vers la droite
        rectY += 1; // Déplacer le rectangle vers le bas

        // Afficher le rectangle rouge
        SDL_Rect rect = {rectX, rectY, 3, 3};
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderFillRect(renderer, &rect);
        // Mettre à jour l'écran + taux de raffraichissement en millisecondes ~~~ 150ms de Delay => environ 60fps
        SDL_RenderPresent(renderer);
        SDL_Delay(10);
        }   
    // Attendre quelques secondes avant de fermer la fenêtre
    SDL_Delay(5000);

    /* libère la mémoire associée à la fenêtre window - ferme la bibiliothèque SDL*/
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow (window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

