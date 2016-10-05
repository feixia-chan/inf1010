#include "EtatEndormi.h"

EtatEndormi::EtatEndormi(const string& nom): nom_(nom), duree_(0), type_(TypeEtat::TypeEtat_endormi)
{

}

EtatConfus::EtatEndormi(const string& nom, unsigned int duree): nom_(nom), duree_(duree), type_(TypeEtat::TypeEtat_endormi)
{

}


EtatEndormi::~EtatEndormi()
{

}

ostream& operator<<(ostream& o, const EtatEndormi& etatCreature){ //a vérifier !
    o << "etat" << etatCreature.nom_ << endl;
    return o;
}

bool EtatEndormi::peutAttaquer() const{
    return false;
}

void EtatEndormi::appliquerEtat(Creature& creature){
    if(duree_>0)
        duree--;
}

bool EtatEndormi::estFini() const{
    if(duree_<=0){
        return true;
    }
    else{
        return false;
    }
}
