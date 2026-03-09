#include "animal.h"

Animal::Animal(int maxX, int maxY)
{

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
    if (this->vivant && a.vivant) {
 
        return true; 
    }
    return false;
}




