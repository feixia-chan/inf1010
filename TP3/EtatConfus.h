#ifndef ETATCONFUS_H
#define ETATCONFUS_H

#include <EtatCreature.h>


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


    protected:

    private:
};

ostream& operator<<(ostream& o, const Etatconfus& etatCreature); //fonction globale d'affichage

#endif // ETATCONFUS_H
