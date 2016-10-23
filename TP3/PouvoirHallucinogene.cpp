#include "PouvoirHallucinogene.h"


PouvoirHallucinogene::PouvoirHallucinogene(const string& nom,	unsigned int nombreDeDegat, unsigned int energieNecessaire):
    Pouvoir(nom, nombreDeDegat, energieNecessaire){
    duree_=0;
    type_ =TypeEtat_confus;
}

PouvoirHallucinogene::PouvoirHallucinogene(const string& nom,	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree):
    Pouvoir(nom, nombreDeDegat, energieNecessaire),duree_(duree)
{
    type_ =TypeEtat_confus;
}


PouvoirHallucinogene::~PouvoirHallucinogene()
{

}

ostream& operator<<(ostream& os, const PouvoirHallucinogene& pouvoir){

    os << static_cast<const Pouvoir&>(pouvoir) << "il peut rendre cible confuse";    //Pouvoir::<<
    return os;
}

void PouvoirHallucinogene::appliquerEffetOffensif(Creature& creatureEnnemie){  //meth fausse
     delete creatureEnnemie.getEtat();
    //creatureEnnemie.etat_=nullptr;
    EtatConfus* etat= new EtatConfus("confus",duree_); //il faut créer un nouvel objet etat confus et le remplacer dans etat_
    creatureEnnemie.setEtat(static_cast<EtatConfus*>(etat));
}
