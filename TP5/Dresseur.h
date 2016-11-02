/*
Fichier: Dresseur.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: les dresseurs sont les etres capables d'attraper des creatures
*/
#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <iostream>

#include "Creature.h"
#include "ObjetMagique.h"

using namespace std;

class Dresseur
{
public:
	Dresseur();
	Dresseur(const string& nom, const string& equipe);
	~Dresseur();

	string getNom() const;
	void setNom(const string& nom);

	unsigned int getNombreCreatures() const;

	auto getCreatures() const;
	Creature* getUneCreature(const string& nom) const; //À MODIFIFIER !!
	void setCreature(list<Creature*>  creatures);

	bool ajouterCreature(Creature* creature);
	bool enleverCreature(const string& nom);

	ObjetMagique getObjetMagique() const;
	void setObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	string getEquipe() const;
	void setEquipe(const string& equipe);

	friend ostream& operator<<(ostream& os, const Dresseur& dresseur);

	bool operator==(const Dresseur& dresseur) const;
	bool operator==(const string& nom) const;
	friend bool operator==(const string& nom, const Dresseur& dresseur);

private:
	string nom_;
	string equipe_;
	ObjetMagique objetMagique_;
	// À COMPLÉTER !! créatures

};

#endif
