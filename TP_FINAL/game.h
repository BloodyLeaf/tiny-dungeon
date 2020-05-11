/*
Auteur(e)s :						Pier-Alexandre Caron
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					Game.h
D�claration des m�thode de l'objet Game
*/
#pragma once

#include <SFML/Graphics.hpp>
#include "battleGround.h"
#include "town.h"
#include "hero.h"
#include "MenuPrincipal.h"

using namespace sf;


class game {

private : 

	menuPrincipal menu;

	RenderWindow _window;
	battleGrounds _currentBattleGround;
	bool _heroAlive;

	town _town;

	int _world;
	int _level;

	hero _hero;
	

public:

	void initHero(void);

	void initGame(void);

	void initNewBG(void);

	void playGame(void);

	void nouvelleAventure();
};