/*
Auteur(e)s :						Pier-Alexandre Caron
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					hpBar.h
D�finition des m�thode de l'objet hpBar
*/

#include "attack.h"

void attack::whichAttack(int attackID)
{

	int str=0;
	switch (attackID)
	{
	case 1:
		strAttack(str);
		break;
	default:
		break;
	}
}

void attack::strAttack(int str)
{

}
