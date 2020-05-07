/*
Auteur.e.s :						Étienne Ménard
Date de création du fichier :		2020-05-27
Nom du fichier :					Item.h
Déclaration des méthodes de la classe Items
*/
#pragma once

#include <string>
#include <cassert>
#include <fstream>
#include <vector>

class Item
{
	private:
		int _id;
		std::string _name;	// Item's name
		int _type;			// Type of item - boots: 1, armor: 2, weapon: 3, potion 4; 		
		int _speedMod;		// Speed modifier
		int _defMod;		// Defense modifier
		int _strMod;		// Strength modifier
		int _dexMod;		// Dexterity modifier

	public:
		// Constructeurs
		Item();																						// Builds an empty debug object
		Item(int id, std::string name, int type, int speedMod, int defMod, int strMod, int dexMod);	// Builds an item with set values
		~Item();																					// Destroys the object

		// Getteurs
		const int GetID();
		const std::string GetName();
		const int GetType();
		const int GetSpeedMod();
		const int GetDefenseMod();
		const int GetStrengthMod();
		const int GetDexterityMod();

		// Setteurs
		void SetItem(int id, std::string name, int type, int speedMod, int defMod, int strMod, int dexMod);
		void SetID(int id);
		void SetName(std::string name);
		void SetType(int type);
		void SetSpeedMod(int speedMod);
		void SetDefenseMod(int defMod);
		void SetStrengthMod(int strMod);
		void SetDexterityMod(int dexMod);

		// Custom Setteurs
		void SetBoots(std::string name, int speedMod);
		void SetArmor(std::string name, int defMod);
		void SetStrWeapon(std::string name, int strMod);
		void SetDexWeapon(std::string name, int dexMod);
		void SetWeapon(std::string name, int strMod, int dexMod);
		friend void LoadItems(std::ifstream& file, std::string filePath, std::vector<Item>& item);
};

// Manipulations de fichier
void OpenFile(std::ifstream& file, std::string fileName);
void CheckEmpty(std::ifstream& file);
int GetLineCount(std::ifstream& file);

