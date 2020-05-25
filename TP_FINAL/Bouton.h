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
// + setText et print pour le text de chaque bouton [Emily]

class bouton {

private:
	RectangleShape _posBouton;
	Texture _textureBouton;
	IntRect _rectBouton;

public:
	void initialiserBouton(int posX, int posY, int w, int h, const char* nomBouton);
	void initialiserFondBouton(int posX, int posY, int w, int h,Color color);

	void setRectangleShape(int posX, int posY, int w, int h);
	void setDimension(int w, int h);
	void setPosition(int posX, int posY);
	void setIntRect(IntRect intRect);
	void setTexture(const char* nomSprite);
	void setOutline(int thickness, Color color);
	void setToTransparent(void);
	void setText(const char* message, const char* police, int posX, int posY, int taille, const Color& color, int style);
	void setFillColor(Color color);

	bool contain(Vector2i mousePosition);

	void print(RenderWindow &window);
};