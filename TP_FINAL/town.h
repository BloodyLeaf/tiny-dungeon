/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Town.h
Déclaration des méthode de l'objet Town
*/
#pragma once

#include <SFML/Graphics.hpp>

#include "Bouton.h"

using namespace sf;

class town {


private :
	RectangleShape _background;

	RectangleShape _wallLeft;
	RectangleShape _wallRight;
	RectangleShape _wallTop;

	RectangleShape _hero;

	bouton _option1;
	bouton _option2;
	bouton _option3;
	bouton _option4;

	RectangleShape _backgroundMenu;

	Font _font;
	Text _text;
	Text _textGold;

public:

	void init(int gold);

	void initBuilding(void);

	void initHero(void);

	void initBackground(void);

	void initMenu(void);

	void setText(Text& text, const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style);
	void setTextGold(Text& text, int gold, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style);

	bool townAction(RenderWindow& window, int& heroHP, int & heroMaxHP, int & dmg, int & gold);

	void townEntrance(RenderWindow& window);
	void townExit(RenderWindow& window);

	void printTown(RenderWindow& window);
};
