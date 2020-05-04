/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Windows.h
Déclaration des méthode de l'objet Windows
*/
#pragma once

#include "MenuPrincipal.h"

using namespace sf;

class window {

private:
	RenderWindow _window;
	RectangleShape _fondEcran;

public:

	void init(int w, int h,const char* titre);

};