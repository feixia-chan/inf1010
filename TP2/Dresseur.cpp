#include "Dresseur.h"
#include <iostream>

Dresseur::Dresseur() :nom_("") {}; // A MODIFIER... (si necessaire)

Dresseur::Dresseur(const string& nom):	nom_(nom)
{
	creatures_ = new Creature*[MAX_NOMBRE_CREATURES](); // A MODIFIER... (si necessaire)
}


Dresseur::~Dresseur() // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < nombreCreatures_; i++)
	{
		delete creatures_[i];
		creatures_[i] = nullptr;
	}
	delete[]creatures_;
	creatures_ = nullptr;
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
	return nombreCreatures_;
}

Creature** Dresseur::getCreatures() const // A MODIFIER... (si necessaire)
{
	return creatures_;
}

void Dresseur::setCreature(Creature** creatures) // A MODIFIER... (si necessaire)
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

bool Dresseur::ajouterCreature(const Creature& creature) // A MODIFIER... (si necessaire)
{
	if (nombreCreatures_ < MAX_NOMBRE_CREATURES) {
		for (unsigned int i = 0; i < nombreCreatures_; i++)
		{
			if (creatures_[i]->getNom() == creature.getNom())
				return false;
		}
		creatures_[nombreCreatures_] = new Creature();
		*creatures_[nombreCreatures_] = creature;
		nombreCreatures_++;
	}
	else {
		return false;
	}
}

bool Dresseur::enleverCreature(const string& nom) // A MODIFIER... (si necessaire)
{
	for (unsigned int i = 0; i < nombreCreatures_; i++)
	{
		if (creatures_[i]->getNom() == nom)
		{
			nombreCreatures_--;
			creatures_[i] = creatures_[nombreCreatures_];
			delete creatures_[nombreCreatures_];
			creatures_[nombreCreatures_] = nullptr;

			return true;
		}
	}
	return false;
}

void Dresseur::affichage() const // A MODIFIER... (si necessaire)
{
	cout << nom_ << " possede " << nombreCreatures_  << " creature(s) "<< endl;
}

// ___TP2___
