/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					battleGround.h
Déclaration des méthode de l'objet MenuPrincipal
*/
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <time.h>
#include "Bouton.h"
#include "hpBar.h"
#include "Animation.h"
#include "hero.h"
#include "monstre.h"

using namespace sf;

class battleGrounds {

private: 

	RectangleShape _background;
	std::vector<int> initiative;

	monstre _monster[3];  //3 monstre du battleground [Sophie]

	Text _text;

	RectangleShape _BackgroundMenu;
	bouton _actionOption[2];
	bouton _targetOption[3];
	bouton _attackOption[4];
	

	RessourceBar _heroHPBar;
	RessourceBar _heroManaBar;

	RessourceBar _MonsterHPBar[3];

	RectangleShape _speedTimer;
	RectangleShape _speedIndicator[4];				//0 1 et 2 sont des monstres 3 et le héro
	

	Color _monsterColor[3]; //Temporairement pour replacer les bonnes couleur apres les animations
	int _whereInMenu;
	int _heroSpeedTimer;							// si reach 50 c'est son tour
	int _monsterSpeedTimer[3];					// si reach 50 c'est son tour

public:

	void initTemporaire(hero& hero);													//Initialise la couleur du monstre et du héro

	void initMenuTarget(void);
	void initMenuAttack(void);
	void initMenuAction(void);

	
	void setText(const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style);
	void setWhereInMenu(int choice);												//navigation du menu : 1 Choix attaque ou consumable
																				//Choisir sa potion consommable ( a faire plus tard )[p-a]
																				//						3 Choisir sa cible
																				//						4 Choisir son attaque
	void initSpeedBar(void);
	void moveSpeedindicator(void);

	void replaceRessourcesBar(hero hero);

	int getWhereMenu(void);

	monstre generateMonster(int x , int y);									//Genere au hasard un indice qui permet de choisir au 
																					// hasard un monstre ( carré de couleur differente for now
													

	void attack(RenderWindow& window, int idMonstre,hero& hero);
	void monsterAttack(RenderWindow& window, hero& hero);
	

																//Switch Case selon l'action

	bool game(RenderWindow& window,hero& hero, int world);

	void animationLevelStart(RenderWindow& window, hero & hero);
	void animationMonsterAttack(RenderWindow& window, int id,hero& hero);
	void animationPlayerUpAttack(RenderWindow& window, hero& hero);
	void animationPlayerMiddleAttack(RenderWindow& window, hero& hero);
	void animationPlayerLowAttack(RenderWindow& window, hero& hero);
	void animationQuitLevel(RenderWindow& window, hero& hero);

	void checkIfDead(int id);
	void updateMenu(hero& hero);

	void print(RenderWindow& window,hero hero);
	void printFull(RenderWindow& window,hero hero);
	void printTargetMenu(RenderWindow& window);
	void printAttackMenu(RenderWindow& window);
	void printActionMenu(RenderWindow& window);
	void printOnlyBackgroundMenu(RenderWindow& window);
	void printRessourcesBar(RenderWindow& window, hero hero);
	void printSpeedIndicator(RenderWindow& window);

	void gestionAnimationAttaque(int target,RenderWindow& window, hero hero);
	
	/*void heroTurn(void);
	void monsterTurn(void);*/
	
};