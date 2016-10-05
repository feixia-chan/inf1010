#include "EtatCreature.h"

EtatCreature::EtatCreature(const string & nom) : nom_(nom), duree_(0), type_(TypeEtat::TypeEtat_normal)
{
}

EtatCreature::EtatCreature(const string & nom, unsigned int duree) : nom_(nom), duree_(duree), type_(TypeEtat::TypeEtat_normal)
{
}

EtatCreature::~EtatCreature()
{
}

void EtatCreature::appliquerEtat(Creature & creature)
{

}

bool EtatCreature::peutAttaquer() const
{
 //   return rand() % 6 != 0;
    return true;
}

bool EtatCreature::estFini() const
{
    return false;
}

string EtatCreature::getNom() const
{
    return nom_;
}

TypeEtat EtatCreature::getType() const
{
    return type_;
}

ostream & operator<<(ostream & o, const EtatCreature & etatCreature)
{
    o << "etat" << etatCreature.nom_ << endl;

    return o;
}