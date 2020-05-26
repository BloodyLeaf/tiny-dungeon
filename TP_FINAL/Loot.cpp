/*
Auteur.e.s :                        Étienne Ménard
Date de création du fichier :        2020-05-25
Nom du fichier :                    Loot.cpp
Déclaration des méthodes de la classe Loot
*/

#include "Loot.h"

void Loot::pickType(int& type) {
    srand(time(NULL));
    int type = (rand() % 4);
}

void Loot::pickIndex(int& index) {
    srand(time(NULL));
    int type = (rand() % 10);
}