#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <thread>  // Ajouté pour le mode automatique
#include <chrono>  // Ajouté pour gérer le temps
#include "src/loup.h"
#include "src/pierre.h"
#include "src/lion.h"
#include "src/ours.h"

// Fonction pour effacer l'écran (Windows et Linux/Mac)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void afficherPlateau(const std::vector<Animal*>& animaux, int maxX, int maxY) {
    std::vector<std::vector<char>> grille(maxY, std::vector<char>(maxX, '.'));

    for (Animal* a : animaux) {
        if (a->getVivant()) {
            grille[a->getY()][a->getX()] = a->getNom()[0];
        }
    }

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

    for (int i = 0; i < 6; ++i) {
        animaux.push_back(new Loup(maxX, maxY));
        animaux.push_back(new Pierre(maxX, maxY));
        animaux.push_back(new Lion(maxX, maxY));
        animaux.push_back(new Ours(maxX, maxY));
    }

    int tour = 1;

    while (true) {
        clearScreen(); // Rend la simulation "animée"
        std::cout << "========== TOUR " << tour << " ==========" << std::endl;

        // 1. DÉPLACEMENT
        for (Animal* a : animaux) {
            if (a->getVivant()) a->deplace(maxX, maxY);
        }

        // 2. RÉSOLUTION DES COMBATS
        for (size_t i = 0; i < animaux.size(); ++i) {
            for (size_t j = i + 1; j < animaux.size(); ++j) {
                Animal* a = animaux[i];
                Animal* b = animaux[j];

                if (a->getVivant() && b->getVivant() && a->getX() == b->getX() && a->getY() == b->getY()) {
                    a->setAttaque(); 
                    b->setAttaque();

                    std::cout << "[COMBAT] " << a->getNom() << " vs " << b->getNom() 
                              << " en (" << a->getX() << "," << a->getY() << ")" << std::endl;
                    
                    if (a->attaque(*b)) {
                        std::cout << "   >>> GAGNANT : " << a->getNom() << " (" << a->getAttaque().getNomAttaque() << ")" << std::endl;
                    } else {
                        std::cout << "   >>> GAGNANT : " << b->getNom() << " (" << b->getAttaque().getNomAttaque() << ")" << std::endl;
                    }
                }
            }
        }

        // 3. AFFICHAGE
        afficherPlateau(animaux, maxX, maxY);

        // 4. COMPTAGE ET CONDITION D'ARRÊT
        int vivants = 0;
        Animal* dernierSurvivant = nullptr;
        for (Animal* a : animaux) {
            if (a->getVivant()) {
                vivants++;
                dernierSurvivant = a;
            }
        }
        
        std::cout << "Survivants : " << vivants << "\n";
        
        if (vivants <= 1) {
            std::cout << "\nSIMULATION TERMINEE !" << std::endl;
            if (dernierSurvivant) 
                std::cout << "Le vainqueur final est : " << dernierSurvivant->getNom() << " !" << std::endl;
            else 
                std::cout << "Tout le monde est mort... Match nul !" << std::endl;
            break;
        }

        // 5. PAUSE (500ms = 0.5 seconde)
        // Ajuste cette valeur pour accélérer ou ralentir (ex: 200 pour rapide)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        
        tour++;
    }

    for (Animal* a : animaux) delete a;
    return 0;
}