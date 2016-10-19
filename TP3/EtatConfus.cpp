#include "EtatConfus.h"


EtatConfus::EtatConfus(const string& nom): EtatCreature(nom)
{
    type_=TypeEtat_confus;
}

EtatConfus::EtatConfus(const string& nom, unsigned int duree): EtatCreature(nom, duree)
{

     type_=TypeEtat_confus;
}
}

EtatConfus::~EtatConfus()
{

}

ostream& operator<<(ostream& o, const EtatConfus& etatCreature){ //a vérifier !
    o << "etat" << etatCreature.nom_ << endl;
    return o;
}

bool EtatConfus::peutAttaquer() const {
    return rand() % 2 != 0;
}

void EtatConfus::appliquerEtat(Creature& creature){
    int degats= creature.getPointDeVie()*0.05 // degats = 5% de PV actuels
    if(rand() % 3 = 0){   //on a une chance sur trois que ca marche soit 33%
        //tests sur les 5% de PVT
        if(degats<=5){   //5% de PV < 5 PV
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

bool EtatConfus::estFini() const{
    if(duree_==0 || rand() % 3 = 0){
        //c'est finit
        return true;
    }
    else{
        return false;
    }
}
