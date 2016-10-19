#include "PouvoirHallucinogene.h"


PouvoirHallucinogene::PouvoirHallucinogene(const string& nom,	unsigned int nombreDeDegat, unsigned int energieNecessaire):
    Pouvoir(nom, nombreDegat, energieNecessaire), type_(TypeEtat_confus){
    duree_=0;
}

PouvoirHallucinogene::PouvoirHallucinogene(const string& nom,	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree):
    Pouvoir(nom, nombreDegat, energieNecessaire),duree_(duree_),type_(TypeEtat_confus){

}


PouvoirHallucinogene::~PouvoirHallucinogene()
{

}

ostream& operator<<(ostream& os, const PouvoirHallucinogene& pouvoir){

    os << pouvoir << "il peut rendre cible confuse";    //Pouvoir::<<
    return os;
}

void PouvoirHallucinogene::appliquerEffetOffensif(Creature& creatureEnnemie){  //meth fausse
     delete creatureEnnemie.etat_;
    //creatureEnnemie.etat_=nullptr;
    etat= new EtatEmpoisonne("confus",duree_)); //il faut créer un nouvel objet etat confus et le remplacer dans etat_
    creatureEnnemie.setEtat(static_cast<EtatConfus>etat);
}
