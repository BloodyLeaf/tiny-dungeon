/*
Programme: hero.cpp
Acteur: Sophie Bourgault
Date de création: 05 mai 2020
But du programme: Définition de l'objet hero.
*/

#include "hero.h"

void hero::initHero()
{

    initPersonnage(Color::Cyan, 100, 100);
    initHeroAttack();
    setPv(35);
    setMaxPv(35);
    setStr(1);
    setDex(1);
    setMana(12);
    setMaxMana(12);
    setInt(3);
    setSpeed(5);
}

void hero::initHeroAttack()
{
    _attack[0].initAttack(0,1,"STR base attack");
    _attack[1].initAttack(0,1,"DEX base attack");
    _attack[2].initAttack(10,2,"STR base critical attack");
    _attack[3].initAttack(10,2,"DEX base critical attack");
}

//methode qui retourne la race du personnage [sophie]
string hero::getRace() const
{
    return _race;
}

//methode qui retourne la classe du personnage [sophie]
string hero::getClasse() const
{
    return _classe;
}

//Retourne le mana du hero [P-A]
int hero::getMana()
{
    return _mana;
}
//Retourne le mana max du hero [P-A]
int hero::getMaxMana()
{
    return _maxMana;
}
//Retourne l'intel du hero [P-A]
int hero::getInt()
{
    return _int;
}

//Retourne l'armes actuelle du hero[sophie]
Item hero::getWeapon() const
{
    return _weapon;
}
//Retourne les botte actuelle du hero[sophie]
Item hero::getBoots() const
{
    return _weapon;
}
//Retourne l'armure actuelle[sophie]
Item hero::getArmor() const
{
    return _armor;
}

//methode qui modifie la race du personnage [sophie]
void hero::setRace(string race)
{
    _race = race;
}

//methode qui modifie la classe du personnage [sophie]
void hero::setClasse(string classe)
{
    _classe = classe;
}
//Permet de changer d'arme[sophie]
void hero::setWeapon(Item weapon)
{
    _weapon = weapon;
}
//permet de changer de botte[sophie]
void hero::setBoots(Item boots)
{
    _boots = boots;
}
//permet de changer d'armure[sophie]
void hero::setArmur(Item armor)
{
    _armor = armor;
}

//Set le mana du hero
void hero::setMana(int mana)
{
    _mana = mana;
}

//Set le mana max du hero
void hero::setMaxMana(int maxMana)
{
    _maxMana = maxMana;
}

//Set l'intel du hero
void hero::setInt(int intel)
{
    _int = intel;
}


void hero::rechercheHero(ifstream& fichier, int personnage)
{
    int donnee;
    ouvrirFichier(fichier);

    while (!fichier.eof()) {
        fichier >> donnee;

        if (donnee == personnage) {

            fichier >> donnee;
            setStr(donnee);

            fichier >> donnee;
            setPv(donnee);

            fichier >> donnee;
            setMaxPv(donnee);

            fichier >> donnee;
            setGold(donnee);

            break;
        }
    }
}

//permet au personnage d'utiliser un attaque
void hero::useAnAttack(personnage & cible, int id)
{
    if (id == 1 || id == 3) {
        _attack[id].attackOnATarget(cible, getStr() + _weapon.GetStrengthMod());
        setMana(getMana() - _attack[id].getManaCost());
    }
    if (id == 2 || id == 4) {
        _attack[id].attackOnATarget(cible, getDex() + _weapon.GetDexterityMod() );
    }
}
bool hero::checkIfSkillCanBeUsed(int id)
{
    
        if (_mana >= _attack[id].getManaCost()) return true;
        else return false;
    
}
/*void hero::setEquipement(vector <int> equipement)
{
    for (int i = 0; i < equipement.size(); i++) {
        _equipement.at(i) = (equipement.at(i));
    }
}*/