/*
Fichier: EtatEndormi.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 5/10/2016
Description: sous classe de EtatCreature
*/

#ifndef ETATENDORMI_H
#define ETATENDORMI_H

#include "EtatCreature.h"
using namespace std;

class EtatEndormi : public EtatCreature
{
    public:
        EtatEndormi(const string& nom);
        EtatEndormi(const string& nom, unsigned int duree);
        ~EtatEndormi();


    bool peutAttaquer() const; //ne peut pas attaquer
    void appliquerEtat(Creature& creature); //décrémente durée

    bool estFini() const; //finit si duree =0


    protected:

    private:
};

ostream& operator<<(ostream& o, const EtatEndormi& etatCreature); //fonction globale d'affichage

#endif // ETATENDORMI_H
