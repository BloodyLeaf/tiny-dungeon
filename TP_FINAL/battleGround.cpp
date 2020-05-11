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


	_monster[0].initPositionPersonnage(1600, 100);
	_monster[1].initPositionPersonnage(1800, 300);
	_monster[2].initPositionPersonnage(1700, 500);


	_heroHPBar.init(hero.getPositionX(),hero.getPositionY(),10,10);
	_testBarMonster[0].init(_monster[0].getPositionX(), _monster[0].getPositionY(),10,10);
	_testBarMonster[1].init(_monster[1].getPositionX(), _monster[1].getPositionY(), 10, 10);
	_testBarMonster[2].init(_monster[2].getPositionX(), _monster[2].getPositionY(), 10, 10);


	for (int i = 0; i < 3; i++) {
		_monsterColor[i] = _monster[1].getCharacterColor();
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
	_text.setPosition(_monster[0].getPositionX(),_monster[0].getPositionY() -30);
	
	Time pause = seconds(0.25f);
	for (int i = 0; i < 4; i++) {

		_monster[idMonstre].setCharColor(Color::Transparent);
		window.clear();
		printFull(window,hero);
		window.display();
		sleep(pause);

		_monster[idMonstre].setCharColor(_monsterColor[idMonstre]);
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


	bool playerAttacked = false;
	bool heroAlive = true;
	int aliveMonster = 3;
	for (int i = 0; i < 3; i++) {
		_monster[i].setMaxPv(2 + (world / 3));
		_monster[i].setPv(_monster[i].getMaxPv());
		_monster[i].setStr(1 + (world / 4));
		
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
					if(_monster[0].getPv()>0){
						_monster[0].setPv(_monster[0].getPv() - hero.getStr());
						playerAttacked = true;
						animationPlayerUpAttack(window,hero);
						checkIfDead(0, _monster[0].getPv());
						
					}
					break;
				case Keyboard::Right:
					if (_monster[1].getPv() > 0) {
						_monster[1].setPv(_monster[1].getPv() - hero.getStr());
						playerAttacked = true;
						animationPlayerMiddleAttack(window,hero);
						checkIfDead(1, _monster[1].getPv());
						
					}
					break;
				case Keyboard::Down:
					if (_monster[2].getPv() > 0) {
						_monster[2].setPv(_monster[2].getPv() - hero.getStr());
						playerAttacked = true;
						animationPlayerLowAttack(window,hero);
						checkIfDead(2, _monster[2].getPv());
						
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

					if (mousePosition.x > _monster[0].getPositionX() &&
						mousePosition.x < _monster[0].getPositionX() + _monster[0].getPositionX() )//&&
						//mousePosition.y > _monster[0].getPosition().y &&
						//mousePosition.y < _monster[0].getPosition().y + _monster[0].getSize().y)
						attack(window, 0,hero);
					
					
				}
			}
		}
		_heroHPBar.init(hero.getPositionX(), hero.getPositionY(), hero.getPv(), hero.getMaxPv());
		_testBarMonster[0].init(_monster[0].getPositionX(), _monster[0].getPositionY(), _monster[0].getPv(), _monster[0].getMaxPv());
		_testBarMonster[1].init(_monster[1].getPositionX(), _monster[1].getPositionY(), _monster[1].getPv(), _monster[1].getMaxPv());
		_testBarMonster[2].init(_monster[2].getPositionX(), _monster[2].getPositionY(), _monster[2].getPv(), _monster[2].getMaxPv());
		window.clear();
		printFull(window,hero);
		window.display();

		if (_monster[0].getPv() <= 0 && _monster[1].getPv() <= 0 && _monster[2].getPv() <= 0) {
			//animation sortir du level
			aliveMonster = 0;
			animationQuitLevel(window,hero);
			return true;
		}

		//Les monstres qui attaque [ P-A ] 

		
		if (playerAttacked == true){
			for (int i = 0; i < 3; i++) {
				if (_monster[i].getPv() > 0) {
					hero.setPv(hero.getPv() - _monster[i].getStr());
					
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
		_monster[0].initPositionPersonnage(_monster[0].getPositionX() - 6, _monster[0].getPositionY());
		_monster[1].initPositionPersonnage(_monster[1].getPositionX() - 6, _monster[1].getPositionY());
		_monster[2].initPositionPersonnage(_monster[2].getPositionX() - 6, _monster[2].getPositionY());
		hero.setPosition(hero.getPositionX() + 4, hero.getPositionY());

		window.clear();
		print(window, hero);
		window.display();

	}
}

void battleGrounds::animationMonsterAttack(RenderWindow& window, int id,hero& hero)
{
	for (int j = 0; j < 50; j++) {
		_monster[id].setPosition(_monster[id].getPositionX() - 5, _monster[id].getPositionY());
		window.clear();
		printFull(window,hero);
		window.display();
	}
	monsterAttack(window,hero);

	
	for (int j = 0; j < 50; j++) {
		_monster[id].setPosition(_monster[id].getPositionX() + 5, _monster[id].getPositionY());
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
		_monster[id].setCharColor(Color::Transparent);
		_testBarMonster[id].setToTransparent();
		_option[id].setToTransparent();
	}
}

void battleGrounds::print(RenderWindow& window,hero hero)
{
	window.draw(_background);
	_monster[0].printChar(window);
	_monster[1].printChar(window);
	_monster[2].printChar(window);
	hero.printChar(window);
	//window.draw(_text);
}

void battleGrounds::printFull(RenderWindow& window,hero hero)
{
	window.draw(_background);
	_monster[0].printChar(window);
	_monster[1].printChar(window);
	_monster[2].printChar(window);
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
