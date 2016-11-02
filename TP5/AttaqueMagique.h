/*
Fichier: AttaqueMagique.h
Auteur(s): Maude Carrier
Date de creation: 11 octobre 2016
Description: Caractèrise l'attaque magique
*/
#ifndef ETAT_CREATURE_H
#define ETAT_CREATURE_H

#include <iostream>
#include "Creature.h"

using namespace std;

class AttaqueMagique
{
public:
	AttaqueMagique(unsigned int duree) { duree_ = duree; }

	virtual ~AttaqueMagique() {} // À MODIFIER (si nécessaire...)

	unsigned int getDuree() const { return duree_; }
	void setDuree(unsigned int duree) { duree_ = duree; }

	virtual string getTypeAttaque() const { return typeid(AttaqueMagique).name(); }

    virtual void appliquerAttaque(Creature& creature) = 0; //à appliquer sur la créature qui possède ce pouvoir // À MODIFIER (si nécessaire...)
	virtual bool estFini() const { return true;	} //si vrai, informe la créature qu'elle peut retourner à l'état normal // À MODIFIER (si nécessaire...)

	friend ostream& operator<<(ostream& o, const AttaqueMagique& attaqueMagique) // À MODIFIER (si nécessaire...)
	{
		return o << "Attaque magique de type " << attaqueMagique.getTypeAttaque() << " avec une durée de " << attaqueMagique.duree_ << endl;
	}

protected:
    unsigned int duree_;
};
#endif




