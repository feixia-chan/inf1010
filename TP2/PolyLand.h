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
	PolyLand();
	~PolyLand();

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

	bool ajouterDresseur(Dresseur* dresseur); //ajoute un dresseur dans PolyLand
	bool ajouterCreature(const Creature& creature); //ajoute une créature dans PolyLand

	bool retirerDresseur(const string& nom); //enlève le dresseur si existant
	bool retirerCreature(const string& nom); // enlève la créature si existante

	Dresseur* choisirDresseurAleatoire(); //
	Creature* choisirCreatureAleatoire(); //

	bool attraperCreature(Dresseur* dresseur, Creature* creature); //permet au dresseur d'ajouter la créature si attrapée
	bool relacherCreature(Dresseur* dresseur, const string& nomCreature); // supprime la créature du dresseur

	void infoDresseur(const string& nom) const;

	//________TP2_______
	friend ostream& operator<<(ostream& flux, const PolyLand& polyland); //affiche les infoDresseurs de polyland
	bool operator+=(Dresseur* dresseur);    //ajoute un dresseur dans Polyland
    bool operator-=(const Dresseur& dresseur); //enlève un dresseur de polyland

private:
	//________TP2_______
    vector<Dresseur*> listeDresseurs_;
    int nombreDresseurs_;
    vector<Creature*> listeCreatures_;
    int nombreCreatures_;
};


#endif
