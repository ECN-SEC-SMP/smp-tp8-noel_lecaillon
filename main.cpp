#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include "src/loup.h"
#include "src/pierre.h"
#include "src/lion.h"
#include "src/ours.h"

void afficherPlateau(const std::vector<Animal*>& animaux, int maxX, int maxY) {
    // Création d'une grille vide pour l'affichage
    std::vector<std::vector<char>> grille(maxY, std::vector<char>(maxX, '.'));

    for (Animal* a : animaux) {
        if (a->getVivant()) {
            grille[a->getY()][a->getX()] = a->getNom()[0];
        }
    }

    // Rendu visuel avec bordures
    std::cout << "\n" << std::string(maxX * 2 + 3, '-') << "\n";
    for (int y = 0; y < maxY; ++y) {
        std::cout << "| ";
        for (int x = 0; x < maxX; ++x) {
            std::cout << grille[y][x] << " ";
        }
        std::cout << "|\n";
    }
    std::cout << std::string(maxX * 2 + 3, '-') << "\n";
}

int main() {
    std::srand(std::time(nullptr));
    int maxX = 10, maxY = 10;
    std::vector<Animal*> animaux;

    // --- INITIALISATION (25% du plateau) ---
    // On crée environ 24 animaux (6 de chaque type)
    for (int i = 0; i < 6; ++i) {
        animaux.push_back(new Loup(maxX, maxY));
        animaux.push_back(new Pierre(maxX, maxY));
        animaux.push_back(new Lion(maxX, maxY));
        animaux.push_back(new Ours(maxX, maxY));
    }

    int tour = 1;
    bool continuer = true;

    while (continuer) {
        std::cout << "\n========== TOUR " << tour << " ==========" << std::endl;

        // 1. DÉPLACEMENT
        for (Animal* a : animaux) {
            if (a->getVivant()) a->deplace(maxX, maxY);
        }

        // 2. RÉSOLUTION DES COMBATS AVEC DÉTAILS
        for (size_t i = 0; i < animaux.size(); ++i) {
            for (size_t j = i + 1; j < animaux.size(); ++j) {
                Animal* a = animaux[i];
                Animal* b = animaux[j];

                if (a->getVivant() && b->getVivant() && a->getX() == b->getX() && a->getY() == b->getY()) {
                    
                    // On prépare les attaques
                    a->setAttaque(); 
                    b->setAttaque();

                    std::cout << "[COMBAT] " << a->getNom() << " vs " << b->getNom() 
                              << " en (" << a->getX() << "," << a->getY() << ")" << std::endl;
                    
                    std::cout << "   -> " << a->getNom() << " utilise " << a->getAttaque().getNomAttaque() << std::endl;
                    std::cout << "   -> " << b->getNom() << " utilise " << b->getAttaque().getNomAttaque() << std::endl;

                    if (a->attaque(*b)) {
                        std::cout << "   >>> VICTOIRE : " << a->getNom() << " !" << std::endl;
                    } else {
                        std::cout << "   >>> VICTOIRE : " << b->getNom() << " !" << std::endl;
                    }
                }
            }
        }

        // 3. AFFICHAGE DE LA GRILLE
        afficherPlateau(animaux, maxX, maxY);

        // 4. COMPTAGE DES SURVIVANTS
        int vivants = 0;
        for (Animal* a : animaux) if (a->getVivant()) vivants++;
        
        std::cout << "Survivants : " << vivants << "\n";
        
        if (vivants <= 1) {
            std::cout << "La simulation est terminee !" << std::endl;
            break;
        }

        std::cout << "Appuyez sur Entree pour le tour suivant (ou 0 pour quitter)... ";
        std::string saisie;
        std::getline(std::cin, saisie);
        if (saisie == "0") continuer = false;
        
        tour++;
    }

    // Nettoyage
    for (Animal* a : animaux) delete a;
    return 0;
}