/*
Auteur(e)s :						Pier-Alexandre Caron
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					Bouton.cpp
D�claration des m�thode de l'objet bouton
*/
#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

//Faire des images pour chacun des boutons [ P-A ]

class bouton {

private:
	RectangleShape _posBouton;
	Texture _textureBouton;
	IntRect _rectBouton;

public:
	void initialiserBouton(int posX, int posY, int w, int h, const char* nomBouton);

	void setRectangleShape(int posX, int posY, int w, int h);
	void setDimension(int w, int h);
	void setPosition(int posX, int posY);
	void setIntRect(IntRect intRect);
	void setTexture(const char* nomSprite);
	void setOutline(int thickness, Color color);
	void setToTransparent(void);

	void print(RenderWindow &window);
};