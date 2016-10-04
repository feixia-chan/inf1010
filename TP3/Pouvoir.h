/*
Fichier: Pouvoir.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 30 septembre par Philippe Troclet
Description: La classe Pouvoir correspond aux differents attaques 
*/
#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <iostream>

#include "Creature.h"
#include "TypeEtat.h"

using namespace std;

class Creature;

class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const string& nom, 
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	~Pouvoir();

	unsigned int getNombreDeDegat() const;
	unsigned int getEnergieNecessaire() const;
	string getNom() const;
    TypeEtat getType() const; //renvoie le type, qui caractérise l'effet du pouvoir (ex: empoisonner)

	void setNombreDeDegat(unsigned int nombreDegat);
	void setEnergieNecessarie(unsigned int energieNecessaire);
	void setNom(const string& nom);

	Pouvoir(const Pouvoir& pouvoir);
	Pouvoir& operator=(const Pouvoir& pouvoir);

	bool operator==(const Pouvoir& pouvoir) const;

	friend ostream& operator<<(ostream& os, const Pouvoir& pouvoir);

    void appliquerEffetOffensif(Creature& creatureEnnemie);
    void appliquerEffetDefensif(Creature& creatureAllie);
protected:
	string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;
    TypeEtat type_;
};

#endif