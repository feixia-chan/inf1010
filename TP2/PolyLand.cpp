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

bool PolyLand::ajouterDresseur(Dresseur* dresseur) // A MODIFIER... (si necessaire)
{
	if (nombreDresseurs_ >= MAX_DRESSEURS)
		return false;
	for (unsigned int i = 0; i < nombreDresseurs_; i++)
	{
		if (dresseurs_[i]->getNom() == dresseur->getNom())
			return false;
	}
	dresseurs_[nombreDresseurs_++] = dresseur;
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
		if (dresseurs_[i]->getNom() == nom)
		{
			dresseurs_[i] = dresseurs_[nombreDresseurs_ - 1];
			dresseurs_[nombreDresseurs_ - 1] = nullptr;
			nombreDresseurs_--;
			return true;
		}
	}
	return false;
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
