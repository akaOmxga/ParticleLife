//Fichier en-tête 
//Contenant les structures de données 

#ifndef structs_hpp
#define structs_hpp

#include <SDL2/SDL.h>
#include <vector>
#include <tuple>
#include <iostream> //// a supp après les test

//Déclaration du type matrice pour la matrice de coefficient d'attraction :
typedef std::vector<std::vector<double>> MatAttract;

class Particle 
{
private:
    std::tuple<int, int, int, int> color; // (r, g, b, a)
    SDL_Rect rectangle; // rectangle contenant la position x,y et le rayon
    std::vector<float> velocity;  // (v_x, v_y)
    float mass; // float

public:

    // Constructeur par défaut
    Particle() {} 

    // Constructeur
    Particle(const std::tuple<int, int, int, int> col,
             const SDL_Rect rect,
             const std::vector<float> vel,
             const float m)
        : color(col), rectangle(rect), velocity(vel), mass(m) {}

    // Méthode pour accéder au rectangle d'une particule
    SDL_Rect get_rectangle() const
    {
        return rectangle;
    }

    // Méthode pour accéder à la couleur d'une particule
    std::tuple<int, int, int, int> get_color() const
    {
        return color;
    }

    // Méthode pour accéder au type de la couleur d'une particule 
    // les types sont les suivants :
    // rouge -> 0 / vert -> 1 / bleu -> 2 / jaune -> 3 / violet -> 4
    int get_color_type() const
    {
        if (color == std::make_tuple(255,0,0,255)) // rouge
            {return(0);}
        else if (color == std::make_tuple(0,255,0,255)) // vert
            {return(1);}
        else if (color == std::make_tuple(0,0,255,255)) // bleu
            {return(2);}
        else if (color == std::make_tuple(255,255,0,255)) // jaune
            {return(3);}
        else if (color == std::make_tuple(128,0,255,255)) // violet
            {return(4);}
        else 
            {return(-1);}
    }

    // Méthode pour accéder à la masse d'une particule
    float get_mass() const
    {
        return mass;
    }

    // Méthode pour accéder à la vitesse d'une particule
    std::vector<float> get_vel() const
    {
        return velocity;
    }

    // Méthode pour accéder à la vitesse d'une particule
    int get_radius() const
    {
        return rectangle.w ; // car w et h sont les mêmes par construction de la particule
    }

    // Méthode pour accéder au coordonnées (x,y) (tuple, associé au reectangle) d'une particule
    std::vector<float> get_coords() const
    {   
        std::vector<float> coords(2);
        coords[0] = rectangle.x;
        coords[1] = rectangle.y;
        return(coords);
    }

    // Méthode pour vérifier si la particule est un Photon
    bool isPhoton() const 
    {
        return mass == 0;
    }

    // Méthode pour remplacer la vitesse de la particule
    void replace_vel(const std::vector<float>& new_vel)
    {
        velocity = new_vel;
    }

    // Méthode pour remplacer les coordonnées de la particule
    void replace_coords(const std::vector<float>& new_coords)
    {
        SDL_Rect new_rect = {static_cast<int>(new_coords[0]),static_cast<int>(new_coords[1]),get_radius(),get_radius()};
        rectangle = new_rect;
    }

    // Méthode pour afficher la vitesse de la particule
    void affiche_vel()
    {
        float vx = velocity[0];
        float vy = velocity[1];
        std::cout << "[" << vx << ";" << vy << "]" << std::endl;
    }

    // Méthode pour afficher la vitesse de la particule
    void affiche_coords()
    {
        float coords_x = rectangle.x;
        float coords_y = rectangle.y;
        std::cout << "[" << coords_x << ";" << coords_y << "]" << std::endl;
    }

};

class Univers {
private:
    std::vector<Particle> particles;

public:

    // Constructeur par défaut
    Univers() {} 

    // Constructeur prenant des particules en argument et les ajoutant directement au tableau
    Univers(const Particle& firstParticle, ...) 
    {
        particles.push_back(firstParticle); // Ajoute la première particule au vecteur

        // Utilisation d'une liste d'arguments variables pour ajouter les autres particules
        va_list args;
        va_start(args, firstParticle);

        Particle particle = va_arg(args, Particle);
        while (!particle.isPhoton()) { // Vérifie si la particule n'est pas un photon
            particles.push_back(particle);
            particle = va_arg(args, Particle);
        }

        va_end(args);
    }

    // Méthode pour obtenir la taille du vecteur particles
    size_t size_univers() const 
    {
        return particles.size();
    }

    Particle& get_particle(size_t index)
    {
        return particles[index];
    }

    const Particle& get_particle_const(size_t index) const
    {
        return particles[index];
    }

    // Méthode pour ajouter une particule à l'univers
    void add_particle(Particle &particule) 
    {
        particles.push_back(particule);
    }

};


#endif // Fin de la directive #ifndef
