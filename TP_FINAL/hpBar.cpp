/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					hpBar.h
Définition des méthode de l'objet hpBar
*/

#include "hpBar.h"

void RessourceBar::initHpBar(int x, int y, float hp, float maxHP)
{
	_background.setPosition(Vector2f(x, y - 50));
	_background.setFillColor(Color::White);
	_background.setOutlineThickness(3);
	_background.setOutlineColor(Color::Black);
	_background.setSize(Vector2f(100, 15));


	_percent = (hp / maxHP) * 100;
	if (_percent < 0) _percent = 0;
	_remaining.setPosition(Vector2f(x, y - 50));
	_remaining.setSize(Vector2f(_percent, 15));
	_remaining.setFillColor(Color::Red);

}
void RessourceBar::initManaBar(int x, int y, float mana, float maxMana)
{
	_background.setPosition(Vector2f(x, y - 28));
	_background.setFillColor(Color::White);
	_background.setOutlineThickness(3);
	_background.setOutlineColor(Color::Black);
	_background.setSize(Vector2f(100, 15));


	_percent = (mana / maxMana) * 100;

	_remaining.setPosition(Vector2f(x, y - 28));
	_remaining.setSize(Vector2f(_percent, 15));
	_remaining.setFillColor(Color::Blue);
}
void RessourceBar::setToTransparent(void)
{
	_background.setFillColor(Color::Transparent);
	_remaining.setFillColor(Color::Transparent);
	_background.setOutlineThickness(0);
	_background.setOutlineColor(Color::Transparent);
	
}
void RessourceBar::printRessourceBar(RenderWindow& window)
{
	window.draw(_background);
	window.draw(_remaining);
}
