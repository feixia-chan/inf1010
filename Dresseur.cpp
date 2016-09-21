#include "Dresseur.h"
#include <iostream>

using namespace std;

//Constructeurs

Dresseur::Dresseur(){   //Constructeur par défaut

    nom_="";
    nombreCreatures_=0;
    nombreCreaturesMax_=2;
    creatures_=nullptr;
    objetMagique_=0;    //à modifier
}

Dresseur::Dresseur(const string& nom){ //Constructeur avec nom
    nom_=nom;
    nombreCreatures_=0;
    nombreCreaturesMax_=2;
    creatures_=nullptr;
    objetMagique_=0;    //à modifier
}

//Destructeur

Dresseur::~Dresseur(){

}

//Accesseurs

string Dresseur::getNom() const{
    return nom_;
}

ObjectMagique Dresseur::getObjetMagique() const{
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

bool Dresseur::ajouterCreature(const Creature creature){
    for (int i=0; i<creatures_->size();i++){
        if (creature==creatures_[i]){
            return false;
        }
    }
    int c=0;
    while(creatures_[c]=!nullptr){
        c++;
    }
    creatures_[c]=creature;
    if (creatures_->size()==nombreCreaturesMax_){
        nombreCreaturesMax_*=2;
    }
    return true;
}

bool Dresseur::retirerCreature(const string& nom){
    for (int i=0;i<creatures_->size();i++){
        if(creatures_[i]->getNom==nom){
            creatures_[i]=nullptr;
            return true;
        }
    }
    return false;
}

//Objet magique pour soigner

void Dresseur::utiliserObjetMagique(Creature* creature){
    if(creature->getPointDeVie()+objetMagique_.bonus>=creature->getPointDeVieTotal()){
        creature.setPointDeVie(creature->getPointDeVieTotal());
    }
    else{
        creature.setPointDeVie(creature->getPointDeVie()+objetMagique_.bonus);
    }
    if(creature->getEnergie()+objetMagique_.bonus>=creature->getEnergieTotale()){
        creature.setEnergie(creature->getEnergieTotale());
    }
    else{
        creature->setEnergie(creature->getEnergie()+objetMagique_.bonus);
    }
}

//Affichage

void Dresseur::affichage(){
    cout<<"Le dresseur "<<this->getNom()<<" possède "<<this->getNombreCreatures()<<" créatures"<<endl;
}
