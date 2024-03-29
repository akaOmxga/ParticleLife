// Fichier en-tête 
// de la fonction initialisation

#ifndef initialisation_hpp //éviter les superposition d'importation
#define initialisation_hpp //éviter les superposition d'importation

#include "defs.hpp"
#include <tuple>


// Fonction create_particle permettant de créer une particule selon une mode choisit :
// choix_create appartient {1,2} 
// 1 - création discrète parmi la liste des possibilités
// 2 - création random
Particle create_particle(const int choix_create);

// Fonction init permettant d'initialiser les particules
Univers init(const int nbr_particle,const int choix_creation);

#endif /* initialisation_hpp */ //éviter les superposition d'importation