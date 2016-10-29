/*
Fichier: AttaqueMagiquePoison.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 26 octobre 2016
Description: attaque des cr�atures magiques
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
//    string getTypeAttaque() const;
    //appliquerAttaque n'est pas virtuelle
    bool appliquerAttaque(Creature& creatureAdverse);    //energie -2 � 33%de r�ussite si energie >5 && duree_>0
    bool estFini(); //vrai si dur�e_==0
protected:

private:
};

#endif // ATTAQUEMAGIQUEPOISON_H
