#include "CreatureMagique.h"

CreatureMagique::CreatureMagique() : bonus_(0)
{
	attaqueMagique_ = nullptr;
}

CreatureMagique::CreatureMagique(const Creature& creature, unsigned int bonus) :bonus_(bonus), Creature(creature)
{
	attaqueMagique_ = nullptr;
}

CreatureMagique::CreatureMagique(const CreatureMagique & creatureMagique) : Creature(creatureMagique), bonus_(creatureMagique.bonus_)
{
	if (creatureMagique.getAttaque()->getTypeAttaque() == typeid(AttaqueMagiqueConfusion).name())
	{
		attaqueMagique_ = new AttaqueMagiqueConfusion(creatureMagique.getAttaque()->getDuree());
	}
	else
	{
		attaqueMagique_ = new AttaqueMagiquePoison(creatureMagique.getAttaque()->getDuree());
	}
}

CreatureMagique::~CreatureMagique()
{
	delete attaqueMagique_;
	attaqueMagique_ = nullptr;
}

CreatureMagique& CreatureMagique::operator=(const CreatureMagique& creatureMagique)
{
	if (this != &creatureMagique)
	{
		Creature c(creatureMagique);
		Creature::operator=(c);
		bonus_ = creatureMagique.bonus_;
		delete attaqueMagique_;
		if (creatureMagique.getAttaque()->getTypeAttaque() == typeid(AttaqueMagiqueConfusion).name())
		{
			attaqueMagique_ = new AttaqueMagiqueConfusion(creatureMagique.getAttaque()->getDuree());
		}
		else
		{
			attaqueMagique_ = new AttaqueMagiquePoison(creatureMagique.getAttaque()->getDuree());
		}
	}
	return *this;
}

void CreatureMagique::attaquer(const Pouvoir & pouvoir, Creature & creature)
{
    if (getPointDeVie() + bonus_ <= getPointDeVieTotal()) {
        setPointDeVie(getPointDeVie() + bonus_);
    }
    else {
        setPointDeVie(getPointDeVieTotal());
    }

	if (!attaqueMagique_->estFini()) //Si l'État est encore applicable
	{
		attaqueMagique_->appliquerAttaque(creature);  //On applique l'état sur la créature adverse
	}
	Creature::attaquer(pouvoir, creature); //Ensuite on attaque la créature
}

std::ostream& operator<<(std::ostream & os, const CreatureMagique& creature)
{
	Creature c(creature);
	os << c << "Cette créature de la " << creature.getTypeCreature() << "a aussi une attaque magique de type " << creature.getAttaque()->getTypeAttaque();
	os << " qui a une durée de " << creature.getAttaque()->getDuree() << std::endl;
    return os;
}

std::string CreatureMagique::getTypeCreature() const
{
	return (typeid(*this).name());
}

AttaqueMagique* CreatureMagique::getAttaque() const
{
	return attaqueMagique_;
}

unsigned int CreatureMagique::getBonus() const
{
	return bonus_;
}

void CreatureMagique::setBonus(unsigned int bonus)
{
	bonus_ = bonus;
}

void CreatureMagique::apprendreAttaqueMagique(const AttaqueMagique* attaqueMagique)
{
	if (attaqueMagique != nullptr)
	{
		delete attaqueMagique_;
	}
	if (attaqueMagique->getTypeAttaque() == typeid(AttaqueMagiqueConfusion).name())
	{
		attaqueMagique_ = new AttaqueMagiqueConfusion(attaqueMagique->getDuree());
	}
	else
	{
		attaqueMagique_ = new AttaqueMagiquePoison(attaqueMagique->getDuree());
	}
}

void CreatureMagique::oublierAttaqueMagique(const AttaqueMagique* attaqueMagique)
{
	if (attaqueMagique != nullptr)
	{
		delete attaqueMagique_;
		attaqueMagique_ = nullptr;
	}
}
