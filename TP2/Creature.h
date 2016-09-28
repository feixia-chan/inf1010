#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "ObjetMagique.h"
#include "Pouvoir.h"

using namespace std;

class Creature
{
public:
	Creature(); // A MODIFIER... (si necessaire)
	Creature(const string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie); // A COMPLETER... (si necessaire)
	~Creature(); // A MODIFIER... (si necessaire)

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
	Pouvoir getPouvoirs() const; // A MODIFIER... (si necessaire)

	void attaquer(Creature& creature);// A MODIFIER... (si necessaire)
	int experienceGagnee(const Creature& creature);

	void setAttaque(unsigned int attaque);
	void setDefense(unsigned int defense);
	void setPointDeVie(unsigned int pointDeVie);
	void setEnergie(unsigned int energie);
	void setExperience(unsigned int experience);
	void setNiveau(unsigned int niveau);
	void setPouvoirs(const Pouvoir& pouvoirs); // A MODIFIER... (si necessaire)

	void information() const; // A MODIFIER... (si necessaire)

	// _________TP2___________

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

	// _________TP2___________

};

#endif