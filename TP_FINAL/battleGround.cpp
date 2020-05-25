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
void battleGrounds::initBG(hero& hero)
{
	Font font;
	_whereInSprite = 0;
	Texture texture;
	texture.loadFromFile("ressources/background.png");
	IntRect shape(0,0,1001,417);
	_background.setSize(Vector2f(1500, 800));
	//_background.setFillColor(Color::White);
	setBackground(texture,shape);


	
	hero.initPositionPersonnage(-140, 300);
	

	setText("A été attaqué", font, "ressources/arial.ttf", 800 / 2 - 100, 600 / 2 - 24, 16, Color::White, Text::Bold);



	_monster[0] = generateMonster(1600, 150);
	_monster[1] = generateMonster(1800, 300);
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
	initMenuSpell();
	initanimationSpell();

	initSpeedBar();

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

	_attackOption[0].initialiserBouton(100, 675, 180, 100,"ressources/str1.png");
	_attackOption[1].initialiserBouton(380, 675, 180, 100, "ressources/str2.png");
	_attackOption[2].initialiserBouton(660, 675, 180, 100, "ressources/str3.png");
	_attackOption[3].initialiserBouton(940, 675, 180, 100, "ressources/str4.png");
	_attackOption[4].initialiserBouton(1220, 675, 180, 100, "ressources/str5.png");
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

	_actionOption[0].initialiserBouton(100, 675, 250, 100, "ressources/optionPotion.png");
	_actionOption[1].initialiserBouton(450, 675, 250, 100, "ressources/optionAttack.png");
	_actionOption[2].initialiserBouton(800, 675, 250, 100, "ressources/optionPray.png");
	_actionOption[3].initialiserBouton(1150, 675, 250, 100, "ressources/optionCastSpell.png");
}

//P-A
//Init menu des sorts
//recois void
//retourne void
void battleGrounds::initMenuSpell(void)
{
	_BackgroundMenu.setPosition(0, 625);
	_BackgroundMenu.setSize(Vector2f(1500, 200));
	_BackgroundMenu.setFillColor(Color::Color(192, 192, 192));

	_spellOption[0].initialiserBouton(100, 675, 180, 100, "ressources/spell1.png");
	_spellOption[1].initialiserBouton(380, 675, 180, 100, "ressources/spell2.png");
	_spellOption[2].initialiserBouton(660, 675, 180, 100, "ressources/spell3.png");
	_spellOption[3].initialiserBouton(940, 675, 180, 100, "ressources/spell4.png");
	_spellOption[4].initialiserBouton(1220, 675, 180, 100, "ressources/spell5.png");

}

void battleGrounds::initanimationSpell(void)
{

	_spell[0].loadAnimationFromNotePad("ressources/animationSpell.txt", "windScytheUp");
	_spell[1].loadAnimationFromNotePad("ressources/animationSpell.txt", "windScytheMid");
	_spell[2].loadAnimationFromNotePad("ressources/animationSpell.txt", "windScytheDown");

	_spell[3].loadAnimationFromNotePad("ressources/animationSpell.txt", "fireInvocationUp");
	_spell[4].loadAnimationFromNotePad("ressources/animationSpell.txt", "fireInvocationMid");
	_spell[5].loadAnimationFromNotePad("ressources/animationSpell.txt", "fireInvocationDown");

	_spell[6].loadAnimationFromNotePad("ressources/animationSpell.txt", "thunderUp");
	_spell[7].loadAnimationFromNotePad("ressources/animationSpell.txt", "thunderMid");
	_spell[8].loadAnimationFromNotePad("ressources/animationSpell.txt", "thunderDown");

	_spell[9].loadAnimationFromNotePad("ressources/animationSpell.txt", "divineFireUp");
	_spell[10].loadAnimationFromNotePad("ressources/animationSpell.txt", "divineFireMid");
	_spell[11].loadAnimationFromNotePad("ressources/animationSpell.txt", "divineFireDown");

	_spell[12].loadAnimationFromNotePad("ressources/animationSpell.txt", "divinePresenceUp");
	_spell[13].loadAnimationFromNotePad("ressources/animationSpell.txt", "divinePresenceMid");
	_spell[14].loadAnimationFromNotePad("ressources/animationSpell.txt", "divinePresenceDown");
}
void battleGrounds::initAnimationHeroAttack(void)
{
	_heroAttackAnimation[0].loadAnimationFromNotePad("ressources/heroAttack.txt", "basicAttackUp");
	_heroAttackAnimation[1].loadAnimationFromNotePad("ressources/heroAttack.txt", "basicAttackMid");
	_heroAttackAnimation[2].loadAnimationFromNotePad("ressources/heroAttack.txt", "basicAttackTop");
	_heroAttackAnimation[3].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
	_heroAttackAnimation[4].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
	_heroAttackAnimation[5].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
	_heroAttackAnimation[6].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
	_heroAttackAnimation[7].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
	_heroAttackAnimation[8].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
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
void battleGrounds::setBackground(Texture& texture,IntRect& shape)
{
	_background.setTexture(&texture);
	_background.setTextureRect(shape);
}
//P-A
//Initialise la bar que  je fais afficher dans le haut pour les vitesse
//Void
void battleGrounds::initSpeedBar(void)
{
	_backgroundSpeedTimer.setPosition(250, 0);
	_backgroundSpeedTimer.setSize(Vector2f(1000, 60));
	_backgroundSpeedTimer.setFillColor(Color::Black);

	for (int i = 0; i < 4; i++) {
		_speedIndicator[i].setPosition(250, 4 + ( i * 14));
		_speedIndicator[i].setSize(Vector2f(0, 10));
	}
	for (int i = 0; i < 3; i++) {
		_speedIndicator[i].setFillColor(Color::Red);
	}
	_speedIndicator[3].setFillColor(Color::Cyan);
}

void battleGrounds::moveSpeedindicator(void)
{
	float w;
	for (int i = 0; i < 4; i++) {
		w = 20*_speedtimer[i];
		if (w > 1000)w = 1000;
		_speedIndicator[i].setSize(Vector2f(w, 10));
	}
}


//P-A
//Incrémente les speed de tout le monde selon leur stats de speed
//Recois un hero
//Retourne void
void battleGrounds::addSpeed(hero hero)
{
	for (int i = 0; i < 3; i++) {
		if (_monster[i].getPv() > 0) {
			_speedtimer[i] += _monster[i].getSpeed();
		}
		
	}
	_speedtimer[3] += hero.getSpeed();
}
bool battleGrounds::heroTurn(hero & hero,RenderWindow & window)
{
	Event event;
	int target;
	
	setWhereInMenu(1);
	moveSpeedindicator();
	updateMenu(hero);
	window.clear();
	printFull(window, hero);
	window.display();

	Vector2i mousePosition;

	while(true){
		while(window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			else if (event.type == Event::MouseButtonPressed) {
				mousePosition = Vector2i(0, 0);
				if (event.mouseButton.button == Mouse::Left ){
					mousePosition = Mouse::getPosition(window);
					if (getWhereMenu() == 1) {

						//Option pour choisir son type d'action
						if (_actionOption[0].contain(mousePosition)) {
							
							
						}
						
						if (_actionOption[1].contain(mousePosition)) {
							setWhereInMenu(3);
							mousePosition = Vector2i(0, 0);
						}
						if (_actionOption[2].contain(mousePosition)) {
							hero.setPv(hero.getPv() +  ( hero.getFaith()));
							hero.setMana(hero.getMana() + 2 * (hero.getFaith()));
							mousePosition = Vector2i(0, 0);
							return true;

							//Add animation to show it healed
						}
						if (_actionOption[3].contain(mousePosition)) {
							setWhereInMenu(6);
							mousePosition = Vector2i(0, 0);
						}
					}
					//Option pour choisir un monstre 
					if (getWhereMenu() == 3) {
						if (_targetOption[0].contain(mousePosition)) {
							if (_monster[0].getPv() > 0) {
								target = 0;
								setWhereInMenu(4);
								mousePosition = Vector2i(0, 0);
							}
						}
						if (_targetOption[1].contain(mousePosition)) {
							if (_monster[1].getPv() > 0) {
								target = 1;
								setWhereInMenu(4);
								mousePosition = Vector2i(0, 0);
							}
						}
						if (_targetOption[2].contain(mousePosition)) {
							if (_monster[2].getPv() > 0) {
								target = 2;
								setWhereInMenu(4);
								mousePosition = Vector2i(0, 0);
							}
						}
					}
					
					if (getWhereMenu() == 4) {

						if (_attackOption[0].contain(mousePosition)) {

							if (hero.checkIfSkillCanBeUsed(0)) {
								
								
								gestionAnimationAttaque(target, window, hero,0);
								hero.useAnAttack(_monster[target], 0);
								setWhereInMenu(0);
								hero.setMana(hero.getMana() + hero.getFaith());
								if (hero.getMana() > hero.getMaxMana()) hero.setMana(hero.getMaxMana());
								return true;
							}
						}
						if (_attackOption[1].contain(mousePosition)) {

							if (hero.checkIfSkillCanBeUsed(1)) {
								
								
								gestionAnimationAttaque(target, window, hero,1);
								hero.useAnAttack(_monster[target], 1);
								setWhereInMenu(0);
								return true;
							}
						}
						if (_attackOption[2].contain(mousePosition)) {

							if (hero.checkIfSkillCanBeUsed(2)) {
								
								
								gestionAnimationAttaque(target, window, hero,2);
								hero.useAnAttack(_monster[target], 2);
								setWhereInMenu(0);
								return true;
							}
						}
						if (_attackOption[3].contain(mousePosition)) {

							if (hero.checkIfSkillCanBeUsed(3)) {
								
								
								gestionAnimationAttaque(target, window, hero,1);
								hero.useAnAttack(_monster[target], 3);
								setWhereInMenu(0);
								return true;
							}
						}
						if (_attackOption[4].contain(mousePosition)) {

							if (hero.checkIfSkillCanBeUsed(4)) {
								
								
								gestionAnimationAttaque(target, window, hero,2);
								hero.useAnAttack(_monster[target], 4);
								setWhereInMenu(0);
								return true;
							}
						}
					}
					if (getWhereMenu() == 5) {

						if (_spellOption[0].contain(mousePosition)) {

							if (hero.checkIfSpellCanBeUsed(0)) {
								
							
								setWhereInMenu(0);
								gestionAnimationSpell(target, window, hero,0);
								hero.useASpell(_monster[target], 0);
								
								return true;
							}
						}
						if (_spellOption[1].contain(mousePosition)) {

							if (hero.checkIfSpellCanBeUsed(1)) {
								
								
								setWhereInMenu(0);
								gestionAnimationSpell(target, window, hero,1);
								hero.useASpell(_monster[target], 1);
								
								return true;
							}
						}
						if (_spellOption[2].contain(mousePosition)) {

							if (hero.checkIfSpellCanBeUsed(2)) {
								
								
								setWhereInMenu(0);
								gestionAnimationSpell(target, window, hero,2);
								hero.useASpell(_monster[target], 2);
								
								return true;
							}
						}
						if (_spellOption[3].contain(mousePosition)) {

							if (hero.checkIfSpellCanBeUsed(3)) {
								
								
								setWhereInMenu(0);
								gestionAnimationSpell(target, window, hero,3);
								hero.useASpell(_monster[target], 3);
								
								return true;
							}
						}
						if (_spellOption[4].contain(mousePosition)) {

							if (hero.checkIfSpellCanBeUsed(4)) {
								
								
								setWhereInMenu(0);
								gestionAnimationSpell(target, window, hero,4);
								hero.useASpell(_monster[target], 4);
								
								return true;
							}
						}
					}
					if (getWhereMenu() == 6) {
						if (_targetOption[0].contain(mousePosition)) {
							if (_monster[0].getPv() > 0) {
								target = 0;
								setWhereInMenu(5);

							}
						}
						if (_targetOption[1].contain(mousePosition)) {
							if (_monster[1].getPv() > 0) {
								target = 1;
								setWhereInMenu(5);

							}
						}
						if (_targetOption[2].contain(mousePosition)) {
							if (_monster[2].getPv() > 0) {
								target = 2;
								setWhereInMenu(5);

							}
						}
					}
				}
			}
			

			
		}

		_whereInSprite++;
		if (_whereInSprite > 2)_whereInSprite = 0;
		hero.useAnimationIdle(_whereInSprite, 1);
		moveSpeedindicator();
		updateMenu(hero);
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window, hero);
		window.display();
		sf::sleep(seconds(0.10f));
		
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
		sf::sleep(pause);

		_monster[idMonstre].setCharColor(_monsterColor[idMonstre]);
		window.clear();
		printFull(window, hero);
		window.display();
		sf::sleep(pause);
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
		hero.setIntRect(IntRect(120,235,43,43));
		window.clear();
		printFull(window,hero);
		window.display();
		sf::sleep(pause);
		hero.setIntRect(IntRect(460, 236, 43, 43));
		window.clear();
		printFull(window,hero);
		window.display();
		sf::sleep(pause);
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
	
	_monster[0].setSpeed(3 + (world / 3));
	_monster[1].setSpeed(4 + (world / 2));
	_monster[2].setSpeed(3 + (world / 2));
	_monster[0].setMaxPv(2 + (world / 2));
	_monster[1].setMaxPv(3 + (world / 3));
	_monster[2].setMaxPv(4 + (world / 4));
	_monster[0].setStr(1 + (world / 2));
	_monster[1].setStr(2 + (world / 2));
	_monster[2].setStr(2 + (world / 3));
	for (int i = 0; i < 3; i++) {
		
		_monster[i].setPv(_monster[i].getMaxPv());
		
		
		
	}
	

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
		
		
		for (int i = 0; i < 4; i++) {
			if(_speedtimer[i]>=50){
				
				if (i == 3) {
					
					
					heroTurn(hero, window);
				}
				else if (i == 0 || i == 1 || i == 2) monsterTurn(i, window, hero);
				if (hero.getPv() <= 0)return false;
				_speedtimer[i] = 0;
			}
		}

		
			//Fin de la méthode player Turn
			//Va devenir la méthode choose an attack
		for (int i = 0; i < 3; i++) {
			checkIfDead(i);
		}

		addSpeed(hero);
		_whereInSprite++;
		if (_whereInSprite > 2)_whereInSprite = 0;
		hero.useAnimationIdle(_whereInSprite, 1);
		moveSpeedindicator();
		updateMenu(hero);
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();
		sf::sleep(seconds(0.1f));
		


		

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
	for (int i = 0; i < 125; i++) {
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
	for (int j = 0; j < 15; j++) {
		_monster[id].setPosition(_monster[id].getPositionX() - 14, _monster[id].getPositionY());

		_whereInSprite++;
		if (_whereInSprite > 2)_whereInSprite = 0;
		hero.useAnimationIdle(_whereInSprite, 1);
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();
		sf::sleep(seconds(0.1f));
	}
	animationHeroIsFlashing(window,hero);

	
	for (int j = 0; j < 15; j++) {
		_monster[id].setPosition(_monster[id].getPositionX() + 14, _monster[id].getPositionY());

		_whereInSprite++;
		if (_whereInSprite > 2)_whereInSprite = 0;
		hero.useAnimationIdle(_whereInSprite, 1);
		replaceRessourcesBar(hero);
		window.clear();
		printFull(window,hero);
		window.display();
		sf::sleep(seconds(0.1f));
	}
	

}

void battleGrounds::animationPlayerUpAttack(RenderWindow& window,hero& hero)
{
	for(int i = 0 ; i <30;i++){
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
	for (int i = 0; i < 30; i++) {
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
		replaceRessourcesBar(hero);
		window.clear();
		print(window, hero);
		window.display();
	}
}

void battleGrounds::checkIfDead(int id)
{
	if(_monster[id].getPv()<=0){
		_monster[id].setCharColor(Color::Transparent);
		_MonsterHPBar[id].setToTransparent();
		
		_targetOption[id].setToTransparent();
		_speedtimer[id] = 0;
	}
}

void battleGrounds::updateMenu(hero& hero)
{
	for(int i = 0 ; i<5 ; i ++){
		if (!hero.checkIfSkillCanBeUsed(i)) {
			_attackOption[i].setToTransparent();

		}
		if (hero.checkIfSkillCanBeUsed(i)) {
			_attackOption[i].setDimension(180, 100);
		}
	}
	for (int i = 0; i < 5; i++) {
		if (!hero.checkIfSpellCanBeUsed(i)) {
			_spellOption[i].setToTransparent();

		}
		if (hero.checkIfSpellCanBeUsed(i)) {
			_spellOption[i].setDimension(180, 100);
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
	if (getWhereMenu() == 6) printTargetMenu(window);
	if (getWhereMenu() == 4) printAttackMenu(window);
	if (getWhereMenu() == 5) printSpellMenu(window);
	
	
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
	_attackOption[4].print(window);
}

void battleGrounds::printSpellMenu(RenderWindow& window)
{
	window.draw(_BackgroundMenu);
	_spellOption[0].print(window);
	_spellOption[1].print(window);
	_spellOption[2].print(window);
	_spellOption[3].print(window);
	_spellOption[4].print(window);
}

void battleGrounds::printActionMenu(RenderWindow& window)
{
	window.draw(_BackgroundMenu);
	_actionOption[0].print(window);
	_actionOption[1].print(window);
	_actionOption[2].print(window);
	_actionOption[3].print(window);
}

void battleGrounds::printOnlyBackgroundMenu(RenderWindow& window)
{
	window.draw(_BackgroundMenu);
}

void battleGrounds::printRessourcesBar(RenderWindow& window, hero hero)
{
	_heroHPBar.printRessourceBar(window);
	_heroManaBar.printRessourceBar(window);
	for(int i = 0 ; i < 3 ; i ++ ){
		if (_monster[i].getPv() > 0) {
			_MonsterHPBar[i].printRessourceBar(window);
		}
	}
	
}

void battleGrounds::printSpeedIndicator(RenderWindow& window)
{
	window.draw(_backgroundSpeedTimer);
	for (int i = 0; i < 4; i++) {
		window.draw(_speedIndicator[i]);
	}
}

void battleGrounds::printSpell(RenderWindow& window,hero hero)
{
	printFull(window, hero);
	window.draw(_projectile);
}

void battleGrounds::gestionAnimationAttaque(int target, RenderWindow& window, hero hero,int skillID)
{
	int indiceSkillTouse = (skillID * 3) + target;
	int nbFrame = _heroAttackAnimation[indiceSkillTouse].getNbFrame();

	for (int i = 0; i < nbFrame; i++) {
		window.clear();
		hero.setPositionWithVector2f(_heroAttackAnimation[indiceSkillTouse].getPosition(i));
		hero.setSize(_heroAttackAnimation[indiceSkillTouse].getSize(i));
		hero.setIntRect(_heroAttackAnimation[indiceSkillTouse].getSprite(i));
		printFull(window, hero);
		window.display();
		sf::sleep(seconds(0.1f));
	}
}

void battleGrounds::gestionAnimationSpell(int target, RenderWindow& window, hero hero,int spellId)
{
	int indiceSpellToCast = (spellId * 3) + target;
	int nbFrame = _spell[indiceSpellToCast].getNbFrame();
	Texture texture;
	switch (spellId)
	{
	case 0:
		texture.loadFromFile("ressources/windScythe.png");
		break;
	case 1:
		texture.loadFromFile("ressources/fireInvocation.png");
		break;
	case 2:
		texture.loadFromFile("ressources/thunderSummon.png");
		break;
	case 3:
		texture.loadFromFile("ressources/divineFire.png");
		break;
	case 4:
		texture.loadFromFile("ressources/divinePresence.png");
		break;
	default:
		break;
	}
	_projectile.setTexture(&texture);

	for (int i = 0; i < nbFrame; i++) {
		window.clear();
		_projectile.setSize(_spell[indiceSpellToCast].getSize(i));
		_projectile.setPosition(_spell[indiceSpellToCast].getPosition(i));
		_projectile.setPosition(_projectile.getPosition().x+ 100, _projectile.getPosition().y);
		_projectile.setTextureRect(_spell[indiceSpellToCast].getSprite(i));
		printSpell(window, hero);
		window.display();
		sf::sleep(seconds(0.1f));
	}
	_projectile.setSize(Vector2f(0, 0));
}



/*void battleGrounds::heroTurn(void)
{

}*/
