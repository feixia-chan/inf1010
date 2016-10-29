#include "CreatureMagique.h"

//Constructeur par d�faut
CreatureMagique::CreatureMagique(): Creature()
{
    bonus_=0;
    attaqueMagique_=nullptr;
}

//constructeur par param�tres
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
    if(creatureMagique.attaqueMagique_->getTypeAttaque()=="20AttaqueMagiquePoison") //explication sur cette ligne � la fin du fichier
        attaqueMagique_= new AttaqueMagiquePoison();
    else
        attaqueMagique_= new AttaqueMagiqueConfusion();
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
CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
    if(this != &creatureMagique)
    {
        Creature::operator=(creatureMagique);
        bonus_=creatureMagique.bonus_;
        delete attaqueMagique_;
        attaqueMagique_=nullptr;
        if(creatureMagique.attaqueMagique_->getTypeAttaque()=="20AttaqueMagiquePoison")  //lorsque l'on veut afficher un string
            attaqueMagique_= new AttaqueMagiquePoison();                                //avec typeid().name(), pour une AttaqueMagiquePoison
        else                                                                            //on obtient "20AttaqueMagiquePoison" je ne sais pas d'o� vient le 20
            attaqueMagique_= new AttaqueMagiqueConfusion();                             //et peut �tre qu'il diff�re d'un compilateur � l'autre
    }
    return *this;

}
ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique)
{
    os<<static_cast<Creature>(creatureMagique);
    os<<"Cette cr�ature a un bonus de "<<creatureMagique.bonus_<<endl;
    os<<"Cette cr�ature appartient � la "<<typeid(creatureMagique).name()<<endl;
    os<<"et "<<*creatureMagique.attaqueMagique_<<endl;
    return os;
}

//Apprentissage et oubli d'attaque magique
void CreatureMagique::apprendreAttaqueMagique(AttaqueMagique* attaqueMagique)
{
    cout<<attaqueMagique->getTypeAttaque()<<endl;
    if(attaqueMagique->getTypeAttaque()=="20AttaqueMagiquePoison")
    {
        attaqueMagique_= new AttaqueMagiquePoison();
    }
    else
    {
        attaqueMagique_= new AttaqueMagiqueConfusion();
    }
}

void CreatureMagique::oublierAttaqueMagique()
{
    delete attaqueMagique_;
    attaqueMagique_=nullptr;
}
