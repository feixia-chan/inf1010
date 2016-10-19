#include "PouvoirSoporifique.h"


PouvoirSoporifique::PouvoirSoporifique(const string& nom,	unsigned int nombreDeDegat, unsigned int energieNecessaire):
    Pouvoir(nom, nombreDegat, energieNecessaire){
    duree_=0;
    type_ = TypeEtat_endormi;
}

PouvoirSoporifique::PouvoirSoporifique(const string& nom,	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree):
    Pouvoir(nom, nombreDegat, energieNecessaire),duree_(duree_)){
    type_ = TypeEtat_endormi;
}


PouvoirSoporifique::~PouvoirSoporifique()
{

}

ostream& operator<<(ostream& os, const PouvoirSoporifique& pouvoir){

    os << pouvoir << "il peut endormir la cible";    //Pouvoir::<<
    return os;
}

void PouvoirSoporifique::appliquerEffetOffensif(Creature& creatureEnnemie){  //meth fausse
     delete creatureEnnemie.etat_;
    //creatureEnnemie.etat_=nullptr;
    EtatEndormi* etat= new EtatEmpoisonne("endormi",duree_)); //il faut créer un nouvel objet etat endormi et le remplacer dans etat_
    creatureEnnemie.setEtat(static_cast<EtatEndormi*>etat);
}
