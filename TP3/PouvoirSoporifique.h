/*
Fichier: PouvoirSoporifique.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 5/10/2016
Description: sous classe de Pouvoir

*/

#ifndef POUVOIRSOPORIFIQUE_H
#define POUVOIRSOPORIFIQUE_H

#include "Pouvoir.h"


class PouvoirSoporifique : public Pouvoir
{
 public:
        PouvoirSoporifique(const string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);

		PouvoirSoporifique(const string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
        ~PouvoirSoporifique();

        friend ostream& operator<<(ostream& os, const PouvoirSoporifique& pouvoir);

    void appliquerEffetOffensif(Creature& creatureEnnemie); //on endort la créature


    protected:
    int duree_;
    private:
};

#endif // POUVOIRSOPORIFIQUE_H
