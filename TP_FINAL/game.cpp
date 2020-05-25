/*
Auteur(e)s :						Pier-Alexandre Caron
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					Game.h
D�finition des m�thode de l'objet Game
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
		case 1: //si click sur bouton Nouvelle aventure, retourne 1 
			initHero();
			_heroAlive = true;
			break;
		case 2:
			//read in sauvegarde
			//_hero.initHeroPoursuivre();
			_heroAlive = true;
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
					_hero.setGold(_hero.getGold() + 15);

				}
			}
			//write dans le fichier de sauvegarde
			//menu.writeInSauvegarde(_hero.getMaxPv, _hero.getStr, _hero.getMaxMana, _hero.getFaith, _hero.getSpeed);
		}

	}
}
