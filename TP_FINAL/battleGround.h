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
	bouton _option[3];
	

	hpBar _heroHPBar;
	hpBar _testBarMonster[3];
	

	Color _monsterColor[3]; //Temporairement pour replacer les bonnes couleur apres les animations

public:

	void initTemporaire(hero& hero);													//Initialise la couleur du monstre et du héro

	void initMenu(void);

	//void setBackground(void);
	//void setMonster(void);
	void setInitiative(void);													//Trie le vecteur initiative en ordre décroissant pour les ordres d'attaque
	void setText(const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style);

	RectangleShape generateMonster(int x , int y);									//Genere au hasard un indice qui permet de choisir au 
																					// hasard un monstre ( carré de couleur differente for now
													

	void attack(RenderWindow& window, int idMonstre,hero& hero);
	void monsterAttack(RenderWindow& window, hero& hero);


	void tour(void);															//Switch Case selon l'action

	bool game(RenderWindow& window,hero& hero, int world);

	void animationLevelStart(RenderWindow& window, hero & hero);
	void animationMonsterAttack(RenderWindow& window, int id,hero& hero);
	void animationPlayerUpAttack(RenderWindow& window, hero& hero);
	void animationPlayerMiddleAttack(RenderWindow& window, hero& hero);
	void animationPlayerLowAttack(RenderWindow& window, hero& hero);
	void animationQuitLevel(RenderWindow& window, hero& hero);

	void checkIfDead(int id,int hp);

	void print(RenderWindow& window,hero hero);
	void printFull(RenderWindow& window,hero hero);
};