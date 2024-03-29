// Fichier source
// de la fonction affichage
// cette dernière permet l'actualisation de la fenêtre d'affichage

#include "affichage.hpp"

void affiche_particule(Particle& particule, SDL_Renderer* renderer)
{
    SDL_Rect particule_rectangle = particule.get_rectangle();
    std::tuple<int, int, int, int> particule_color = particule.get_color();
    SDL_SetRenderDrawColor(renderer, std::get<0>(particule_color), std::get<1>(particule_color), std::get<2>(particule_color), std::get<3>(particule_color));
    SDL_RenderFillRect(renderer, &particule_rectangle);
    SDL_RenderPresent(renderer);
}

void display(Univers &univers, SDL_Renderer* renderer)
{
    size_t n;
    n = univers.size_univers();
    cout << " display " << endl;
    cout << endl;
    for (int i = 0; i<n; i++)
        {
            Particle& particule_i = univers.get_particle(i);
            affiche_particule(particule_i, renderer);
        }
};