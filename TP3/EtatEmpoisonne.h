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


    void appliquerEtat(Creature& creature); //d�cr�mente dur�e et enleve 5PV

    bool estFini() const; //finit si duree =0
    protected:

    private:
};

ostream& operator<<(ostream& o, const EtatEmpoisonne& etatCreature); //fonction globale d'affichage

#endif // ETATEMPOISONNE_H
