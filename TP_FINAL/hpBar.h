/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					hpBar.h
Déclaration des méthode de l'objet hpBar
*/
#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class RessourceBar {

private:

	RectangleShape _background;
	RectangleShape _remaining;

	float _percent;
	Color _ressourceType;				//Pour les hp le mana ou la barre de speed ( eventuellement ) 

public:

	void initHpBar(int x, int y,float hp, float maxHP);	
	void initManaBar(int x, int y, float mana, float maxMana);

	//Manque un setposition [P-A]

	//manque un set to transparent [P-A]

	//void setPercent(int hp);

	void setToTransparent(void);

	void printRessourceBar(RenderWindow& window);

};
