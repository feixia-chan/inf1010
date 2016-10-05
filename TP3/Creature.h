/*
Fichier: Creature.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 30 septembre 2016 par Philippe Troclet
Description: Les creatures sont des etres destines au combat
*/
#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <vector>

#include "ObjetMagique.h"
#include "Pouvoir.h"
#include "EtatCreature.h"

using namespace std;

//Décarations anticipées pour que la compilation soit possible
class Pouvoir;

class EtatCreature;

class Creature
{
public:
	Creature();
	Creature(const string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie);
	~Creature();

	string getNom() const;
	unsigned int getAttaque() const;
	unsigned int getDefense() const;
	unsigned int getPointDeVie() const;
	unsigned int getPointDeVieTotal() const;
	unsigned int getEnergie() const;
	unsigned int getEnergieTotale() const;
	unsigned int getExperience() const;
	unsigned int getExperienceNecessaire() const;
	unsigned int getNiveau() const;
	vector<Pouvoir*> getPouvoirs() const;
    EtatCreature* getEtat();
	void attaquer(const Pouvoir& pouvoir, Creature& creature);
	int experienceGagnee(const Creature& creature);

	bool apprendrePouvoir(Pouvoir* pouvoir);
	bool oublierPouvoir(Pouvoir* pouvoir);

	void setNom(const string& nom);
	void setAttaque(unsigned int attaque);
	void setDefense(unsigned int defense);
	void setPointDeVie(unsigned int pointDeVie);
	void setEnergie(unsigned int energie);
	void setExperience(unsigned int experience);
	void setNiveau(unsigned int niveau);
	void setPouvoirs(vector<Pouvoir*> pouvoirs);
    void setEtat(EtatCreature* etat);

	Creature(const Creature& creature);
	Creature& operator=(const Creature& creature);

	bool operator==(const Creature& creature) const;
	bool operator==(const string& nom) const;
	friend bool operator==(const string& nom, const Creature& creature);

	friend ostream& operator<<(ostream& os, const Creature& creature);

private:

	string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	vector<Pouvoir*> pouvoirs_;
    EtatCreature* etat_;

    void revenirEtatNormal();
};

#endif
