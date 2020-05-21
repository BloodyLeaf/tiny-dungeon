/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					MenuPrincipal.h
Déclaration des méthode de l'objet MenuPrincipal
*/
#pragma once

#include "Bouton.h"
#include "Animation.h"

class menuPrincipal {

private:

	RectangleShape _fondEcran;
	RectangleShape _fondEcranPersonnage;
	bouton poursuivre;
	bouton credits;
	bouton _boutonNouvelleAventure;
	Text _textBoutonNouvelAventure;
	Font _font;

	RectangleShape _logoAnimation;
	animation _animationIdle;

	

public:

	void initMenuPrincipal();
	void printTitle(const char* title);
	void print(RenderWindow& window);
	void loadBoutons(bouton &nomBouton, const char* message, int posX, int posY, const Color& colorText,const Color& colorOutline, int style, const char* police, int w, int h, int taillePolice);
	void setText(Text& text, const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style);
	void changeAnimation(int whereInAnimation);

	bool optionMenu(RenderWindow& window);
};