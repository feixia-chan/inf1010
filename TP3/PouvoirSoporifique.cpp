#include "PouvoirSoporifique.h"


PouvoirSoporifique::PouvoirSoporifique(const string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire):
    Pouvoir(nom, nombreDeDegat, energieNecessaire){
    duree_=0;
    type_ = TypeEtat_endormi;
}

PouvoirSoporifique::PouvoirSoporifique(const string& nom, unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree):
    Pouvoir(nom, nombreDeDegat, energieNecessaire),duree_(duree)
{
    type_ = TypeEtat_endormi;
}


PouvoirSoporifique::~PouvoirSoporifique()
{

}

ostream& operator<<(ostream& os, const PouvoirSoporifique& pouvoir){

    os << static_cast<const Pouvoir&>(pouvoir) << "il peut endormir la cible";    //Pouvoir::<<
    return os;
}

void PouvoirSoporifique::appliquerEffetOffensif(Creature& creatureEnnemie){  //meth fausse
     delete creatureEnnemie.getEtat();
    //creatureEnnemie.etat_=nullptr;
    EtatEndormi* etat= new EtatEndormi("endormi",duree_); //il faut créer un nouvel objet etat endormi et le remplacer dans etat_
    creatureEnnemie.setEtat(static_cast<EtatEndormi*>(etat));
}
