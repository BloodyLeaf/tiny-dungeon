/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Game.h
Définition des méthode de l'objet Game
*/

#include "game.h"

void game::initGame()
{

	_window.create(VideoMode(1500, 800), "Tiny Dungeon");
	_window.setFramerateLimit(60);
	_heroAlive = true;
	_level = 1;
	_world = 0;

}

void game::initNewBG(void)
{
	_currentBattleGround.initTemporaire();
}

void game::playGame(void)
{
	//Menu Principal [ P-A ] 

	initGame();

	int gold=0;
	int heroHP=25;
	int maxHeroHp=25;
	int dmg=1;

	while (_window.isOpen())
	{
		while (_heroAlive == true) {

			if(_level==3){

				_level = 1;
				_world++;

				_town.init();
				_heroAlive = _town.townAction(_window, heroHP, maxHeroHp, dmg,gold);
				gold += 10;
				
			}
			else {
				_currentBattleGround.initTemporaire();
				_heroAlive = _currentBattleGround.game(_window,heroHP,maxHeroHp,dmg);
				_level++;
			}

		}
		
	}

}
