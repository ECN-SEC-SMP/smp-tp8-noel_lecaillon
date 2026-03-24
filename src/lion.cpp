#include "lion.h"

Lion::Lion(int maxX, int maxY) : Animal(maxX, maxY) {
    this->_nom = "Lion"; // Symbole pour l'affichage
}

Lion::Lion(int maxX, int maxY, int a, int b): Animal(maxX, maxY, a, b)
{
    this->_nom = "Lion"; // Symbole pour l'affichage
}

void Lion::deplace(int maxX, int maxY) {
    // Directions possibles : (1,1), (1,-1), (-1,-1), (-1,1)
    int dx = (rand() % 2 == 0) ? 1 : -1;
    int dy = (rand() % 2 == 0) ? 1 : -1;

    // Gestion du monde torique (bordure)
    this->x = (this->x + dx + maxX) % maxX;
    this->y = (this->y + dy + maxY) % maxY;
}

void Lion::setAttaque() {
    // Aléatoire entre Feuille (1) et Ciseaux (2)
    if (rand() % 2 == 0) {
        this->_typeAttaque = Attaque(Attaque::Type::FEUILLE);
    } else {
        this->_typeAttaque = Attaque(Attaque::Type::CISEAUX);
    }
}