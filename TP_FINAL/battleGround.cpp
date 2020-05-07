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
void battleGrounds::initTemporaire(hero& hero)
{
	Font font;

	_background.setSize(Vector2f(1500, 800));
	_background.setFillColor(Color::White);


	
	hero.initPositionPersonnage(0, 300);
	

	setText("A été attaqué", font, "ressources/arial.ttf", 800 / 2 - 100, 600 / 2 - 24, 16, Color::White, Text::Bold);

	_monster[0] = generateMonster(1600, 100);
	_monster[1] = generateMonster(1800, 300);
	_monster[2] = generateMonster(1700, 500);


	_heroHPBar.init(hero.getPositionX(),hero.getPositionY(),10,10);
	_testBarMonster[0].init(_monster[0].getPosition().x, _monster[0].getPosition().y,10,10);
	_testBarMonster[1].init(_monster[1].getPosition().x, _monster[1].getPosition().y, 10, 10);
	_testBarMonster[2].init(_monster[2].getPosition().x, _monster[2].getPosition().y, 10, 10);


	for (int i = 0; i < 3; i++) {
		_monsterColor[i] = _monster[i].getFillColor();
	}

	initMenu();

}

void battleGrounds::initMenu(void)
{
	_BackgroundMenu.setPosition(0, 625);
	_BackgroundMenu.setSize(Vector2f(1500, 200));
	_BackgroundMenu.setFillColor(Color::Color(192, 192, 192));

	_option[0].initialiserBouton(150, 675, 300, 100, "ressources/attackUp.png");
	_option[0].setOutline(5, Color::Black);

	_option[1].initialiserBouton(600, 675, 300, 100, "ressources/attackMiddle.png");
	_option[1].setOutline(5, Color::Black);

	_option[2].initialiserBouton(1050, 675, 300, 100, "ressources/attackDown.png");
	_option[2].setOutline(5, Color::Black);
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
	indice = rand() % 5 + 1;

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
		spider.setFillColor(Color::Blue);

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


	default:
		break;
	}

}

void battleGrounds::attack(RenderWindow& window,int idMonstre,hero& hero)
{
	_text.setPosition(_monster[0].getPosition().x,_monster[0].getPosition().y -30);
	
	Time pause = seconds(0.25f);
	for (int i = 0; i < 4; i++) {

		_monster[idMonstre].setFillColor(Color::Transparent);
		window.clear();
		printFull(window,hero);
		window.display();
		sleep(pause);

		_monster[idMonstre].setFillColor(_monsterColor[idMonstre]);
		window.clear();
		printFull(window, hero);
		window.display();
		sleep(pause);
	}
}

void battleGrounds::monsterAttack(RenderWindow& window, hero& hero)
{
	_text.setPosition(hero.getPositionX(), hero.getPositionY() - 30);
	Time pause = seconds(0.25f);
	
	for (int i = 0; i < 4; i++) {
		hero.setCharColor(Color::Transparent);
		window.clear();
		printFull(window,hero);
		window.display();
		sleep(pause);
		hero.setCharColor(Color::Cyan);
		window.clear();
		printFull(window,hero);
		window.display();
		sleep(pause);
	}

}


void battleGrounds::tour(void)
{
}

bool battleGrounds::game(RenderWindow& window,hero& hero, int world)
{
	
	Event event;


	int monsterhp[3];
	int monsterMaxHP = 2 + ( world/2) ;
	bool playerAttacked = false;
	bool heroAlive = true;
	int aliveMonster = 3;
	int monsterAttack = 1 + (world / 4);
	for (int i = 0; i < 3; i++) {
		monsterhp[i] = monsterMaxHP;
		
	}
	
	print(window,hero);
	animationLevelStart(window,hero);
				

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
						monsterhp[0] -= hero.getStr();
						playerAttacked = true;
						animationPlayerUpAttack(window,hero);
						checkIfDead(0, monsterhp[0]);
						
					}
					break;
				case Keyboard::Right:
					if (monsterhp[1] > 0) {
						monsterhp[1] -= hero.getStr();
						playerAttacked = true;
						animationPlayerMiddleAttack(window,hero);
						checkIfDead(1, monsterhp[1]);
						
					}
					break;
				case Keyboard::Down:
					if (monsterhp[2] > 0) {
						monsterhp[2] -= hero.getStr();
						playerAttacked = true;
						animationPlayerLowAttack(window,hero);
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
		_heroHPBar.init(hero.getPositionX(), hero.getPositionY(), hero.getPv(), hero.getMaxPv());
		_testBarMonster[0].init(_monster[0].getPosition().x, _monster[0].getPosition().y, monsterhp[0], monsterMaxHP);
		_testBarMonster[1].init(_monster[1].getPosition().x, _monster[1].getPosition().y, monsterhp[1], monsterMaxHP);
		_testBarMonster[2].init(_monster[2].getPosition().x, _monster[2].getPosition().y, monsterhp[2], monsterMaxHP);
		window.clear();
		printFull(window,hero);
		window.display();

		if (monsterhp[0] <= 0 && monsterhp[1] <= 0 && monsterhp[2] <= 0) {
			//animation sortir du level
			aliveMonster = 0;
			animationQuitLevel(window,hero);
			return true;
		}

		//Les monstres qui atttaque [ P-A ] 

		
		if (playerAttacked == true){
			for (int i = 0; i < 3; i++) {
				if (monsterhp[i] > 0) {
					hero.setPv(hero.getPv() - monsterAttack);
					
					animationMonsterAttack(window, i,hero);
					_heroHPBar.init(hero.getPositionX(), hero.getPositionY(), hero.getPv(), hero.getMaxPv());

					
				}
				if (hero.getPv() == 0) {
					return false;
				}
			}
			playerAttacked = false;
		}
	}
}

void battleGrounds::animationLevelStart(RenderWindow& window,hero& hero)
{
	for (int i = 0; i < 90; i++) {
		_monster[0].setPosition(_monster[0].getPosition().x - 6, _monster[0].getPosition().y);
		_monster[1].setPosition(_monster[1].getPosition().x - 6, _monster[1].getPosition().y);
		_monster[2].setPosition(_monster[2].getPosition().x - 6, _monster[2].getPosition().y);
		hero.setPosition(hero.getPositionX() + 4, hero.getPositionY());



		window.clear();
		print(window, hero);
		window.display();

	}
}

void battleGrounds::animationMonsterAttack(RenderWindow& window, int id,hero& hero)
{
	for (int j = 0; j < 50; j++) {
		_monster[id].setPosition(_monster[id].getPosition().x - 5, _monster[id].getPosition().y);
		window.clear();
		printFull(window,hero);
		window.display();
	}
	monsterAttack(window,hero);

	
	for (int j = 0; j < 50; j++) {
		_monster[id].setPosition(_monster[id].getPosition().x + 5, _monster[id].getPosition().y);
		window.clear();
		printFull(window,hero);
		window.display();
	}
	

}

void battleGrounds::animationPlayerUpAttack(RenderWindow& window,hero& hero)
{
	for(int i = 0 ; i <40;i++){
		hero.setPosition(hero.getPositionX(), hero.getPositionY() - 5);
		window.clear();
		printFull(window,hero);
		window.display();
	}
	for(int i = 0; i < 50; i++) {
		hero.setPosition(hero.getPositionX()+5, hero.getPositionY());
		window.clear();
		printFull(window,hero);
		window.display();
	}
	attack(window, 0,hero);
	for (int i = 0; i < 50; i++) {
		hero.setPosition(hero.getPositionX() - 5, hero.getPositionY());
		window.clear();
		printFull(window,hero);
		window.display();
	}
	for (int i = 0; i < 40; i++) {
		hero.setPosition(hero.getPositionX(), hero.getPositionY() + 5);
		window.clear();
		printFull(window,hero);
		window.display();
	}
}

void battleGrounds::animationPlayerMiddleAttack(RenderWindow& window,hero& hero)
{
	for (int j = 0; j < 50; j++) {
		hero.setPosition(hero.getPositionX() + 5, hero.getPositionY());
		window.clear();
		printFull(window,hero);
		window.display();
	}
	attack(window, 1, hero);


	for (int j = 0; j < 50; j++) {
		hero.setPosition(hero.getPositionX() - 5, hero.getPositionY());
		window.clear();
		printFull(window, hero);
		window.display();
	}
}

void battleGrounds::animationPlayerLowAttack(RenderWindow& window,hero& hero)
{
	for (int i = 0; i < 35; i++) {
		hero.setPosition(hero.getPositionX(), hero.getPositionY() + 5);
		window.clear();
		printFull(window, hero);
		window.display();
	}
	for (int i = 0; i < 50; i++) {
		hero.setPosition(hero.getPositionX() +5, hero.getPositionY());
		window.clear();
		printFull(window, hero);
		window.display();
	}
	attack(window, 2, hero);
	for (int i = 0; i < 50; i++) {
		hero.setPosition(hero.getPositionX() - 5, hero.getPositionY());
		window.clear();
		printFull(window, hero);
		window.display();
	}
	for (int i = 0; i < 35; i++) {
		hero.setPosition(hero.getPositionX() , hero.getPositionY()-5);
		window.clear();
		printFull(window, hero);
		window.display();
	}
}

void battleGrounds::animationQuitLevel(RenderWindow& window,hero& hero)
{
	for (int j = 0; j < 200; j++) {
		hero.setPosition(hero.getPositionX() + 6, hero.getPositionY());
		window.clear();
		print(window, hero);
		window.display();
	}
}

void battleGrounds::checkIfDead(int id,int hp)
{
	if (hp == 0) {
		_monster[id].setFillColor(Color::Transparent);
		_testBarMonster[id].setToTransparent();
		_option[id].setToTransparent();
	}
}

void battleGrounds::print(RenderWindow& window,hero hero)
{
	window.draw(_background);
	window.draw(_monster[0]);
	window.draw(_monster[1]);
	window.draw(_monster[2]);
	hero.printChar(window);
	//window.draw(_text);
}

void battleGrounds::printFull(RenderWindow& window,hero hero)
{
	window.draw(_background);
	window.draw(_monster[0]);
	window.draw(_monster[1]);
	window.draw(_monster[2]);
	hero.printChar(window);
	_heroHPBar.printHPBar(window);
	_testBarMonster[0].printHPBar(window);
	_testBarMonster[1].printHPBar(window);
	_testBarMonster[2].printHPBar(window);
	window.draw(_BackgroundMenu);
	_option[0].print(window);
	_option[1].print(window);
	_option[2].print(window);
}
