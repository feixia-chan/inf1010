#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include <vector>
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2

using namespace std;

class Dresseur
{
public:
    //constructeurs et destructeur
	Dresseur();
	Dresseur(const string& nom, const string& equipe); // A MODIFIER... (si necessaire)
	~Dresseur(); // A MODIFIER... (si necessaire)

	//accesseurs set/get
	string getNom() const;
	void setNom(const string& nom);
	unsigned int getNombreCreatures() const; //vecteur.size()

	vector<Creature*> getCreatures() const;
	void setCreature(const vector<Creature*>& creatures);

	ObjetMagique getObjetMagique() const;
	void setObjetMagique(const ObjetMagique& objetMagique);

    string getEquipe();
    void setEquipe(const string& equipe);

    Creature* getUneCreature(const string& creature); //methode obtenirUneCreature renommée de façon cohérente avec nos accesseurs

	void utiliserObjetMagique(Creature* creature);
	bool ajouterCreature(Creature* creature); // modifié
	bool enleverCreature(const string& nom); // A MODIFIER... (si necessaire)

	void affichage() const; //a supprimer ?

    //opérateurs
    friend ostream& operator<<(ostream& flux, const Dresseur& dresseur);
    friend bool operator==(const string nom, const Dresseur& d2);
    bool operator==(Dresseur dresseur2) const;
    bool operator==(const string& nom) const;

private:
	string nom_;
	ObjetMagique objetMagique_;
	string equipe_;
	vector<Creature*> creatures_;


	// ___TP2____


};

#endif
