/*
Programme: hero.h
Acteur: Sophie Bourgault
Date de création: 05 mai 2020
But du programme: Déclaration de l'objet hero.
*/
#pragma once
#include <iostream>
#include "personnage.h"
#include "Item.h"
#include <string>
#include <vector>
#include "attack.h"
#include "Animation.h"


using namespace std;

class hero : public personnage
{

private:

    int _mana;                                              //Stats pour des meilleurs attaque [P-A ]
    int _maxMana;
    int _faith;

    string _race, _classe;                                //modificateur de stats [sophie]
    Item _weapon;
    Item _boots;
    Item _armor;

    attack _attack[5];
    
    animation _attackAnimation[9];
    animation _idle[2];
    //animation _idleCombats;

public:

    void initHero();                                      //initialise le hero en attendant qu'on finise la lecture du blocNote [P-A temp]
    void initHeroAttack();                                  //Initialise les attaques du hero [ P-A ]
    void initHeroSpell();                                   //Initialise la liste des sort possible du hero [P-A]

    string getRace() const;                                //retourne la race du personnage [sophie]
    string getClasse() const;                            //retourne la race du personnage [sophie]

    int getMana();                                      //Retoure le mana actuel [ P-A ] 
    int getMaxMana();                                   //Retourne le mana Max [P-A ]
    int getFaith();                                       //Retourne le int du personnage [P-A]

    Item getWeapon() const;
    Item getBoots() const;
    Item getArmor() const;
    //getteur de vector <int> equipement a faire[sophie]

    void setRace(string race);                            //modificateur de la race du personnage [sophie]
    void setClasse(string classe);                        //modificateur de la classe du personnage [sophie]
    //void setteur de vector <int> equipement a faire[sophie]
    //void setEquipement(vector <int> equipement);        //modificateur de lequipement du personnage [sophie]

    void setWeapon(Item weapon);
    void setBoots(Item boots);
    void setArmur(Item armor);

    void setMana(int mana);                     //Set Le mana actuel du hero
    void setMaxMana(int maxMana);               //Set le mana max du hero
    void setFaith(int intel);                     //set la stats d'inteligence du hero

    void rechercheHero(ifstream& fichier, int personnage);        //recherche dans un fichier texte a laide de id et attribution de donnee [sophie]
    void useAnAttack(personnage& cible, int id);                     // Pour permettre au personnage d'utiliser des attaques[P-A]
    void useASpell(personnage& cible, int id);                      //pour permettre au hero de lancer des sorts[P-A]

    bool checkIfSkillCanBeUsed(int id);                     //Check if mana + str is high enought for cost
    bool checkIfSpellCanBeUsed(int id);                     //Check if mana + faith is high enought for cost

    void useAnimation(int whereInAnimation,int animationID);        //0 idleShop 1 idleBattleGround

};