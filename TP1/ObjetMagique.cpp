#include "ObjetMagique.h"

//Constructeurs
ObjetMagique::ObjetMagique()    //Constructeur par défaut
{
    nom_="";
    bonus_=0;
}

ObjetMagique::ObjetMagique(string nom, int bonus){  //Contructeur à paramètres
    nom_=nom;
    bonus_=bonus;
}

//Destructeur
ObjetMagique::~ObjetMagique()
{
    //dtor
}

//Accesseurs
string ObjetMagique::getNom() const{
    return nom_;
}

int ObjetMagique::getBonus() const{
    return bonus_;
}

//Modificateurs
void ObjetMagique::setNom(const string& nom){
    nom_=nom;
}

void ObjetMagique::setBonus(const int& bonus){
    bonus_=bonus;
}

//Affichage
void ObjetMagique::afficher() const{
    cout<<"L'objet "<<this->getNom()<<" confère un bonus de "<<this->getBonus()<<endl;
}
