#include "Pouvoir.h"
#include <iostream>


Pouvoir::Pouvoir()
{
}

Pouvoir::Pouvoir(const string& nom,
	unsigned int nombreDeDegat,	unsigned int energieNecessaire):
	nom_(nom), nombreDeDegat_(nombreDeDegat), energieNecessaire_(energieNecessaire)
{
}


Pouvoir::~Pouvoir()
{
}

unsigned int Pouvoir::getEnergieNecessaire() const
{
	return energieNecessaire_;
}

string Pouvoir::getNom() const
{
	return nom_;
}

unsigned int Pouvoir::getNombreDeDegat() const
{
	return nombreDeDegat_;
}

void Pouvoir::setNombreDeDegat(unsigned int nombreDegat)
{
	nombreDeDegat_ = nombreDegat;
}

void Pouvoir::setEnergieNecessaire(unsigned int energieNecessaire)
{
	energieNecessaire_ = energieNecessaire;
}

void Pouvoir::setNom(const string& nom)
{
	nom_ = nom;
}

void Pouvoir::description() const // A MODIFIER... (si necessaire)
{
	cout << nom_ << " necessite " << energieNecessaire_ << " energie et inflige " << nombreDeDegat_ << " degats" << endl;
}
