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

 int getDuree() const
{
    return duree_;
}

 void setDuree(int& duree)
{
    duree_=duree;
}

//meths

virtual string getTypeAttaque() const
{
    return typeid(AttaqueMagique).name; //retourne une string "AttaqueMagique"
}

virtual bool estFini(){
    return true;
}

friend ostream& operator<< (ostream& flux, AttaqueMagique& AttaqueMagique){
   // flux = "Cette créature de la classe " << typeid(CreatureMagique).name << " a aussi une attaque magique de type " << typeid(AttaqueMagique).name << " qui a une durée de "<< duree_ << endl;
    return flux;
}

