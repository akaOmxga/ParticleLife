// Fichier source
// de l'initialisation

#include "initialisation.hpp"

Particle create_particle(const int choix_create)
    {   
        Particle new_particule;
        if(choix_create == 1) // version discrète parmi la liste des possibilités
            {   
                size_t random_indice = getRandomNumber(0, Standard_Model.size_univers() - 1);
                const Particle old_particule = Standard_Model.get_particle_const(random_indice);
                // création de la particule à renvoyer suivant les caractéristiques de celle tirée au sort
                const std::tuple<int, int, int, int> new_particle_color = old_particule.get_color();
                SDL_Rect new_particle_rectangle = {getRandomNumber(0, WIDTH),getRandomNumber(0, HEIGHT), rayon2, rayon2};
                std::vector<float> new_particle_speed = {static_cast<float>(getRandomNumber(0, v_max)), static_cast<float>(getRandomNumber (0, v_max))};  
                const float new_particle_mass = static_cast<float>(getRandomNumber(0, m_max)); 
                new_particule = Particle (new_particle_color, new_particle_rectangle, new_particle_speed, new_particle_mass);
            }
        else // version random
            {   
                const int rayon = getRandomNumber(0, r_max); 
                const std::tuple<int, int, int, int> particle_color = std::make_tuple(getRandomNumber(0, 255),getRandomNumber(0, 255),getRandomNumber(0, 255),getRandomNumber(0, 255));
                const SDL_Rect particle_rectangle = {getRandomNumber(0, WIDTH),getRandomNumber(0, HEIGHT), rayon, rayon};
                const std::vector<float> particle_speed = {static_cast<float>(getRandomNumber(0, v_max)), static_cast<float>(getRandomNumber (0, v_max))};      
                const float particle_mass = static_cast<float>(getRandomNumber(0, m_max));                                                   
                new_particule = Particle (particle_color, particle_rectangle, particle_speed, particle_mass);
            }
        return(new_particule);
    };

Univers init(const int nbr_particle,const int choix_create)
    {
        Univers resultat;
        for (int i=0;i<nbr_particle;i++)
            {
                Particle particule = create_particle(choix_create);
                resultat.add_particle(particule);
            }
        return(resultat);
    };