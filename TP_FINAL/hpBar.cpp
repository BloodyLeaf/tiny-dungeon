/*
Auteur(e)s :						Pier-Alexandre Caron
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					hpBar.h
D�finition des m�thode de l'objet hpBar
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
void hpBar::setToTransparent(void)
{
	_background.setFillColor(Color::Transparent);
	_remaining.setFillColor(Color::Transparent);
	_background.setOutlineThickness(0);
	_background.setOutlineColor(Color::Transparent);
	
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