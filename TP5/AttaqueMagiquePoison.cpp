#include "AttaqueMagiquePoison.h"

AttaqueMagiquePoison::AttaqueMagiquePoison() : AttaqueMagique(MIN_DUREE_POISON) // À MODIFIER
{}

AttaqueMagiquePoison::AttaqueMagiquePoison(unsigned int duree) : AttaqueMagique(duree) // À MODIFIER
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

std::string AttaqueMagiquePoison::getTypeAttaque() const
{
	return (typeid(*this).name());
}
