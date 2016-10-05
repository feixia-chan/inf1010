/*
Fichier: EtatConfus.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 5/10/2016
Description: sous classe de Pouvoir

C:\Users\Alexandra\Documents\POLY\Info 1010\TP\Rendu\inf1010\TP3
*/

#include "PouvoirPoison.h"

PouvoirPoison::PouvoirPoison(const string& nom,	unsigned int nombreDeDegat, unsigned int energieNecessaire):
    Pouvoir(nom, nombreDegat, energieNecessaire), type_(TypeEtat_empoisonne){
    duree_=0;
}

PouvoirPoison::PouvoirPoison(const string& nom,	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree):
    Pouvoir(nom, nombreDegat, energieNecessaire),duree_(duree_),type_(TypeEtat_empoisonne){

}


PouvoirPoison::~PouvoirPoison()
{

}

ostream& operator<<(ostream& os, const PouvoirPoison& pouvoir){

    os << pouvoir << "il peut empoisonner la cible";    //Pouvoir::<<
    return os;
}

void PouvoirPoison::appliquerEffetOffensif(Creature& creatureEnnemie){
    creatureEnnemie.setEtat("empoisonnée");//a quoi ca sert?
}
