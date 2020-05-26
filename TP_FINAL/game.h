/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Game.h
Déclaration des méthode de l'objet Game
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
	
	Item _itemList[30];

public:

	void initHero(void);

	void initGame(void);

	void initNewBG(void);

	void playGame(void);

	void initItemList(void);

	void generateLoot(void);
};