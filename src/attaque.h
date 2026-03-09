#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <string>

class Attaque 
{
    public :
    Attaque(); //crée une attaque random
    Attaque(int a); //crée une attaque spécifique
    int getTypeAttaque() const;
    bool resoudreAttaque(Attaque &a) const;
    std::string getNomAttaque() const;

    private : 
    int     _type;
};

#endif