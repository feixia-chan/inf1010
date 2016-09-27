#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2

using namespace std;

class Dresseur
{
public:
	Dresseur(); // A MODIFIER... (si necessaire)
	Dresseur(const string& nom); // A MODIFIER... (si necessaire)
	~Dresseur(); // A MODIFIER... (si necessaire)

	string getNom() const;
	void setNom(const string& nom);

	unsigned int getNombreCreatures() const; // A MODIFIER... (si necessaire)

	Creature** getCreatures() const; // A MODIFIER... (si necessaire)
	void setCreature(Creature** creatures); // A MODIFIER... (si necessaire)

	ObjetMagique getObjetMagique() const;
	void setObjetMagique(const ObjetMagique& objetMagique);

	void utiliserObjetMagique(Creature* creature);

	bool ajouterCreature(const Creature& creature); // A MODIFIER... (si necessaire)
	bool enleverCreature(const string& nom); // A MODIFIER... (si necessaire)

	void affichage() const; // A COMPLETER... (si necessaire)

private:
	string nom_;
	ObjetMagique objetMagique_;

	// ___TP2____


};

#endif
