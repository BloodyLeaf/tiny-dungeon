/*
Auteur(e)s :						Pier-Alexandre Caron
Date de création du fichier :		2020-04-27
Nom du fichier :					hpBar.h
Définition des méthode de l'objet hpBar
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
