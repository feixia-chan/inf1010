/*
Fichier: EtatConfus.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 5/10/2016
Description: sous classe de EtatCreature
*/

#ifndef ETATCONFUS_H
#define ETATCONFUS_H

#include "EtatCreature.h"
using namespace std;

class EtatConfus : public EtatCreature
{
    public:
        EtatConfus(const string& nom);
        EtatConfus(const string& nom, unsigned int duree);
        ~EtatConfus();


    void appliquerEtat(Creature& creature); //une fois sur 3 : elle perd 5% de ses PV actuels ou 5PV direct.
                                            //La durée est décrémentée
    bool peutAttaquer() const; //la créature peut attaquer l'autre 50% du tps
    bool estFini() const; //finit si duree =0 ou une fois sur trois
    friend ostream& operator<<(ostream& o, const EtatConfus& etatCreature); //fonction globale d'affichage

    protected:

    private:
};



#endif // ETATCONFUS_H
