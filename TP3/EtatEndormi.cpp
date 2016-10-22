#include "EtatEndormi.h"

EtatEndormi::EtatEndormi(const string& nom): EtatCreature(nom)
{
 type_=TypeEtat_endormi;
}

EtatEndormi::EtatEndormi(const string& nom, unsigned int duree): EtatCreature(nom,duree)
{
 type_=TypeEtat_endormi;

}


EtatEndormi::~EtatEndormi()
{

}

ostream& operator<<(ostream& o, const EtatEndormi& etatCreature){ //a vérifier !
    o << "etat" << etatCreature.getNom() << endl;
    return o;
}

bool EtatEndormi::peutAttaquer() const{
    return false;
}

void EtatEndormi::appliquerEtat(Creature& creature){
    if(duree_>0)
        duree_--;
}

bool EtatEndormi::estFini() const{
    if(duree_<=0){
        return true;
    }
    else{
        return false;
    }
}
