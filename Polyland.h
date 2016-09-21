#ifndef POLYLAND_H
#define POLYLAND_H

#include <iostream>
#include <cstdlib>
#include "Dresseur.h"
#include "Creature.h"

using namespace std;

class Polyland
{
    public:
        //Constructeur et destructeur
        Polyland();
        ~Polyland();

        //Accesseurs
        int getNbDresseurs() const;
        int getNbCreatures() const;

        //Modifier le tableau de dresseurs
        void ajouterDresseur(const Dresseur& dresseur);
        void retirerDresseur(const string& nom);

        //Modifier le tableau créatures
        void ajouterCreature(Creature creature);
        void retirerCreature(string nom);

        //Méthodes de choix aléatoire
        Dresseur choisirDresseurAleatoire();
        Creature choisirCreatureAleatoire();

        //Attraper et relacher des créatures
        bool attraperCreature(Dresseur& dresseur, Creature& creature);
        bool relacherCreature(Dresseur& dresseur, Creature& creature);

        //Infos
        void infosDresseur(const string& nom) const;

    private:
        Dresseur** listeDresseur;
        int nombreDresseur_;
        Creature** listeCreature;
        int nombreCreature_;
};

#endif // POLYLAND_H
