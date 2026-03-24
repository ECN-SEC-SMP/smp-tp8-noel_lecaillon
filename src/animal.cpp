#include "animal.h"

Animal::Animal(int maxX, int maxY)
{
    this->x = std::rand() % maxX;
    this->y = std::rand() % maxY;
    this->vivant = true;
}

Animal::Animal(int maxX, int maxY, int a, int b)
{

    if(a >= 0 && a < maxX) {
        this->x = a;
    } else {
        this->x = 0; 
    }

    if(b >= 0 && b < maxY) {
        this->y = b;
    } else {
        this->y = 0;
    }

    this->vivant = 1;
}



void Animal::setVivant(bool v){
    this->vivant = v;
}


bool Animal::attaque(Animal &a){
  if (this->_typeAttaque.resoudreAttaque(a._typeAttaque)) {
        a.setVivant(false);
        return true; // "this" a gagné
    } else {
        this->setVivant(false);
        return false; // "this" a perdu
    }
}




