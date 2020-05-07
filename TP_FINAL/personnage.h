/*
Programme: personnage.h
Acteur: Sophie Bourgault
Date de création: 04 mai 2020
But du programme: Déclaration de l'objet personnage de Tiny Dungeon.
*/
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>


//using namespace std;
using namespace sf;

class personnage {

private:

    int _str, _pv, _maxPv, _gold;
    RectangleShape _position;        //Ajouter rectangleShape [Sophie]

public:

    personnage();
    personnage(int str, int pv, int maxPv, int gold);        //Ajouter rectangleShape [Sophie]
    ~personnage();

    void initPositionPersonnage(int x , int y);

    int getStr() const;                    //retourne valeur de strenght [Sophie]
    int getPv() const;                    //retourne valeur de point de vie [Sophie]
    int getMaxPv() const;                //retourne valeur de max point de vie [sophie]
    int getGold() const;                //retourne quantite dor [sophie]
    int getPositionX();                 //retourne le x de la position du shape [P-A]
    int getPositionY();                 //retourne le x de la position du shape [P-A]
    Color getCharacterColor();          //retourne la couleur actuelle du character[P-A]

    void setStr(int str);                //modifie la valeur de strenght [Sophie]
    void setPv(int pv);                    //modifie la valeur de point de vie [Sophie]
    void setMaxPv(int maxPv);            //modifie la valeur de point de vie maximum [sophie]
    void setGold(int gold);                //modifie la quantite dor du personnage [sophie]
    void setPosition(int x, int y);         //Set La position du personnage [ P-A ]
    void initPersonnage(void);                  //Initialisation du personnage au début du jeu [P-A ] + parametre a ajouter si + de perso
    void setCharColor(Color color);             //Set la couleur du hero actuel [P-A]



    void recevoirDegat(int degat);        //modifie les points de vie [Sophie]
    void printChar(RenderWindow & window);        //Affiche un personnage [P-A]

   
};
