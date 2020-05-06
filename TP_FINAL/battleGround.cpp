/*
Auteur.e.s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					battleGround.cpp
Déclaration des méthode de l'objet MenuPrincipal
*/

#include "battleGround.h"


//P-A
//Init tout mes private temporairement
//recois void
//retourne void
void battleGrounds::initTemporaire(void)
{
	Font font;

	_background.setSize(Vector2f(1500, 800));
	_background.setFillColor(Color::White);


	_hero.setSize(Vector2f(100, 100));
	_hero.setPosition(0, 400);
	_hero.setFillColor(Color::Cyan);

	setText("A été attaqué", font, "ressources/arial.ttf", 800 / 2 - 100, 600 / 2 - 24, 16, Color::White, Text::Bold);

	_monster[0] = generateMonster(1600, 100);
	_monster[1] = generateMonster(1800, 350);
	_monster[2] = generateMonster(1700, 550);

	//_option1.initialiserBouton();		 // Bouton qui seront cote a cote dans le bas de l'écran pour les options du combats
	//_option2.initialiserBouton();
	//_option3.initialiserBouton();
	//_option4.initialiserBouton();

	_testBar.init(_hero.getPosition().x,_hero.getPosition().y,10,10);
	_testBar2.init(_monster[0].getPosition().x, _monster[0].getPosition().y,10,10);
	_testBar3.init(_monster[1].getPosition().x, _monster[1].getPosition().y, 10, 10);
	_testBar4.init(_monster[2].getPosition().x, _monster[2].getPosition().y, 10, 10);


	for (int i = 0; i < 3; i++) {
		_monsterColor[i] = _monster[i].getFillColor();
	}

}


void battleGrounds::setInitiative(void)
{
	// Algorithme de tri + vecteur de ID de personnage
}

void battleGrounds::setText(const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style)
{
	font.loadFromFile(police);
	_text.setFont(font);
	_text.setString(message);
	_text.setCharacterSize(taille);
	_text.setFillColor(color);
	_text.setStyle(style);
	_text.setPosition(posX, posY);
}



RectangleShape battleGrounds::generateMonster(int x , int y)
{
	srand(time(NULL));

	int indice;
	indice = rand() % 6 + 1;

	RectangleShape goblin;			//green
	RectangleShape spider;			//Black
	RectangleShape fireElemental;	//red
	RectangleShape bandits;			//Magenta
	RectangleShape worm;			//yellow
	RectangleShape giantFish;		//blue

	

	switch (indice)
	{
	case 1:
		goblin.setSize(Vector2f(70, 70));
		goblin.setPosition(x, y);
		goblin.setFillColor(Color::Green);

		return goblin;
		break;

	case 2:
		spider.setSize(Vector2f(50, 50));
		spider.setPosition(x, y);
		spider.setFillColor(Color::Black);

		return spider;
		break;

	case 3:

		fireElemental.setSize(Vector2f(100, 100));
		fireElemental.setPosition(x, y);
		fireElemental.setFillColor(Color::Red);

		return fireElemental;
		break;

	case 4:

		bandits.setSize(Vector2f(100, 100));
		bandits.setPosition(x, y);
		bandits.setFillColor(Color::Magenta);

		return bandits;

		break;

	case 5:

		worm.setSize(Vector2f(80, 80));
		worm.setPosition(x, y);
		worm.setFillColor(Color::Yellow);

		return worm;
		break;

	case 6:

		giantFish.setSize(Vector2f(120, 120));
		giantFish.setPosition(x, y);
		giantFish.setFillColor(Color::Blue);

		return giantFish;
		break;

	default:
		break;
	}

}

void battleGrounds::attack(RenderWindow& window,int idMonstre)
{
	_text.setPosition(_monster[0].getPosition().x,_monster[0].getPosition().y -30);
	
	Time pause = seconds(0.25f);
	for (int i = 0; i < 4; i++) {

		_monster[idMonstre].setFillColor(Color::Transparent);
		window.clear();
		printFull(window);
		window.display();
		sleep(pause);

		_monster[idMonstre].setFillColor(_monsterColor[idMonstre]);
		window.clear();
		printFull(window);
		window.display();
		sleep(pause);
	}
}

void battleGrounds::monsterAttack(RenderWindow& window)
{
	_text.setPosition(_hero.getPosition().x, _hero.getPosition().y - 30);
	Time pause = seconds(0.25f);
	
	for (int i = 0; i < 4; i++) {
		_hero.setFillColor(Color::White);
		window.clear();
		printFull(window);
		window.display();
		sleep(pause);
		_hero.setFillColor(Color::Cyan);
		window.clear();
		printFull(window);
		window.display();
		sleep(pause);
	}

}


void battleGrounds::tour(void)
{
}

bool battleGrounds::game(RenderWindow& window, int& heroHP, const int heroMaxHP, const int dmg)
{
	

	Event event;


	int monsterhp[3];
	int monsterMaxHP[3];
	bool playerAttacked = false;
	bool heroAlive = true;
	int aliveMonster = 3;

	for (int i = 0; i < 3; i++) {
		monsterhp[i] = 2;
		monsterMaxHP[i] = 2;
	}
	
	print(window);
	animationLevelStart(window);
				

	while(true){
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();

			else if (event.type == Event::KeyPressed) {
				switch (event.key.code) {
				case Keyboard::Escape:
					window.close();
					break;
				case Keyboard::Up:
					if(monsterhp[0]>0){
						monsterhp[0] -= dmg;
						playerAttacked = true;
						animationPlayerUpAttack(window);
						checkIfDead(0, monsterhp[0]);
						
					}
					break;
				case Keyboard::Right:
					if (monsterhp[1] > 0) {
						monsterhp[1] -= dmg;
						playerAttacked = true;
						animationPlayerMiddleAttack(window);
						checkIfDead(1, monsterhp[1]);
						
					}
					break;
				case Keyboard::Down:
					if (monsterhp[2] > 0) {
						monsterhp[2] -= dmg;
						playerAttacked = true;
						animationPlayerLowAttack(window);
						checkIfDead(2, monsterhp[2]);
						
					}
				
					break;
				default : 
					_text.setFillColor(Color::White);
					break;
				}
			}
			else if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					Vector2i mousePosition = Mouse::getPosition();

					/*if (mousePosition.x > _monster[0].getPosition().x )/*&& 
						mousePosition.x < _monster[0].getPosition().x + _monster[0].getSize().x &&
						mousePosition.y > _monster[0].getPosition().y && 
						mousePosition.y < _monster[0].getPosition().y + _monster[0].getSize().y) 
						attack(window,0);*/
					
					
				}
			}
		}
		_testBar.init(_hero.getPosition().x, _hero.getPosition().y, heroHP, heroMaxHP);
		_testBar2.init(_monster[0].getPosition().x, _monster[0].getPosition().y, monsterhp[0], monsterMaxHP[0]);
		_testBar3.init(_monster[1].getPosition().x, _monster[1].getPosition().y, monsterhp[1], monsterMaxHP[1]);
		_testBar4.init(_monster[2].getPosition().x, _monster[2].getPosition().y, monsterhp[2], monsterMaxHP[2]);
		window.clear();
		printFull(window);
		window.display();

		if (monsterhp[0] <= 0 && monsterhp[1] <= 0 && monsterhp[2] <= 0) {
			//animation sortir du level
			aliveMonster = 0;
			animationQuitLevel(window);
			return true;
		}

		//Les monstres qui atttaque [ P-A ] 

		
		if (playerAttacked == true){
			for (int i = 0; i < 3; i++) {
				if (monsterhp[i] > 0) {
					heroHP--;
					
					animationMonsterAttack(window, i);
					_testBar.init(_hero.getPosition().x, _hero.getPosition().y, heroHP, heroMaxHP);

					
				}
				if (heroHP == 0) {
					return false;
				}
			}
			playerAttacked = false;
		}
	}
}

void battleGrounds::animationLevelStart(RenderWindow& window)
{
	for (int i = 0; i < 90; i++) {
		_monster[0].setPosition(_monster[0].getPosition().x - 6, _monster[0].getPosition().y);
		_monster[1].setPosition(_monster[1].getPosition().x - 6, _monster[1].getPosition().y);
		_monster[2].setPosition(_monster[2].getPosition().x - 6, _monster[2].getPosition().y);
		_hero.setPosition(_hero.getPosition().x + 4, _hero.getPosition().y);



		window.clear();
		print(window);
		window.display();

	}
}

void battleGrounds::animationMonsterAttack(RenderWindow& window, int id)
{
	for (int j = 0; j < 50; j++) {
		_monster[id].setPosition(_monster[id].getPosition().x - 5, _monster[id].getPosition().y);
		window.clear();
		printFull(window);
		window.display();
	}
	monsterAttack(window);

	
	for (int j = 0; j < 50; j++) {
		_monster[id].setPosition(_monster[id].getPosition().x + 5, _monster[id].getPosition().y);
		window.clear();
		printFull(window);
		window.display();
	}
	

}

void battleGrounds::animationPlayerUpAttack(RenderWindow& window)
{
	for(int i = 0 ; i <60;i++){
		_hero.setPosition(_hero.getPosition().x, _hero.getPosition().y - 5);
		window.clear();
		printFull(window);
		window.display();
	}
	for(int i = 0; i < 50; i++) {
		_hero.setPosition(_hero.getPosition().x+5, _hero.getPosition().y);
		window.clear();
		printFull(window);
		window.display();
	}
	attack(window, 0);
	for (int i = 0; i < 50; i++) {
		_hero.setPosition(_hero.getPosition().x - 5, _hero.getPosition().y);
		window.clear();
		printFull(window);
		window.display();
	}
	for (int i = 0; i < 60; i++) {
		_hero.setPosition(_hero.getPosition().x, _hero.getPosition().y + 5);
		window.clear();
		printFull(window);
		window.display();
	}
}

void battleGrounds::animationPlayerMiddleAttack(RenderWindow& window)
{
	for (int j = 0; j < 50; j++) {
		_hero.setPosition(_hero.getPosition().x + 5, _hero.getPosition().y);
		window.clear();
		printFull(window);
		window.display();
	}
	attack(window, 1);


	for (int j = 0; j < 50; j++) {
		_hero.setPosition(_hero.getPosition().x - 5, _hero.getPosition().y);
		window.clear();
		printFull(window);
		window.display();
	}
}

void battleGrounds::animationPlayerLowAttack(RenderWindow& window)
{
	for (int i = 0; i < 30; i++) {
		_hero.setPosition(_hero.getPosition().x, _hero.getPosition().y + 5);
		window.clear();
		printFull(window);
		window.display();
	}
	for (int i = 0; i < 50; i++) {
		_hero.setPosition(_hero.getPosition().x + 5, _hero.getPosition().y);
		window.clear();
		printFull(window);
		window.display();
	}
	attack(window, 2);
	for (int i = 0; i < 50; i++) {
		_hero.setPosition(_hero.getPosition().x - 5, _hero.getPosition().y);
		window.clear();
		printFull(window);
		window.display();
	}
	for (int i = 0; i < 30; i++) {
		_hero.setPosition(_hero.getPosition().x, _hero.getPosition().y - 5);
		window.clear();
		printFull(window);
		window.display();
	}
}

void battleGrounds::animationQuitLevel(RenderWindow& window)
{
	for (int j = 0; j < 200; j++) {
		_hero.setPosition(_hero.getPosition().x + 6, _hero.getPosition().y);
		window.clear();
		print(window);
		window.display();
	}
}

void battleGrounds::checkIfDead(int id,int hp)
{
	if (hp == 0) {
		_monster[id].setFillColor(Color::Transparent);
	}
}

void battleGrounds::print(RenderWindow& window)
{
	window.draw(_background);
	window.draw(_monster[0]);
	window.draw(_monster[1]);
	window.draw(_monster[2]);
	window.draw(_hero);
	//window.draw(_text);
}

void battleGrounds::printFull(RenderWindow& window)
{
	window.draw(_background);
	window.draw(_monster[0]);
	window.draw(_monster[1]);
	window.draw(_monster[2]);
	window.draw(_hero);
	_testBar.printHPBar(window);
	_testBar2.printHPBar(window);
	_testBar3.printHPBar(window);
	_testBar4.printHPBar(window);

}
