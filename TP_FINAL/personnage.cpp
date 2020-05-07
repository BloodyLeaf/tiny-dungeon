/*
Programme: personnage.cpp
Acteur: Sophie Bourgault
Date de cr�ation: 04 mai 2020
But du programme: D�finition de l'objet personnage.
*/

#include "personnage.h"

//ajouter rectangleShape [Sophie]
//constructeur aucun parametre
personnage::personnage()
{
    _str = _pv = _maxPv = _gold = 0;
}

//Constructeur 2 parametre mais deviensdra a 5 parametre
//ajout de rectangleShape [sophie]
personnage::personnage(int str, int pv, int maxPv, int gold)
{
    _str = str;
    _pv = pv;
    _maxPv = maxPv;
    _gold = gold;
}

//destructeur
//ajouter rectangleShape [sophie]
personnage::~personnage()
{
    _str = 0;
    _pv = 0;
}

void personnage::initPositionPersonnage(int x , int y)
{
    _position.setSize(Vector2f(100, 100));
    _position.setPosition(x, y);
    _position.setFillColor(Color::Cyan);
}

//methode qui retourne la valeur de str [Sophie]
int personnage::getStr() const
{
    return _str;
}

//methode qui retourne la valeur de pv [sophie]
int personnage::getPv() const
{
    return _pv;
}

//methode qui retourne la valeur de point de vie maximum [sophie]
int personnage::getMaxPv() const
{
    return _maxPv;
}

//methode qui retourne la quantit/ dor du personnage [sophie]
int personnage::getGold() const
{
    return _gold;
}

//methode qui retourne le x de la position
int personnage::getPositionX()
{
    return _position.getPosition().x;
}
//methode qui retourne le y de la position
int personnage::getPositionY()
{
    return _position.getPosition().y;
}

Color personnage::getCharacterColor()
{
    return _position.getFillColor();
}

//methode qui modifie la valeur de str [sophie]
void personnage::setStr(int str)
{
    _str = str;
}

//methode qui modifie la valeur de pv [sophie]
void personnage::setPv(int pv)
{
    _pv = pv;
}

//methode qui modifie la valeur de point de vie maximum du personnage [sophie]
void personnage::setMaxPv(int maxPv)
{
    _maxPv = maxPv;
}

//methode qui modifie la qua tite dor du personnage [sophie]
void personnage::setGold(int gold)
{
    _gold = gold;
}

void personnage::setPosition(int x, int y)
{
    _position.setPosition(x, y);
}
//Temooraire Initialise un hero pour garder le jeu fonctionnel 
void personnage::initPersonnage(void)
{
    _str= 1 ;
    _pv = _maxPv = 25;
    _gold=0;
}

void personnage::setCharColor(Color color)
{
    _position.setFillColor(color);
}

//methode qui prend un int et le soustrait a la valeur de pv [sophie]
void personnage::recevoirDegat(int degat)
{
    _pv = _pv - degat;
}

void personnage::printChar(RenderWindow& window)
{
    window.draw(_position);
}
