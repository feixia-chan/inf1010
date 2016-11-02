/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 6 septembre 2016 par Maude Carrier
*/

#include "Dresseur.h"


Dresseur::Dresseur() :nom_(""), equipe_("") {};

Dresseur::Dresseur(const std::string& nom, const std::string& equipe) : nom_(nom), equipe_(equipe) {};

Dresseur::~Dresseur()
{
}

std::string Dresseur::getNom() const
{
	return nom_;
}

void Dresseur::setNom(const std::string& nom)
{
	nom_ = nom;
}

unsigned int Dresseur::getNombreCreatures() const
{
	return creatures_.size();
}

auto Dresseur::getCreatures() const
{
	return creatures_;
}

Creature* Dresseur::getUneCreature(const std::string& nom) const //À MODIFIFIER !!
{
    /*complétez moi*/
	return;
}

void Dresseur::setCreature(std::list<Creature*> creatures) //A Compléter
{
	creatures_ = creatures;
}

bool Dresseur::ajouterCreature(Creature* creature)
{
    FoncteurEgalCreatures comparaison(creature);
    auto position_creature = find_if(creatures_.begin(), creatures_.end(), comparaison);
    if (position_creature != creatures_.end())
        return false;

	creatures_.push_back(creature);
	return true;
}

bool Dresseur::enleverCreature(const std::string& nom)
{
    FoncteurCreaturesDeMemeNom foncteurComparaison(nom);
    auto position = find_if(creatures_.begin(), creatures_.end(), foncteurComparaison);
    if (position == creatures_.end())
        return false;

    creatures_.erase(position);

	return true;
}

ObjetMagique Dresseur::getObjetMagique() const
{
	return objetMagique_;
}

void Dresseur::setObjetMagique(const ObjetMagique & objetMagique)
{
	objetMagique_ = objetMagique;
}

void Dresseur::utiliserObjetMagique(Creature* creature)
{

	if ((creature->getPointDeVieTotal() - creature->getPointDeVie()) >= objetMagique_.getBonus()) {
		creature->setPointDeVie(creature->getPointDeVie() + objetMagique_.getBonus());
	}
	else {
		creature->setPointDeVie(creature->getPointDeVieTotal());
	}
	if ((creature->getEnergieTotale() - creature->getEnergie()) > objetMagique_.getBonus()) {
		creature->setEnergie(creature->getEnergie() + objetMagique_.getBonus());
	}
	else {
		creature->setEnergie(creature->getEnergieTotale());
	}
}

std::string Dresseur::getEquipe() const
{
	return equipe_;
}

void Dresseur::setEquipe(const std::string& equipe)
{
	equipe_ = equipe;
}

bool Dresseur::operator==(const Dresseur& dresseur) const //A compléter
{
    if (creatures_.size() == 0 && dresseur.creatures_.size() == 0)
        return true;
    else if (creatures_.size() != dresseur.creatures_.size())
        return false;

    /*Complétez moi! Vérifiez l'égalité entre les créatures via
    find_if*/

	return true;
}

bool Dresseur::operator==(const std::string& nom) const
{
	return (nom_ == nom);
}

bool operator==(const std::string& nom, const Dresseur& dresseur)
{
	return dresseur == nom;
}

std::ostream& operator<<(std::ostream& os, const Dresseur& dresseur)
{
    return os << dresseur.nom_ << " possede " << dresseur.creatures_.size()
        << " creature(s) et appartient a l'equipe " << dresseur.equipe_ << std::endl;
}
