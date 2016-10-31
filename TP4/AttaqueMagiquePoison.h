/*
Fichier: AttaqueMagiquePoison.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 26 octobre 2016
Description: attaque des créatures magiques
*/

#ifndef ATTAQUEMAGIQUEPOISON_H
#define ATTAQUEMAGIQUEPOISON_H

#include "AttaqueMagique.h"
#include <typeinfo>

using namespace std;

class AttaqueMagiquePoison : public AttaqueMagique
{
public:

    //constructeurs & destructeurs
    AttaqueMagiquePoison();
    AttaqueMagiquePoison(int duree);
    virtual ~AttaqueMagiquePoison();


    //meths
//    virtual string getTypeAttaque() const;
    //appliquerAttaque est virtuelle, car elle a été déclarée comme telle dans AttaqueMagique
    virtual bool appliquerAttaque(Creature& creatureAdverse);    //energie -2 à 33%de réussite si energie >5 && duree_>0
    virtual bool estFini(); //vrai si durée_==0
protected:

private:
};

#endif // ATTAQUEMAGIQUEPOISON_H
