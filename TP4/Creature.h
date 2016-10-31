/*
Fichier: Creature.h
Auteur(s): Alexandre MAO, Maude CARRIER et Philippe TROCLET
Date de creation: 31 aout 2016
Date de modification: 11 octobre 2016 par Maude Carrier
Description: Les creatures sont des etres destines au combat
*/
#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include "Pouvoir.h"
#include <vector>
#include <typeinfo>

using namespace std;

class Creature
{
public:
    Creature();
    Creature(const string& nom, unsigned int attaque,
             unsigned int defense, unsigned int pointDeVie, unsigned int energie);
    virtual ~Creature();

    string getNom() const;
    unsigned int getAttaque() const;
    unsigned int getDefense() const;
    unsigned int getPointDeVie() const;
    unsigned int getPointDeVieTotal() const;
    unsigned int getEnergie() const;
    unsigned int getEnergieTotale() const;
    unsigned int getExperience() const;
    unsigned int getExperienceNecessaire() const;
    unsigned int getNiveau() const;
    vector<Pouvoir*> getPouvoirs() const;

    virtual void attaquer(const Pouvoir& pouvoir,Creature& creature);
    int experienceGagnee(const Creature& creature);

    bool apprendrePouvoir(Pouvoir* pouvoir);
    bool oublierPouvoir(Pouvoir* pouvoir);

    void setNom(const string& nom);
    void setAttaque(unsigned int attaque);
    void setDefense(unsigned int defense);
    void setPointDeVie(unsigned int pointDeVie);
    void setEnergie(unsigned int energie);
    void setExperience(unsigned int experience);
    void setNiveau(unsigned int niveau);
    void setPouvoirs(vector<Pouvoir*> pouvoirs);

    string getTypeCreature() const;   //Virtuelle car on peut avoir des créatures créaturesMagique (d'ou l'utilisation de typeid)


    Creature(const Creature& creature);
    Creature& operator=(const Creature& creature);

    bool operator==(const Creature& creature) const;
    bool operator==(const string& nom) const;
    friend bool operator==(const string& nom, const Creature& creature);

    friend ostream& operator<<(ostream& os, const Creature& creature);

protected:

    string nom_;
    unsigned int attaque_;
    unsigned int defense_;
    unsigned int pointDeVie_;
    unsigned int pointDeVieTotal_;
    unsigned int energie_;
    unsigned int energieTotal_;
    unsigned int experience_;
    unsigned int experienceNecessaire_;
    unsigned int niveau_;
    vector<Pouvoir*> pouvoirs_;

};

#endif
