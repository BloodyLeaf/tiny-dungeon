/*
Auteur(e)s :						Pier-Alexandre Caron , Sophie, Étienne , Émily
Date de création du fichier :		2020-04-27
Nom du fichier :					Source.cpp
Nom du projet	:					Nom a trouver
But du projet : Réaliser un jeu de style D&D tour par tour
*/

#include <SFML/Graphics.hpp>
//#include "Window.h"

#include "MenuPrincipal.h"
#include "battleGround.h"


using namespace sf;

int main(void) {


	RenderWindow window(VideoMode(1500, 800), "Tiny Dungeon");
	window.setFramerateLimit(60);
	Event event;

	menuPrincipal menuPrincipal;
	battleGrounds battleGround1;

	battleGround1.game(window);

	


	return 0;
}