/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					Windows.cpp
Déclaration des méthode de l'objet Windows
*/


#include "Window.h"

void window::init(int w, int h,const char* titre)
{
	_window.create(VideoMode(w, h), titre);
}
