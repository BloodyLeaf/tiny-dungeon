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
#include "Animation.h"

using namespace sf;

class battleGrounds {

private: 
	int _whereInSprite;
	RectangleShape _background;
	Texture _textureBackground;
	Texture _textureMonster[2];
	

	monstre _monster[3];  //3 monstre du battleground [Sophie]

	Text _text;

	RectangleShape _BackgroundMenu;
	bouton _actionOption[4];
	bouton _targetOption[3];
	bouton _attackOption[5];
	bouton _spellOption[5];
	

	RessourceBar _heroHPBar;
	RessourceBar _heroManaBar;

	RessourceBar _MonsterHPBar[3];

	RectangleShape _backgroundSpeedTimer;
	RectangleShape _speedIndicator[4];				//0 1 et 2 sont des monstres 3 et le héro
	

	Color _monsterColor[3]; //Temporairement pour replacer les bonnes couleur apres les animations
	int _whereInMenu;			//0 no menu 1 menu des action 3 menu de target 4 menu d'attaque 5 menu des sorts 6 menu de target pour les sorts
	int _speedtimer[4];			//0 a 2 monstre 3 hero

	RectangleShape _projectile;
	animation _spell[15];

	animation _heroAttackAnimation[9];
	animation _heroProjectileAnimation[6];
	animation _monsterAttack[6];
public:

	void initBG(hero& hero);													//Initialise la couleur du monstre et du héro

	void initMenuTarget(void);
	void initMenuAttack(void);
	void initMenuAction(void);
	void initMenuSpell(void);
	void initanimationSpell(void);
	void initAnimationHeroAttack(void);
	void initProjectileAnimation(void);
	void initmonsterAttackAnimation(void);
	
	void setText(const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style);
	void setWhereInMenu(int choice);												//navigation du menu : 1 Choix attaque ou consumable
																				//Choisir sa potion consommable ( a faire plus tard )[p-a]
																				//						3 Choisir sa cible
																				//						4 Choisir son attaque
	void setBackground();

	void initSpeedBar(void);
	void moveSpeedindicator(void);
	
	void addSpeed(hero hero);

	bool heroTurn(hero & hero, RenderWindow& window);
	void monsterTurn(int id, RenderWindow& window, hero& hero);

	void replaceRessourcesBar(hero hero);

	int getWhereMenu(void);

	void generateMonster(int x , int y,int monsterID);									//Genere au hasard un indice qui permet de choisir au 
																					// hasard un monstre ( carré de couleur differente for now
													
	void monsterAttack(int id,RenderWindow& window,hero & hero);
	void animationHeroIsFlashing(RenderWindow& window, hero& hero);
	

																//Switch Case selon l'action

	bool game(RenderWindow& window,hero& hero, int world);

	void animationLevelStart(RenderWindow& window, hero & hero);
	void animationMonsterAttack(RenderWindow& window, int id,hero& hero);
	void animationQuitLevel(RenderWindow& window, hero& hero);

	void checkIfDead(int id);
	void updateMenu(hero& hero);

	void print(RenderWindow& window,hero hero);
	void printFull(RenderWindow& window,hero hero);
	void printTargetMenu(RenderWindow& window);
	void printAttackMenu(RenderWindow& window);
	void printSpellMenu(RenderWindow& window);
	void printActionMenu(RenderWindow& window);
	void printOnlyBackgroundMenu(RenderWindow& window);
	void printRessourcesBar(RenderWindow& window, hero hero);
	void printSpeedIndicator(RenderWindow& window);
	void printSpell(RenderWindow& window,hero hero);

	void gestionAnimationAttaque(int target, RenderWindow& window, hero hero, int skillId);
	void gestionAnimationSpell(int target, RenderWindow& window, hero hero,int spellId);
	
	
	/*void heroTurn(void);
	void monsterTurn(void);*/
	
};