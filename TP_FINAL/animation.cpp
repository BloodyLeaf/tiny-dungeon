/*
Auteur.e.s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Animation.h
Définition des méthode de l'objet Animation
*/

#include "Animation.h"

void animation::loadAnimationFromNotePad(std::string fileName,std::string animationName)
{
	
	std::string temp;
	int x=0, y=0, w=0, h=0;
	float posX=0, posY=0;
	std::ifstream fichierL1(fileName.c_str());
	int qqtyOfFrame;
	if(fichierL1){
		std::cout << "YES" << std::endl;
		while (!fichierL1.eof()) {
			fichierL1 >> temp;
			if (temp == animationName) {
				fichierL1 >> qqtyOfFrame;
				for (int i = 0; i < qqtyOfFrame; i++) {
					fichierL1 >> x;
					fichierL1 >> y;
					fichierL1 >> w;
					fichierL1 >> h;
					fichierL1 >> posX;
					fichierL1 >> posY;
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
