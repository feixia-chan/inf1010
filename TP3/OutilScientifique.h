/*
Fichier: ObjetScientifique.h
Auteur(s): Philippe Troclet
Date de creation: 30 septembre 2016
Description: Il s'agit des différents outils utilisables par un professeur
*/
#ifndef OUTIL_SCIENTIFIQUE_H
#define OUTIL_SCIENTIFIQUE_H

#include <string>

#include "Creature.h"

using namespace std;

class OutilScientifique
{
public:
    OutilScientifique(const string& nom, const string& description);
    ~OutilScientifique();

    string getNom() const;
    string getDesciption() const;

    void utiliser(Creature& creature);

    friend ostream& operator<<(ostream& os, const OutilScientifique& outil);
private:
    string nom_;
    string description_;
};
#endif // !OUTIL_SCIENTIFIQUE_H


