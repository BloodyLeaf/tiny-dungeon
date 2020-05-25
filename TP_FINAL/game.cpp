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
	


	while (_window.isOpen()) {
		menu.initMenuPrincipal();
		if (menu.optionMenu(_window) == true) {  //si click sur bouton Nouvelle aventure, retourne true
			initHero();
			_heroAlive = true;
		}
		while (_window.pollEvent(event)) {
			if (event.type == Event::Closed)
				_window.close();
			int toBeat = 3 + (_world / 2);
			while (_heroAlive == true) {

				if (_level == toBeat) {

					_level = 0;
					_world++;

					_town.init(_hero);										//Refaire les méthode de town avec un hero
					_heroAlive = _town.townAction(_window, _hero);			// et non un int


				}
				else {
					_currentBattleGround.initBG(_hero);
					_heroAlive = _currentBattleGround.game(_window, _hero, _world);
					_level++;
					_hero.setGold(_hero.getGold() + 15);
					
				}
			}
			
		}

	}
}
