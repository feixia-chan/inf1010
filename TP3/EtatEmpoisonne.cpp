#include "EtatEmpoisonne.h"

EtatEmpoisonne::EtatEmpoisonne(const string& nom): EtatCreature(nom), type_(TypeEtat::TypeEtat_empoisonne)
{

}

EtatEmpoisonne::EtatEmpoisonne(const string& nom, unsigned int duree): EtatCreature(nom,duree), type_(TypeEtat::TypeEtat_empoisonne)
{

}

EtatEmpoisonne::~EtatEmpoisonne()
{

}


 void EtatEmpoisonne::appliquerEtat(Creature& creature){
    creature.setPointDeVie(creature.getPointDeVie()-5;
    if(creature.getPointDeVie()==0){
        creature.setPointDeVie(0);
    }
    duree --;
 }



  bool EtatEmpoisonne::estFini() const{
    return(duree_==0),
  }
