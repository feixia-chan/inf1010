#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand() // A MODIFIER... (si necessaire)
{
	dresseurs_ = new Dresseur*[MAX_DRESSEURS]();
	creatures_ = new Creature*[MAX_CREATURES]();
}


PolyLand::~PolyLand() // A MODIFIER... (si necessaire)
{
	delete[]dresseurs_;
	dresseurs_ = nullptr;

	for (unsigned int i = 0; i < nombreCreatures_; i++)
	{
		delete creatures_[i];
		creatures_[i] = nullptr;
	}
	delete[]creatures_;
	creatures_ = nullptr;

}

//accesseurs
vector<Dresseur*> PolyLand::getListeDresseurs(){
    return listeDresseurs_;
}
int PolyLand::getNombreDresseurs(){
    return nombreDresseurs_;
}
vector<Creature*> PolyLand::getListeCreatures(){
    return listeCreatures_;
}
int Polyland::getNombreCreatures(){
    return nombreCreatures_;
}

//modicateurs
void PolyLand::setListeDresseurs(const vector<Dresseur*>& listeD){
    listeDresseurs_=listeD;
}
void PolyLand::setNombreDresseurs(const int& nombreD){
    nombreDresseurs_=nombreD;
}
void PolyLand::setListeCreatures(const vector<Creature*>& listeC){
    listeCreatures_=listeC;
}
void PolyLand::setNombreCreatures(const int& nombreC){
    nombreCreatures_=nombreC;
}

bool PolyLand::ajouterDresseur(Dresseur* dresseur) //modifié
{

	for (unsigned int i = 0; i < nombreDresseurs_; i++)
	{
		if (listeDresseurs_[i]->getNom() == dresseur->getNom())
			return false;
	}
	nombreDresseurs_++;
	listeDresseurs_.push_back(dresseur);

	cout << dresseur->getNom() << " a bien été ajouté !" << endl;
	return true;
}

bool PolyLand::ajouterCreature(const Creature& creature) // A MODIFIER... (si necessaire)
{
	if(nombreCreatures_ >= MAX_CREATURES)
		return false;
	creatures_[nombreCreatures_] = new Creature();
	*creatures_[nombreCreatures_] = creature;
	nombreCreatures_++;
	cout << creature.getNom() << " a bien été ajouté !" << endl;
	return true;
}

bool PolyLand::retirerDresseur(const string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < nombreDresseurs_; i++)
	{
		if (listeDresseurs_[i]->getNom() == nom)
		{
		    if(i==nombreDresseurs_){    //le dresseur est en dernière position du tableau
                delete listeDresseurs_[i];
                listeDresseurs_.pop_back();
                cout << "Le dresseur " << nom <<" a bien été retiré ! << endl;
		    }
		    else{
                Dresseur* stockDresseur=listeDresseurs_[nombreDresseurs_];
                listeDresseurs_[nombreDresseur_]=listeDresseurs_[i];
                listeDresseurs_[i]=stockDresseur;

                //suppression du dresseur
                delete listeDresseur_[nombreDresseurs_];
                listeDresseurs_.pop_back();
                cout << "Le dresseur " << nom <<" a bien été retiré ! << endl;
            }
            return true;
		}
		else {  //message d'erreur
            cout <<" Le dresseur renseigné ne fait pas partie de Polyland. Il n'a pas pu être retiré." << endl;
			return false;
		}
}

bool PolyLand::retirerCreature(const string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < nombreCreatures_; i++)
	{
		if (creatures_[i]->getNom() == nom)
		{
			delete creatures_[i];
			creatures_[i] = creatures_[nombreCreatures_ - 1];
			creatures_[nombreCreatures_ - 1] = nullptr;
			nombreCreatures_--;
			return true;
		}
	}
	return false;
}

Dresseur* PolyLand::choisirDresseurAleatoire() // A MODIFIER... (si necessaire)
{
	if (nombreDresseurs_ > 0)
    {
		unsigned int indice = rand() % nombreDresseurs_;
		return dresseurs_[indice];
	}
	else
    {
		return nullptr;
	}
}

Creature* PolyLand::choisirCreatureAleatoire() // A MODIFIER... (si necessaire)
{
	if (nombreCreatures_ > 0)
    {
		unsigned int indice = rand() % nombreCreatures_;
		return creatures_[indice];
	}
	else {
		return nullptr;
	}
}

bool PolyLand::attraperCreature(Dresseur* dresseur,const Creature& creature) // A MODIFIER... (si necessaire)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const string& nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

void PolyLand::infoDresseur(const string& nom) const // A MODIFIER... (si necessaire)
{
	Dresseur* dresseur = nullptr;
	for (unsigned int i = 0; i < nombreDresseurs_; i++)
	{
		if (dresseurs_[i]->getNom() == nom)
		{
			dresseur = dresseurs_[i];
			break;
		}
	}
	if (dresseur != nullptr)
	{
		cout << "Informations sur le dresseur: " << endl;
		dresseur->affichage();
		for (unsigned int i = 0; i < dresseur->getNombreCreatures(); i++)
		{
			cout << "- " << i + 1 << " - ";
			dresseur->getCreatures()[i]->information();
		}
	}
	else
	{
		cout << "Dresseur introuvable!" << endl;
	}
}

//opérateurs
bool PolyLand::operator+=(const Dresseur& dresseur){
    return ajouterDresseur();
}
bool operator-=(const Dresseur& dresseur){
    return retirerDresseur(dresseur.getNom());
}
