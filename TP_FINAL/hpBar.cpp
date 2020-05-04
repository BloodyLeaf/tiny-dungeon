/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					hpBar.h
Définition des méthode de l'objet hpBar
*/

#include "hpBar.h"

void hpBar::init(int x, int y, float hp, float maxHP)
{
	_background.setPosition(Vector2f(x, y - 28));
	_background.setFillColor(Color::White);
	_background.setOutlineThickness(3);
	_background.setOutlineColor(Color::Black);
	_background.setSize(Vector2f(100, 15));


	_percent = (hp / maxHP) * 100;

	_remaining.setPosition(Vector2f(x, y - 28));
	_remaining.setSize(Vector2f(_percent, 15));
	_remaining.setFillColor(Color::Red);

}
void hpBar::printHPBar(RenderWindow& window)
{
	window.draw(_background);
	window.draw(_remaining);
}
/*
void hpBar::setPercent(int hp)
{
}
*/