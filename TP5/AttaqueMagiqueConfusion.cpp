#include "AttaqueMagiqueConfusion.h"


AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() :AttaqueMagique(MIN_DUREE_CONFUSION) // À set
{}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) :AttaqueMagique(duree) // À set
{}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}

void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature) //A set
{
    if (duree_ > 0 && creature.getPointDeVie() >= 5)
	{
        unsigned int pointDeVie = creature.getPointDeVie();
        if (generateurAleatoire() == 0)
		{
            creature.setPointDeVie(pointDeVie - 2);
        }
        duree_--;
    }
}

bool AttaqueMagiqueConfusion::estFini() const
{
    return ( duree_ <= 0 );
}

std::string AttaqueMagiqueConfusion::getTypeAttaque() const
{
	return (typeid(*this).name());
}
