#ifndef OBJETMAGIQUE_H
#define OBJETMAGIQUE_H

#include <string>

using namespace std;

class ObjetMagique
{
public:
	ObjetMagique();
	ObjetMagique(const string &nom, int bonus);
	~ObjetMagique();

	string getNom() const;
	int getBonus() const;

	void setNom(const string& nom);
	void setBonus(int bonus);

	void affichage() const; // A MODIFIER... (si necessaire)

    friend ostream& operator<< (const ObjetMagique& potion, ostream& flux);


private:
	string nom_;
	int bonus_;
};

#endif
