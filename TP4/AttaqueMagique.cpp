/*
Fichier: AttaqueMagique.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 26 octobre 2016
Description: classe abstraite pour les attaques des créatures magiques
*/

#include "AttaqueMagique.h"



AttaqueMagique::AttaqueMagique(int duree):duree_(duree)
{

}

AttaqueMagique::~AttaqueMagique()
{

}

//accesseurs

int AttaqueMagique::getDuree() const
{
    return duree_;
}

void AttaqueMagique::setDuree(int& duree)
{
    duree_=duree;
}

//meths

string AttaqueMagique::getTypeAttaque() const
{
    return typeid(*this).name(); //retourne une string "AttaqueMagique"
}

bool AttaqueMagique::estFini()
{
    return true;
}

ostream& operator<< (ostream& flux, AttaqueMagique& AttaqueMagique)
{
    flux << " a aussi une attaque magique de type " << AttaqueMagique.getTypeAttaque() << " qui a une durée de "<< AttaqueMagique.duree_<<endl;
    return flux;
}

