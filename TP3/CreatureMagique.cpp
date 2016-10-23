#include "CreatureMagique.h"

//Constructeur par parametres
CreatureMagique::CreatureMagique(const string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, unsigned int bonus):Creature(nom,attaque,defense,pointDeVie, energie),bonus_(bonus)
{}
//Destructeur
CreatureMagique::~CreatureMagique()
{}
//constructeur par copie
CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique): Creature(creatureMagique)
{
    bonus_=creatureMagique.bonus_;
}
//Accesseurs
int CreatureMagique::getBonus() const
{
    return bonus_;
}
//Modificateurs
void CreatureMagique::setBonus(int bonus)
{
    bonus_=bonus;
}
//operators
ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique)
{
    os<<creatureMagique;
    os<<"Et "<<creatureMagique.getNom()<<" a aussi un bonus de "<<creatureMagique.bonus_;
    return os;
}

CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
    if(this != &creatureMagique){
        Creature::operator=(creatureMagique);
        bonus_=creatureMagique.bonus_;
    }
    return *this;
}
//Methode attaquer surchargée
void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature)
{
    Creature::attaquer(pouvoir, creature);
    if(this->getPointDeVie()+bonus_>this->getPointDeVieTotal()){
        this->setPointDeVie(this->getPointDeVieTotal());
    }
    else{
        setPointDeVie(this->getPointDeVie()+bonus_);
    }
}
