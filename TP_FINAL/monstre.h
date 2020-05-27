/*
Programme: monstre.h
Acteur: Sophie Bourgault
Date de cr�ation: 05 mai 2020
But du programme: D�claration de l'objet monstre.
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

    void initMonster(int w, int h, int x, int y);              //Initialise les monstre selon des parametre recu [ P-A ] temp en attendant read bloc note

    int getRating() const;                //retourne le rating du personnage monstre [sophie]
    int getAttackHasard() const;        //retourne la valeur de lattack par hasard du personnage monstre [sophie]

    void setRating(int rating);            //modifie le rating du personnage monstre [sophie]
    void setAttackHasard(int hasard);    //modifie la valeur de lattack hasard du personnage monstre [sophie]

    void rechercheMonstre(ifstream& fichier, int personnage);        //recherche dans un fichier texte a laide de id et attribution de donnee [sophie]
    
};