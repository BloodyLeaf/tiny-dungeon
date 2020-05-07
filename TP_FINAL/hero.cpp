/*
Programme: hero.cpp
Acteur: Sophie Bourgault
Date de création: 05 mai 2020
But du programme: Définition de l'objet hero.
*/

#include "hero.h"

//methode qui retourne la race du personnage [sophie]
string hero::getRace() const
{
    return _race;
}

//methode qui retourne la classe du personnage [sophie]
string hero::getClasse() const
{
    return _classe;
}
//Retourne l'armes actuelle du hero[sophie]
Item hero::getWeapon() const
{
    return _weapon;
}
//Retourne les botte actuelle du hero[sophie]
Item hero::getBoots() const
{
    return _weapon;
}
//Retourne l'armure actuelle[sophie]
Item hero::getArmor() const
{
    return _armor;
}

//methode qui modifie la race du personnage [sophie]
void hero::setRace(string race)
{
    _race = race;
}

//methode qui modifie la classe du personnage [sophie]
void hero::setClasse(string classe)
{
    _classe = classe;
}
//Permet de changer d'arme[sophie]
void hero::setWeapon(Item weapon)
{
    _weapon = weapon;
}
//permet de changer de botte[sophie]
void hero::setBoots(Item boots)
{
    _boots = boots;
}
//permet de changer d'armure[sophie]
void hero::setArmur(Item armor)
{
    _armor = armor;
}
/*void hero::setEquipement(vector <int> equipement)
{
    for (int i = 0; i < equipement.size(); i++) {
        _equipement.at(i) = (equipement.at(i));
    }
}*/