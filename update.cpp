// Fichier source 
// de la fonction  update
// cette dernière permet l'actualisation 
// de la position des différentes particules

#include "update.hpp"

/*
const std::vector<float>& update_borders(const std::vector<float>& coords) 
{
    float x = coords[0];
    float y = coords[1];

    // Vérification selon x
    if (x < 0) 
    {x = WIDTH-x;} 
    else if (x >= WIDTH) 
    {x = x - WIDTH;}

    // Vérification selon y
    if (y < 0) 
    {y = HEIGHT-y;} 
    else if (y >= HEIGHT) 
    {y = y - HEIGHT;}

    return {x, y};
}
*/ // OLD VERSION 

const std::vector<float>& update_borders(const std::vector<float>& coords) {
    static std::vector<float> updated_coords(2); // Déclaration d'une variable statique locale

    float x = coords[0];
    float y = coords[1];

    // Vérification selon x
    if (x < 0) 
    {x = WIDTH-x;} 
    else if (x >= WIDTH) 
    {x = x - WIDTH;}

    // Vérification selon y
    if (y < 0) 
    {y = HEIGHT-y;} 
    else if (y >= HEIGHT) 
    {y = y - HEIGHT;}

    updated_coords[0] = x; // Mise à jour des coordonnées dans la variable statique
    updated_coords[1] = y;

    return updated_coords; // Retourne une référence à la variable statique
}


void update_particle(Univers &univers, Particle& particule, const int choix_create)
{
    // Obtenir l'accélération de la particule
    std::vector<float> F = force(univers, particule, choix_create);
    std::vector<float> acc(2);
    acc[0] = F[0]/(particule.get_mass());
    acc[1] = F[1]/(particule.get_mass());
    

    // Double intégration pendant dt afin d'obtenir
    // La nouvelle vitesse de la particule :
    std::vector<float> v = particule.get_vel();

    /*
    float new_vel_x = static_cast<float>(pow((1/2),(dt/dvt))*v[0] + acc[0]*dt);
    float new_vel_y = static_cast<float>(pow((1/2),(dt/dvt))*v[1] + acc[1]*dt);
    const std::vector<float>& new_vel = {new_vel_x, new_vel_y}; // avec force
    */

    float new_vel_x = static_cast<float>(v[0] + acc[0]*dt);
    float new_vel_y = static_cast<float>(v[1] + acc[1]*dt);
    const std::vector<float>& new_vel = {new_vel_x, new_vel_y}; // avec force
    
    //const std::vector<float>& new_vel = {static_cast<float>(v[0]), static_cast<float>(v[1])}; // mouvement rect et unif indep

    // Les nouvelles coordonnées de la particule : 
    std::vector<float> coords = particule.get_coords();

    float new_coords_x = static_cast<float>(coords[0] + v[0]*dt);
    float new_coords_y = static_cast<float>(coords[1] + v[1]*dt);
    const std::vector<float>& new_coords = {new_coords_x, new_coords_y};

    // Actualisation de la vitesse :
    particule.replace_vel(new_vel);

    // Actualisation des coordonnées :    
    const std::vector<float>& final_coords = update_borders(new_coords);   // sans oublier d'appeler update_borders pour la symétrie de l'univers
    particule.replace_coords(final_coords);
};

void update(Univers &univers, const int choix_create)
{
    size_t n;
    n = univers.size_univers();
    cout << " update " << endl;
    cout << endl;
    for (int i = 1 ; i<n; i++) // mettre i = 0 
        {
            Particle& particule_i = univers.get_particle(i);
            update_particle(univers, particule_i, choix_create);
        }
};

