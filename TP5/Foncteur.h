#ifndef  FRONTEUR
#define  FRONTEUR

#include "Dresseur.h"
#include "Creature.h"
#include <string>
#include <stdlib.h>

#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 6

using namespace std;

//Foncteur permettant d'obtenir l'attaque de la cr�ature pass�e en argument
class FoncteurObtenirAttaqueCreature
{
public:
    FoncteurObtenirAttaqueCreature() {}
    ~FoncteurObtenirAttaqueCreature() {}

    unsigned int operator() (const Creature* creature) const
    {
        return creature->getAttaque();
    }
};

//Foncteur de comparaison des attaques de creatures
class FoncteurComparerCreatures
{

public:
    FoncteurComparerCreatures() {}
    ~FoncteurComparerCreatures() {}
    //return true si attaque de cr�ature1 < att. cr�ature2
    bool operator()(const Creature* creature1, const Creature* creature2)
    {
        return(creature1->getAttaque()<creature2->getAttaque());
    }
};

//foncteur de comparaison des noms de Dresseurs
class FoncteurComparerDresseurs
{
public:
    FoncteurComparerDresseurs() {}
    ~FoncteurComparerDresseurs() {}
    //return true si nom1 < nom2 (alphab�tiquement)
    bool operator()(const string& nom1, const string& nom2)
    {
        return (nom1<nom2); //operator< d�j� surcharg� pour string

    }


};

//foncteur de comparaison du nombre de d�gats des pouvoirs
class FoncteurComparerPouvoirs
{
public:
    FoncteurComparerPouvoirs() {}
    ~FoncteurComparerPouvoirs() {}
    //renvoie true si pouvoir 1 a moins de degats que pouvoir2
    bool operator() (const Pouvoir* p1, const Pouvoir* p2)
    {
        return (p1->getNombreDeDegat()<p2->getNombreDeDegat());
    }
};



//Foncteur permettant de comparer le nom de deux cr�atures
class FoncteurCreaturesDeMemeNom
{
public:
    FoncteurCreaturesDeMemeNom(string nom):nom_(nom){}
    ~FoncteurCreaturesDeMemeNom() {}

    bool operator()(const Creature* creature) const
    {
        return nom_==creature->getNom();
    }

private:
    string nom_;
};

//Foncteur permettant de comparer deux cr�atures
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

//Foncteur incr�mentant compteur si min<=PV cr�ature<=max
class FoncteurCreatureVie
{
public:
    FoncteurCreatureVie(int min, int max):vieMin_(min),vieMax_(max),c$ompteur_(0) {}
    ~FoncteurCreatureVie() {}
    int getCompteur()
    {
        return compteur_;
    }
    void operator()(const Creature* creature)
    {
        if(min_<=creature->getPointDeVie()&& creature->getPointDeVie()<=max_)
        {
            compteur_++;
        }
    }

private:
    int vieMin_;
    int vieMax_;
    int compteur_

};

//Foncteur g�n�rant un nombre al�atoir dans l'intervalle
class FoncteurGenerateurNombresAlea
{
public:
    FoncteurGenerateurNombresAlea():min_(0),max_(6) {}
    FoncteurGenerateurNombresAlea(int min, int max):min_(min),max_(max) {}
    ~FoncteurGenerateurNombresAlea() {}
    //gen�re le nb al�atoire
    int operator()()
    {
        return rand()%max_ + min_; //[ min_ ; max_ ]
    }

private:
    int min_;   //borne inf
    int max_;   //borne sup

};

#endif;
