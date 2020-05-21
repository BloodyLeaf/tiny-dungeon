/*
Programme: personnage.h
Acteur: Sophie Bourgault
Date de création: 04 mai 2020
But du programme: Déclaration de l'objet personnage de Tiny Dungeon.
*/
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>


using namespace std;
using namespace sf;

class personnage {

protected:

    int _str, _pv, _maxPv, _gold, _id, _speed, _dex;
    RectangleShape _position;        //Ajouter rectangleShape [Sophie]
    Texture _texture;                   //Pour avoir la file des sprite du hero [P-A]
    IntRect _sprite;

public:

    personnage();
    personnage(int str, int pv, int maxPv, int gold, int mana, int speed, int dex);        //Ajouter rectangleShape [Sophie]
    ~personnage();

    void initPositionPersonnage(int x , int y);
    void initPersonnage(Color color, int w, int h);

    int getStr() const;                     //retourne valeur de strenght [Sophie]
    int getPv() const;                      //retourne valeur de point de vie [Sophie]
    int getMaxPv() const;                   //retourne valeur de max point de vie [sophie]
    int getGold() const;                    //retourne quantite dor [sophie]
    //int getMana() const;                    //retourne la valeur du mana [Sophie]
    int getSpeed() const;                   //retourne la vitesse du personnage [sophie]
    int getDex() const;                     //retourne le dexterite du personnage [sophie]
    int getId() const;                      //retourne Id de la race [sophie]
    int getPositionX();                     //retourne le x de la position du shape [P-A]
    int getPositionY();                     //retourne le x de la position du shape [P-A]
    Color getCharacterColor();              //retourne la couleur actuelle du character[P-A]

    void setStr(int str);                   //modifie la valeur de strenght [Sophie]
    void setPv(int pv);                      //modifie la valeur de point de vie [Sophie]
    void setMaxPv(int maxPv);               //modifie la valeur de point de vie maximum [sophie]
    void setGold(int gold);                 //modifie la quantite dor du personnage [sophie]
    void setId(int id);                      //modifie le id du personnage [sophie]
    void setMana(int mana);                 //modifie le mana du personnage [sophie]
    void setSpeed(int speed);               //modifie le vitesse du personnage [sophie]
    void setDex(int dex);                   //modifie la dexterite du personnage [sophie]
    void setPosition(int x, int y);         //Set La position du personnage [ P-A ]
    void initPersonnage(void);              //Initialisation du personnage au début du jeu [P-A ] + parametre a ajouter si + de perso
    void setCharColor(Color color);         //Set la couleur du hero actuel [P-A]
    void setIntRect(IntRect rect);           //Modifie le sprite du personnage[P-A]
    

    void recevoirDegat(int degat);                                       //modifie les points de vie [Sophie]
    void printChar(RenderWindow & window);                               //Affiche un personnage [P-A]

    void ouvrirFichier(ifstream& fichier);                              //ouverture de fichier [sophie]
    void recherchePersonnage(ifstream& fichier, int personnage);        //recherche dans un fichier texte a laide de id et attribution de donnee [sophie]
   
};
