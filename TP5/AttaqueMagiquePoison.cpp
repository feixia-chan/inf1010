#include "AttaqueMagiquePoison.h"

AttaqueMagiquePoison::AttaqueMagiquePoison() : AttaqueMagique(MIN_DUREE_POISON),foncteur_(FoncteurGenerateurNombresAlea(1,6)) // modifié
{}

AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int duree) : AttaqueMagique(duree),foncteur_(FoncteurGenerateurNombresAlea(1,6)) // modifié
{}

AttaqueMagiquePoison::~AttaqueMagiquePoison()
{
}

void AttaqueMagiquePoison::appliquerAttaque(Creature & creature) //A modifier
{
	if (duree_ > 0 && creature.getEnergie() >= 5)
	{
		unsigned int energie = creature.getEnergie();
		if (generateurAleatoire() == 0)
		{
			creature.setEnergie(energie - 2);
		}
		duree_--;
	}
}

bool AttaqueMagiquePoison::estFini() const
{
    return (duree_ <= 0);
}

string AttaqueMagiquePoison::getTypeAttaque() const
{
	return (typeid(*this).name());
}
