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

using namespace sf;

class battleGrounds {

private: 

	RectangleShape _background;
	std::vector<int> initiative;

	RectangleShape _monster[3];
	RectangleShape _hero;

	Text _text;

	RectangleShape _BackgroundMenu;
	bouton _option[3];
	

	hpBar _heroHPBar;
	hpBar _testBarMonster[3];
	

	Color _monsterColor[3]; //Temporairement pour replacer les bonnes couleur apres les animations

public:

	void initTemporaire(void);													//Initialise la couleur du monstre et du héro

	void initMenu(void);

	//void setBackground(void);
	//void setMonster(void);
	void setInitiative(void);													//Trie le vecteur initiative en ordre décroissant pour les ordres d'attaque
	void setText(const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style);

	RectangleShape generateMonster(int x , int y);									//Genere au hasard un indice qui permet de choisir au 
																					// hasard un monstre ( carré de couleur differente for now
													

	void attack(/*int str,int strModifier,int reductionFromArmor*/RenderWindow& window, int idMonstre);				//Va devenir une méthode
	void monsterAttack(RenderWindow& window);


	void tour(void);															//Switch Case selon l'action

	bool game(RenderWindow& window,int & heroHP,const int heroMaxHP,const int dmg, int world);

	void animationLevelStart(RenderWindow& window);
	void animationMonsterAttack(RenderWindow& window, int id);
	void animationPlayerUpAttack(RenderWindow& window);
	void animationPlayerMiddleAttack(RenderWindow& window);
	void animationPlayerLowAttack(RenderWindow& window);
	void animationQuitLevel(RenderWindow& window);

	void checkIfDead(int id,int hp);

	void print(RenderWindow& window);
	void printFull(RenderWindow& window);
};