/*
Fichier: EtatCreature.h
Auteur(s): Philippe Troclet
Date de creation: 30 septembre 2016
Description: Caractèrise l'état d'une créature, et l'impact qu'à ce dernier sur la
                dite créature
*/
#ifndef ETAT_CREATURE_H
#define ETAT_CREATURE_H

#include <iostream>

#include "Creature.h"
#include "TypeEtat.h"

using namespace std;

//déclaration anticipée nécessaire à cause des inclusions circulaires
class Creature;

class EtatCreature
{
public:
    EtatCreature(const string& nom);
    EtatCreature(const string& nom, unsigned int duree);
    ~EtatCreature();

    void appliquerEtat(Creature& creature); //à appliquer sur la créature qui possède ce pouvoir
    bool peutAttaquer() const; //détermine si l'état de la créature lui permet d'attaquer
    bool estFini() const; //si vrai, informe la créature qu'elle peut retourner à l'état normal

    string getNom() const;
    TypeEtat getType() const;

    friend ostream& operator<<(ostream& o, const EtatCreature& etatCreature);
private:
    string nom_;    //normal, confus, empoisonné ou endormi
protected:
    unsigned int duree_;    //durée de l'état nom_
    TypeEtat type_;     //normal, confus, empoisonné ou endormi
};
#endif // !ETAT_CREATURE_H




