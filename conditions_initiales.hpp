// Ce fichier en-tête permet de décrire des conditions initiales correctes permettant un mouvement :




////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////                                              ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////                   NE PAS                     ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////                  MODIFIER                    ///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////                                              ///////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////














#ifndef defs_hpp //éviter les superposition d'importationd
#define defs_hpp //éviter les superposition d'importation

#include "structs.hpp"
#include "random_generator.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>
using namespace std;


/////////////////////////////////////////////////////////////////////GENERAL SETTINGS////////////////////////////////////////////////////////////////////////////////////////////

//Taille de l'écran : 
const int WIDTH = 800 ;
const int HEIGHT = 600 ;

//Temps de simulation en millisecondes :
const int t_simu = 20000;

//Nombre de rectangle que l'ont veut generer :
const int nbr_particle = 100;

//Temps d'actualisation infinitésimale dt :
const float dt = 1.0f / 50.0f;


//Temps en sec de demi-vie pendant lequel une particule doit perdre 1/2 de sa vitesse 
const float dvt = 10;

//Choix du mode de création
//choix_create appartient {1,2} 
// 1 - création discrète parmi la liste des possibilités
// 2 - création random
const int choix_create = 2;
// choix_create 1 : fonctionne à l'initialisation, l'affichage mais l'update fait disparaitre les particules, la simulation se ferme correctement
// choix_create 2 : fonctionne à l'initialisation, l'affichage mais l'update fait disparaitre les particules, la simulation se ferme correctement

//Distance d'interaction maximale : DIMax
const int DIMax = 50;

//Distance d'interaction minimale : DIMin

const int DIMin = 5;

/////////////////////////////////////////////////////////////////////RANDOM CREATION SETTINGS ////////////////////////////////////////////////////////////////////////////////////////////

//vitesse maximale
const int v_max = 100 ;
// masse maximale
const int m_max = 20 ;
// rayon maximale
const int r_max = 10 ;

//////////////////////////////////////////////////////////////////////DISCRETE CREATION SETTINGS///////////////////////////////////////////////////////////////////////////////////////////


//Setting création discrète parmi la liste des possibilités 

//particule 1 
const int rayon1 = 2; 
const std::tuple<int, int, int, int> particle_color1 = std::make_tuple(255,0,0,255); //couleur rouge
const SDL_Rect particle_rectangle1 = {getRandomNumber(0, WIDTH),getRandomNumber(0, HEIGHT), rayon1, rayon1};
const std::vector<float> particle_speed1 = {static_cast<float>(getRandomNumber(0, v_max)), static_cast<float>(getRandomNumber (0, v_max))};  
const float particle_mass1 = 5;                                                   
const Particle particule1(particle_color1, particle_rectangle1, particle_speed1, particle_mass1);

//particule 2
const int rayon2 = 4; 
const std::tuple<int, int, int, int> particle_color2 = std::make_tuple(0,255,0,255); //couleur verte
const SDL_Rect particle_rectangle2 = {getRandomNumber(0, WIDTH),getRandomNumber(0, HEIGHT), rayon2, rayon2};
const std::vector<float> particle_speed2 = {static_cast<float>(getRandomNumber(0, v_max)), static_cast<float>(getRandomNumber (0, v_max))};  
const float particle_mass2 = 10;                                                   
const Particle particule2(particle_color2, particle_rectangle2, particle_speed2, particle_mass2);

//particule 3 
const int rayon3 = 8; 
const std::tuple<int, int, int, int> particle_color3 = std::make_tuple(0,0,255,255); //couleur bleu
const SDL_Rect particle_rectangle3 = {getRandomNumber(0, WIDTH),getRandomNumber(0, HEIGHT), rayon3, rayon3};
const std::vector<float> particle_speed3 = {static_cast<float>(getRandomNumber(0, v_max)), static_cast<float>(getRandomNumber (0, v_max))};  
const float particle_mass3 = 20;                                                   
const Particle particule3(particle_color3, particle_rectangle3, particle_speed3, particle_mass3);

//particule 4 
const int rayon4 = 6; 
const std::tuple<int, int, int, int> particle_color4 = std::make_tuple(255,255,0,255); //couleur jaune
const SDL_Rect particle_rectangle4 = {getRandomNumber(0, WIDTH),getRandomNumber( 0,  HEIGHT), rayon4, rayon4};
const std::vector<float> particle_speed4 = {static_cast<float>(getRandomNumber(0, v_max)), static_cast<float>(getRandomNumber (0, v_max))};  
const float particle_mass4 = 15;                                                   
const Particle particule4(particle_color4, particle_rectangle4, particle_speed4, particle_mass4);

//particule 5
const int rayon5 = 25; 
const std::tuple<int, int, int, int> particle_color5 = std::make_tuple(128,0,255,255); //couleur violet
const SDL_Rect particle_rectangle5 = {getRandomNumber(0, WIDTH),getRandomNumber( 0, HEIGHT), rayon5, rayon5};
const std::vector<float> particle_speed5 ={static_cast<float>(getRandomNumber(0, v_max)), static_cast<float>(getRandomNumber (0, v_max))};  
const float particle_mass5 = 5;                                                   
const Particle particule5(particle_color5, particle_rectangle5, particle_speed5, particle_mass5);

//photon
const int r_photon = 0; 
const std::tuple<int, int, int, int> photon_color = std::make_tuple(0,0,0,255); //couleur blanche
const SDL_Rect photon_rectangle = {getRandomNumber(0, WIDTH),getRandomNumber( 0, HEIGHT), r_photon, r_photon};
const std::vector<float> photon_speed = {static_cast<float>(v_max), static_cast<float>(v_max)};      
const float photon_mass = 0;                                                   
const Particle photon(photon_color, photon_rectangle, photon_speed, photon_mass);

//Création de l'objet univers contenant toutes les particules possibles : 
const Univers Standard_Model = Univers(particule1,particule2,particule3,particule4,particule5,photon);

//////////////////////////////////////////////////////////////////////ATTRACTION FACTOR DISCRETE SETTINGS///////////////////////////////////////////////////////////////////////////////////////////

// Matrice constitué d'élément Ai,j / Ai,j = coef_attraction(particule_i,particule_j) 
// matrice pas forcément symétrique ! et l'attraction appartenant à [0;1] dépend des couleurs 

const MatAttract Matrice_attraction = 
    {
        {0.2, 0.4, 0.6, 0.8, 1.0},
        {0.4, 0.6, 0.8, 1.0, 0.2},
        {0.6, 0.8, 1.0, 0.2, 0.4},
        {0.8, 1.0, 0.2, 0.4, 0.6},
        {1.0, 0.2, 0.4, 0.6, 0.8}
    };

// correspondant au couleur dans l'ordre {rouge, vert, bleu, jaune, violet}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif  // defs_hpp