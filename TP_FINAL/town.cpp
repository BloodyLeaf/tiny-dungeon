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
	//Pour le gold
	setText(_textGold, "Gold :", _font, "ressources/arial.ttf", 300, 50, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textGoldQty, hero.getGold(), _font, "ressources/arial.ttf", 380, 50, 24, Color::White, Text::Bold);

	//Pour les HP
	setText(_textHP, "Points de vie :", _font, "ressources/arial.ttf", 300, 85, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textCurrentHP, hero.getPv(), _font, "ressources/arial.ttf", 500, 85, 24, Color::White, Text::Bold);
	setText(_textHPDivider, " / ", _font, "ressources/arial.ttf", 525, 85, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textMaxHP, hero.getMaxPv(), _font, "ressources/arial.ttf", 550, 85, 24, Color::White, Text::Bold);

	setText(_textDmg, "Attaque : ", _font, "ressources/arial.ttf", 300, 120, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textDmgCurrent, hero.getStr() , _font, "ressources/arial.ttf", 420, 120, 24, Color::White, Text::Bold);
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
	_option1.initialiserBouton(1100,40,300,150,"ressources/augmentAttack.png");
	_option1.setOutline(5, Color::Black);

	_option2.initialiserBouton(1100, 230, 300, 150, "ressources/augmentHP.png");
	_option2.setOutline(5, Color::Black);

	_option3.initialiserBouton(1100, 420, 300, 150, "ressources/fullHeal.png");
	_option3.setOutline(5, Color::Black);

	_option4.initialiserBouton(1100, 640, 300, 150, "ressources/nextLevel.png");
	_option4.setOutline(5, Color::Black);


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

void town::updateIntegerStats(Text& text,int newStats)
{
	std::string message = std::to_string(newStats);
	text.setString(message);
}

bool town::townAction(RenderWindow& window, hero & hero)
{

	Event event;
	
	
	townEntrance(window,hero);

	while (true) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();

			else if (event.type == Event::KeyPressed) {
				switch (event.key.code) {
				case Keyboard::Escape:
					window.close();
					break;
				
				case Keyboard::Num1:
					if (hero.getGold() >= 25) {
						hero.setStr(hero.getStr() + 1);
						hero.setGold(hero.getGold() - 25);
						updateIntegerStats(_textGoldQty, hero.getGold());
						updateIntegerStats(_textDmgCurrent, hero.getStr());
					}
					break;

				case Keyboard::Num2:
					if (hero.getGold() >= 25) {
						hero.setPv(hero.getPv() + 5);
						hero.setMaxPv(hero.getMaxPv() + 5);
						hero.setGold(hero.getGold() - 25);
						updateIntegerStats(_textGoldQty, hero.getGold());
						updateIntegerStats(_textCurrentHP, hero.getPv());
						updateIntegerStats(_textMaxHP, hero.getMaxPv());
					}
					break;

				case Keyboard::Num3:
					if (hero.getGold() >= 25) {
						hero.setPv(hero.getMaxPv());
						hero.setGold(hero.getGold() - 25);
						updateIntegerStats(_textGoldQty, hero.getGold());
						updateIntegerStats(_textCurrentHP, hero.getPv());
					}
					break;
					
				case Keyboard::Right:

					townExit(window,hero);
					return true;
					break;
				default:
					
					break;
				}
			}
		}

		window.clear();
		printTown(window,hero);
		window.display();
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
		hero.setPosition(hero.getPositionX() , hero.getPositionY());
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
	_option1.print(window);
	_option2.print(window);
	_option3.print(window);
	_option4.print(window);

	window.draw(_textGold);
	window.draw(_textGoldQty);

	window.draw(_textHP);
	window.draw(_textCurrentHP);
	window.draw(_textHPDivider);
	window.draw(_textMaxHP);

	window.draw(_textDmg);
	window.draw(_textDmgCurrent);
}
