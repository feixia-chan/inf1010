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
	Dresseur(const string& nom, const string& equipe);
	~Dresseur();

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

    Creature* getUneCreature(const string& creature); //methode obtenirUneCreature renomm�e de fa�on coh�rente avec nos accesseurs : retourne la cr�ature dont on a renseign� le nom

	void utiliserObjetMagique(Creature* creature);  //utiliser un objet
	bool ajouterCreature(Creature* creature); //dit si on a r�ussit � ajouter une cr�ature
	bool enleverCreature(const string& nom);    //retire la cr�ature de la liste

	void affichage() const;

    //op�rateurs
    friend ostream& operator<<(ostream& flux, const Dresseur& dresseur);
    friend bool operator==(const string& nom, const Dresseur& d2);   //nom==dresseur
    bool operator==(Dresseur dresseur2) const;  //compare les tableaux de cr�atures des dresseurs
    bool operator==(const string& nom) const;   //dresseur==nom

private:
	string nom_;
	ObjetMagique objetMagique_;
	string equipe_;
	vector<Creature*> creatures_;


	// ___TP2____


};

#endif
