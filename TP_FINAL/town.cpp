/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Game.h
Définition des méthode de l'objet Game
*/

#include "town.h"

void town::init(hero & hero)
{
	initBuilding();
	initHero(hero);
	initBackground();
	initMenu();
	
	updateText(hero);

	_freeUpgrade = false;
}

void town::initBuilding(void)
{
	_wallLeft.setSize(Vector2f(80,500));
	_wallLeft.setPosition(200, 380);
	_wallLeft.setFillColor(Color::White);

	_wallTop.setSize(Vector2f(600, 80));
	_wallTop.setPosition(200, 300);
	_wallTop.setFillColor(Color::White);

	_wallRight.setSize(Vector2f(80, 500));
	_wallRight.setPosition(720, 380);
	_wallRight.setFillColor(Color::White);
}

void town::initHero(hero & hero)
{
	hero.setPosition(-150, 600 );
	
}

void town::initBackground(void)
{
	_background.setSize(Vector2f(1500, 800));
	_background.setFillColor(Color::Black);
	
}

void town::initMenu(void)
{
	_optionUpgrade[0].initialiserBouton(1033, 80, 200, 100, "ressources/pv_max.png");
	

	_optionUpgrade[1].initialiserBouton(1266, 80, 200, 100, "ressources/mana_max.png");
	

	_optionUpgrade[2].initialiserBouton(1033, 260, 200, 100, "ressources/force_max.png");
	

	_optionUpgrade[3].initialiserBouton(1266, 260, 200, 100, "ressources/foi_max.png");
	

	_optionUpgrade[4].initialiserBouton(1033, 440, 200, 100, "ressources/vitesse_max.png");
	

	_optionUpgrade[5].initialiserBouton(1266, 440, 200, 100, "ressources/soins_complet.png");
	

	_optionUpgrade[6].initialiserBouton(1150, 620, 200, 100, "ressources/continuer_laventure.png");
	

	_boutonfreeUpgrade[0].initialiserBouton(1075,200,350,100,"ressources/freeHpUpg.png"); 
	_boutonfreeUpgrade[0].setOutline(5, Color::Black);

	_boutonfreeUpgrade[1].initialiserBouton(1075,350,350,100,"ressources/freeManaUpg.png");
	_boutonfreeUpgrade[1].setOutline(5, Color::Black);



	_backgroundMenu.setSize(Vector2f(500, 800));
	_backgroundMenu.setPosition(1001, 0);
	_backgroundMenu.setFillColor(Color::White);


}

void town::setText(Text& text, const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style)
{
	font.loadFromFile(police);
	text.setFont(font);
	text.setString(message);
	text.setCharacterSize(taille);
	text.setFillColor(color);
	text.setStyle(style);
	text.setPosition(posX, posY);
}

void town::setTextIntegerStats(Text& text, int stats, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style)
{

	std::string message = std::to_string(stats);
	font.loadFromFile(police);
	text.setFont(font);
	text.setString(message);
	text.setCharacterSize(taille);
	text.setFillColor(color);
	text.setStyle(style);
	text.setPosition(posX, posY);
}

void town::updateChar(int choice,hero & hero)
{
	switch (choice)
	{
	case 0:
		if (hero.getGold() >= 25) {
			hero.setGold(hero.getGold() - 25);
			hero.setMaxPv(hero.getMaxPv() + 5);
		}
		break;
	case 1:
		if (hero.getGold() >= 25) {
			hero.setGold(hero.getGold() - 25);
			hero.setMaxMana(hero.getMaxMana() + 5);
		}
		break;
	case 2:
		if (hero.getGold() >= 25) {
			hero.setGold(hero.getGold() - 25);
			hero.setStr(hero.getStr() + 1);
		}
		break;
	case 3:
		if (hero.getGold() >= 25) {
			hero.setGold(hero.getGold() - 25);
			hero.setFaith(hero.getFaith() + 1);
		}
		break;
	case 4:
		if (hero.getGold() >= 25) {
			hero.setGold(hero.getGold() - 25);
			hero.setSpeed(hero.getSpeed() + 1);
		}
		break;
	case 5:
		if (hero.getGold() >= 25) {
			hero.setGold(hero.getGold() - 25);
			hero.setPv(hero.getMaxPv());
			hero.setMana(hero.getMaxMana());
		}
		break;
	default:
		break;
	}
}

void town::updateText(hero & hero)
{
	//Pour le gold
	setText(_textGold, "Gold :", _font, "ressources/arial.ttf", 300, 15, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textGoldQty, hero.getGold(), _font, "ressources/arial.ttf", 380, 15, 24, Color::White, Text::Bold);

	//Pour les HP
	setText(_textHP, "Points de vie :", _font, "ressources/arial.ttf", 300, 50, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textCurrentHP, hero.getPv(), _font, "ressources/arial.ttf", 500, 50, 24, Color::White, Text::Bold);
	setText(_textHPDivider, " / ", _font, "ressources/arial.ttf", 525, 50, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textMaxHP, hero.getMaxPv(), _font, "ressources/arial.ttf", 550, 50, 24, Color::White, Text::Bold);

	//Pour le damage
	setText(_textDmg, "Attaque : ", _font, "ressources/arial.ttf", 300, 85, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textDmgCurrent, hero.getStr(), _font, "ressources/arial.ttf", 420, 85, 24, Color::White, Text::Bold);

	//Pour le mana
	setText(_mana, "Réserve de mana : ", _font, "ressources/arial.ttf", 300, 120, 24, Color::White, Text::Bold);
	setTextIntegerStats(_currentMana, hero.getMana(), _font, "ressources/arial.ttf", 550, 120, 24, Color::White, Text::Bold);
	setText(_manaDivider, " / ", _font, "ressources/arial.ttf", 580, 120, 24, Color::White, Text::Bold);
	setTextIntegerStats(_maxMana, hero.getMaxMana(), _font, "ressources/arial.ttf", 600, 120, 24, Color::White, Text::Bold);

	//Pour la faith

	setText(_faithText, "Foi : ", _font, "ressources/arial.ttf", 300, 155, 24, Color::White, Text::Bold);
	setTextIntegerStats(_faith, hero.getFaith(), _font, "ressources/arial.ttf", 420, 155, 24, Color::White, Text::Bold);
	//Pour le speed
	setText(_speedText, "Vitesse : ", _font, "ressources/arial.ttf", 300, 190, 24, Color::White, Text::Bold);
	setTextIntegerStats(_speed, hero.getSpeed(), _font, "ressources/arial.ttf", 420, 190, 24, Color::White, Text::Bold);
}

bool town::townAction(RenderWindow& window, hero & hero)
{

	Event event;
	int whereInSprite = 0;
	Vector2i mousePosition;
	
	townEntrance(window,hero);

	while (true) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();

			else if (event.type == Event::KeyPressed) {
				switch (event.key.code) {
				case Keyboard::Escape:
					window.close();
					break;
				
				}
			}
			else if (event.type == Event::MouseButtonPressed) {
				mousePosition = Vector2i(0, 0);
				if (event.mouseButton.button == Mouse::Left) {
					mousePosition = Mouse::getPosition(window);
					if (_freeUpgrade == false) {
						if (_boutonfreeUpgrade[0].contain(mousePosition)) {
							hero.setMaxPv(hero.getMaxPv() + hero.getStr());
							_freeUpgrade = true;
						}
						if (_boutonfreeUpgrade[1].contain(mousePosition)) {
							hero.setMaxMana(hero.getMaxMana() + hero.getFaith());
							_freeUpgrade = true;
						}
					}
					if (_freeUpgrade == true) {
						for (int i = 0; i < 6; i++) {
							if (_optionUpgrade[i].contain(mousePosition)) {
								updateChar(i, hero);
							}
						}
						if (_optionUpgrade[6].contain(mousePosition)) {
							townExit(window, hero);
							return true;
						}
					}
				}
			}
		}
		whereInSprite++;
		if (whereInSprite > 2)whereInSprite = 0;
		updateText(hero);
		hero.useAnimationIdle(whereInSprite,0);
		window.clear();
		printTown(window,hero);
		window.display();
		sleep(seconds(0.20f));
	}
}

void town::townEntrance(RenderWindow& window,hero & hero)
{
	for (int i = 0; i < 117; i++) {
		hero.setPosition(hero.getPositionX() + 5, hero.getPositionY());
		window.clear();
		printTown(window,hero);
		window.display();
	}
}

void town::townExit(RenderWindow& window,hero & hero)
{
	for (int i = 0; i < 117; i++) {
		hero.setPosition(hero.getPositionX() - 5 , hero.getPositionY());
		window.clear();
		printTown(window,hero);
		window.display();
	}
}

void town::printTown(RenderWindow& window,hero & hero)
{
	window.draw(_background);
	hero.printChar(window);
	window.draw(_wallLeft);
	window.draw(_wallTop);
	window.draw(_wallRight);

	
	window.draw(_backgroundMenu);
	if(_freeUpgrade==true){
		for (int i = 0; i < 7; i++) {
			_optionUpgrade[i].print(window);
		}
	}
	else if (_freeUpgrade == false) {
		_boutonfreeUpgrade[0].print(window);
		_boutonfreeUpgrade[1].print(window);
	}
	

	window.draw(_textGold);
	window.draw(_textGoldQty);

	window.draw(_textHP);
	window.draw(_textCurrentHP);
	window.draw(_textHPDivider);
	window.draw(_textMaxHP);

	window.draw(_textDmg);
	window.draw(_textDmgCurrent);

	window.draw(_mana);
	window.draw(_currentMana);
	window.draw(_manaDivider);
	window.draw(_maxMana);
	window.draw(_faithText);
	window.draw(_faith);
	window.draw(_speedText);
	window.draw(_speed);
}
