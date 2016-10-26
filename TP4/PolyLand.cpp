/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description:
*/
#include "PolyLand.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

PolyLand::PolyLand() {};


PolyLand::~PolyLand()
{
	while (creatures_.size() != 0)
	{
		delete creatures_.back();
		creatures_.back() = nullptr;
		creatures_.pop_back();
	}
	while (dresseurs_.size() != 0)
	{
		dresseurs_.back() = nullptr;
		dresseurs_.pop_back();
	}
}


bool PolyLand::ajouterDresseur(Dresseur* dresseur)
{
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		if (dresseur->getNom() == *(dresseurs_[i]))
		{
			cout << dresseur->getNom() << " n'a pas ete ajoute" << endl;
			return false;
		}
	}
	dresseurs_.push_back(dresseur);
	cout << dresseur->getNom() << " a bien �t� ajout� !" << endl;
	return true;
}

bool PolyLand::retirerDresseur(const string& nom)
{
	for (unsigned int i = 0; i < dresseurs_.size(); i++)
	{
		if (*(dresseurs_[i]) == nom)
		{
			dresseurs_[i] = dresseurs_.back();
			dresseurs_.pop_back();
			cout << nom << " a bien �t� retire !" << endl;
			return true;
		}
	}
	return false;
}

bool PolyLand::ajouterCreature(Creature* creature)
{
	creatures_.push_back(new Creature(*creature));
	cout << creature->getNom() << " a bien �t� ajout� !" << endl;
	return true;
}

bool PolyLand::retirerCreature(const string& nom)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (creatures_[i]->getNom() == nom)
		{
			delete creatures_[i];
			creatures_[i] = creatures_.back();
			creatures_.pop_back();
			cout << nom << " a bien �t� retire !" << endl;
			return true;
		}
	}
	return false;
}

Dresseur* PolyLand::choisirDresseurAleatoire()
{
	if (dresseurs_.size() > 0) {
		unsigned int indice = rand() % dresseurs_.size();
		return dresseurs_[indice];
	}
	else {
		return nullptr;
	}
}

Creature* PolyLand::choisirCreatureAleatoire()
{
	if (creatures_.size() > 0) {
		unsigned int indice = rand() % creatures_.size();
		return creatures_[indice];
	}
	else {
		return nullptr;
	}
}

bool PolyLand::attraperCreature(Dresseur* dresseur, Creature* creature)
{
	return dresseur->ajouterCreature(creature);
}

bool PolyLand::relacherCreature(Dresseur* dresseur, const string nomCreature)
{
	return dresseur->enleverCreature(nomCreature);
}

PolyLand& PolyLand::operator+= (Dresseur* dresseur)
{
	ajouterDresseur(dresseur);
	return *this;
}

PolyLand& PolyLand::operator-=(Dresseur* dresseur)
{
	retirerDresseur(dresseur->getNom());
	return *this;
}

PolyLand& PolyLand::operator+= (Creature* creature)
{
	ajouterCreature(creature);
	return *this;
}

PolyLand& PolyLand::operator-=(Creature* creature)
{
	retirerCreature(creature->getNom());
	return *this;
}

ostream& operator<<(ostream& os, const PolyLand& poly)
{
	for (unsigned int i = 0; i < poly.dresseurs_.size(); i++)
	{
		os << *(poly.dresseurs_[i]);
	}
	return os;
}
