/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 11 octobre 2016 par Maude Carrier
*/
#include "Dresseur.h"
#include <iostream>

Dresseur::Dresseur() :nom_(""), equipe_("") {};

Dresseur::Dresseur(const string& nom, const string& equipe) : nom_(nom), equipe_(equipe) {};

Dresseur::~Dresseur()
{
    while (creatures_.size() != 0)
    {
        creatures_.back() = nullptr;
        creatures_.pop_back();
    }
}

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
            creatures_[i] = nullptr;
            creatures_[i] = creatures_.back();
            creatures_.pop_back();
            return true;
        }
    }
    return false;
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

    if ((creature->getPointDeVieTotal() - creature->getPointDeVie()) >= objetMagique_.getBonus())
    {
        creature->setPointDeVie(creature->getPointDeVie() + objetMagique_.getBonus());
    }
    else
    {
        creature->setPointDeVie(creature->getPointDeVieTotal());
    }
    if ((creature->getEnergieTotale() - creature->getEnergie()) > objetMagique_.getBonus())
    {
        creature->setEnergie(creature->getEnergie() + objetMagique_.getBonus());
    }
    else
    {
        creature->setEnergie(creature->getEnergieTotale());
    }
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
    return os << dresseur.nom_ << " possede " << dresseur.creatures_.size() << " creature(s) et appartient a l'equipe " << dresseur.equipe_ << endl;
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
