#ifndef POUVOIRPOISON_H
#define POUVOIRPOISON_H

#include "Pouvoir.h"


class PouvoirPoison : public Pouvoir
{
    public:
        PouvoirPoison(const string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);

		PouvoirPoison(const string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree);
        ~PouvoirPoison();

        friend ostream& operator<<(ostream& os, const PouvoirPoison& pouvoir);  //pas sure

    void appliquerEffetOffensif(Creature& creatureEnnemie); //on empoisonne la créature


    protected:
    int duree_;
    private:
};

#endif // POUVOIRPOISON_H
