/*
Auteur(e)s :						Pier-Alexandre Caron, Emily Bernier
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					MenuPrincipal.h
D�claration des m�thode de l'objet MenuPrincipal
*/
#pragma once

#include "Bouton.h"
#include "Animation.h"
#include <fstream>
using namespace std;

class menuPrincipal {

private:

	RectangleShape _fondEcran;
	RectangleShape _fondEcranPersonnage;

	Text _textTitle;
	bouton _poursuivre;
	Text _poursuivreText;

	bouton credits;

	bouton _boutonNouvelleAventure;
	Text _textBoutonNouvelAventure;
	Font _font;

	RectangleShape _logoAnimation;
	animation _animationIdle;

	

public:

	void initMenuPrincipal();
	void print(RenderWindow& window);
	void loadBoutons(bouton &nomBouton, const char* message, int posX, int posY, const Color& colorText,const Color& colorOutline, int style, const char* police, int w, int h, int taillePolice);
	void setText(Text& text, const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style);
	void changeAnimation(int whereInAnimation);

	void writeInSauvegarde(int pv, int maxPv, int Str, int maxMana, int Faith, int Speed, int potions, int mana);
	int readInSauvegarde();

	int optionMenu(RenderWindow& window);
};