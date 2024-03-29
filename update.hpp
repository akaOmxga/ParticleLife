// Fichier en-tête 
// de la fonction  update
// cette dernière permet l'actualisation 
// de la position des différentes particules

#ifndef update_hpp
#define update_hpp

#include "defs.hpp"
#include "force.hpp"

const std::vector<float>& update_borders(const std::vector<float>& coords);

void update_particle(Univers &univers, Particle& particule, const int choix_create);

void update(Univers &univers, const int choix_create);

#endif // Fin de la directive #ifndef