/*
Programme: monstre.h
Acteur: Sophie Bourgault
Date de création: 05 mai 2020
But du programme: Déclaration de l'objet monstre.
*/

#include <iostream>
#include "personnage.h"
#pragma once

using namespace std;

class monstre : public personnage
{

private:

    int _rating, _attackHasard;

public:

    int getRating() const;                //retourne le rating du personnage monstre [sophie]
    int getAttackHasard() const;        //retourne la valeur de lattack par hasard du personnage monstre [sophie]

    void setRating(int rating);            //modifie le rating du personnage monstre [sophie]
    void setAttackHasard(int hasard);    //modifie la valeur de lattack hasard du personnage monstre [sophie]
};