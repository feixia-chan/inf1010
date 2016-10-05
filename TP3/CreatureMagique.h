/*
Fichier: CreatureMagique.h
Auteur(s): Alexandra LIN et Maxime HAUDEGOND
Date de creation: 4 octobre 2016
Date de modification:
Description: les creatures magiques sont des creatures avec un bonus
*/

#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include "Creature.h"


class CreatureMagique : public Creature
{
    public:
        CreatureMagique(const string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, unsigned int bonus);
        ~CreatureMagique();
        CreatureMagique(const CreatureMagique& creatureMagique);
        int getbonus_() { return bonus_; }
        void setbonus_(int val) { bonus_ = val; }
    private:
        unsigned int bonus_;
};

#endif // CREATUREMAGIQUE_H
