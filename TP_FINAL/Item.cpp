/*
Auteur.e.s :						�tienne M�nard
Date de cr�ation du fichier :		2020-05-06
Nom du fichier :					Item.cpp
D�claration des m�thodes de la classe Items
*/

#include "Item.h"

// Author:		�tienne M�nard
// Date:		2020-05-06
// Parameters:	none
// Return:		none
// Description:	Creates an empty debug object.
Item::Item() {
	_name = "Debug";
	_type = 0;
	_speedMod = 0;
	_defMod = 0;
	_strMod = 0;
	_dexMod = 0;
}

// Author:		�tienne M�nard
// Date:		2020-05-06
// Parameters:	name - Name of the item.
//				type - Type of the item (boots: 1, armor: 2, weapon: 3, potion: 4).
//				speedMod, defMod, strMod, dexMod - Item's stat modifiers.
// Return:		none
// Description:	Creates an empty debug object.
Item::Item(std::string name, int type, int speedMod, int defMod, int strMod, int dexMod) {
	assert(type <= 4 && type >= 0);
	_name = name;
	_type = type;
	_speedMod = speedMod;
	_defMod = defMod;
	_strMod = strMod;
	_dexMod = dexMod;
}

// Author:		�tienne M�nard
// Date:		2020-05-06
// Parameters:	none
// Return:		none
// Description:	Destroys the object.
Item::~Item() {
	_name = "";
	_speedMod = 0;
	_defMod = 0;
	_strMod = 0;
	_dexMod = 0;
}

// Getteurs
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
void Item::SetItem(std::string name, int type, int speedMod, int defMod, int strMod, int dexMod) {
	_name = name;
	_type = type;
	_speedMod = speedMod;
	_defMod = defMod;
	_strMod = strMod;
	_dexMod = dexMod;
}

void Item::SetName(std::string name) {
	_name = name;
}

void Item::SetType(int type) {
	assert(type <= 4 && type >= 0);
	_type = type;
}

void Item::SetSpeedMod(int speedMod) {
	_speedMod = speedMod;
}

void Item::SetDefenseMod(int defMod) {
	_defMod = defMod;
}

void Item::SetStrengthMod(int strMod) {
	_strMod = strMod;
}

void Item::SetDexterityMod(int dexMod) {
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