#include "CreatureMagique.h"

//Constructeur par d�faut
CreatureMagique::CreatureMagique(): Creature()
{
    bonus_=0;
    attaqueMagique_=nullptr;
}

//constructeur par param�tres
CreatureMagique::CreatureMagique(const string nom, unsigned int attaque, unsigned int defense,
                                 unsigned int pointDeVie, unsigned int energie, unsigned int bonus):
                                     Creature(nom,attaque,defense,pointDeVie,energie), bonus_(bonus)
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
    attaqueMagique_=new AttaqueMagique(*typeid(creatureMagique.attaqueMagique_));
}

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

//Type de la cr�ature
string CreatureMagique::getTypeCreature() const
{
    return typeid(CreatureMagique).name;
}

//Attaquer
void attaquer(const Pouvoir& pouvoir, Creature& creature)
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

//Apprentissage et oubli d'attaque magique
void CreatureMagique::apprendreAttaqueMagique(AttaqueMagique* attaqueMagique)
{
    attaqueMagique_=new AttaqueMagique(*attaqueMagique);
}

void CreatureMagique::oublierAttaqueMagique()
{
    delete attaqueMagique_;
}
