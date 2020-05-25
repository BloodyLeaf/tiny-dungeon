/*
Auteur(e)s :						Pier-Alexandre Caron, Emily Bernier
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					MenuPrincipal.cpp
D�claration des m�thode de l'objet MenuPrincipal
*/

#include "MenuPrincipal.h"

void menuPrincipal::initMenuPrincipal()
{
	
	_fondEcran.setSize(Vector2f(1500, 800));
	_fondEcran.setFillColor(Color::White);
	_fondEcran.setPosition(0, 0);

	
	_fondEcranPersonnage.setSize(Vector2f(100, 100));
	_fondEcranPersonnage.setFillColor(Color::White);
	_fondEcranPersonnage.setPosition(700, 35);
	_fondEcranPersonnage.setOutlineThickness(5);
	_fondEcranPersonnage.setOutlineColor(Color::Color(153, 102, 51));
	

	
	_logoAnimation.setSize(Vector2f(100, 100));
	

	//_logoAnimation.setFillColor(Color::Blue);
	_animationIdle.loadAnimationFromNotePad("ressources/animation.txt", "idleMainMenu");
	changeAnimation(0);


	_boutonNouvelleAventure.initialiserFondBouton(500, 300, 500, 100, Color::Black);  
	setText(_textBoutonNouvelAventure, "Nouvelle Aventure", _font, "ressources/ShadowsIntoLight-Regular.ttf", 640, 330, 30, Color::White, Text::Bold);

}
void menuPrincipal::setText(Text& text, const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style)
{
	font.loadFromFile(police);
	text.setFont(font);
	text.setString(message);
	text.setCharacterSize(taille);
	text.setFillColor(color);
	text.setStyle(style);
	text.setPosition(posX, posY);
}
//[P-A]
//Permet de changer les sprite en cours selon un indice
//Recois un indice de ou l'animation est rendu
//Retourne Void
void menuPrincipal::changeAnimation(int whereInAnimation)
{
	
	_logoAnimation.setPosition(_animationIdle.getPosition(whereInAnimation));
	_logoAnimation.setTextureRect(_animationIdle.getSprite(whereInAnimation));
	
}

void menuPrincipal::print(RenderWindow& window)
{
	window.draw(_fondEcran);
	window.draw(_fondEcranPersonnage);
	_boutonNouvelleAventure.print(window);
	window.draw(_textTitle);
	window.draw(_textBoutonNouvelAventure);
	window.draw(_logoAnimation);
	
}

void menuPrincipal::printTitle(const char *title, RenderWindow& window) {
	setText(_textTitle, title, _font, "ressources/ShadowsIntoLight-Regular.ttf", 570, 170, 65, Color::Black, Text::Bold);

}
void menuPrincipal::loadBoutons(bouton &nomBouton, const char *message, int posX, int posY,const Color &colorText,const Color &colorOutline, int style, const char *police, int w, int h, int taillePolice) {
	nomBouton.initialiserBouton(posX, posY, w, h, message);
	nomBouton.setText(message, police, posX + 10, posY + 10, taillePolice, colorText, style);
	nomBouton.setOutline(5, colorOutline);
	nomBouton.setFillColor(Color::White);

}
// boutons du menu (nouvelle aventure, poursuivre, credits, etc..) [emily] + animation de P-A
bool menuPrincipal::optionMenu(RenderWindow& window) {
	
	Event event;
	
	int whereInAnimation=-1;

	Texture texture;
	texture.loadFromFile("ressources/hero.png");
	_logoAnimation.setTexture(&texture);

	printTitle("Tiny Dungeon", window);

	while (true) {
		while (window.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				Vector2i mousePosition = Mouse::getPosition(window);
				if (_boutonNouvelleAventure.contain(mousePosition)) {
					return true;
					//nouvelleAventure();
				}

				/*switch (event.key.code)
				{
				case Keyboard::Escape:
					window.close();
					break;
				case Keyboard::Num1:
					return true;
					break;
				case Keyboard::Num2:
					//ContinuerAventure()
					break;
				case Keyboard::Num3:

					break;
				default:
					break;
				}
				*/
			}
		}
			
		
		whereInAnimation++;
		if (whereInAnimation > 2)whereInAnimation = 0;
		changeAnimation(whereInAnimation);
		window.clear();
		print(window);
		window.display();
		sleep(seconds(0.20f));

	}
}
