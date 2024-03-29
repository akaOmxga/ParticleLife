// Fichier en-tête 
// de la fonction affichage
// cette dernière permet l'actualisation de la fenêtre d'affichage

#ifndef affichage_hpp
#define affichage_hpp

#include "defs.hpp"

void affiche_particule(Particle& particule, SDL_Renderer* renderer);

void display(Univers &univers,  SDL_Renderer* renderer);

#endif // Fin de la directive #ifndef