#include "EtatConfus.h"


EtatConfus::EtatConfus(const string& nom): nom_(nom), duree_(0), type_(TypeEtat::TypeEtat_confus)
{

}

EtatConfus::EtatConfus(const string& nom, unsigned int duree): nom_(nom), duree_(duree), type_(TypeEtat::TypeEtat_confus)
{

}

EtatConfus::~EtatConfus()
{

}

ostream& operator<<(ostream& o, const EtatCreature& etatCreature){ //a vérifier !
    o << "etat" << etatCreature.nom_ << endl;
    return o;
}

bool peutAttaquer() const {
    return rand() % 2 != 0;
}

void appliquerEtat(Creature& creature){
    int degats= creature.getPointDeVie()*0.05 // degats = 5% de PVT
    if(rand() % 3 = 0){   //on a une chance sur trois que ca marche soit 33%
        //tests sur les 5% de PVT
        if(degats<=5){   //5% de PVT < 5 PV
            degats = 5;
        }
        //modification du nombre de PV de la créature
        creature.setPointDeVie(creature.getPointDeVie()-degats);
        //si la créature décède
        if(creature.getPointDeVie()<0){
            creature.setPointDeVie(0);
        }
        //on décrémente la durée de l'état
        duree_--;
    }
}

bool estFini() const{
    if(duree_==0 || rand() % 3 = 0){
        //c'est finit
        return true;
    }
    else{
        return false;
    }
}
