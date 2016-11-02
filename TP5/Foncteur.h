#ifndef  FRONTEUR
#define  FRONTEUR

#include "Dresseur.h"
#include "Creature.h"
#include <string>
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

//Froncteur permettant d'obtenir l'attaque de la créature passée en argument
class FoncteurObtenirAttaqueCreature
{
public:
    FoncteurObtenirAttaqueCreature() {}
    ~FoncteurObtenirAttaqueCreature() {}

    unsigned int operator() (const Creature* creature) const {
        return creature->getAttaque();
    }
};

//Foncteur permettant de comparer le nom de deux créatures
class FoncteurCreaturesDeMemeNom
{
    public:
    FoncteurCreaturesDeMemeNom(string nom) {nom_=nom;}
    ~FoncteurCreaturesDeMemeNom() {}

    bool operator()(const Creature* creature) const
    {
        return nom_==creature->getNom();
    }

    private:
        string nom_;
};

//Foncteur permettant de comparer deux créatures
class FoncteurEgalCreature
{
public:
    FoncteurEgalCreature() {}
    ~FoncteurEgalCreature() {}

    bool operator()(const Creature* creature) const
    {
        return *creature_==*creature;
    }

private:
    Creature* creature_;
};

#endif;
