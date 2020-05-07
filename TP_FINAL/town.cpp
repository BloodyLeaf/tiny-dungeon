/*
Auteur(e)s :						Pier-Alexandre Caron
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					Game.h
D�finition des m�thode de l'objet Game
*/

#include "town.h"

void town::init(int gold,int herohp, int heroMaxHp, int dmg)
{
	initBuilding();
	initHero();
	initBackground();
	initMenu();
	//Pour le gold
	setText(_textGold, "Gold :", _font, "ressources/arial.ttf", 300, 50, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textGoldQty, gold, _font, "ressources/arial.ttf", 380, 50, 24, Color::White, Text::Bold);

	//Pour les HP
	setText(_textHP, "Points de vie :", _font, "ressources/arial.ttf", 300, 85, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textCurrentHP, herohp, _font, "ressources/arial.ttf", 500, 85, 24, Color::White, Text::Bold);
	setText(_textHPDivider, " / ", _font, "ressources/arial.ttf", 525, 85, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textMaxHP, heroMaxHp, _font, "ressources/arial.ttf", 550, 85, 24, Color::White, Text::Bold);

	setText(_textDmg, "Attaque : ", _font, "ressources/arial.ttf", 300, 120, 24, Color::White, Text::Bold);
	setTextIntegerStats(_textDmgCurrent, dmg , _font, "ressources/arial.ttf", 420, 120, 24, Color::White, Text::Bold);
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

void town::initHero(void)
{
	_hero.setSize(Vector2f(100, 100));
	_hero.setFillColor(Color::Cyan);
	_hero.setPosition(-150, 600 );
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

bool town::townAction(RenderWindow& window, int& heroHP, int& heroMaxHP, int& dmg, int& gold)
{

	Event event;
	
	
	townEntrance(window);

	while (true) {
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();

			else if (event.type == Event::KeyPressed) {
				switch (event.key.code) {
				case Keyboard::Escape:
					window.close();
					break;
				
				case Keyboard::Num1:

					dmg++;
					gold -= 25;
					updateIntegerStats(_textGoldQty, gold);
					updateIntegerStats(_textDmgCurrent, dmg);
					break;

				case Keyboard::Num2:

					heroHP += 5;
					heroMaxHP += 5;
					gold -= 25;
					updateIntegerStats(_textGoldQty, gold);
					updateIntegerStats(_textCurrentHP, heroHP);
					updateIntegerStats(_textMaxHP, heroMaxHP);
					break;

				case Keyboard::Num3:

					heroHP = heroMaxHP;
					gold -= 25;
					updateIntegerStats(_textGoldQty, gold);
					updateIntegerStats(_textCurrentHP, heroHP);
					break;

				case Keyboard::Right:

					townExit(window);
					return true;
					break;
				default:
					
					break;
				}
			}
		}

		window.clear();
		printTown(window);
		window.display();
	}
}

void town::townEntrance(RenderWindow& window)
{
	for (int i = 0; i < 117; i++) {
		_hero.setPosition(_hero.getPosition().x + 5, _hero.getPosition().y);
		window.clear();
		printTown(window);
		window.display();
	}
}

void town::townExit(RenderWindow& window)
{
	for (int i = 0; i < 117; i++) {
		_hero.setPosition(_hero.getPosition().x + 5, _hero.getPosition().y);
		window.clear();
		printTown(window);
		window.display();
	}
}

void town::printTown(RenderWindow& window)
{
	window.draw(_background);
	window.draw(_hero);
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