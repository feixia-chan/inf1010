/*
Fichier: Polyland.h
Auteur(s): Maxime HAUDEGOND & Alexandra LIN
Date de creation: 20 Septembre 2016

Description: les dresseurs sont les etres capables d'attraper des creatures
*/

#ifndef POLYLAND_H
#define POLYLAND_H

#include <iostream>
#include <cstdlib>
#include "Dresseur.h"
#include "Creature.h"

#define MAX_NOMBRE_CREATURES 1000
#define MAX_NOMBRE_DRESSEURS 100

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
        bool ajouterDresseur(Dresseur* dresseur);
        bool retirerDresseur(const string& nom);

        //Modifier le tableau créatures
        bool ajouterCreature(Creature creature);
        bool retirerCreature(string nom);

        //Méthodes de choix aléatoire
        Dresseur* choisirDresseurAleatoire();
        Creature* choisirCreatureAleatoire();

        //Attraper et relacher des créatures
        bool attraperCreature(Dresseur* dresseur, Creature creature);
        bool relacherCreature(Dresseur* dresseur, const string& nom);

        //Infos
        void infosDresseur(const string& nom) const;

    private:
        Dresseur** listeDresseur_;
        int nombreDresseur_;
        Creature** listeCreature_;
        int nombreCreature_;
};

#endif // POLYLAND_H
