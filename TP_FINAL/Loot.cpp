/*
Auteur.e.s :                        �tienne M�nard
Date de cr�ation du fichier :        2020-05-25
Nom du fichier :                    Loot.cpp
D�claration des m�thodes de la classe Loot
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