/*
Auteur.e.s :						�tienne M�nard
Date de cr�ation du fichier :		2020-05-18
Nom du fichier :					Potion.h
D�claration des m�thodes de la classe Potion
*/

#pragma once
#include <cassert>

class Potion
{
	private:
		int	_healVal; // Valeur de 0 � 100 qui correspond au pourcentage de vie du joueur qui est gagn�e.

	public:
		// Constructeurs
		Potion();
		Potion(int healVal);
		~Potion();

		// Getteurs
		const int GetHealValue();

		// Setteurs
		void SetHealValue(int healVal);

		// M�thodes custom
		void HealPlayer(int playerMaxHealth, int& playerCurrentHealth);
};

