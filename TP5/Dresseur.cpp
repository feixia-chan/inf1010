/*
Fichier: Dresseur.cpp
Auteur(s): Alexandre MAO
Date de creation: 31 aout 2016
Date de modification: 6 septembre 2016 par Maude Carrier
*/

#include "Dresseur.h"


Dresseur::Dresseur() :nom_(""), equipe_("") {};

Dresseur::Dresseur(const string& nom, const string& equipe) : nom_(nom), equipe_(equipe) {};

Dresseur::~Dresseur()
{
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

list<Creature*> Dresseur::getCreatures() const
{
	return creatures_;
}

Creature* Dresseur::getUneCreature(const string& nom) const //� MODIFIFIER !!
{
	auto pos=find_if(creatures_.begin(),creatures_.end(), FoncteurCreaturesDeMemeNom(nom));
	if(pos!=creatures_.end()){
        return *pos;
	}
	else{
        return nullptr;
	}
}

void Dresseur::setCreature(list<Creature*> creatures) //A Compl�ter
{
	creatures_ = creatures;
}

bool Dresseur::ajouterCreature(Creature* creature)
{
    FoncteurEgalCreature comparaison(creature);
    auto position_creature = find_if(creatures_.begin(), creatures_.end(), comparaison);
    if (position_creature != creatures_.end())
        return false;

	creatures_.push_back(creature);
	return true;
}

bool Dresseur::enleverCreature(const string& nom)
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

string Dresseur::getEquipe() const
{
	return equipe_;
}

void Dresseur::setEquipe(const string& equipe)
{
	equipe_ = equipe;
}

bool Dresseur::operator==(const Dresseur& dresseur) const //A compl�ter
{
    if (creatures_.size() == 0 && dresseur.creatures_.size() == 0)
        return true;
    else if (creatures_.size() != dresseur.creatures_.size())
        return false;
    for(auto pos=creatures_.begin();pos!=creatures_.end();pos++){
        auto creature=find_if(dresseur.creatures_.begin(),dresseur.creatures_.end(),FoncteurEgalCreature(*pos));
        if(creature==dresseur.creatures_.end())
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

ostream& operator<<(ostream& os, const Dresseur& dresseur)
{
    return os << dresseur.nom_ << " possede " << dresseur.creatures_.size()
        << " creature(s) et appartient a l'equipe " << dresseur.equipe_ << endl;
}

//M�thodes template
template<typename predicat>
void Dresseur::appliquerFoncteurUnaire(predicat predicatUnaire)
{
    for_each(creatures_.begin();creatures_.end();predicatUnaire);
}

template<typename predicat>
void Dresseur::supprimerElement(predicat predicatUnaire)
{

}

template<typename predicat>
Creature* Dresseur::getCreatureMax(predicat predicatBin)
{
    sort(creatures_.begin();creatures_.end();predicatBin);
    return creatures_.begin(); //? Max veut dire la premi�re ou la derni�re ?
}
