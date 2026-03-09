#include "attaque.h"

Attaque::Attaque()
{
    int nombreAleatoire = std::rand() % 3;

    // 2. On convertit l'entier vers le type enum class Type
    // 0 devient PIERRE, 1 devient FEUILLE, 2 devient CISEAUX
    this->_type = static_cast<Type>(nombreAleatoire);

}
    
Attaque::Attaque(Type t)
{
   this->_type = t;
}

bool Attaque::resoudreAttaque(Attaque &a) const
{
    // 1. Cas du match nul : même type d'attaque
    if (this->_type == a._type) {
        // Un match nul est réglé par l'utilisation du générateur aléatoire
        return (std::rand() % 2 == 0); 
    }

    // 2. Cas où "this" gagne selon les règles classiques
    if ((this->_type == Type::PIERRE && a._type == Type::CISEAUX) ||
        (this->_type == Type::FEUILLE && a._type == Type::PIERRE) ||
        (this->_type == Type::CISEAUX && a._type == Type::FEUILLE)) {
        return true;
    }

    // 3. Sinon, c'est l'autre animal qui gagne
    return false;

}

std::string Attaque::getNomAttaque() const
{
    switch (this->_type) {
        case Type::PIERRE:  return "Pierre";
        case Type::FEUILLE: return "Feuille";
        case Type::CISEAUX: return "Ciseaux";
        default:            return "Inconnu";
    }
}
