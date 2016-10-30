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
    if(creatureMagique.attaqueMagique_->getTypeAttaque()=="20AttaqueMagiquePoison") //explication sur cette ligne à la fin du fichier
        attaqueMagique_= new AttaqueMagiquePoison(creatureMagique.attaqueMagique_->getDuree());
    else
        attaqueMagique_= new AttaqueMagiqueConfusion(creatureMagique.attaqueMagique_->getDuree());
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
        cout<<"Tentative d'application de l'attaque magique"<<endl;
        attaqueMagique_->appliquerAttaque(creature);
    }
    if(pointDeVie_+bonus_<pointDeVieTotal_)
    {
        pointDeVie_+=bonus_;
        cout<<nom_<<"applique son bonus et a maintenant "<<pointDeVie_<<" PV"<<endl;
    }
    else
    {
        pointDeVie_=pointDeVieTotal_;
        cout<<nom_<<" applique son bonus et a maintenant "<<pointDeVie_<<" PV"<<endl;
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
        if(creatureMagique.attaqueMagique_->getTypeAttaque()=="20AttaqueMagiquePoison")                 //lorsque l'on veut afficher un string
            attaqueMagique_= new AttaqueMagiquePoison(creatureMagique.attaqueMagique_->getDuree());     //avec typeid().name(), pour une AttaqueMagiquePoison
        else                                                                                            //on obtient "20AttaqueMagiquePoison" je ne sais pas d'où vient le 20
            attaqueMagique_= new AttaqueMagiqueConfusion(creatureMagique.attaqueMagique_->getDuree());  //et peut être qu'il diffère d'un compilateur à l'autre
    }
    return *this;

}
ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique)
{
    os<<static_cast<Creature>(creatureMagique);
    os<<"Cette créature a un bonus de "<<creatureMagique.bonus_<<endl;
    os<<"Cette créature appartient à la classe "<<typeid(creatureMagique).name();
    os<<" et "<<*creatureMagique.attaqueMagique_<<endl;
    return os;
}

//Apprentissage et oubli d'attaque magique
void CreatureMagique::apprendreAttaqueMagique(AttaqueMagique* attaqueMagique)
{
    if(attaqueMagique->getTypeAttaque()=="20AttaqueMagiquePoison")
    {
        attaqueMagique_= new AttaqueMagiquePoison(attaqueMagique->getDuree());
    }
    else
    {
        attaqueMagique_= new AttaqueMagiqueConfusion(attaqueMagique->getDuree());
    }
}

void CreatureMagique::oublierAttaqueMagique()
{
    delete attaqueMagique_;
    attaqueMagique_=nullptr;
}
