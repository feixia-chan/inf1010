#ifndef ATTAQUEMAGIQUEPOISON_H
#define ATTAQUEMAGIQUEPOISON_H

#include "AttaqueMagique.h"

using namespace std;

class AttaqueMagiquePoison : public AttaqueMagique
{
    public:

        //constructeurs & destructeurs
        AttaqueMagiquePoison();
         AttaqueMagiquePoison(int duree);
        virtual ~AttaqueMagiquePoison();


        //meths
        string getTypeAttaque();
        //appliquerAttaque n'est pas virtuelle
         bool appliquerAttaque(Creature& creatureAdverse);    //energie -2 à 33%de réussite si energie >2 && duree_>0

    protected:

    private:
};

#endif // ATTAQUEMAGIQUEPOISON_H
