/*
Fichier: AttaqueMagique.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 26 octobre 2016
Description:  attaques des cr�atures magiques
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
    //  string getTypeAttaque() const; //Note : cette m�thode nous a �t� demand�e dans l'�nonc�, mais la d�finition de la classe m�re est suffisante en r�alit�... et n'est m�me pas virtuelle comme le type de retour est un string !!
//appliquerAttaque n'est pas virtuelle
    virtual bool appliquerAttaque(Creature& creatureAdverse);    //PV -2 � 33% de r�ussite si PV >5 && duree_>0
   virtual  bool estFini();

protected:

private:
};

#endif // ATTAQUEMAGIQUECONFUSION_H
