/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					MenuPrincipal.h
Déclaration des méthode de l'objet MenuPrincipal
*/
#pragma once

#include "Bouton.h"

class menuPrincipal {

private:

	RectangleShape _fondEcran;
	bouton _boutonRace;
	bouton _boutonClasse;

public:

	void initMenuPrincipal();
	void initBouton();

	void print(RenderWindow& window);

};