/*
Auteur(e)s :						Pier-Alexandre Caron, Emily Bernier
Date de création du fichier :		2020-04-27
Nom du fichier :					MenuPrincipal.h
Déclaration des méthode de l'objet MenuPrincipal
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

	bouton _boutonCredits;
	Text _textBoutonCredits;
	RectangleShape _fondCredits;
	Texture _imageCredits;


	bouton _boutonNouvelleAventure;
	Text _textBoutonNouvelAventure;
	Font _font;

	bouton _boutonRetour;
	Texture _imageRetour;

	RectangleShape _logoAnimation;
	animation _animationIdle;

	

public:

	void initMenuPrincipal();
	void print(RenderWindow& window);
	//void loadBoutons(bouton &nomBouton, const char* message, int posX, int posY, const Color& colorText,const Color& colorOutline, int style, const char* police, int w, int h, int taillePolice);
	void setText(Text& text, const char* message, Font& font, const char* police, int posX, int posY, int taille, const Color& color, int style);
	void changeAnimation(int whereInAnimation);
	void ouvrirCredits(RenderWindow& window);

	int optionMenu(RenderWindow& window);
};