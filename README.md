# Compte Rendu TP - Simulation d'Écosystème et Programmation Orientée Objet

## Introduction

Ce projet présente une simulation d'écosystème dynamique où différentes entités animales interagissent, se déplacent et combattent sur une grille bidimensionnelle. L'objectif est d'illustrer les principes de la programmation orientée objet, notamment l'héritage, le polymorphisme et l'encapsulation, à travers un système de combat basé sur le principe "Pierre-Feuille-Ciseaux".

## Fonctionnement Général

Le programme simule une partie où plusieurs animaux (Lions, Loups, Ours, Pierres) sont placés sur une grille de 10x10. La simulation progresse par tours successifs. À chaque tour, les actions suivantes sont effectuées :

1.  **Déplacement** : Chaque animal vivant se déplace aléatoirement sur la grille.
2.  **Combat** : Si deux animaux se retrouvent sur la même case, un combat est initié. La résolution du combat détermine le vainqueur selon les règles de "Pierre-Feuille-Ciseaux".
3.  **Affichage** : L'état actuel de la grille, incluant la position de chaque animal vivant, est affiché.
4.  **Vérification de Fin** : Le nombre de survivants est compté. Si un seul animal reste en vie, ou si tous les animaux sont éliminés, la simulation se termine. Sinon, le tour suivant commence après une courte pause.

## Détail des Classes et Fonctions

Le projet est structuré autour d'une hiérarchie de classes pour gérer les animaux et leurs interactions.

### 1. `src/Animal.h` - Classe de Base `Animal`

Cette classe abstraite sert de modèle pour toutes les entités du jeu.

*   **Attributs Protégés :**
    *   `_nom` : `std::string` - Le nom de l'animal (ex: "Loup", "Lion").
    *   `x`, `y` : `int` - Les coordonnées de l'animal sur la grille.
    *   `vivant` : `bool` - Indique si l'animal est encore en vie.
    *   `_typeAttaque` : `Attaque` - L'instance d'attaque associée à l'animal.

*   **Constructeurs :**
    *   `Animal(int maxX, int maxY)` : Constructeur pour initialiser l'animal avec des coordonnées aléatoires dans les limites de la grille (`maxX`, `maxY`).
    *   `Animal(int maxX, int maxY, int a, int b)` : Constructeur pour initialiser l'animal avec des coordonnées spécifiées (`a`, `b`).

*   **Méthodes Publiques :**
    *   `getNom() const` : Retourne le nom de l'animal.
    *   `getX() const`, `getY() const` : Retournent les coordonnées `x` et `y`.
    *   `getVivant() const` : Retourne l'état de vie de l'animal.
    *   `getAttaque() const` : Retourne l'objet `Attaque` de l'animal.
    *   `setVivant(bool v)` : Modifie l'état de vie de l'animal.
    *   `attaque(Animal &a)` : Déclenche un combat entre cet animal et un autre (`a`). Retourne `true` si cet animal gagne, `false` sinon.
    *   `setAttaque() = 0` : Méthode virtuelle pure. Chaque classe dérivée doit implémenter cette méthode pour définir le type d'attaque de l'animal.
    *   `deplace(int maxX, int maxY) = 0` : Méthode virtuelle pure. Chaque classe dérivée doit implémenter cette méthode pour définir le comportement de déplacement de l'animal.

### 2. `src/Attaque.h` - Classe `Attaque`

Cette classe gère la logique des types d'attaques et la résolution des combats.

*   **Énumération `Type` :**
    *   Définit les trois types d'attaques possibles : `PIERRE`, `FEUILLE`, `CISEAUX`.

*   **Attribut Privé :**
    *   `_type` : `Type` - Le type d'attaque spécifique de l'instance.

*   **Constructeurs :**
    *   `Attaque()` : Crée une attaque de type aléatoire.
    *   `Attaque(Type t)` : Crée une attaque d'un type spécifié.

*   **Méthodes Publiques :**
    *   `getTypeAttaque() const` : Retourne le type d'attaque.
    *   `resoudreAttaque(Attaque &a) const` : Méthode clé pour le combat. Compare le type de cette attaque avec celui de l'attaque `a` et retourne `true` si cette attaque gagne (selon les règles Pierre-Feuille-Ciseaux), `false` sinon.
    *   `getNomAttaque() const` : Retourne le nom textuel du type d'attaque (ex: "Feuille").

### 3. Classes Dérivées `Animal` (`src/Lion.h`, `src/Loup.h`, `src/Ours.h`, `src/Pierre.h`)

Ces classes héritent de `Animal` et implémentent les méthodes virtuelles pures. Bien que les implémentations spécifiques ne soient pas fournies dans les fichiers d'en-tête (.cpp), on peut déduire leur rôle :

*   **`Lion`, `Loup`, `Ours`, `Pierre` :** Chaque classe hérite de `Animal`, définit son propre nom (`_nom`) dans son constructeur et implémente `setAttaque()` et `deplace()`. Le comportement exact de déplacement et le type d'attaque initialisé par `setAttaque()` sont spécifiques à chaque animal. Par exemple, `Pierre` pourrait toujours avoir une attaque "Pierre" et un déplacement très limité, tandis que `Lion` pourrait avoir des attaques plus puissantes ou des schémas de déplacement différents.

### 4. `main.cpp` - Orchestration de la Simulation

Ce fichier contient la logique principale du programme.

*   **Fonction `clearScreen()` :**
    *   Utilise `system("cls")` (Windows) ou `system("clear")` (Linux/Mac) pour effacer la console, créant un effet d'animation lors de la mise à jour de la grille.

*   **Fonction `afficherPlateau(const std::vector<Animal*>& animaux, int maxX, int maxY)` :**
    *   Prend une liste d'animaux et les dimensions de la grille.
    *   Crée une grille 2D de caractères représentant l'état du plateau.
    *   Place le premier caractère du nom de chaque animal vivant sur sa position correspondante dans la grille.
    *   Dessine la grille dans la console avec des bordures.

*   **Fonction `main()` :**
    *   **Initialisation :**
        *   Initialise le générateur de nombres aléatoires (`std::srand`).
        *   Définit les dimensions de la grille (`maxX`, `maxY`).
        *   Crée un `std::vector<Animal*>` pour stocker les pointeurs vers les animaux.
        *   Instancie et ajoute plusieurs objets de chaque type d'animal (Loup, Pierre, Lion, Ours) au vecteur.
    *   **Boucle de Simulation (`while (true)`) :**
        *   Appelle `clearScreen()` pour effacer la console.
        *   Affiche le numéro du tour actuel.
        *   **Phase de Déplacement :** Itère sur tous les animaux vivants et appelle leur méthode `deplace()`.
        *   **Phase de Combat :** Itère sur toutes les paires d'animaux pour détecter les collisions sur la même case. Si une collision survient, les deux animaux appellent `setAttaque()` (pour définir leur attaque du tour) puis leur méthode `attaque()`. Le résultat du combat est affiché.
        *   **Phase d'Affichage :** Appelle `afficherPlateau()` pour montrer l'état mis à jour de la grille.
        *   **Vérification de Fin :** Compte les animaux vivants. Si le nombre est inférieur ou égal à 1, la simulation se termine, en annonçant le survivant ou un match nul.
        *   **Pause :** Introduit une pause de 500 millisecondes (`std::chrono::milliseconds(500)`) pour ralentir la simulation et la rendre visible.
        *   Incrémente le compteur de tours.
    *   **Nettoyage :** Après la fin de la boucle, chaque pointeur d'animal est supprimé pour libérer la mémoire allouée dynamiquement.

## Conclusion

Ce projet démontre efficacement l'utilisation de l'héritage et du polymorphisme pour créer une simulation. La séparation des responsabilités entre la classe de base `Animal`, la logique d'attaque, et les comportements spécifiques des différentes espèces animales permet une gestion claire du code.
