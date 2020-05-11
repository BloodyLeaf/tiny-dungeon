/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Game.h
Définition des méthode de l'objet Game
*/

#include "game.h"

void game::initHero(void)
{
	_hero.initPersonnage();
	
}

void game::initGame()
{
	initHero();
	_window.create(VideoMode(1500, 800), "Tiny Dungeon");
	_window.setFramerateLimit(60);
	_heroAlive = true;
	_level = 1;
	_world = 0;

}

void game::initNewBG(void)
{
	_currentBattleGround.initTemporaire(_hero);
}

void game::playGame(void)
{
	//Menu Principal [ P-A ] 

	initGame();

	
	int toBeat = 13 + (_world / 3);


	while (_window.isOpen())
	{
		while (_heroAlive == true) {

			if(_level == toBeat){

				_level = 0;
				_world++;

				_town.init(_hero);										//Refaire les méthode de town avec un hero
				_heroAlive = _town.townAction(_window, _hero);			// et non un int
				
				
			}
			else {
				_currentBattleGround.initTemporaire(_hero);
				_heroAlive = _currentBattleGround.game(_window,_hero, _world);
				_level++;
				_hero.setGold(_hero.getGold()+ 15);
			}

		}
		
	}

}
