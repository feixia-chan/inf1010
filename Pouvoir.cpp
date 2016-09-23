#include "Pouvoir.h"
//tableau polyland : un tableau de dresseur (pointeur). tableau cr�ature : ajouter cr�ature via copie.


    //constructeurs
Pouvoir::Pouvoir(){
    nom_="";
    nombreDeDegat_=0;
    energieNecessaire_=0;
}

Pouvoir::Pouvoir(string nom, int nombreDeDegat, int energieNecessaire){
    nom_=nom;
    nombreDeDegat_=nombreDeDegat;
    energieNecessaire_=energieNecessaire;
}

    //Destructeur
Pouvoir::~Pouvoir(){}

    //Accesseurs
string Pouvoir::getNom() const{
    return nom_;
}

int Pouvoir::getNombreDeDegat() const{
    return nombreDeDegat_;
}

int Pouvoir::getEnergieNecessaire() const{
    return energieNecessaire_;
}

//modificateurs
void Pouvoir::setNom(string nom){
    nom_=nom;
}

void Pouvoir::setNombreDeDegat(int nb){
    nombreDeDegat_=nb;
}

void Pouvoir::setEnergieNecessaire(int energie){
    energieNecessaire_=energie;
}
    //M�thode
void Pouvoir::description(){
    cout << "nom :" << this->getNom() <<endl;
    cout << "Force (nombre de d�gats) :" << this->getNombreDeDegat() <<endl;
    cout << "Energie n�cessaire :" << this->getEnergieNecessaire() <<endl;
}
