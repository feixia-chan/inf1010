/*
Fichier: PolyLand.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: Polyland represente le pays que l'on va explorer, il va contenir
            les differents elements de jeu
*/
#ifndef POLYLAND_H
#define POLYLAND_H

#include <vector>
#include <iostream>

#include "Dresseur.h"
#include "Creature.h"

using namespace std;

class PolyLand
{
public:
	PolyLand();
	~PolyLand();
	
	bool ajouterDresseur(Dresseur* dresseur);
	bool retirerDresseur(const string& nom);

	bool ajouterCreature(Creature* creature);
	bool retirerCreature(const string& nom);

	Dresseur* choisirDresseurAleatoire();
	Creature* choisirCreatureAleatoire();

	bool attraperCreature(Dresseur* dresseur, Creature* creature);
	bool relacherCreature(Dresseur* dresseur, const string nomCreature);

	PolyLand& operator+=(Dresseur* dresseur);
	PolyLand& operator-=(Dresseur* dresseur);
	PolyLand& operator+=(Creature* creature);
	PolyLand& operator-=(Creature* creature);

	friend ostream& operator<<(ostream& os, const PolyLand& poly);

private:
	vector<Dresseur*> dresseurs_;
	vector<Creature*> creatures_;
};
#endif