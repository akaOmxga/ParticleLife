// Fichier source
// de la fonction random

#include "random_generator.hpp"

int getRandomNumber(int a,const int b) 
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(a, b);
    return dis(gen);
}