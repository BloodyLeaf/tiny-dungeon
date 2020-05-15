/*
Auteur(e)s :						Pier-Alexandre Caron
Date de cr�ation du fichier :		2020-04-27
Nom du fichier :					hpBar.h
D�finition des m�thode de l'objet hpBar
*/

#include "attack.h"



void attack::initAttack(int manacost, int modifier,string attackName)
{
	_manaCost = manacost;
	_modifier = modifier;
	_attackName = attackName;
}



void attack::attackOnATarget(personnage& cible, int damageStats)
{
	cible.setPv(cible.getPv() - (damageStats * _modifier));
}

int attack::getManaCost(void)
{
	return _manaCost;
}
