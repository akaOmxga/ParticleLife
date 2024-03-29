// Fichier en tête
// implémentant le calcul de la force appliquée sur une particule

#ifndef force_hpp
#define force_hpp

#include "norme.hpp"

std::vector<float> unit_vector(Particle& particule, Particle& particule_i);

float module_force(Particle& particule, Particle& particule_i, const int choix_create);

std::vector<float> MultiplyVector(std::vector<float>& vect, float scalaire);

std::vector<float> addVectors(std::vector<float>& vect1,std::vector<float>& vect2);

std::vector<float> force(Univers &univers,Particle& particule, const int choix_create);

#endif // Fin de la directive #ifndef