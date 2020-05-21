/*
Auteur.e.s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					battleGround.cpp
Déclaration des méthode de l'objet MenuPrincipal
*/

#include "battleGround.h"


//P-A
//Init beaucoup de morceau de battleground
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
	_monster[1] = generateMonster(1800, 350);
	_monster[2] = generateMonster(1700, 500);


	

	_heroHPBar.initHpBar(hero.getPositionX(),hero.getPositionY(),10,10);
	_heroManaBar.initManaBar(hero.getPositionX(), hero.getPositionY(), 10, 10);
	

	_MonsterHPBar[0].initMonsterHpBar(_monster[0].getPositionX(), _monster[0].getPositionY(),10,10);
	_MonsterHPBar[1].initMonsterHpBar(_monster[1].getPositionX(), _monster[1].getPositionY(), 10, 10);
	_MonsterHPBar[2].initMonsterHpBar(_monster[2].getPositionX(), _monster[2].getPositionY(), 10, 10);



	for (int i = 0; i < 3; i++) {
		_monsterColor[i] = _monster[1].getCharacterColor();
	}

	initMenuTarget();
	initMenuAttack();
	initMenuAction();


	setWhereInMenu(0);
	for (int i = 0; i < 4; i++) {
		_speedtimer[i] = 0;
	}
}
//P-A
//Initialise le menu des cibles
//recois void
//retourne void

void battleGrounds::initMenuTarget(void)
{
	_BackgroundMenu.setPosition(0, 625);
	_BackgroundMenu.setSize(Vector2f(1500, 200));
	_BackgroundMenu.setFillColor(Color::Color(192, 192, 192));

	_targetOption[0].initialiserBouton(150, 675, 300, 100, "ressources/attackUp.png");
	_targetOption[0].setOutline(5, Color::Black);

	_targetOption[1].initialiserBouton(600, 675, 300, 100, "ressources/attackMiddle.png");
	_targetOption[1].setOutline(5, Color::Black);

	_targetOption[2].initialiserBouton(1050, 675, 300, 100, "ressources/attackDown.png");
	_targetOption[2].setOutline(5, Color::Black);
}

//P-A
//Init tout menu des attaques
//recois void
//retourne void
void battleGrounds::initMenuAttack(void)
{
	_BackgroundMenu.setPosition(0, 625);
	_BackgroundMenu.setSize(Vector2f(1500, 200));
	_BackgroundMenu.setFillColor(Color::Color(192, 192, 192));

	_attackOption[0].initialiserBouton(40, 675, 325, 100, "ressources/strBasicAttack.png");
	_attackOption[1].initialiserBouton(405, 675, 325, 100, "ressources/dexBasicAttack.png");
	_attackOption[2].initialiserBouton(770, 675, 325, 100, "ressources/strCritAttack.png");
	_attackOption[3].initialiserBouton(1135, 675, 325, 100, "ressources/dexCriticalAttack.png");
}
//P-A
//Init tout menu des action
//recois void
//retourne void
void battleGrounds::initMenuAction(void)
{
	_BackgroundMenu.setPosition(0, 625);
	_BackgroundMenu.setSize(Vector2f(1500, 200));
	_BackgroundMenu.setFillColor(Color::Color(192, 192, 192));

	_actionOption[0].initialiserBouton(283, 675, 325, 100, "ressources/optionPotion.png");
	_actionOption[1].initialiserBouton(891, 675, 325, 100, "ressources/optionAttack.png");
}
//P-A
//Init du texte
//recois beaucoup de parametre de texte
//retourne void
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
//P-A
//Me permet de naviguer dans les menu pour en afficher des different
//recoid l'update du menu
void battleGrounds::setWhereInMenu(int choice)
{
	_whereInMenu = choice;
}
//P-A
//Initialise la bar que  je fais afficher dans le haut pour les vitesse
//Void
void battleGrounds::initSpeedBar(void)
{
	/*_speedTimer.setPosition(500, 0);
	_speedTimer.setSize(Vector2f(1000, 100));
	_speedTimer.setFillColor(Color::Color(192, 192, 192));*/
}


//P-A
//Incrémente les speed de tout le monde selon leur stats de speed
//Recois un hero
//Retourne void
void battleGrounds::addSpeed(hero hero)
{
	for (int i = 0; i < 3; i++) {
		_speedtimer[i] += _monster[i].getSpeed();
	}
	_speedtimer[3] += hero.getSpeed();
}
bool battleGrounds::heroTurn(hero & hero,RenderWindow & window)
{
	Event event;
	int target;
	
	setWhereInMenu(1);
	updateMenu(hero);
	window.clear();
	printFull(window, hero);
	window.display();
	while(true){
		while(window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			
			else if (event.type == Event::KeyPressed) {
				if (getWhereMenu() == 1) {

					switch (event.key.code) {
					case Keyboard::Escape:
						window.close();
						break;
					case Keyboard::Num1:
						//Not yet implemented 
						break;
					case Keyboard::Num2:
						setWhereInMenu(3);
						break;
					default:
						break;
					}
				}

				if (getWhereMenu() == 3) {
					switch (event.key.code) {
					case Keyboard::Escape:
						window.close();
						break;
					case Keyboard::Up:
						if (_monster[0].getPv() > 0) {
							target = 0;
							setWhereInMenu(4);

						}
						break;
					case Keyboard::Right:
						if (_monster[1].getPv() > 0) {
							target = 1;
							setWhereInMenu(4);

						}
				
						break;
					case Keyboard::Down:
						if (_monster[2].getPv() > 0) {
							target = 2;
							setWhereInMenu(4);

						}
						break;
					default:
						break;
					}
				}
				if (getWhereMenu() == 4) {
					switch (event.key.code)
					{
					case Keyboard::Num1:
						if (hero.checkIfSkillCanBeUsed(0)) {
							hero.setMana(hero.getMana() + hero.getInt());
							if (hero.getMana() > hero.getMaxMana()) hero.setMana(hero.getMaxMana());
							gestionAnimationAttaque(target, window, hero);
							hero.useAnAttack(_monster[target], 1);
							setWhereInMenu(0);
							return true;
						}
						break;
					case Keyboard::Num2:
						if (hero.checkIfSkillCanBeUsed(1)) {
							hero.setMana(hero.getMana() + hero.getInt());
							if (hero.getMana() > hero.getMaxMana()) hero.setMana(hero.getMaxMana());
							gestionAnimationAttaque(target, window, hero);
							hero.useAnAttack(_monster[target], 2);
							setWhereInMenu(0);
							return true;
						}
						break;
					case Keyboard::Num3:
						if (hero.checkIfSkillCanBeUsed(2)) {
							hero.setMana(hero.getMana() + hero.getInt());
							if (hero.getMana() > hero.getMaxMana()) hero.setMana(hero.getMaxMana());
							gestionAnimationAttaque(target, window, hero);
							hero.useAnAttack(_monster[target], 3);
							setWhereInMenu(0);
							return true;
						}
						break;
					case Keyboard::Num4:
						if (hero.checkIfSkillCanBeUsed(3)) {
							hero.setMana(hero.getMana() + hero.getInt());
							if (hero.getMana() > hero.getMaxMana()) hero.setMana(hero.getMaxMana());
							gestionAnimationAttaque(target, window, hero);
							hero.useAnAttack(_monster[target], 4);
							setWhereInMenu(0);
							return true;
						}
						break;
					default:
						break;
					}
				}
			}

			updateMenu(hero);
			replaceRessourcesBar(hero);
			window.clear();
			printFull(window, hero);
			window.display();
			
		}
	}
	
}

void battleGrounds::monsterTurn(int id, RenderWindow& window, hero& hero)
{
	monsterAttack(id, window, hero);

}
	
	
//P-A
//reajuste les bar de ressources selon les deplacements du monstres<
//Recois un hero
void battleGrounds::replaceRessourcesBar(hero hero)
{
	_heroHPBar.initHpBar(hero.getPositionX(), hero.getPositionY(), hero.getPv(), hero.getMaxPv());
	_heroManaBar.initManaBar(hero.getPositionX(), hero.getPositionY(), hero.getMana(), hero.getMaxMana());
	_MonsterHPBar[0].initMonsterHpBar(_monster[0].getPositionX(), _monster[0].getPositionY(), _monster[0].getPv(), _monster[0].getMaxPv());
	_MonsterHPBar[1].initMonsterHpBar(_monster[1].getPositionX(), _monster[1].getPositionY(), _monster[1].getPv(), _monster[1].getMaxPv());
	_MonsterHPBar[2].initMonsterHpBar(_monster[2].getPositionX(), _monster[2].getPositionY(), _monster[2].getPv(), _monster[2].getMaxPv());
}
//p-a
//Me permet de savoir je uis ou dans ce menu
//void
//void
int battleGrounds::getWhereMenu(void)
{
	return _whereInMenu;
}



//p-a et sophie
//genere les monstres au hasard ( leur size et leur couleur ) 
//recois une position x et y
//Retourne un monstre
monstre battleGrounds::generateMonster(int x , int y)
{
	srand(time(NULL));

	int indice;
	indice = rand() % 5 + 1;

	monstre monster;

	switch (indice)
	{
	case 1:
		monster.initMonster(Color::Green, 70, 70, x, y);

		return monster;
		
	case 2:
		monster.initMonster(Color::Blue, 50, 50, x, y);
		return monster;

	case 3:
		monster.initMonster(Color::Red, 100, 100, x, y);
		
		return monster;	

	case 4:
		monster.initMonster(Color::Magenta, 100, 100, x, y);
		return monster;
	case 5:
		monster.initMonster(Color::Yellow, 80, 80, x, y);
		return monster;
	default:
		break;
	}

}
void battleGrounds::monsterAttack(int id,RenderWindow& window, hero& hero)
{
	if (_monster[id].getPv() > 0) {


		animationMonsterAttack(window, id, hero);
		hero.setPv(hero.getPv() - _monster[id].getStr());
		_heroHPBar.initHpBar(hero.getPositionX(), hero.getPositionY(), hero.getPv(), hero.getMaxPv());


	}
	
}
//P-A
//Animation pour l'attaque du monstre
//recois une RenderWindoe, une id de monstre et un hero
//void
void battleGrounds::animationMonsterIsFlashing(RenderWindow& window,int idMonstre,hero& hero)
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
//P-A
//Animation du hero lorsqu'il se fait attaquer
//recois une RenderWindoe et un hero
//void
void battleGrounds::animationHeroIsFlashing(RenderWindow& window, hero& hero)
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
//P-A
//Objet principal de battleground
//Gere beaucoup de parametre ainsi que les tour d'attaque de tout le monded
//Recois une RenderWindoe, un hero et un world ( int ) 
//retourne un bool pour savoir si le personnage est mort ou vivant
bool battleGrounds::game(RenderWindow& window,hero& hero, int world)
{
	
	Event event;
	int choice=0;
	//Savoir si le joueur a choisi une attaque

	//Modifier PV et attack monstre
	int monsterhp[3];
	int monsterMaxHP = 2 + ( world/2) ;
	bool playerAttacked = false;
	bool heroAlive = true;
	int aliveMonster = 3;
	
	for (int i = 0; i < 3; i++) {
		_monster[i].setMaxPv(2 + (world / 3));
		_monster[i].setPv(_monster[i].getMaxPv());
		_monster[i].setStr(1 + (world / 4));
		
		
	}
	_monster[0].setSpeed(3 + (world / 3));
	_monster[1].setSpeed(4 + (world / 2));
	_monster[2].setSpeed(3 + (world / 2));

	int target;

	print(window,hero);
	animationLevelStart(window,hero);
	setWhereInMenu(0);
	Clock clock;
	Time time;

	while(true){
		
		
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::KeyPressed) {
				
			}
			
		} 
		
		addSpeed(hero);
		for (int i = 0; i < 4; i++) {
			if(_speedtimer[i]>=50){
				_speedtimer[i] = 0;
				if (i == 3) {
					
					
					heroTurn(hero, window);
				}
				else if (i == 0 || i == 1 || i == 2) monsterTurn(i, window, hero);
			}
		}

		
			//Fin de la méthode player Turn
			//Va devenir la méthode choose an attack
		for (int i = 0; i < 3; i++) {
			checkIfDead(i);
		}
		updateMenu(hero);
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();

		

		//Les monstres qui attaque [ P-A ] 

		

		if (_monster[0].getPv() <= 0 && _monster[1].getPv() <= 0 && _monster[2].getPv() <= 0) {
			//animation sortir du level
			aliveMonster = 0;
			animationQuitLevel(window, hero);
			return true;
		}
	
	}
}
//P-A
//Animation pour le debut du level
//recois une RenderWindoe  et un hero
//void
void battleGrounds::animationLevelStart(RenderWindow& window,hero& hero)
{
	for (int i = 0; i < 90; i++) {
		_monster[0].initPositionPersonnage(_monster[0].getPositionX() - 6, _monster[0].getPositionY());
		_monster[1].initPositionPersonnage(_monster[1].getPositionX() - 6, _monster[1].getPositionY());
		_monster[2].initPositionPersonnage(_monster[2].getPositionX() - 6, _monster[2].getPositionY());
		hero.setPosition(hero.getPositionX() + 4, hero.getPositionY());
		replaceRessourcesBar(hero);
		window.clear();
		print(window, hero);
		window.display();

	}
}
//P-A
//Animation pour le debut du level
//recois une RenderWindoe  et un hero
//void
void battleGrounds::animationMonsterAttack(RenderWindow& window, int id,hero& hero)
{
	for (int j = 0; j < 50; j++) {
		_monster[id].setPosition(_monster[id].getPositionX() - 5, _monster[id].getPositionY());
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();
	}
	animationHeroIsFlashing(window,hero);

	
	for (int j = 0; j < 50; j++) {
		_monster[id].setPosition(_monster[id].getPositionX() + 5, _monster[id].getPositionY());
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();
	}
	

}

void battleGrounds::animationPlayerUpAttack(RenderWindow& window,hero& hero)
{
	for(int i = 0 ; i <40;i++){
		hero.setPosition(hero.getPositionX(), hero.getPositionY() - 5);
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();
	}
	for(int i = 0; i < 50; i++) {
		hero.setPosition(hero.getPositionX()+5, hero.getPositionY());
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();
	}
	animationMonsterIsFlashing(window, 0,hero);
	for (int i = 0; i < 50; i++) {
		hero.setPosition(hero.getPositionX() - 5, hero.getPositionY());
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();
	}
	for (int i = 0; i < 40; i++) {
		hero.setPosition(hero.getPositionX(), hero.getPositionY() + 5);
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();
	}
}

void battleGrounds::animationPlayerMiddleAttack(RenderWindow& window,hero& hero)
{
	for (int j = 0; j < 50; j++) {
		hero.setPosition(hero.getPositionX() + 5, hero.getPositionY());
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();
	}
	animationMonsterIsFlashing(window, 1, hero);


	for (int j = 0; j < 50; j++) {
		hero.setPosition(hero.getPositionX() - 5, hero.getPositionY());
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window, hero);
		window.display();
	}
}

void battleGrounds::animationPlayerLowAttack(RenderWindow& window,hero& hero)
{
	for (int i = 0; i < 35; i++) {
		hero.setPosition(hero.getPositionX(), hero.getPositionY() + 5);
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window, hero);
		window.display();
	}
	for (int i = 0; i < 50; i++) {
		hero.setPosition(hero.getPositionX() +5, hero.getPositionY());
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window, hero);
		window.display();
	}
	animationMonsterIsFlashing(window, 2, hero);
	for (int i = 0; i < 50; i++) {
		hero.setPosition(hero.getPositionX() - 5, hero.getPositionY());
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window, hero);
		window.display();
	}
	for (int i = 0; i < 35; i++) {
		hero.setPosition(hero.getPositionX() , hero.getPositionY()-5);
		replaceRessourcesBar(hero);
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

void battleGrounds::checkIfDead(int id)
{
	if(_monster[id].getPv()==0){
		_monster[id].setCharColor(Color::Transparent);
		_MonsterHPBar[id].setToTransparent();
		_targetOption[id].setToTransparent();
	}
}

void battleGrounds::updateMenu(hero& hero)
{
	for(int i = 0 ; i<4 ; i ++){
		if (!hero.checkIfSkillCanBeUsed(i)) {
			_attackOption[i].setToTransparent();

		}
	}
}

void battleGrounds::print(RenderWindow& window,hero hero)
{
	window.draw(_background);
	_monster[0].printChar(window);
	_monster[1].printChar(window);
	_monster[2].printChar(window);
	hero.printChar(window);
	printRessourcesBar(window, hero);

}

void battleGrounds::printFull(RenderWindow& window,hero hero)
{
	window.draw(_background);
	_monster[0].printChar(window);
	_monster[1].printChar(window);
	_monster[2].printChar(window);
	hero.printChar(window);
	printRessourcesBar(window,hero);
	printSpeedIndicator(window);
	if (getWhereMenu() == 0) printOnlyBackgroundMenu(window);
	if (getWhereMenu() == 1) printActionMenu(window);
	if (getWhereMenu() == 3) printTargetMenu(window);
	if (getWhereMenu() == 4) printAttackMenu(window);
	
	
}

void battleGrounds::printTargetMenu(RenderWindow& window)
{
	window.draw(_BackgroundMenu);
	_targetOption[0].print(window);
	_targetOption[1].print(window);
	_targetOption[2].print(window);
}

void battleGrounds::printAttackMenu(RenderWindow& window)
{
	window.draw(_BackgroundMenu);
	_attackOption[0].print(window);
	_attackOption[1].print(window);
	_attackOption[2].print(window);
	_attackOption[3].print(window);
}

void battleGrounds::printActionMenu(RenderWindow& window)
{
	window.draw(_BackgroundMenu);
	_actionOption[0].print(window);
	_actionOption[1].print(window);
}

void battleGrounds::printOnlyBackgroundMenu(RenderWindow& window)
{
	window.draw(_BackgroundMenu);
}

void battleGrounds::printRessourcesBar(RenderWindow& window, hero hero)
{
	_heroHPBar.printRessourceBar(window);
	_heroManaBar.printRessourceBar(window);
	_MonsterHPBar[0].printRessourceBar(window);
	_MonsterHPBar[1].printRessourceBar(window);
	_MonsterHPBar[2].printRessourceBar(window);
}

void battleGrounds::printSpeedIndicator(RenderWindow& window)
{
	/*window.draw(_speedTimer);*/

}

void battleGrounds::gestionAnimationAttaque(int target, RenderWindow& window, hero hero)
{
	switch (target)
	{
	case 0:
		animationPlayerUpAttack(window, hero);
		break;
	case 1:
		animationPlayerMiddleAttack(window, hero);
		break;
	case 2:
		animationPlayerLowAttack(window, hero);
		break;
	default:
		break;
	}
}

/*void battleGrounds::heroTurn(void)
{

}*/
