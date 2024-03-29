// Fichier source
// implémentant les différentes normes utilisables sur les couleurs 
// définit le facteur d'attraction


///////////////////////////////////////////////////////////////////NORM AND RANDOM SETTINGS///////////////////////////////////////////////////////////////////////////////////////

#include "norme.hpp"

//////////////////// NORME SUR LES COULEURS ////////////////////

std::tuple<int, int, int, int> substract_tuple_color(std::tuple<int, int, int, int> color1, std::tuple<int, int, int, int> color2)
{
    return(std::make_tuple(std::get<0>(color1)-std::get<0>(color2),
                           std::get<1>(color1)-std::get<1>(color2),
                           std::get<2>(color1)-std::get<2>(color2),
                           std::get<3>(color1)-std::get<3>(color2)
                          )
          );
};

float norm_on_color(std::tuple<int, int, int, int> color)
{
    int r, g, b, a;
    std::tie(r, g, b, a) = color;
    return(std::sqrt( std::pow(r,2) +  std::pow(g,2) + std::pow(b,2) + std::pow(a,2)  ));
};

float distance_color(Particle particule1, Particle particule2)
{
    std::tuple<int, int, int, int> color1 = particule1.get_color();
    std::tuple<int, int, int, int> color2 = particule2.get_color();
    return(norm_on_color(substract_tuple_color(color1,color2))/pow(128,2));
};


//////////////////// NORME SUR LES COORDONNEES SPATIALES ////////////////////

std::vector<float> substract_tuple(std::vector<float> pos1, std::vector<float> pos2)
{
    std::vector<float> soustraction = {pos1[0]-pos2[0],pos1[1]-pos2[1]};
    return soustraction;
};

float norm(std::vector<float> pos)
{
    float x = pos[0];
    float y = pos[1];
    return(std::sqrt( std::pow(x,2) +  std::pow(y,2) ));
};

float distance(Particle& particule1, Particle& particule2)
{
    std::vector<float> pos1 = particule1.get_coords();
    std::vector<float> pos2 = particule2.get_coords();
    float dist = norm(substract_tuple(pos1,pos2));
    return(dist);
};
