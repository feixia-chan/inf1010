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
//Constructeur par copie
Pouvoir::Pouvoir(const Pouvoir& pouvoir)
{
    nom_=pouvoir.nom_;
    nombreDeDegat_=pouvoir.nombreDeDegat_;
    energieNecessaire_=pouvoir.energieNecessaire_;
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
	//cout << nom_ << " necessite " << energieNecessaire_ << " energie et inflige " << nombreDeDegat_ << " degats" << endl;
	cout<<*this<<endl;
}

//surcharge d'operateurs
Pouvoir& Pouvoir::operator=(const Pouvoir& pouvoir)
{
        nom_=pouvoir.nom_;
        nombreDeDegat_=pouvoir.nombreDeDegat_;
        energieNecessaire_=pouvoir.energieNecessaire_;
    return *this;
}

bool Pouvoir::operator==(const Pouvoir& pouvoir)
{
    return(nom_==pouvoir.nom_ && nombreDeDegat_==pouvoir.nombreDeDegat_ && energieNecessaire_==pouvoir.energieNecessaire_);
}

ostream& operator<<(ostream& o, const Pouvoir& pouvoir){
    return o<<pouvoir.nom_<< " fait "<<pouvoir.nombreDeDegat_<<" de degats et a besoin de "<<pouvoir.energieNecessaire_<<" PE";
}
