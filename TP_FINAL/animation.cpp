/*
Auteur.e.s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Animation.h
Définition des méthode de l'objet Animation
*/

#include "Animation.h"

void animation::loadAnimationFromNotePad(std::string fileName,std::string animationName)
{
	char delimiter(';');
	std::string temp;
	int x, y, w, h;
	float posX, posY;
	std::ifstream fichierL1(fileName.c_str());
	int qqtyOfFrame;
	if(fichierL1){
		std::cout << "YES" << std::endl;
		while (!fichierL1.eof()) {
			getline(fichierL1, temp,delimiter);
			if (temp.compare(animationName)) {
				getline(fichierL1, temp, delimiter);
				qqtyOfFrame = std::stoi(temp);
				for (int i = 0; i < 3; i++) {
					getline(fichierL1, temp, delimiter);
					x = std::stoi(temp);
					getline(fichierL1, temp, delimiter);
					y = std::stoi(temp);
					getline(fichierL1, temp, delimiter);
					w = std::stoi(temp);
					getline(fichierL1, temp, delimiter);
					h = std::stoi(temp);
					getline(fichierL1, temp, delimiter);
					posX = std::stof(temp);
					getline(fichierL1, temp, delimiter);
					posY = std::stof(temp);

					_sprite.push_back(IntRect(x, y, w, h));
					_position.push_back(Vector2f(posX, posY));
				}
			}
		}
	}
	else {
		std::cout << "FUCK" << std::endl;
	}
	

	

}

IntRect animation::getSprite(int whereInAnimation)
{
	return _sprite.at(whereInAnimation);
}

Vector2f animation::getPosition(int whereInAnimation)
{
	return _position.at(whereInAnimation);
}
