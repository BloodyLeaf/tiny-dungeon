/*
Auteur(e)s :						Pier-Alexandre Caron
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					Windows.cpp
D�claration des m�thode de l'objet Windows
*/


#include "Window.h"

void window::init(int w, int h,const char* titre)
{
	_window.create(VideoMode(w, h), titre);
}
