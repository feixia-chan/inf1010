#include "AttaqueMagiqueConfusion.h"


AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() :AttaqueMagique(MIN_DUREE_CONFUSION),foncteur_(FoncteurGenerateurNombresAlea(1,6)) // modifié
{}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) :AttaqueMagique(duree),foncteur_(FoncteurGenerateurNombresAlea(1,6)) //modifié
{}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}

void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature) //A Moodifier
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

string AttaqueMagiqueConfusion::getTypeAttaque() const
{
	return (typeid(*this).name());
}
