#include "CreatureMagique.h"

CreatureMagique::CreatureMagique(const string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, unsigned int bonus):Creature(nom,attaque,defense,pointDeVie, energie),bonus_(bonus)
{}

CreatureMagique::~CreatureMagique()
{}

CreatureMagique::CreatureMagique(const CreatureMagique& creatureMagique)
{

}
