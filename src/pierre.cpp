#include "pierre.h"

Pierre::Pierre(int maxX, int maxY) : Animal(maxX, maxY)
{
    this->_nom = "Pierre";
    this->_typeAttaque = _typeAttaque = Attaque(Attaque::Type::PIERRE);
}

Pierre::Pierre(int maxX, int maxY, int a, int b): Animal(maxX, maxY, a, b)
{
    this->_nom = "Pierre";
    this->_typeAttaque = _typeAttaque = Attaque(Attaque::Type::PIERRE);
}

void Pierre::setAttaque()
{
    //UNE SEULE ATTAQUE
}

void Pierre::deplace(int maxX, int maxY)
{
    //AUCUN DEPLACEMENT
}