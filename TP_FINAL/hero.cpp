/*
Programme: hero.cpp
Acteur: Sophie Bourgault
Date de création: 05 mai 2020
But du programme: Définition de l'objet hero.
*/

#include "hero.h"

void hero::initHero()
{

    //initPersonnage(Color::Cyan, 100, 100);
    _position.setSize(Vector2f(100, 100));
    initHeroAttack();
    initHeroSpell();
    setMaxPv(25);
    setPv(25);
    
    setStr(1);
    setDex(1);
    setMaxMana(10);
    setMana(10);
    
    setFaith(3);
    setSpeed(5);

    _texture.loadFromFile("ressources/hero.png");
    _position.setTexture(&_texture);
    _position.setTextureRect(IntRect(460, 236, 43, 43));

    _idle[0].loadAnimationFromNotePad("ressources/animation.txt","idleShop");
    _idle[1].loadAnimationFromNotePad("ressources/animation.txt", "idleBattleGround");

    _attackAnimation[0].loadAnimationFromNotePad("ressources/heroAttack.txt", "basicAttackUp");
    _attackAnimation[1].loadAnimationFromNotePad("ressources/heroAttack.txt", "basicAttackMid");
    _attackAnimation[2].loadAnimationFromNotePad("ressources/heroAttack.txt", "basicAttackTop");
    _attackAnimation[3].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
    _attackAnimation[4].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
    _attackAnimation[5].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
    _attackAnimation[6].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
    _attackAnimation[7].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
    _attackAnimation[8].loadAnimationFromNotePad("ressources/heroAttack.txt", "");
}

void hero::initHeroAttack()
{
    _attack[0].initAttack(0,1,1,"STR base attack");
    _attack[1].initAttack(5,2,1,"STR critical attack");
    _attack[2].initAttack(10, 3, 5, "STR bigHit");
    _attack[3].initAttack(15, 6, 10, "STR big big hit");
    _attack[4].initAttack(20, 10, 20, "STR giant hit");
}

void hero::initHeroSpell()
{
    _spell[0].initAttack(5, 1, 1, "basic Spell");
    _spell[1].initAttack(10, 2, 1, "Second Spell");
    _spell[2].initAttack(20, 3, 5, "third Spell");
    _spell[3].initAttack(30, 6, 10, "fourth Spell");
    _spell[4].initAttack(40, 10, 20, "big bang Spell");
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
int hero::getFaith()
{
    return _faith;
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
    if (_mana > _maxMana)_mana = _maxMana;
}

//Set le mana max du hero
void hero::setMaxMana(int maxMana)
{
    _maxMana = maxMana;
}

//Set l'intel du hero
void hero::setFaith(int intel)
{
    _faith = intel;
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
        _attack[id].attackOnATarget(cible, getStr() + _weapon.GetStrengthMod());
        setMana(getMana() - _attack[id].getManaCost());
    
   
}

void hero::useASpell(personnage& cible, int id)
{
    _spell[id].attackOnATarget(cible, getFaith() + _weapon.GetStrengthMod());
    setMana(getMana()-_spell[id].getManaCost());
}
bool hero::checkIfSkillCanBeUsed(int id)
{   
        if (_mana >= _attack[id].getManaCost() && _str>= _attack[id].getRequiredStats()) return true;
        else return false;
}

bool hero::checkIfSpellCanBeUsed(int id)
{
    if (_mana >= _attack[id].getManaCost() && _faith >= _attack[id].getRequiredStats()) return true;
    else return false;
}

void hero::useAnimation(int whereInAnimation,int animationID)
{
    _position.setTextureRect(_idle[animationID].getSprite(whereInAnimation));
    _position.setPosition(_idle[animationID].getPosition(whereInAnimation));
}

/*void hero::setEquipement(vector <int> equipement)
{
    for (int i = 0; i < equipement.size(); i++) {
        _equipement.at(i) = (equipement.at(i));
    }
}*/