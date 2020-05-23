/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Town.h
Déclaration des méthode de l'objet Town
*/
#pragma once

#include <SFML/Graphics.hpp>

#include "Bouton.h"
#include "hero.h"

using namespace sf;

class town {


private :
	RectangleShape _background;

	RectangleShape _wallLeft;
	RectangleShape _wallRight;
	RectangleShape _wallTop;


	bouton _optionUpgrade[7];

	bouton _boutonfreeUpgrade[2];

	RectangleShape _backgroundMenu;
	RectangleShape _backGroundFreeUpgrade;

	Font _font;

	Text _textGold;
	Text _textGoldQty;

	Text _textHP;
	Text _textCurrentHP;
	Text _textHPDivider;
	Text _textMaxHP;

	Text _textDmg;
	Text _textDmgCurrent;

	Text _mana;
	Text _currentMana;
	Text _manaDivider;
	Text _maxMana;

	Text _faithText;
	Text _faith;

	Text _speedText;
	Text _speed;

	bool _freeUpgrade;

public:

	void init(hero & hero);

	void initBuilding(void);

	void initHero(hero & hero);

	void initBackground(void);

	void initMenu(void);

	void setText(Text& text, const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style);
	void setTextIntegerStats(Text& text, int stats, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style);
	void updateChar(int choice, hero & hero);
	void updateIntegerStats(Text& text,int newStats);

	bool townAction(RenderWindow& window, hero & hero);

	void townEntrance(RenderWindow& window,hero & hero);
	void townExit(RenderWindow& window,hero & hero);

	void printTown(RenderWindow& window,hero & hero);
};
