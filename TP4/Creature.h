/*
Fichier: Creature.h
Auteur(s): Alexandre MAO, Maude CARRIER et Philippe TROCLET
Date de creation: 31 aout 2016
Date de modification: 11 octobre 2016 par Maude Carrier
Description: Les creatures sont des etres destines au combat
*/
#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "Pouvoir.h"
#include <vector>

class Creature
{
public:
	Creature();
	Creature(const std::string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie);
	~Creature();

	std::string getNom() const;
	unsigned int getAttaque() const;
	unsigned int getDefense() const;
	unsigned int getPointDeVie() const;
	unsigned int getPointDeVieTotal() const;
	unsigned int getEnergie() const;
	unsigned int getEnergieTotale() const;
	unsigned int getExperience() const;
	unsigned int getExperienceNecessaire() const;
	unsigned int getNiveau() const;
	std::vector<Pouvoir*> getPouvoirs() const;

	void attaquer(const Pouvoir& pouvoir,Creature& creature);
	int experienceGagnee(const Creature& creature);

	bool apprendrePouvoir(Pouvoir* pouvoir);
	bool oublierPouvoir(Pouvoir* pouvoir);

	void setNom(const std::string& nom);
	void setAttaque(unsigned int attaque);
	void setDefense(unsigned int defense);
	void setPointDeVie(unsigned int pointDeVie);
	void setEnergie(unsigned int energie);
	void setExperience(unsigned int experience);
	void setNiveau(unsigned int niveau);
	void setPouvoirs(std::vector<Pouvoir*> pouvoirs);

	Creature(const Creature& creature);
	Creature& operator=(const Creature& creature);

	bool operator==(const Creature& creature) const;
	bool operator==(const std::string& nom) const;
	friend bool operator==(const std::string& nom, const Creature& creature);

	friend std::ostream& operator<<(std::ostream& os, const Creature& creature); // � set (si n�cessaire...)

protected:

	std::string nom_;
	unsigned int attaque_;
	unsigned int defense_;
	unsigned int pointDeVie_;
	unsigned int pointDeVieTotal_;
	unsigned int energie_;
	unsigned int energieTotal_;
	unsigned int experience_;
	unsigned int experienceNecessaire_;
	unsigned int niveau_;
	std::vector<Pouvoir*> pouvoirs_;

};

#endif
