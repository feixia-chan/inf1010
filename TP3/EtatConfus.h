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
                                            //La dur�e est d�cr�ment�e
    bool peutAttaquer() const; //marche � 50%
    bool estFini() const; //finit si duree =0 ou une fois sur trois


    protected:

    private:
};

ostream& operator<<(ostream& o, const EtatCreature& etatCreature); //fonction globale d'affichage

#endif // ETATCONFUS_H
