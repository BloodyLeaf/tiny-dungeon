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

	setText(_textTitle, "Tiny Dungeon", _font, "ressources/ShadowsIntoLight-Regular.ttf", 570, 170, 65, Color::Black, Text::Bold);

	_boutonNouvelleAventure.initialiserFondBouton(500, 300, 500, 100, Color::Black);  
	setText(_textBoutonNouvelAventure, "Nouvelle Aventure", _font, "ressources/ShadowsIntoLight-Regular.ttf", 640, 330, 30, Color::White, Text::Bold);

	_poursuivre.initialiserFondBouton(500, 440, 500, 100, Color::Black);
	setText(_poursuivreText, "Poursuivre une aventure", _font, "ressources/ShadowsIntoLight-Regular.ttf", 600, 470, 30, Color::White, Text::Bold);

	_boutonCredits.initialiserFondBouton(500, 580, 500, 100, Color::Black);
	setText(_textBoutonCredits, "Cr�dits", _font, "ressources/ShadowsIntoLight-Regular.ttf", 700, 610, 30, Color::White, Text::Bold);


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
	_poursuivre.print(window);
	window.draw(_poursuivreText);
	window.draw(_logoAnimation);
	_boutonCredits.print(window);
	window.draw(_textBoutonCredits);
	
}

/*void menuPrincipal::loadBoutons(bouton &nomBouton, const char *message, int posX, int posY,const Color &colorText,const Color &colorOutline, int style, const char *police, int w, int h, int taillePolice) {
	nomBouton.initialiserBouton(posX, posY, w, h, message);
	nomBouton.setText(message, police, posX + 10, posY + 10, taillePolice, colorText, style);
	nomBouton.setOutline(5, colorOutline);
	nomBouton.setFillColor(Color::White);

}*/

// boutons du menu (nouvelle aventure, poursuivre, credits, etc..) [emily] + animation de P-A
int menuPrincipal::optionMenu(RenderWindow& window) {
	
	Event event;
	
	int whereInAnimation=-1;

	Texture texture;
	texture.loadFromFile("ressources/hero.png");
	_logoAnimation.setTexture(&texture);

	while (true) {
		while (window.pollEvent(event)) {
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				Vector2i mousePosition = Mouse::getPosition(window);
				//Nouvelle Aventure (1)
				if (_boutonNouvelleAventure.contain(mousePosition)) {
					return 1;
				}
				//Poursuivre
				if (_poursuivre.contain(mousePosition)) {
					return 2;
				}
				//Credits
				if (_boutonCredits.contain(mousePosition)) {
					ouvrirCredits(window);
				}
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
void menuPrincipal::ouvrirCredits(RenderWindow& window) {

	bool temp=false;

	if (!_imageCredits.loadFromFile("ressources/credits.png")) {
		exit;
	}
	_imageCredits.loadFromFile("credits.png");
	_boutonRetour.initialiserBouton(100, 100, 100, 100, "ressources/arrowBack.png");

	_fondCredits.setSize(Vector2f(1500, 800));
	_fondCredits.setTexture(&_imageCredits);

	Event event;
	while (window.waitEvent(event)) {
		Vector2i mousePosition = Mouse::getPosition(window);
			window.clear();
			window.draw(_fondCredits);
			_boutonRetour.print(window);
			window.display();
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
				if (_boutonRetour.contain(mousePosition)==true) {
					break;
				}
			}
	}
}
