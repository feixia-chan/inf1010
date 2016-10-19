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

using namespace std;

class CreatureMagique : public Creature
{
    public:
        //Constructeur par parametres
        CreatureMagique(const string& nom, unsigned int attaque,
		unsigned int defense, unsigned int pointDeVie, unsigned int energie, unsigned int bonus);
		//Desstructeur
        ~CreatureMagique();
        //Constructeur par copie
        CreatureMagique(const CreatureMagique& creatureMagique);
        //Accesseurs/Modificateurs
        int getBonus() const;
        void setBonus(int bonus);
        //Méthode surchargée
        void attaquer(const Pouvoir& pouvoir, Creature& creature);
        //operator
        CreatureMagique& operator=(const CreatureMagique& creatureMagique);
        friend ostream& operator<<(ostream& os, const CreatureMagique& creatureMagique);

    private:
        unsigned int bonus_;
};

#endif // CREATUREMAGIQUE_H
