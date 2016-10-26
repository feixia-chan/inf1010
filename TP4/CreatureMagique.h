/*
Fichier: CreatureMagique.h
Auteur(s): Alexandra LIN et Maxime HAUDEGOND
Date de creation: 26 octobre 2016
Description: Les creatures magiques sont des etres destines au combat et possèdent des attaques magiques
*/

#ifndef CREATUREMAGIQUE_H
#define CREATUREMAGIQUE_H

#include "Creature.h"

using namespace std;

class CreatureMagique : public Creature
{
    public:
        CreatureMagique();
        CreatureMagique(Creature creatute, unsigned int bonus);
        ~CreatureMagique();
        CreatureMagique(const CreatureMagique& creatureMagique);

        //Accesseurs et Modificateurs
        AttaqueMagique* getAttaqueMagique() const;
        unsigned int getBonus() const;
        void setBonus(unsigned int bonus);

        //Type de la créature
        string getTypeCreature() const;

        //Attaquer
        void attaquer(const Pouvoir& pouvoir, Creature& creature);

        //Appentissage et oubli d'attaque magique
        void apprendreAttaqueMagique(AttaqueMagique* attaqueMagique);
        void oublierAttaqueMagique();

        //operator
        operator=(const CreatureMagique& creatureMagique);
        friend ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique);

    private:
        AttaqueMagique* attaqueMagique_;
        unsigned int bonus_;
};

#endif // CREATUREMAGIQUE_H
