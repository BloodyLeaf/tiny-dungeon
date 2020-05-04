/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					hpBar.h
Déclaration des méthode de l'objet hpBar
*/
#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class hpBar {

private:

	RectangleShape _background;
	RectangleShape _remaining;

	float _percent;

public:

	void init(int x, int y,float hp, float maxHP);	

	//Manque un setposition [P-A]

	//manque un set to transparent [P-A]

	//void setPercent(int hp);

	void printHPBar(RenderWindow& window);

};
