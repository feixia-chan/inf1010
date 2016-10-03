#include "Dresseur.h"
#include <iostream>

Dresseur::Dresseur() :nom_(""),equipe_("") {
    ObjetMagique potion;
    objetMagique_=potion;
    //pas d'initialisation du vecteur
};

Dresseur::Dresseur(const string& nom, const string& equipe):	nom_(nom),equipe_(equipe)
{
    ObjetMagique potion;
    objetMagique_=potion;
    //la capacité du vecteur se remplira toute seule
}


Dresseur::~Dresseur() //modifié
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		delete creatures_[i];
		creatures_.pop_back();
	}
}

string Dresseur::getNom() const
{
	return nom_;
}

void Dresseur::setNom(const string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::getNombreCreatures() const
{
	return creatures_.size();
}

vector <Creature*> Dresseur::getCreatures() const
{
	return creatures_;
}

void Dresseur::setCreature(const vector <Creature*>& creatures)
{
	creatures_ = creatures;
}

ObjetMagique Dresseur::getObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::setObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

string Dresseur::getEquipe(){
    return equipe_;
}

void Dresseur::setEquipe(const string& equipe){
    equipe_=equipe;
}

Creature* Dresseur::getUneCreature(const string& creature){
    bool trouve=false;
    int compteur = 0;
    while(!trouve && compteur<creatures_.size()){
        if (creatures_[compteur]->getNom() == creature){
            trouve=true;
        }
        else{
            compteur++;
        }
    }
    if(trouve){
        return creatures_[compteur];
    }
    else{
        cout <<"la créature que vous cherchez n'a pas été attrapée par ce dresseur" << endl;
        return nullptr;
    }
}


void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->getPointDeVieTotal() - creature->getPointDeVie()) >= objetMagique_.getBonus()) {
		creature->setPointDeVie(creature->getPointDeVie() + objetMagique_.getBonus());
	}
	else {
		creature->setPointDeVie(creature->getPointDeVieTotal());
	}
	if ((creature->getEnergieTotale() - creature->getEnergie()) > objetMagique_.getBonus()) {
		creature->setEnergie(creature->getEnergie() + objetMagique_.getBonus());
	}
	else {
		creature->setEnergie(creature->getEnergieTotale());
	}
}

bool Dresseur::ajouterCreature(Creature* creature)
{
		for (unsigned int i = 0; i < creatures_.size(); i++)
		{
			if (creatures_[i]->getNom() == creature->getNom())
				return false;   //si on a déjà la créature on peut pas l'ajouter
		}
		creatures_.push_back(new Creature(*creature));   //ajout d'une créature
		return true;
}

bool Dresseur::enleverCreature(const string& nom)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (creatures_[i]->getNom() == nom)
		{
		    if(i==creatures_.size()-1){
                //si c'est la derniere créature
                delete creatures_[i];
                creatures_.pop_back();
                cout << "la créature " << nom << "a bien été retirée !"<<endl;
		    }
		    else{
                //on déplace la créature à la fin du tableau
                Creature* stock = creatures_[creatures_.size()-1];
                creatures_[creatures_.size()-1]=creatures_[i];
                creatures_[i]=stock;

                //delete

                delete creatures_[creatures_.size()-1];
                creatures_.pop_back();
                cout << "la créature " << nom << "a bien été retirée !"<<endl;
		    }
			return true;
		}
	}
	return false;
}


void Dresseur::affichage() const // A MODIFIER... (si necessaire)
{
	cout << this << endl;
}

// ___TP2___

ostream& operator<<(ostream& flux, const Dresseur& dresseur){
    return flux << dresseur.nom_ << " possede " << dresseur.getNombreCreatures()  << " creature(s) et appartient à l'équipe "<< dresseur.equipe_ << endl;
}

bool Dresseur::operator==(Dresseur dresseur2) const{
    if(creatures_.size()==dresseur2.getCreatures().size()){
        for(int i=0; i<creatures_.size();i++){   //parcourt le vecteur de d1
            if(creatures_[i] == dresseur2.getUneCreature(creatures_[i]->getNom())){ //d2 possede la creature_[i]
                i++;
            }
            else{
                break;
            }
        }
        return true;    //toutes les créatures sont égales
    }
    return false;       //la taille ou les créatures sont différentes
}

bool Dresseur::operator==(const string& nom) const{
    return(nom_==nom);
}

bool operator==(const string& nom, const Dresseur& d2){
    return nom==d2.getNom();
}

