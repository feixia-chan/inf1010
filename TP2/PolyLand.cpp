#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand() // A MODIFIER... (si necessaire)
{
	nombreCreatures_=0;
	nombreDresseurs_=0;
}


PolyLand::~PolyLand() // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < listeDresseurs_.size(); i++)
	{
		delete listeDresseurs_[i];
		listeDresseurs_.pop_back();
	}

	for (unsigned int i = 0; i < listeCreatures_.size(); i++)
	{
		delete listeCreatures_[i];
		listeCreatures_.pop_back();
	}

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
int PolyLand::getNombreCreatures(){
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

bool PolyLand::ajouterDresseur(Dresseur* dresseur) //modifi�
{

	for (unsigned int i = 0; i < nombreDresseurs_; i++)
	{
		if (listeDresseurs_[i]->getNom() == dresseur->getNom())
			return false;
	}
	nombreDresseurs_++;
	listeDresseurs_.push_back(dresseur);

	cout << dresseur->getNom() << " a bien �t� ajout� !" << endl;
	return true;
}

bool PolyLand::ajouterCreature(const Creature& creature) // A MODIFIER... (si necessaire)
{
	if(nombreCreatures_ >= MAX_CREATURES)
		return false;
	listeCreatures_[nombreCreatures_] = new Creature(creature);
	nombreCreatures_++;
	cout << creature.getNom() << " a bien �t� ajout� !" << endl;
	return true;
}

bool PolyLand::retirerDresseur(const string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < nombreDresseurs_; i++)
	{
		if (listeDresseurs_[i]->getNom() == nom)
		{
		    if(i==nombreDresseurs_){    //le dresseur est en derni�re position du tableau
                delete listeDresseurs_[i];
                listeDresseurs_.pop_back();
                cout << "Le dresseur " << nom <<" a bien �t� retir� !" << endl;
		    }
		    else{
                Dresseur* stockDresseur=listeDresseurs_[nombreDresseurs_];
                listeDresseurs_[nombreDresseurs_]=listeDresseurs_[i];
                listeDresseurs_[i]=stockDresseur;

                //suppression du dresseur
                delete listeDresseurs_[nombreDresseurs_];
                listeDresseurs_.pop_back();
                cout << "Le dresseur " << nom <<" a bien �t� retir� !" << endl;
            }
            return true;
		}
		else {  //message d'erreur
            cout <<" Le dresseur renseign� ne fait pas partie de Polyland. Il n'a pas pu �tre retir�." << endl;
			return false;
		}
}

bool PolyLand::retirerCreature(const string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < nombreCreatures_; i++)
	{
		if (listeCreatures_[i]->getNom() == nom)
		{
		    if(i==nombreCreatures_){    //le dresseur est en derni�re position du tableau
                delete listeCreatures_[i];
                listeCreatures_.pop_back();
                cout << "La cr�ature " << nom <<" a bien �t� retir�e !" << endl;
		    }
		    else{
                Creature* stockCreature=listeCreatures_[nombreCreatures_];
                listeCreatures_[nombreCreatures_]=listeCreatures_[i];
                listeCreatures_[i]=stockCreature;

                //suppression du dresseur
                delete listeCreatures_[nombreCreatures_];
                listeCreatures_.pop_back();
                cout << "La cr�ature " << nom <<" a bien �t� retir�e !" << endl;
            }
            return true;
		}
		else {  //message d'erreur
            cout <<" La cr�ature renseign�e ne fait pas partie de Polyland. Elle n'a pas pu �tre retir�e." << endl;
			return false;
		}
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

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature) // A MODIFIER... (si necessaire)
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

//op�rateurs
bool PolyLand::operator+=(Dresseur* dresseur){
    return ajouterDresseur(dresseur);
}
bool PolyLand::operator-=(const Dresseur& dresseur){
    return retirerDresseur(dresseur.getNom());
}

ostream& operator<<(ostream& flux, const PolyLand& polyland){
    for(unsigned int i=0;i<listeDresseurs_.size();i++){
        flux<<listeDresseurs_[i]->affichage();
    }
    return flux;
}
