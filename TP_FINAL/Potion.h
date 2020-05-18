/*
Auteur.e.s :						Étienne Ménard
Date de création du fichier :		2020-05-18
Nom du fichier :					Potion.h
Déclaration des méthodes de la classe Potion
*/

#pragma once
#include <cassert>

class Potion
{
	private:
		int	_healVal; // Valeur de 0 à 100 qui correspond au pourcentage de vie du joueur qui est gagnée.

	public:
		// Constructeurs
		Potion();
		Potion(int healVal);
		~Potion();

		// Getteurs
		const int GetHealValue();

		// Setteurs
		void SetHealValue(int healVal);

		// Méthodes custom
		void HealPlayer(int playerMaxHealth, int& playerCurrentHealth);
};

