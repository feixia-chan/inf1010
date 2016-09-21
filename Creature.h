/*
Fichier: Creature.h
Auteurs: Alexandra LIN & Maxime HAUDEGOND
Date de creation: 14 sept 2016

Description: les créatures peuplent PolyLand
*/

#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include <string>
#include <iostream>
#include "Pouvoir.h"



using namespace std;

class Creature{
public:
    //constructeurs
    Creature();
    Creature(string nom, int attaque, int defense, int pointDeVie, int energie);

    //destructeur
    ~Creature();

    //accesseurs
    string getNom() const;
    int getAttaque() const;
    int getDefense() const;
    int getPointDeVie() const;
    int getPointDeVieTotal() const;
    int getEnergie() const;
    int getEnergieTotale() const;
    int getExperience()const ;
    int getExperienceNecessaire() const;
    int getNiveau() const;
    Pouvoir getPouvoir() const;

    //modificateurs
    void setNom(string nom) ;
    void setAttaque(int attaque) ;
    void setDefense(int defense) ;
    void setPointDeVie(int pv) ;
    void setPointDeVieTotal(int pvTotal) ;
    void setEnergie(int energie) ;
    void setEnergieTotale(int energieTotale) ;
    void setExperience(int xp) ;
    void setExperienceNecessaire(int xpNecessaire) ;
    void setNiveau(int lvl) ;
    void setPouvoir(Pouvoir pouvoir) ;

    //methodes
    void attaquer(Creature & creature);    // attaque la créature ciblée avec le pouvoir
    int experienceGagner(const Creature& creature);     //calcule et donne l'XP gagnée par la créature
    void information();     //affiche les stats de la créature

    private:
    //attributs
   string nom_;
   int attaque_;
   int defense_;
   int pointDeVie_;
   int pointDeVieTotal_;
   int energie_;
   int energieTotale_; //modification du nom de base energieTotal >> energieTotale
   int experience_;
   int experienceNecessaire_;
   int niveau_;
   Pouvoir pouvoir_;
};


#endif // CREATURE_H_INCLUDED
