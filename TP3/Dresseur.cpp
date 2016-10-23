/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 6 septembre 2016 par Maude Carrier
*/
#include <iostream>

#include "Dresseur.h"

Dresseur::Dresseur() :nom_(""), equipe_("") {};

Dresseur::Dresseur(const string& nom, const string& equipe) : nom_(nom), equipe_(equipe) {
    objetMagique_= new ObjetMagique(); //sinon ca marche pas
};

Dresseur::~Dresseur()
{
    delete objetMagique_;
};

string Dresseur::getNom() const
{
	return nom_;
}

void Dresseur::setNom(const string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::getNombreCreatures() const
{
	return creatures_.size();
}

vector<Creature*> Dresseur::getCreatures() const
{
	return creatures_;
}

Creature* Dresseur::getUneCreature(const string& nom) const
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (*(creatures_[i]) == nom)
		{
			return creatures_[i];
		}

	}
	return nullptr;

}

void Dresseur::setCreature(vector<Creature*> creatures)
{
	creatures_ = creatures;
}

bool Dresseur::ajouterCreature(Creature* creature)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i] == *creature)
		{
			return false;
		}
	}
	creatures_.push_back(creature);
	return true;
}

bool Dresseur::enleverCreature(const string& nom)
{
	for (unsigned int i = 0; i < creatures_.size(); i++)
	{
		if (*creatures_[i] == nom)
		{
			creatures_[i] = creatures_.back();
			creatures_.pop_back();
			return true;
		}
	}
	return false;
}

ObjetMagique Dresseur::getObjetMagique() const
{
	return *objetMagique_;
}

void Dresseur::setObjetMagique(const ObjetMagique & objetMagique)
{
    delete objetMagique_;
    objetMagique_ = nullptr;
	objetMagique_ = new ObjetMagique(objetMagique);
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{
    objetMagique_->utiliserSur(*creature);
    delete objetMagique_;
    objetMagique_ = nullptr;
}

string Dresseur::getEquipe() const
{
	return equipe_;
}

void Dresseur::setEquipe(const string& equipe)
{
	equipe_ = equipe;
}

ostream& operator<<(ostream& os, const Dresseur& dresseur)
{
	return os << dresseur.nom_ << " possede " << dresseur.creatures_.size() <<
        " creature(s) et appartient a l'equipe " << dresseur.equipe_ << endl;
}

bool Dresseur::operator==(const Dresseur& dresseur) const
{
	if (creatures_.size() == 0 && dresseur.creatures_.size() == 0)
	{
		return true;
	}
	else if (creatures_.size() == dresseur.creatures_.size())
	{
		for (unsigned int i = 0; i < creatures_.size(); i++)
		{
			for (unsigned int j = 0; j < dresseur.creatures_.size(); j++)
			{
				if (*(creatures_[i]) == *(dresseur.creatures_[j]))
				{
					break;
				}
				else if (j = dresseur.creatures_.size() - 1)
				{
					return false;
				}
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

bool Dresseur::operator==(const string& nom) const
{
	return (nom_ == nom);
}

bool operator==(const string& nom, const Dresseur& dresseur)
{
	return dresseur == nom;
}
