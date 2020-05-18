/*
Auteur.e.s :						�tienne M�nard
Date de cr�ation du fichier :		2020-05-18
Nom du fichier :					Potion.cpp
D�claration des m�thodes de la classe Potion
*/

#include "Potion.h"

Potion::Potion() {
	_healVal = 50;
}

Potion::Potion(int healVal) {
	assert(healVal >= 0 && healVal <= 100);
	_healVal = healVal;
}

Potion::~Potion() {
	_healVal = 0;
}

const int Potion::GetHealValue() {
	return _healVal;
}

void Potion::SetHealValue(int healVal) {
	assert(healVal >= 0 && healVal <= 100);
	_healVal = healVal;
}

void Potion::HealPlayer(int playerMaxHealth, int& playerCurrentHealth) {
	playerCurrentHealth += playerMaxHealth / _healVal;
}