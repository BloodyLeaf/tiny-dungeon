/*
Auteur.e.s :						Pier-Alexandre Caron
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					battleGround.cpp
D�claration des m�thode de l'objet MenuPrincipal
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
	

	setText("A �t� attaqu�", font, "ressources/arial.ttf", 800 / 2 - 100, 600 / 2 - 24, 16, Color::White, Text::Bold);



	_monster[0] = generateMonster(1600, 100);
	_monster[1] = generateMonster(1800, 300);
	_monster[2] = generateMonster(1700, 500);


	//Get position must change
	_heroHPBar.initHpBar(hero.getPositionX(),hero.getPositionY(),10,10);
	_heroManaBar.initManaBar(hero.getPositionX(), hero.getPositionY(), 10, 10);
	

	_MonsterHPBar[0].initHpBar(_monster[0].getPositionX(), _monster[0].getPositionY(),10,10);
	_MonsterHPBar[1].initHpBar(_monster[1].getPositionX(), _monster[1].getPositionY(), 10, 10);
	_MonsterHPBar[2].initHpBar(_monster[2].getPositionX(), _monster[2].getPositionY(), 10, 10);



	for (int i = 0; i < 3; i++) {
		_monsterColor[i] = _monster[1].getCharacterColor();
	}

	initMenuTarget();
	initMenuAttack();


	setTargetIsChosen(false);
}

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

void battleGrounds::setTargetIsChosen(bool choice)
{
	_targetIsChosen = choice;
}

void battleGrounds::replaceRessourcesBar(hero hero)
{
	_heroHPBar.initHpBar(hero.getPositionX(), hero.getPositionY(), hero.getPv(), hero.getMaxPv());
	_heroManaBar.initManaBar(hero.getPositionX(), hero.getPositionY(), hero.getMana(), hero.getMaxMana());
	_MonsterHPBar[0].initHpBar(_monster[0].getPositionX(), _monster[0].getPositionY(), _monster[0].getPv(), _monster[0].getMaxPv());
	_MonsterHPBar[1].initHpBar(_monster[1].getPositionX(), _monster[1].getPositionY(), _monster[1].getPv(), _monster[1].getMaxPv());
	_MonsterHPBar[2].initHpBar(_monster[2].getPositionX(), _monster[2].getPositionY(), _monster[2].getPv(), _monster[2].getMaxPv());
}

bool battleGrounds::TargetIsChosen(void)
{
	return _targetIsChosen;
}




//Doit return un monster + fix la generation dans init temporaire
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

	//Savoir si le joueur a choisi une attaque
	bool _attackIsChosen = false;

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
		_monster[i].setSpeed(4);
		
	}
	int target;
	print(window,hero);
	animationLevelStart(window,hero);
				

	while(true){
		while (window.pollEvent(event)) {
			
			if (event.type == Event::Closed) window.close();

			else if (event.type == Event::KeyPressed) {

				
				//Va devenir la m�thode playerTurn pour le targeting de la cible
				if(TargetIsChosen()==false){
					
					
					switch (event.key.code) {
						case Keyboard::Escape:
							window.close();
							break;
						case Keyboard::Up:
							if(_monster[0].getPv()>0){
								target = 0;
								setTargetIsChosen(true);
						
							}
							break;
						case Keyboard::Right:
							if (_monster[1].getPv() > 0) {
								target = 1;
								setTargetIsChosen(true);
						
							}
							break;
						case Keyboard::Down:
							if (_monster[2].getPv() > 0) {
								target = 2;
								setTargetIsChosen(true);
						
							}
				
							break;
						default : 
							_text.setFillColor(Color::White);
							break;
					}
				}
				else {
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
					switch (event.key.code)
					{
						case Keyboard::Num1 :
							if(hero.checkIfSkillCanBeUsed(0)){
								hero.useAnAttack(_monster[target], 1);
								playerAttacked = true;
								setTargetIsChosen(false);
							}
							break;
						case Keyboard::Num2:
							if (hero.checkIfSkillCanBeUsed(1)) {
								hero.useAnAttack(_monster[target], 2);
								playerAttacked = true;
								setTargetIsChosen(false);
							}
							break;
						case Keyboard::Num3:
								if (hero.checkIfSkillCanBeUsed(2)) {
								hero.useAnAttack(_monster[target], 3);
								playerAttacked = true;
								setTargetIsChosen(false);
								}
							break;
						case Keyboard::Num4:
								if (hero.checkIfSkillCanBeUsed(3)) {
								hero.useAnAttack(_monster[target], 4);
								playerAttacked = true;
								setTargetIsChosen(false);
								}
							break;
					default:
						break;
					}
				}
			}
			/*else if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					Vector2i mousePosition = Mouse::getPosition();

					if (mousePosition.x > _monster[0].getPositionX() &&
						mousePosition.x < _monster[0].getPositionX() + _monster[0].getPositionX() )//&&
						//mousePosition.y > _monster[0].getPosition().y &&
						//mousePosition.y < _monster[0].getPosition().y + _monster[0].getSize().y)
						attack(window, 0,hero);
					
					
				}
			}*/
		} 
			//Fin de la m�thode player Turn
			//Va devenir la m�thode choose an attack
		for (int i = 0; i < 3; i++) {
			checkIfDead(i);
		}
		updateMenu(hero);
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();

		

		//Les monstres qui attaque [ P-A ] 

		
		if (playerAttacked == true){
			for (int i = 0; i < 3; i++) {
				if (_monster[i].getPv() > 0) {
					hero.setPv(hero.getPv() - _monster[i].getStr());
					
					animationMonsterAttack(window, i,hero);
					_heroHPBar.initHpBar(hero.getPositionX(), hero.getPositionY(), hero.getPv(), hero.getMaxPv());

					
				}
				if (hero.getPv() == 0) {
					return false;
				}
			}
			playerAttacked = false;
		}

		if (_monster[0].getPv() <= 0 && _monster[1].getPv() <= 0 && _monster[2].getPv() <= 0) {
			//animation sortir du level
			aliveMonster = 0;
			animationQuitLevel(window, hero);
			return true;
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
		replaceRessourcesBar(hero);
		window.clear();
		print(window, hero);
		window.display();

	}
}

void battleGrounds::animationMonsterAttack(RenderWindow& window, int id,hero& hero)
{
	for (int j = 0; j < 50; j++) {
		_monster[id].setPosition(_monster[id].getPositionX() - 5, _monster[id].getPositionY());
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();
	}
	monsterAttack(window,hero);

	
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
	attack(window, 0,hero);
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
	attack(window, 1, hero);


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
	attack(window, 2, hero);
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
	if (TargetIsChosen() == false) printTargetMenu(window);
	else printAttackMenu(window);
	
	
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

void battleGrounds::printRessourcesBar(RenderWindow& window, hero hero)
{
	_heroHPBar.printRessourceBar(window);
	_heroManaBar.printRessourceBar(window);
	_MonsterHPBar[0].printRessourceBar(window);
	_MonsterHPBar[1].printRessourceBar(window);
	_MonsterHPBar[2].printRessourceBar(window);
}
