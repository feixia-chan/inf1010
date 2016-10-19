/*
Fichier: PouvoirHallucinogene.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 6/10/2016
Description: sous classe de Pouvoir

*/

#ifndef POUVOIRHALLUCINOGENE_H
#define POUVOIRHALLUCINOGENE_H

#include "Pouvoir.h"

include namespace std

class PouvoirHallucinogene : public Pouvoir
{
    public:
        PouvoirHallucinogene(const string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);

		PouvoirHallucinogene(const string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
        ~PouvoirHallucinogene();

        friend ostream& operator<<(ostream& os, const PouvoirHallucinogene& pouvoir);  //pas sure

    void appliquerEffetOffensif(Creature& creatureEnnemie); //on rend la créature confuse


    protected:
    int duree_;
    private:
};

#endif // POUVOIRHALLUCINOGENE_H
