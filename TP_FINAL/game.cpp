/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Game.h
Définition des méthode de l'objet Game
*/

#include "game.h"


void game::initHero(void)
{
	_hero.initHero();
	
}

void game::initGame(){
	

	_window.create(VideoMode(1500, 800), "Tiny Dungeon");
	_window.setFramerateLimit(60);
	_level = 1;
	_world = 0;
	initHero();
	initItemList();
}

void game::initItemList() {
	ifstream file;
	file.open("items.txt");

	// Temp variables
	int id;
	std::string name;
	int type;
	int speedMod;
	int defMod;
	int strMod;

	for (int i = 0; i < 30; i++) {
		file >> id >> name >> type >> speedMod >> defMod >> strMod;
		for (int j = 0; j < name.length(); j++) {
			if (name[j] == '_') {
				name[j] = ' ';
			}
		}
		_itemList[i].SetItem(id, name, type, speedMod, defMod, strMod);
	}
	file.close();
}

void game::generateLoot() {
	// Génère un loot aléatoire [Étienne]
	srand(time(NULL));
    int lootType = (rand() % 4);
    int lootIndex = (rand() % 10) + 1;

    switch (lootType)
    {
    case 0: // gagne une potion
        _hero.setPotion(_hero.getPotion() + 1);
        // sfml pour dire qu'on a une potion de plus
        break;

    case 1:
        _hero.setBoots(_itemList[lootIndex]);
        //
        break;

    case 2:
        _hero.setArmur(_itemList[lootIndex + 10]);
        //
        break;

    case 3:
        _hero.setWeapon(_itemList[lootIndex + 20]);
        //
        break;

    default:
        _hero.setPotion(_hero.getPotion() + 1);
        break;
    }
}

void game::initNewBG(void)
{
	_currentBattleGround.initBG(_hero);
}

//Boucle du jeu
void game::playGame()
{
	

	initGame();
	

	Event event;
	
	menu.initMenuPrincipal();

	while (_window.isOpen()) {
		int option= menu.optionMenu(_window);
		switch (option) {
		case 1: //si click sur bouton Nouvelle aventure, retourne 1 [em]
			initHero();
			_heroAlive = true;
			break;
		case 2:
			//read in sauvegarde
			_hero.readInSauvegarde();
			if (_hero.getPv() > 0) { 
				_heroAlive = true;
			}
			else {   //si hero = mort dans derniere partie, faire nouvelle partie
				initHero();
				_heroAlive = true;
			}
			break;

		}
		while (_window.pollEvent(event)) {
			if (event.type == Event::Closed)
				_window.close();
			int toBeat = 3 + (_world / 2);
			while (_heroAlive == true) {

				if (_level == toBeat) {

					_level = 0;
					_world++;

					_town.init(_hero);										
					_heroAlive = _town.townAction(_window, _hero);			


				}
				else {
					_currentBattleGround.initBG(_hero);
					_heroAlive = _currentBattleGround.game(_window, _hero, _world);
					_level++;
					_hero.setGold(_hero.getGold() + 35);
					generateLoot();
				}
				//write dans le fichier de sauvegarde
				_hero.writeInSauvegarde();
			}
		}

	}
}
