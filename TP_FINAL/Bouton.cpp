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
	//setIntRect(rectBouton);
	setTexture(nomBouton);
}


void bouton::setRectangleShape(int posX, int posY, int w, int h)
{
	_posBouton.setPosition(posX, posY);
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

void bouton::print(RenderWindow& window)
{
	window.draw(_posBouton);
}
