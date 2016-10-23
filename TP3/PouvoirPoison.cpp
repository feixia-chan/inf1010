

#include "PouvoirPoison.h"

PouvoirPoison::PouvoirPoison(const string& nom,	unsigned int nombreDeDegat, unsigned int energieNecessaire):
    Pouvoir(nom, nombreDeDegat, energieNecessaire){
    duree_=0;
    type_=TypeEtat_empoisonne;
}

PouvoirPoison::PouvoirPoison(const string& nom,	unsigned int nombreDeDegat, unsigned int energieNecessaire, int duree):
    Pouvoir(nom, nombreDeDegat, energieNecessaire),duree_(duree_){
    type_=TypeEtat_empoisonne;
}


PouvoirPoison::~PouvoirPoison()
{

}

ostream& operator<<(ostream& os, const PouvoirPoison& pouvoir){

    os << static_cast<const Pouvoir&>(pouvoir)<< "il peut empoisonner la cible";    //Pouvoir::<<
    return os;
}

void PouvoirPoison::appliquerEffetOffensif(Creature& creatureEnnemie){  //meth fausse
    delete creatureEnnemie.getEtat();
    //creatureEnnemie.etat_=nullptr;
    EtatEmpoisonne* etat= new EtatEmpoisonne("empoisonne",duree_); //il faut créer un nouvel objet etat empoisonné et le remplacer dans etat_
    creatureEnnemie.setEtat(static_cast<EtatEmpoisonne*>(etat));
}
