/*
Programme: hero.h
Acteur: Sophie Bourgault
Date de création: 05 mai 2020
But du programme: Déclaration de l'objet hero.
*/

#include <iostream>
#include "personnage.h"
#include "Item.h"
#include <string>
#include <vector>
#pragma once

using namespace std;

class hero : public personnage
{

private:

    string _race, _classe;                                //modificateur de stats [sophie]
    Item _weapon;
    Item _boots;
    Item _armor;

public:

    string getRace() const;                                //retourne la race du personnage [sophie]
    string getClasse() const;                            //retourne la race du personnage [sophie]

    Item getWeapon() const;
    Item getBoots() const;
    Item getArmor() const;
    //getteur de vector <int> equipement a faire[sophie]

    void setRace(string race);                            //modificateur de la race du personnage [sophie]
    void setClasse(string classe);                        //modificateur de la classe du personnage [sophie]
    //void setteur de vector <int> equipement a faire[sophie]
    //void setEquipement(vector <int> equipement);        //modificateur de lequipement du personnage [sophie]

    void setWeapon(Item weapon);
    void setBoots(Item boots);
    void setArmur(Item armor);

    void rechercheHero(ifstream& fichier, int personnage);        //recherche dans un fichier texte a laide de id et attribution de donnee [sophie]

};