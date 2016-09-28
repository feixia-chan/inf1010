#ifndef DRESSEUR_H
#define DRESSEUR_H

#include <string>
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 2

using namespace std;

class Dresseur
{
public:
    //constructeurs et destructeur
	Dresseur();
	Dresseur(const string& nom, const string& equipe, const ObjetMagique potion); // A MODIFIER... (si necessaire)
	~Dresseur(); // A MODIFIER... (si necessaire)

	//accesseurs set/get
	string getNom() const;
	void setNom(const string& nom);
	unsigned int getNombreCreatures() const; //vecteur.size()

	vector <Creature*> getCreatures() const;
	void setCreature(const vector <Creature*>& creatures);

	ObjetMagique getObjetMagique() const;
	void setObjetMagique(const ObjetMagique& objetMagique);

    string getEquipe();
    void setEquipe(string& equipe);

    Creature* getUneCreature(Creature creature); //methode obtenirUneCreature renommée de façon cohérente avec nos accesseurs

	void utiliserObjetMagique(Creature* creature);
	bool ajouterCreature(const Creature& creature); // A MODIFIER... (si necessaire)
	bool enleverCreature(const string& nom); // A MODIFIER... (si necessaire)

	void affichage() const; // A COMPLETER... (si necessaire)
    //opérateurs
    friend ostream& operator<<(ostream& flux, Dresseur dresseur);

    friend bool operator==(const string nom, const Dresseur& d2);

private:
	string nom_;
	ObjetMagique objetMagique_;
	string equipe_;
	vector <Creature*> creature_;


	// ___TP2____


};
     bool operator==(const Dresseur& dresseur2) const;
     bool operator==(const string& nom) const;
#endif
