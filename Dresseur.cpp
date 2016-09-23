#include "Dresseur.h"


//Constructeurs

Dresseur::Dresseur(){   //Constructeur par défaut

    nom_="";
    nombreCreatures_=0;
    nombreCreaturesMax_=2;
    creatures_=new Creature*[MAX_NOMBRE_CREATURES];
    for(unsigned int i=0;i<nombreCreaturesMax_;i++){
        creatures_[i]=nullptr;
    }
}

Dresseur::Dresseur(const string& nom){ //Constructeur avec nom
    nom_=nom;
    nombreCreatures_=0;
    nombreCreaturesMax_=2;
    creatures_=new Creature*[MAX_NOMBRE_CREATURES];
    for(unsigned int i=0;i<nombreCreaturesMax_;i++){
        creatures_[i]=nullptr;
    }
}

//Destructeur

Dresseur::~Dresseur(){
    for(unsigned int i=0;i<nombreCreaturesMax_;i++){
        delete creatures_[i];
    }
    delete [] creatures_;
    creatures_=nullptr;
}

//Accesseurs

string Dresseur::getNom() const{
    return nom_;
}

ObjetMagique Dresseur::getObjetMagique() const{
    return objetMagique_;
}

Creature** Dresseur::getCreatures() const{
    return creatures_;
}

unsigned int Dresseur::getNombreCreatures() const{
    return nombreCreatures_;
}

//Modificateurs

void Dresseur::setNom(const string& nom){
    nom_=nom;
}

void Dresseur::setObjetMagique(const ObjetMagique& objetMagique){
    objetMagique_=objetMagique;
}

void Dresseur::setCreature(Creature** creatures){
    creatures_=creatures;
}

//Ajouter ou retirer des créatures

bool Dresseur::ajouterCreature(const Creature& creature){
    for (unsigned int i=0; i<nombreCreaturesMax_;i++){
        if (creatures_[i]== &creature){
            return false;
        }
    }
    int c=0;
    while(creatures_[c]!=nullptr){
        c++;
    }
    creatures_[c]= new Creature(creature);
    nombreCreatures_++;
    if (nombreCreatures_==nombreCreaturesMax_){
        Creature** copie = new Creature*[nombreCreaturesMax_];
        for(unsigned int i=0;i<nombreCreaturesMax_;i++){
            copie[i]=creatures_[i];
        }
        delete [] creatures_;
        creatures_=nullptr;
        nombreCreaturesMax_*=2;
        creatures_= new Creature*[nombreCreaturesMax_];
        for(unsigned int i=0;i<nombreCreaturesMax_/2;i++){
            creatures_[i]=copie[i];
        }
        delete [] copie;
        copie = nullptr;

    }
    return true;
}

bool Dresseur::retirerCreature(const string& nom){
    for (unsigned int i=0;i<nombreCreaturesMax_;i++){
        if(creatures_[i]->getNom()==nom){
            creatures_[i]=nullptr;
            nombreCreatures_--;
            return true;
        }
    }
    return false;
}

//Objet magique pour soigner

void Dresseur::utiliserObjetMagique(Creature* creature){
    if(creature->getPointDeVie()+objetMagique_.getBonus()>=creature->getPointDeVieTotal()){
        creature->setPointDeVie(creature->getPointDeVieTotal());
    }
    else{
        creature->setPointDeVie(creature->getPointDeVie()+objetMagique_.getBonus());
    }
    if(creature->getEnergie()+objetMagique_.getBonus()>=creature->getEnergieTotale()){
        creature->setEnergie(creature->getEnergieTotale());
    }
    else{
        creature->setEnergie(creature->getEnergie()+objetMagique_.getBonus());
    }
}

//Affichage

void Dresseur::affichage() const
{
    cout<<"Le dresseur "<<this->getNom()<<" possède "<<this->getNombreCreatures()<<" créatures"<<endl;
}
