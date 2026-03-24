#ifndef ANIMAL_H
#define ANIMAL_H

#include "stdlib.h"
#include <string>
#include "attaque.h"

class Animal
{
    public : 

    Animal(int maxX, int maxY);
    Animal(int maxX, int maxY, int a, int b);
    std::string getNom() const { return _nom;}
    int getX() const {return x;}
    int getY() const {return y;}
    bool getVivant () const {return vivant;}
    Attaque getAttaque() const {return _typeAttaque;}
    void setVivant(bool v);
    bool attaque (Animal &a);
    virtual void setAttaque() = 0;
    virtual void deplace(int maxX, int maxY) = 0;


    protected :

    std::string     _nom;
    int             x; //abscisse de l'animal
    int             y; //ordonnée de l'animal
    bool            vivant;
    Attaque         _typeAttaque;

};

#endif