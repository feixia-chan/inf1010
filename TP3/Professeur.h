/*
Fichier: Professeur.h
Auteur(s): Alexandra LIN et Maxime HAUDEGOND
Date de creation: 4 octobre 2016
Date de modification:
Description: les professeurs sont des dresseurs scientifiques
*/

#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "OutilScientifique.h"
#include "Dresseur.h"
#include <iostream>

using namespace std;

class Professeur: public Dresseur
{
    public:
        Professeur(const string& nom, const string& equipe);    //constructeur par paramètres
        Professeur(const Professeur& prof); //constructeur par copie
        ~Professeur();
        //Accesseurs/Modificateurs
        OutilScientifique* getOutil() const;
        void setOutil(OutilScientifique outil);
        //Soigner une créature
        void soigner(Creature& creature);
        //utiliser l'outil
        void utiliserOutil(Creature& creature);
        //operator
        Professeur& operator=(const Professeur& prof);

    private:
        OutilScientifique* outil_;
};

#endif // PROFESSEUR_H
