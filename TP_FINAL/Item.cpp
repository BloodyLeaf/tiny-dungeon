/*
Auteur.e.s :						Étienne Ménard
Date de création du fichier :		2020-05-06
Nom du fichier :					Item.cpp
Déclaration des méthodes de la classe Items
*/

#include "Item.h"

// Author:		Étienne Ménard
// Date:		2020-05-06
// Parameters:	none
// Return:		none
// Description:	Creates an empty debug object.
Item::Item() {
	_id = 0;
	_name = "Debug";
	_type = 0;
	_speedMod = 0;
	_defMod = 0;
	_strMod = 0;
	_dexMod = 0;
}

// Author:		Étienne Ménard
// Date:		2020-05-06
// Parameters:	name - Name of the item.
//				type - Type of the item (boots: 1, armor: 2, weapon: 3, potion: 4).
//				speedMod, defMod, strMod, dexMod - Item's stat modifiers.
// Return:		none
// Description:	Creates an empty debug object.
Item::Item(int id,  std::string name, int type, int speedMod, int defMod, int strMod, int dexMod) {
	assert(id <= INT_MAX && id >= INT_MIN);
	assert(type <= 4 && type >= 0);
	assert(speedMod <= INT_MAX && speedMod >= INT_MIN);
	assert(defMod <= INT_MAX && defMod >= INT_MIN);
	assert(strMod <= INT_MAX && strMod >= INT_MIN);
	assert(dexMod <= INT_MAX && dexMod >= INT_MIN);
	_id = id;
	_name = name;
	_type = type;
	_speedMod = speedMod;
	_defMod = defMod;
	_strMod = strMod;
	_dexMod = dexMod;
}

// Author:		Étienne Ménard
// Date:		2020-05-06
// Parameters:	none
// Return:		none
// Description:	Destroys the object.
Item::~Item() {
	_id = 0;
	_name = "";
	_speedMod = 0;
	_defMod = 0;
	_strMod = 0;
	_dexMod = 0;
}

// Getteurs
const int Item::GetID() {
	return _id;
}

const std::string Item::GetName() {
	return _name;
}

const int Item::GetType() {
	return _type;
}

const int Item::GetSpeedMod() {
	return _speedMod;
}

const int Item::GetDefenseMod() {
	return _defMod;
}

const int Item::GetStrengthMod() {
	return _strMod;
}

const int Item::GetDexterityMod() {
	return _dexMod;
}

// Setteurs
void Item::SetItem(int id, std::string name, int type, int speedMod, int defMod, int strMod, int dexMod) {
	assert(id <= INT_MAX && id >= INT_MIN);
	assert(type <= 4 && type >= 0);
	assert(speedMod <= INT_MAX && speedMod >= INT_MIN);
	assert(defMod <= INT_MAX && defMod >= INT_MIN);
	assert(strMod <= INT_MAX && strMod >= INT_MIN);
	assert(dexMod <= INT_MAX && dexMod >= INT_MIN);
	_id = id;
	_name = name;
	_type = type;
	_speedMod = speedMod;
	_defMod = defMod;
	_strMod = strMod;
	_dexMod = dexMod;
}

void Item::SetID(int id) {
	assert(id <= INT_MAX && id >= INT_MIN);
	_id = id;
}

void Item::SetName(std::string name) {
	_name = name;
}

void Item::SetType(int type) {
	assert(type <= 4 && type >= 0);
	_type = type;
}

void Item::SetSpeedMod(int speedMod) {
	assert(speedMod <= INT_MAX && speedMod >= INT_MIN);
	_speedMod = speedMod;
}

void Item::SetDefenseMod(int defMod) {
	assert(defMod <= INT_MAX && defMod >= INT_MIN);
	_defMod = defMod;
}

void Item::SetStrengthMod(int strMod) {
	assert(strMod <= INT_MAX && strMod >= INT_MIN);
	_strMod = strMod;
}

void Item::SetDexterityMod(int dexMod) {
	assert(dexMod <= INT_MAX && dexMod >= INT_MIN);
	_dexMod = dexMod;
}

// Custom Setteurs
void Item::SetBoots(std::string name, int speedMod) {
	_type = 1;
	SetName(name);
	SetSpeedMod(speedMod);
}

void Item::SetArmor(std::string name, int defMod) {
	_type = 2;
	SetName(name);
	SetDefenseMod(defMod);
}

void Item::SetStrWeapon(std::string name, int strMod) {
	_type = 3;
	SetName(name);
	SetStrengthMod(strMod);
}

void Item::SetDexWeapon(std::string name, int dexMod) {
	_type = 3;
	SetName(name);
	SetDexterityMod(dexMod);
}

void Item::SetWeapon(std::string name, int strMod, int dexMod) {
	_type = 3;
	SetName(name);
	SetStrengthMod(strMod);
	SetDexterityMod(dexMod);
}

void OpenFile(std::ifstream& file, std::string fileName) {
	file.open(fileName);

	if (!file.is_open()) {
		system("pause");
		exit(0);
	}
}

void CheckEmpty(std::ifstream& file) {
	if (file.fail()) {
		file.close();
		system("pause");
		exit(0);
	}
}

int GetLineCount(std::ifstream& file) {
	int lines = 0;
	std::string temp;
	while (!file.eof()) {
		std::getline(file, temp);
		lines++;
	}
	file.close();
	return lines;
}

void LoadItems(std::ifstream& file, std::string filePath, std::vector<Item>& item) {
	file.open(filePath);

	// Temp variables
	int id;
	std::string name;
	int type;
	int speedMod;
	int defMod;
	int strMod;
	int dexMod;

	for (int i = 0; i < item.size(); i++) {
		file >> id >> name >> type >> speedMod >> defMod >> strMod >> dexMod;
		for (int j = 0; j < name.length(); j++) {
			if (name[j] == '_') {
				name[j] = ' ';
			}
		}
		item[i].SetItem(id, name, type, speedMod, defMod, strMod, dexMod);
	}
	file.close();
}