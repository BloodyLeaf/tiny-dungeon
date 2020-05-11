/*
Auteur(e)s :						Pier-Alexandre Caron
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					MenuPrincipal.cpp
D�claration des m�thode de l'objet MenuPrincipal
*/

#include "MenuPrincipal.h"

void menuPrincipal::initMenuPrincipal()
{
	printTitle("Tiny Dungeon");
	_fondEcran.setSize(Vector2f(1500, 800));
	_fondEcran.setFillColor(Color::White);
	_fondEcran.setPosition(0, 0);

	

	
	_boutonNouvelleAventure.initialiserFondBouton(500, 100, 500, 100, Color::Black); // set un bouton position , dimension, couleur
	setText(_textBoutonNouvelAventure, "1) Nouvelle Aventure", _font, "ressources/arial.ttf", 600, 145, 24, Color::White, Text::Bold);// set du text over un bouton 

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

void menuPrincipal::print(RenderWindow& window)
{
	window.draw(_fondEcran);
	_boutonNouvelleAventure.print(window);
	window.draw(_textBoutonNouvelAventure);
	
}

void menuPrincipal::printTitle(const char *title) {

}
void menuPrincipal::loadBoutons(bouton &nomBouton, const char *message, int posX, int posY,const Color &colorText,const Color &colorOutline, int style, const char *police, int w, int h, int taillePolice) {
	nomBouton.initialiserBouton(posX, posY, w, h, message);
	nomBouton.setText(message, police, posX + 10, posY + 10, taillePolice, colorText, style);
	nomBouton.setOutline(5, colorOutline);
	nomBouton.setFillColor(Color::White);

}
bool menuPrincipal::optionMenu(RenderWindow& window) {
	
	Event event;
	while (true) {
		while (window.pollEvent(event)) {
			if (event.type == Event::KeyPressed) {
				/*if (event.type == Event::MouseButtonPressed) {
				//if (event.mouseButton.button == Mouse::Left){
					//if (mousePosition.x) {}
					nouvelleAventure();
				//}
			}*/
				switch (event.key.code)
				{
				case Keyboard::Escape:
					window.close();
					break;
				case Keyboard::Num1:
						return true;
					break;
				case Keyboard::Num2:
					//OuvrirCredits()
					break;
				default:
					break;
				}
			}
			window.clear();
			print(window);
			window.display();
		}
	}
}