/*
Fichier: Pouvoir.h
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 3 septembre 2016
Description: La classe Pouvoir correspond aux differents attaques
*/
#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
#include <iostream>


class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const std::string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	~Pouvoir();

	unsigned int getNombreDeDegat() const;
	unsigned int getEnergieNecessaire() const;
	std::string getNom() const;

	void setNombreDeDegat(unsigned int nombreDegat);
	void setEnergieNecessarie(unsigned int energieNecessaire);
	void setNom(const std::string& nom);

	Pouvoir(const Pouvoir& pouvoir);
	Pouvoir& operator=(const Pouvoir& pouvoir);

	bool operator==(const Pouvoir& pouvoir) const;

	friend std::ostream& operator<<(std::ostream& os, const Pouvoir& pouvoir);

private:
	std::string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;

};

#endif
