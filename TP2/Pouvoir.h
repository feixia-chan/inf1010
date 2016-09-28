#ifndef POUVOIR_H
#define POUVOIR_H

#include <string>
using namespace std;

class Pouvoir
{
public:
	Pouvoir();
	Pouvoir(const string& nom,
		unsigned int nombreDeDegat, unsigned int energieNecessaire);
	~Pouvoir();

	unsigned int getNombreDeDegat() const;
	unsigned int getEnergieNecessaire() const;
	string getNom() const;

	void setNombreDeDegat(unsigned int nombreDegat);
	void setEnergieNecessaire(unsigned int energieNecessaire);
	void setNom(const string& nom);

	void description() const; // A MODIFIER... (si necessaire)

	//________TP2________

    //constructeur par copie
    Pouvoir(const Pouvoir& pouvoir);
    //surcharges operateurs
    Pouvoir& operator=(const Pouvoir& pouvoir);
    bool operator==(const Pouvoir& pouvoir);
    friend ostream& operator<<(ostream& o, const Pouvoir& pouvoir);

private:
	string nom_;
	unsigned int nombreDeDegat_ ;
	unsigned int energieNecessaire_;

};

#endif
