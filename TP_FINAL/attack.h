/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					battleGround.h
Déclaration des méthode de l'objet MenuPrincipal
*/
#pragma once

#include <SFML/Graphics.hpp>
#include "personnage.h"

using namespace sf;

class attack {
private:

	int _manaCost;
	int _modifier;
	std::string _attackName;

	

public:

	void initAttack(int manacost, int modifier,string attackName);

	
	
	void attackOnATarget(personnage& cible, int damageStats);

	int getManaCost(void);
};