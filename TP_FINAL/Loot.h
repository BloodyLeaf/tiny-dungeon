/*
Auteur.e.s :                        Étienne Ménard
Date de création du fichier :        2020-05-25
Nom du fichier :                    Loot.h
Déclaration des méthodes de la classe Loot
*/

#pragma once

#include <ctime>
#include <cstdlib>

#include "Item.h"

class Loot
{
private:
    int type;
    int index;
public:
    void pickType(int& type);
    void pickIndex(int& index);
};