# TP C++: Simulation d'Animaux et Attaques

Ce projet est un Travaux Pratiques (TP) en C++ visant à simuler des interactions entre différents types d'animaux et des concepts d'attaque, en utilisant les principes de la programmation orientée objet.

## 1. Mise en place du projet

Ce projet utilise CMake pour la compilation. Suivez les étapes ci-dessous pour le configurer et le construire.

### Prérequis

Assurez-vous d'avoir les outils suivants installés sur votre système :
- Un compilateur C++ (par exemple, g++)
- CMake

### Compilation et Exécution

1.  **Cloner le dépôt (si applicable) ou naviguer vers le répertoire du projet:**
    ```bash
    cd /home/romain/Bureau/TPjsp/smp-tp8-noel_lecaillon
    ```

2.  **Créer un répertoire de build et s'y déplacer :**
    ```bash
    mkdir build
    cd build
    ```

3.  **Configurer le projet avec CMake :**
    ```bash
    cmake ..
    ```

4.  **Compiler le projet :**
    ```bash
    make
    ```

5.  **Exécuter l'exécutable généré :**
    ```bash
    ./smp-tp8-noel_lecaillon # Le nom de l'exécutable peut varier selon CMakeLists.txt
    ```

## 2. Architecture du projet

L'architecture du projet est basée sur la programmation orientée objet en C++. Elle est structurée autour de plusieurs classes principales, chacune définie par un fichier d'en-tête (`.h`) et son implémentation (`.cpp`).

-   **`Animal` (animal.h, animal.cpp)**: Cette classe sert probablement de classe de base abstraite ou concrète pour tous les types d'animaux dans la simulation. Elle devrait définir les propriétés communes à tous les animaux (ex: points de vie, nom, etc.) et des méthodes virtuelles pures ou virtuelles pour le comportement spécifique.
-   **`Attaque` (attaque.h, attaque.cpp)**: Cette classe représente un mécanisme d'attaque qui peut être utilisé par les animaux. Elle pourrait définir des propriétés comme la puissance d'attaque et la méthode pour appliquer des dégâts.
-   **`Lion` (lion.h, lion.cpp)**: Une classe dérivée de `Animal`, représentant un lion. Elle implémentera les comportements spécifiques au lion, notamment en termes d'attaque ou de caractéristiques propres.
-   **`Loup` (loup.h, loup.cpp)**: Une autre classe dérivée de `Animal`, représentant un loup. Similaire au lion, elle aura ses propres implémentations de comportements.
-   **`Ours` (ours.h, ours.cpp)**: Une classe dérivée de `Animal`, représentant un ours.
-   **`Pierre` (pierre.h, pierre.cpp)**: Cette classe pourrait représenter un élément inanimé ou un obstacle dans l'environnement, ou un type d'attaque spécifique (ex: lancer de pierre). Sa relation avec les animaux ou l'attaque est à définir plus précisément par le code.
-   **`main.cpp`**: Le point d'entrée principal du programme. Il contiendra la logique d'initialisation, la création des objets (animaux, attaques) et la gestion de la simulation ou des interactions entre eux.

L'ensemble suggère une hiérarchie de classes pour les animaux, potentiellement avec une relation de composition ou d'agrégation avec la classe `Attaque` pour gérer les comportements de combat.

## 3. Compte rendu du TP

### Objectifs du TP

(Cette section serait complétée avec les objectifs spécifiques définis par l'énoncé du TP.)
Exemples d'objectifs potentiels:
-   Implémenter une hiérarchie de classes pour différents animaux.
-   Mettre en œuvre le polymorphisme pour les comportements d'attaque.
-   Gérer l'état des animaux (points de vie, etc.) après une attaque.
-   Démontrer l'utilisation des classes de base et dérivées.
-   Écrire un programme principal (`main.cpp`) qui simule des scénarios d'interaction.

### Réalisation

(Cette section décrirait les étapes de la réalisation, les choix de conception, et les difficultés rencontrées.)
-   **Conception des classes:** Description de la structure des classes `Animal`, `Attaque`, `Lion`, `Loup`, `Ours`, `Pierre`. Justification des relations (héritage, composition).
-   **Implémentation des fonctionnalités:** Détails sur la façon dont les attaques sont gérées, comment les points de vie sont mis à jour, et comment les interactions entre animaux sont simulées.
-   **Tests et validations:** Brève description des tests effectués pour s'assurer du bon fonctionnement des classes et des interactions.

### Résultats

(Cette section présenterait les résultats obtenus, éventuellement avec des extraits de sortie du programme pour illustrer les simulations.)
-   Exemple de simulation: Lion attaque Loup, Loup riposte, etc.
-   Affichage des points de vie restants après les interactions.

### Conclusion

(Cette section résumerait les apprentissages et les points à améliorer.)
-   Ce que le TP a permis d'apprendre sur la POO en C++.
-   Suggestions d'améliorations ou d'extensions possibles pour le projet.
