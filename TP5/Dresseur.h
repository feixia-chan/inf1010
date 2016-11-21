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
#include <list>
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

	list<Creature*> getCreatures() const;
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

	//Méthodes template
	template<typename predicat>
	void appliquerFoncteurUnaire(predicat predicatUnaire);
	template<typename predicat>
	void supprimerElements(predicat predicatUnaire);
	template<typename predicat>
	Creature* getCreatureMax(predicat predicatBin);

private:
	string nom_;
	string equipe_;
	ObjetMagique objetMagique_;
	// À COMPLÉTER !! créatures
	list<Creature*> creatures_;


};

//Méthodes template
template<typename predicat>
void Dresseur::appliquerFoncteurUnaire(predicat predicatUnaire)
{
    for_each(creatures_.begin(),creatures_.end(),predicatUnaire);
}

template<typename predicat>
void Dresseur::supprimerElements(predicat predicatUnaire)
{
	auto it = remove_if(creatures_.begin(), creatures_.end(), predicatUnaire);
	creatures_.erase(it, creatures_.end());
}

template<typename predicat>
Creature* Dresseur::getCreatureMax(predicat predicatBin)
{
    creatures_.sort(predicatBin);
    return *creatures_.begin(); //? Max veut dire la première ou la dernière ?
}

#endif
