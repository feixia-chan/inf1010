#include "CreatureMagique.h"

//Constructeur par défaut
CreatureMagique::CreatureMagique(): Creature()
{
    bonus_=0;
    attaqueMagique_=nullptr;
}

//constructeur par paramètres
CreatureMagique::CreatureMagique(Creature creature, unsigned int bonus):
                                     Creature(creature), bonus_(bonus)
{
    attaqueMagique_=nullptr;
}
CreatureMagique::~CreatureMagique()
{
    delete attaqueMagique_;
    attaqueMagique_=nullptr;
}

//constructeur par copie
CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique): Creature(creatureMagique)
{
    bonus_=creatureMagique.bonus_;
    delete attaqueMagique_;
    attaqueMagique_=nullptr;
//       attaqueMagique_= new (creatureMagique.attaqueMagique_->getTypeAttaque())();
//       //AttaqueMagiquePoison

if(creatureMagique.attaqueMagique_->getTypeAttaque()=="class AttaqueMagiquePoison")
    attaqueMagique_= new AttaqueMagiquePoison();
else
    attaqueMagique_= new AttaqueMagiqueConfusion();

//Accesseurs
AttaqueMagique* CreatureMagique::getAttaqueMagique() const
{
    return attaqueMagique_;
}

unsigned int CreatureMagique::getBonus() const
{
    return bonus_;
}

//Modificateurs
void CreatureMagique::setBonus(unsigned int bonus)
{
    bonus_=bonus;
}

//Type de la créature
string CreatureMagique::getTypeCreature() const
{
    return typeid(CreatureMagique).name();
}

//Attaquer
void CreatureMagique::attaquer(const Pouvoir& pouvoir, Creature& creature)
{
    if(!attaqueMagique_->estFini())
    {
        attaqueMagique_->appliquerAttaque(creature);
    }
    if(pointDeVie_+bonus_<pointDeVieTotal_)
    {
       pointDeVie_+=bonus_;
    }
    else
    {
        pointDeVie_=pointDeVieTotal_;
    }
    Creature::attaquer(pouvoir, creature);

}
//operator
CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
    if(this != &creatureMagique)
    {
       Creature::operator=(creatureMagique);
       bonus_=creatureMagique.bonus_;
       delete attaqueMagique_;
       attaqueMagique_=nullptr;
       attaqueMagique_=new AttaqueMagique(*typeid(creatureMagique.attaqueMagique_));
    }
    return *this;

}
ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique)
{

}

//Apprentissage et oubli d'attaque magique
void CreatureMagique::apprendreAttaqueMagique(AttaqueMagique* attaqueMagique)
{
    attaqueMagique_=new AttaqueMagique(*attaqueMagique);
}

void CreatureMagique::oublierAttaqueMagique()
{
    delete attaqueMagique_;
    attaqueMagique_=nullptr;
}
