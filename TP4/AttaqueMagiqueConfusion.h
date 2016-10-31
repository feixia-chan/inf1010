/*
Fichier: AttaqueMagique.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 26 octobre 2016
Description:  attaques des créatures magiques
*/

#ifndef ATTAQUEMAGIQUECONFUSION_H
#define ATTAQUEMAGIQUECONFUSION_H

#include "AttaqueMagique.h"
#include <typeinfo>

using namespace std;


class AttaqueMagiqueConfusion : public AttaqueMagique
{
public:

    //constructeurs & destructeurs
    AttaqueMagiqueConfusion();
    AttaqueMagiqueConfusion(int duree);
    virtual ~AttaqueMagiqueConfusion();

    //meths
    //  string getTypeAttaque() const; //Note : cette méthode nous a été demandée dans l'énoncé, mais la définition de la classe mère est suffisante en réalité... et n'est même pas virtuelle comme le type de retour est un string !!
//appliquerAttaque n'est pas virtuelle
    virtual bool appliquerAttaque(Creature& creatureAdverse);    //PV -2 à 33% de réussite si PV >5 && duree_>0
   virtual  bool estFini();

protected:

private:
};

#endif // ATTAQUEMAGIQUECONFUSION_H
