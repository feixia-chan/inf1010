#include "AttaqueMagiqueConfusion.h"


AttaqueMagiqueConfusion::AttaqueMagiqueConfusion() :AttaqueMagique(MIN_DUREE_CONFUSION),foncteur_(FoncteurGenerateurNombresAlea(1,6)) // modifi�
{}

AttaqueMagiqueConfusion::AttaqueMagiqueConfusion(unsigned int duree) :AttaqueMagique(duree),foncteur_(FoncteurGenerateurNombresAlea(1,6)) //modifi�
{}

AttaqueMagiqueConfusion::~AttaqueMagiqueConfusion()
{
}

void AttaqueMagiqueConfusion::appliquerAttaque(Creature & creature) //modifi�
{
    if (duree_ > 0 && creature.getPointDeVie() >= 5)
	{
        unsigned int pointDeVie = creature.getPointDeVie();
        if (foncteur_ == 1)     //le foncteur va de 1 � 6 il peut pas �tre =0...
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
