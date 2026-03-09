#ifndef ATTAQUE_H
#define ATTAQUE_H

#include <string>

class Attaque 
{
    public :

    enum class Type {
            PIERRE = 0,
            FEUILLE = 1,
            CISEAUX = 2
        };
    
    Attaque(); //crée une attaque random
    Attaque(Type t); //crée une attaque spécifique
    int getTypeAttaque() const {return _type;}
    bool resoudreAttaque(Attaque &a) const;
    std::string getNomAttaque() const;

    private : 
    int     _type;
};


#endif