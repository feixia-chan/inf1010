#include "Creature.h"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
 ;

Creature::Creature():nom_(""), attaque_(0), defense_(0), pointDeVie_(0),
	energie_(0), experience_(0), niveau_(1) // A MODIFIER... (si necessaire)
{
	energieTotal_ = 0;
	experienceNecessaire_ = 0;
	pointDeVieTotal_ = 0;
}

Creature::Creature(const string& nom, unsigned int attaque,
	unsigned int defense, unsigned int pointDeVie, unsigned int energie):
	nom_(nom), attaque_(attaque), defense_(defense), pointDeVie_(pointDeVie),
	energie_(energie), experience_(0), niveau_(1) // A MODIFIER... (si necessaire)
{
	energieTotal_ = energie;
	experienceNecessaire_ = 100;
	pointDeVieTotal_ = pointDeVie;
}

Creature::~Creature() // A MODIFIER... (si necessaire)
{

}

string Creature::getNom() const
{
	return nom_;
}

unsigned int Creature::getAttaque() const
{
	return attaque_;
}

unsigned int Creature::getDefense() const
{
	return defense_;
}

unsigned int Creature::getPointDeVie() const
{
	return pointDeVie_;
}

unsigned int Creature::getPointDeVieTotal() const
{
	return pointDeVieTotal_;
}

unsigned int Creature::getEnergie() const
{
	return energie_;
}

unsigned int Creature::getEnergieTotale() const
{
	return energieTotal_;
}

unsigned int Creature::getExperience() const
{
	return experience_;
}

unsigned int Creature::getExperienceNecessaire() const
{
	return experienceNecessaire_;
}

unsigned int Creature::getNiveau() const
{
	return niveau_;
}

Pouvoir Creature::getPouvoirs() const
{
	return pouvoir_;
}


void Creature::attaquer(Creature & creature)// A MODIFIER... (si necessaire)
{
	if (energie_ >= pouvoir_.getEnergieNecessaire())
    {
		if (creature.getPointDeVie() >= 0)
        {
			//Calcul du nombre de degat selon une formule
			unsigned int degat = (pouvoir_.getNombreDeDegat())* (attaque_ / 2 - creature.defense_);
			int tentative = rand() % 6;
			//l'attaque rate une fois sur 6
			if (tentative != 3) {
				cout << nom_ << " lance " << pouvoir_.getNom() << " qui inflige " << degat << " degat a " << creature.getNom() << endl;
				if (degat > creature.getPointDeVie()) {
					creature.setPointDeVie(0);
					int xp = experienceGagnee(creature);
					cout << nom_ << " a gagné " << xp << " XP" << endl;
				}
				else
					creature.setPointDeVie(creature.getPointDeVie() - degat);
				cout << creature.getNom() << " a encore " << creature.getPointDeVie() << " PV" << endl;
				energie_ -= pouvoir_.getEnergieNecessaire();
			}
			else {
				cout << "Attaque " << pouvoir_.getNom() << " a échouée" << endl;
			}
		}
		else
			cout << "Vous deja avez vaincu " << creature.getNom() << endl;
	}

}

int Creature::experienceGagnee(const Creature& creature)
{
	if (creature.getPointDeVie() <= 0)
    {
		//Calcul de l'experience selon une formule mystérieuse
		int experience = (creature.getNiveau() + 1 - niveau_) * ((creature.getAttaque() + 5 - attaque_) * (creature.getDefense() + 3 - defense_)) + (pointDeVie_ / 2);
		if (experience > (experienceNecessaire_ - experience_))
        {
			//Cas ou la creature va monter d'un niveau
			int experienceRestante = experience - (experienceNecessaire_ - experience_);
			niveau_++;
			attaque_ += 1;
			defense_ += 1;
			pointDeVie_ += 5;
			energie_ += 5;
			energieTotal_ += 5;
			pointDeVieTotal_ += 5;
			experience_ = experienceRestante;
			experienceNecessaire_ = experienceNecessaire_ * 15 / 10;
		}
		else
        {
			//Sinon elle recupère juste de l'expérience
			experience_ += experience;
		}
		return experience;
	}
	return 0;
}

void Creature::setAttaque(unsigned int attaque)
{
	attaque_ = attaque;
}

void Creature::setDefense(unsigned int defense)
{
	defense_ = defense;
}

void Creature::setPointDeVie(unsigned int pointDeVie)
{
	pointDeVie_ = pointDeVie;
}

void Creature::setEnergie(unsigned int energie)
{
	energie_ = energie;
}

void Creature::setExperience(unsigned int experience)
{
	experience_ = experience;
}

void Creature::setNiveau(unsigned int niveau)
{
	niveau_ = niveau;
}

void Creature::setPouvoirs(Pouvoir pouvoirs) // A MODIFIER... (si necessaire)
{
	pouvoir_ = pouvoirs;
}

void Creature::information() const // A MODIFIER... (si necessaire)
{
	cout << nom_ << " a " << attaque_ << " en attaque et " << defense_ << " en defense, " << endl
		<< "Il a " << pointDeVie_ << "/" << pointDeVieTotal_ << " PV et " << energie_ << "/" << energieTotal_ << " Energie" << endl
		<< "Il est au niveau " << niveau_ << " avec " << experience_ << "d'XP" << endl
		<< "Il lui manque " << experienceNecessaire_ - experience_ << " jusqu'au prochain niveau " << endl;
	cout << "Son pouvoir  est : ";
	pouvoir_.description();
	cout << endl;
}

// _______TP2________
