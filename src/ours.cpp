#include "ours.h"

Ours::Ours(int maxX, int maxY) : Animal(maxX, maxY) {
    this->_nom = "Ours"; 
}

Ours::Ours(int maxX, int maxY, int a, int b) : Animal(maxX, maxY, a, b) {
    this->_nom = "Ours";
}

void Ours::setAttaque() {
    this->_typeAttaque = Attaque(Attaque::Type::FEUILLE);
}

void Ours::deplace(int maxX, int maxY) {
    // Les 8 déplacements possibles (2,1), (1,2), (-1,2), (-2,1), (-2,-1), (-1,-2), (1,-2), (2,-1)
    static const int dx[] = { 2, 1, -1, -2, -2, -1,  1,  2 };
    static const int dy[] = { 1, 2,  2,  1, -1, -2, -2, -1 };

    int choix = std::rand() % 8;

    // Application du mouvement avec gestion du monde torique (modulo)
    this->x = (this->x + dx[choix] + maxX) % maxX;
    this->y = (this->y + dy[choix] + maxY) % maxY;
}
