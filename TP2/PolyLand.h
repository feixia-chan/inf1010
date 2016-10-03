#ifndef POLYLAND_H
#define POLYLAND_H

#include "Dresseur.h"
#include "Creature.h"
#define MAX_DRESSEURS 100
#define MAX_CREATURES 1000
#define MAX_OBJET_MAGIQUE 100
#define MAX_POUVOIRS 10

using namespace std;

class PolyLand
{
public:
    //constructeur, destructeur
	PolyLand(); // A MODIFIER... (si necessaire)
	~PolyLand(); // A MODIFIER... (si necessaire)

	//accesseur
	vector<Dresseur*> getListeDresseurs();
	int getNombreDresseurs();
	vector<Creature*> getListeCreatures();
	int getNombreCreatures();

    //modificateurs
    void setListeDresseurs(const vector<Dresseur*>& listeD);
    void setNombreDresseurs(const int& nombreD);
    void setListeCreatures(const vector<Creature*>& listeC);
    void setNombreCreatures(const int& nombreC);

	bool ajouterDresseur(Dresseur* dresseur); // A MODIFIER... (si necessaire)
	bool ajouterCreature(const Creature& creature); // A MODIFIER... (si necessaire)

	bool retirerDresseur(const string& nom); // A MODIFIER... (si necessaire)
	bool retirerCreature(const string& nom); // A MODIFIER... (si necessaire)

	Dresseur* choisirDresseurAleatoire(); // A MODIFIER... (si necessaire)
	Creature* choisirCreatureAleatoire(); // A MODIFIER... (si necessaire)

	bool attraperCreature(Dresseur* dresseur, Creature* creature); // A MODIFIER... (si necessaire)
	bool relacherCreature(Dresseur* dresseur, const string& nomCreature); // A MODIFIER... (si necessaire)

	void infoDresseur(const string& nom) const; // A MODIFIER... (si necessaire)

	//________TP2_______
	friend ostream& operator<<(ostream& flux, const PolyLand& polyland);
	bool operator+=(Dresseur* dresseur);
    bool operator-=(const Dresseur& dresseur);

private:
	//________TP2_______
    vector<Dresseur*> listeDresseurs_;
    int nombreDresseurs_;
    vector<Creature*> listeCreatures_;
    int nombreCreatures_;
};


#endif
