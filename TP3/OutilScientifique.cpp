#include "OutilScientifique.h"

OutilScientifique::OutilScientifique(const string & nom, const string & description) :
    nom_(nom), description_(description)
{
}

OutilScientifique::~OutilScientifique()
{
}

string OutilScientifique::getNom() const
{
    return nom_;
}

string OutilScientifique::getDesciption() const
{
    return description_;
}

void OutilScientifique::utiliser(Creature & creature)
{
    //methode de classe de base
    //ne fait rien
}

ostream & operator<<(ostream & os, const OutilScientifique & outil)
{
    return os << "l'outil " << outil.nom_ << " permet de " << outil.description_;
}
