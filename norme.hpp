// Fichier en tête
// implémentant les différentes normes utilisables sur les couleurs 
// définit le facteur d'attraction

#ifndef norme_hpp
#define norme_hpp

#include "defs.hpp"
#include <tuple>
#include <cmath>

std::tuple<int, int, int, int> substract_tuple_color(std::tuple<int, int, int, int> color1, std::tuple<int, int, int, int> color2);

float norm_on_color(std::tuple<int, int, int, int> color);

float distance_color(Particle particule1, Particle particule2);

std::vector<float> substract_tuple(std::vector<float> pos1, std::vector<float> pos2);

float norm(std::vector<float> pos);

float distance(Particle& particule1, Particle& particule2);

#endif // Fin de la directive #ifndef