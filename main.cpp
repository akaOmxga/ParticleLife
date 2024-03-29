#include "main.hpp"


/* cf test.cpp pour une petite documentation basique en cas d'oublie */
/* pour run : g++ -I source/include -L source/lib -o main main.cpp initialisation.cpp random_generator.cpp -lmingw32 -lSDL2main -lSDL2 */

int main( int argc, char *argv[])
{   /* initialisation - création de la fenêtre - vérification de la création */
    SDL_Init( SDL_INIT_EVERYTHING ); 
    SDL_Window *window = SDL_CreateWindow( "Particle Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    if (NULL == window)
        {
        std::cout << "Could not create window" << SDL_GetError() << std::endl;
        return(1);
        }

   /* Création du renderer - vérification de la création */
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr)
        {
        SDL_Log("Erreur lors de la création du renderer : %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return(1);
        }

    // Effacer l'écran en noir
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    cout << " Starting Simulation in 5 sec " << endl;
    cout << endl;
    SDL_Delay(1000);
    cout << " 4 " << endl;
    SDL_Delay(1000);
    cout << endl;
    cout << " 3 " << endl;
    SDL_Delay(1000);
    cout << endl;
    cout << " 2 " << endl;
    SDL_Delay(1000);
    cout << endl;
    cout << " 1 " << endl;
    SDL_Delay(1000);
    cout << endl;
    SDL_Delay(1000);

    // Création des particules :
    Univers univers = init(nbr_particle, choix_create);
    cout << " Initialisation Done - Movement Starts in 3 sec " << endl;
    display(univers, renderer);
    cout << endl;
    SDL_Delay(3000);

    // Boucle while principale 
    // Variables pour suivre le temps écoulé
    Uint32 startTime = SDL_GetTicks(); // Temps de départ en millisecondes
    while (SDL_GetTicks() - startTime < t_simu) 
        { 

        // Update la position des particules :
        update(univers, choix_create);
        
        // Effacer l'écran en noir
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // Mettre à jour de l'affichage + taux de raffraichissement en millisecondes ~~~ 150ms de Delay => environ 60fps
        display(univers, renderer);
        SDL_Delay(10);

        }   
    cout << " Simulation Done - Shutting down - Thanks For Watching ! ";
    cout << endl;
    // Attendre quelques secondes avant de fermer la fenêtre
    SDL_Delay(5000);

    /* libère la mémoire associée à la fenêtre window - ferme la bibiliothèque SDL*/
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow (window);
    SDL_Quit();

    return EXIT_SUCCESS;
}

