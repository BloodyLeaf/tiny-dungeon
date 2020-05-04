/*
Auteur(e)s :						Pier-Alexandre Caron
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					MenuPrincipal.h
D�claration des m�thode de l'objet MenuPrincipal
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