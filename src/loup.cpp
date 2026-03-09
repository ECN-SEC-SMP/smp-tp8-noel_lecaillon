#include "loup.h"

Loup::Loup(int maxX, int maxY) : Animal(maxX, maxY) {
    this->_nom = "Wolf";
}

Loup::Loup(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b) {
    this->_nom = "Wolf";
}

void Loup::deplace(int maxX, int maxY) {
    // Téléportation aléatoire n'importe où sur le plateau
    this->x = rand() % maxX;
    this->y = rand() % maxY;
}

void Loup::setAttaque() {
    // Utilise le constructeur par défaut d'Attaque qui fait un rand() sur 0, 1, 2
    _typeAttaque = Attaque(); 
}