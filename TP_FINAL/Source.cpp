/*
Auteur(e)s :						Pier-Alexandre Caron , Sophie, �tienne , �mily
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					Source.cpp
Nom du projet	:					Nom a trouver
But du projet : R�aliser un jeu de style D&D tour par tour
*/

#include <SFML/Graphics.hpp>
//#include "Window.h"

#include "MenuPrincipal.h"
#include "battleGround.h"
#include "game.h"


using namespace sf;

int main(void) {


	game tiny_Dungeon;

	tiny_Dungeon.playGame();
	


	return 0;
}