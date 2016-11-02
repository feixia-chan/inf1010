/*
Fichier: AttaqueMagique.h
Auteur(s): Maude Carrier
Date de creation: 11 octobre 2016
Description: Caract�rise l'attaque magique
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

	virtual ~AttaqueMagique() {} // � MODIFIER (si n�cessaire...)

	unsigned int getDuree() const { return duree_; }
	void setDuree(unsigned int duree) { duree_ = duree; }

	virtual string getTypeAttaque() const { return typeid(AttaqueMagique).name(); }

    virtual void appliquerAttaque(Creature& creature) = 0; //� appliquer sur la cr�ature qui poss�de ce pouvoir // � MODIFIER (si n�cessaire...)
	virtual bool estFini() const { return true;	} //si vrai, informe la cr�ature qu'elle peut retourner � l'�tat normal // � MODIFIER (si n�cessaire...)

	friend ostream& operator<<(ostream& o, const AttaqueMagique& attaqueMagique) // � MODIFIER (si n�cessaire...)
	{
		return o << "Attaque magique de type " << attaqueMagique.getTypeAttaque() << " avec une dur�e de " << attaqueMagique.duree_ << endl;
	}

protected:
    unsigned int duree_;
};
#endif




