/*
Programme: monstre.cpp
Acteur: Sophie Bourgault
Date de création: 05 mai 2020
But du programme: Définition de l'objet monstre.
*/

#include "monstre.h"

//methode qui retourne le rating du personnage monstre [sophie]
int monstre::getRating() const
{
    return _rating;
}

//methode qui retourne la valeur du attackHasard du personnage monstre [sophie]
int monstre::getAttackHasard() const
{
    return _attackHasard;
}

//methode qui modifie le rating du personnage monstre [sophie]
void monstre::setRating(int rating)
{
    _rating = rating;
}

//methode qui modifie la valeur du attackHasard du personnage monstre [sophie]
void monstre::setAttackHasard(int hasard)
{
    _attackHasard = hasard;
}

void monstre::rechercheMonstre(ifstream& fichier, int personnage)
{
    int donnee;
    ouvrirFichier(fichier);

    while (!fichier.eof()) {
        fichier >> donnee;

        if (donnee == personnage) {

            fichier >> donnee;
            setStr(donnee);

            fichier >> donnee;
            setPv(donnee);

            fichier >> donnee;
            setMaxPv(donnee);

            fichier >> donnee;
            setGold(donnee);

            break;
        }
    }
}

