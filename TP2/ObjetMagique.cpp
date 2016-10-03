#include "ObjetMagique.h"
#include <iostream>

ObjetMagique::ObjetMagique()
{
}

ObjetMagique::ObjetMagique(const string & nom, int bonus):
	nom_(nom), bonus_(bonus)
{
}


ObjetMagique::~ObjetMagique()
{
}

string ObjetMagique::getNom() const
{
	return nom_;
}

int ObjetMagique::getBonus() const
{
	return bonus_;
}

void ObjetMagique::setNom(const string& nom)
{
	nom_ = nom;
}

void ObjetMagique::setBonus(int bonus)
{
	bonus_ = bonus;
}

ostream& operator<< (ostream& flux, const ObjetMagique& potion){
    return flux << "l'objet " << potion.nom_ << "fournit un bonus de " << potion.bonus_;
}


void ObjetMagique::affichage() const // A MODIFIER... (si necessaire)
{
	cout << "l'objet " << nom_ << "fournit un bonus de " << bonus_ << endl;
}
