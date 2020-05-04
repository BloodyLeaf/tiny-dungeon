/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					MenuPrincipal.cpp
Déclaration des méthode de l'objet MenuPrincipal
*/

#include "MenuPrincipal.h"
#include "Bouton.h"

void menuPrincipal::initMenuPrincipal()
{
	initBouton();
}

void menuPrincipal::initBouton()
{
	_boutonClasse.initialiserBouton(400,400,200,40,"ressources/boutonClass.jpg");
	_boutonRace.initialiserBouton(400, 400, 200, 40, "ressources/boutonRace.jpg");
	_fondEcran.setSize(Vector2f(1300, 800));
	_fondEcran.setFillColor(Color::Green);
	_fondEcran.setPosition(100, 100);
}

void menuPrincipal::print(RenderWindow& window)
{
	window.draw(_fondEcran);
	

	_boutonRace.print(window);
	_boutonClasse.print(window);
}
