/*
Fichier: ObjetMagique.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification:  6 septembre 2016 par Maude Carrier
Description: La classe ObjetMagique correspond aux differents objets utilisables
			par le dresseur sur ses creatures
*/
#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>
#include <iostream>

using namespace std;

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const string &nom, int bonus);
	~ObjetMagique();

	string getNom() const;
	int getBonus() const;

	void modifierNom(const string& nom);
	void modifierBonus(int bonus);

	friend ostream& operator<<(ostream& os, const ObjetMagique& objet);

private:
	string nom_;
	int bonus_;
};

#endif
