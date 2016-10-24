#include "EtatEmpoisonne.h"

EtatEmpoisonne::EtatEmpoisonne(const string& nom): EtatCreature(nom)
{
 type_=TypeEtat_empoisonne;
}

EtatEmpoisonne::EtatEmpoisonne(const string& nom, unsigned int duree): EtatCreature(nom,duree)
{
 type_=TypeEtat_empoisonne;
}

EtatEmpoisonne::~EtatEmpoisonne()
{

}

//Affichage
ostream& operator<<(ostream& o, const EtatEmpoisonne& etatCreature){
    o << "etat" << etatCreature.getNom() << endl;
    return o;
}

 void EtatEmpoisonne::appliquerEtat(Creature& creature){
     if(creature.getPointDeVie()>0){
     cout <<"on applique l'etat a la créature"<<endl;
    creature.setPointDeVie(creature.getPointDeVie()-5);
    cout << creature.getPointDeVie() << endl << endl;
    if(creature.getPointDeVie()<=0){
        creature.setPointDeVie(0);
    }
    duree_--;
     }
 }



  bool EtatEmpoisonne::estFini() const
  {

    return(duree_<=0);
  }
