// Fichier source
// implémentant les différentes normes utilisables sur les couleurs 
// définit le facteur d'attraction

#include "force.hpp"

// Fonction permettant de multiplier un vector par un scalaire

std::vector<float> MultiplyVector(std::vector<float>& vect, float scalaire) 
{
    // Réservation de la mémoire pour optimiser les performances
    std::vector<float> result;
    result.reserve(vect.size()); 

    // Multiplier les éléments du vecteurs un à un par le scalaire
    for (size_t i = 0; i < vect.size(); ++i) 
    {
        result.push_back(scalaire * vect[i]);
    }
    return result;
}

// Fonction permettant d'additionner deux vecteurs force

std::vector<float> addVectors(std::vector<float>& vect1, std::vector<float>& vect2) 
{
    // Vérifier que les deux vecteurs ont la même taille
    if (vect1.size() != vect2.size()) 
    {
        throw std::invalid_argument("Les vecteurs doivent avoir la même taille pour être additionnés.");
    }

    // Réservation de la mémoire pour optimiser les performances=
    std::vector<float> result;
    result.reserve(vect1.size()); 

    // Addition des éléments correspondants des deux vecteurs
    for (size_t i = 0; i < vect1.size(); ++i) 
    {
        result.push_back(vect1[i] + vect2[i]);
    }
    return result;
}

// Fonction permettant de donner le vecteur unitaire partant de particule vers particule_i (Ur)

std::vector<float> unit_vector(Particle& particule, Particle& particule_i)
{
    std::vector<float> unit(2);
    std::vector<float> coords = particule.get_coords();
    std::vector<float> coords_i = particule_i.get_coords();
    
    // Calcul du vecteur particule->particule_i
    unit[0] = coords_i[0] - coords[0]; 
    unit[1] = coords_i[1] - coords[1]; 
    // Normalisation
    return(MultiplyVector(unit,1/norm(unit)));
};

// Fonction permettant de donner le module de la force subit par particule et engendrée par particule_i

float module_force(Particle& particule, Particle& particule_i, const int choix_create)
{
    float attraction_factor; 
    float module;

    // Calcul du coefficient d'attraction
    if (choix_create == 1) // Cas discret
        { 
            // on détermine la couleur des particules et on renvoie l'élément de la matrice associée
            int couleur_particule = particule.get_color_type();
            int couleur_particule_i = particule_i.get_color_type();
            attraction_factor = Matrice_attraction[couleur_particule][couleur_particule_i];
        }
    else // Cas random
        {attraction_factor = distance_color(particule, particule_i);}

    // Calcul du module de la force
    float r = distance(particule, particule_i);
    if (r<DIMin)
        { module = (r/DIMin) - 1; }
    else if (r>DIMax)
        { module = 0; }
    else 
        { module = attraction_factor*particule.get_mass()*particule_i.get_mass()/pow(r,2); }
    return(module);
};

// Fonction permettant de calculer la force appliquée par l'univers à la particule 

std::vector<float> force(Univers &univers,Particle& particule, const int choix_create)
{
    std::vector<float> force_particle(2); 
    force_particle[0] = 0; 
    force_particle[1] = 0;
    // Dans un premier temps on isole toutes les particules interagissant avec celle dont on calcule la force 
    for (int i = 0; i<univers.size_univers();i++)
        {   
            Particle& particule_i = univers.get_particle(i);
            if (distance(particule, particule_i) < DIMax)
                {
                    // Puis on somme les forces engendrées par toutes ces particules interagissantes pour obtenir la force totale
                    // La force se décompose en : son module F (algébrique) et sa direction u (vecteur unitaire) ;
                    std::vector<float> unitaire_i = unit_vector(particule, particule_i); // Ur
                    float module_i = module_force(particule, particule_i, choix_create); // F
                    std::vector<float> force_i = MultiplyVector(unitaire_i, module_i); // F.Ur
                    force_particle = addVectors(force_i, force_particle); // Ftot = Ftot + F
                }
        }
    // TEST
    std::vector<float> test(2); 
    test[0] = 0; 
    test[1] = 0;  
    return(test);
    // FIN TEST
    
    //return(force_particle);
};