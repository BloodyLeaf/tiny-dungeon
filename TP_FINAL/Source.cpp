/*
Auteur(e)s :						Pier-Alexandre Caron , Sophie Bourgault, Étienne , Émily
Date de création du fichier :		2020-04-27
Nom du fichier :					Source.cpp
Nom du projet	:					Nom a trouver
But du projet : Réaliser un jeu de style D&D tour par tour
*/

#include <SFML/Graphics.hpp>

#include "MenuPrincipal.h"
#include "battleGround.h"
#include "game.h"


using namespace sf;

int main(void) {


	game tiny_Dungeon;

	tiny_Dungeon.playGame();

	/*ifstream fichier;
	hero mage;

	mage.initPersonnage();

	cout << mage.getId() << " ID" << endl;
	cout << mage.getPv() << " PV" << endl;
	cout << mage.getMaxPv() << " MaxPv" << endl;
	cout << mage.getStr() << " Str" << endl;
	cout << mage.getGold() << " Gold" << endl;
	system("pause");

	mage.initPersonnage();
	mage.recherchePersonnage(fichier, mage.getId());

	cout << mage.getId() << " ID" << endl;
	cout << mage.getPv() << " PV" << endl;
	cout << mage.getMaxPv() << " MaxPv" << endl;
	cout << mage.getStr() << " Str" << endl;
	cout << mage.getGold() << " Gold" << endl;

	system("pause");*/
	


	return 0;
}