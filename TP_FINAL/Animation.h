/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Animation.h
Déclaration des méthode de l'objet Animation
*/
#pragma once


#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>

using namespace sf;

class animation {

private:
	
	std::vector<IntRect> _sprite;
	std::vector<Vector2f> _position;

public:

	void loadAnimationFromNotePad(std::string fileName, std::string animationName);

	IntRect getSprite(int whereInAnimation);
	Vector2f getPosition(int whereInAnimation);

};