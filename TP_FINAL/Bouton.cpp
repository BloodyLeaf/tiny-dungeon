/*
Auteur(e)s :						Pier-Alexandre Caron 
Date de création du fichier :		2020-04-27
Nom du fichier :					Bouton.cpp
Définition des méthode de l'objet bouton
*/

#include "Bouton.h"

void bouton::initialiserBouton(int posX, int posY, int w, int h, const char* nomBouton)
{
	setRectangleShape(posX, posY, w, h);
	setTexture(nomBouton);


}

void bouton::initialiserFondBouton(int posX, int posY, int w, int h, Color color)
{
	setRectangleShape(posX, posY, w, h);
	setFillColor(color);
}


void bouton::setRectangleShape(int posX, int posY, int w, int h)
{
	_posBouton.setPosition(posX, posY);
	_posBouton.setSize(Vector2f(w, h));
}

void bouton::setDimension(int w, int h)
{
	_posBouton.setSize(Vector2f(w, h));
}

void bouton::setPosition(int posX, int posY)
{
	_posBouton.setPosition(posX, posY);
}

void bouton::setIntRect(IntRect intRect)
{
	_rectBouton = intRect;
	_posBouton.setTextureRect(intRect);
}

void bouton::setTexture(const char* nomBouton)
{
	_textureBouton.loadFromFile(nomBouton);
	_posBouton.setTexture(&_textureBouton);
}

void bouton::setOutline(int thickness, Color color)
{
	_posBouton.setOutlineThickness(thickness);
	_posBouton.setOutlineColor(color);
}

void bouton::setToTransparent(void)
{
	//setOutline(0, Color::Transparent);
	setDimension(0, 0);
}

void bouton::print(RenderWindow& window)
{
	window.draw(_posBouton);
}
void bouton::setText(const char* message, const char* police, int posX, int posY, int taille, const Color& color, int style) {
	Text text;
	Font font;
	font.loadFromFile(police);
	text.setFont(font);
	text.setString(message);
	text.setCharacterSize(taille);
	text.setFillColor(color);
	text.setStyle(style);
	text.setPosition(posX, posY);

}
void bouton::setFillColor(Color color) {
	_posBouton.setFillColor(color);

}