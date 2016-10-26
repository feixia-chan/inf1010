/*
Fichier: AttaqueMagique.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 26 octobre 2016
Description:  attaques des cr�atures magiques
*/

#ifndef ATTAQUEMAGIQUECONFUSION_H
#define ATTAQUEMAGIQUECONFUSION_H

#include "AttaqueMagique.h"

using namespace std;


class AttaqueMagiqueConfusion : public AttaqueMagique
{
public:

    //constructeurs & destructeurs
    AttaqueMagiqueConfusion();
    AttaqueMagiqueConfusion(int duree);
    virtual ~AttaqueMagiqueConfusion();

    //meths
    string getTypeAttaque() const;
//appliquerAttaque n'est pas virtuelle
    bool appliquerAttaque(Creature& creatureAdverse);    //PV -2 � 33% de r�ussite si PV >5 && duree_>0
    bool estFini();

protected:

private:
};

#endif // ATTAQUEMAGIQUECONFUSION_H
