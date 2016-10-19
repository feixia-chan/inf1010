/*
Fichier: EtatEmpoisonne.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 5/10/2016
Description: sous classe de EtatCreature
*/

#ifndef ETATEMPOISONNE_H
#define ETATEMPOISONNE_H

#include "EtatCreature.h"
using namespace std;

class EtatEmpoisonne : public EtatCreature
{
    public:
        EtatEmpoisonne(const string& nom);
        EtatEmpoisonne(const string& nom, unsigned int duree);
        ~EtatEmpoisonne();


    void appliquerEtat(Creature& creature); //décrémente durée et enleve 5PV

    bool estFini() const; //finit si duree =0

    friend ostream& operator<<(ostream& o, const EtatEmpoisonne& etatCreature); //fonction globale d'affichage

    protected:

    private:
};


#endif // ETATEMPOISONNE_H
