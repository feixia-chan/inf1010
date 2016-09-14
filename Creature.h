/*
Fichier: Creature.h
Auteurs: AlexandrA LIN & Maxime HAUDEGOND
Date de creation: 14 sept 2016

Description: les créatures peuplent PolyLand
*/

#ifndef CREATURE_H_INCLUDED
#define CREATURE_H_INCLUDED

#include <string>
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
    void getNom() const;
    void getAttaque() const;
    void getDefense() const;
    void getPointDeVie() const;
    void getPointDeVieTotal() const;
    void getEnergie() const;
    void getEnergieTotale() const;
    void getExperience()const ;
    void getExperienceNecessaire() const;
    void getNiveau() const;
    void getPouvoir() const;

    //modificateurs
    String setNom(string nom) ;
    int setAttaque(int attaque) ;
    int setDefense(int defense) ;
    int setPointDeVie(int pv) ;
    int setPointDeVieTotal(int pvTotal) ;
    int setEnergie(int energie) ;
    int setEnergieTotale(int energieTotale) ;
    int setExperience(int xp) ;
    int setExperienceNecessaire(int xpNecessaire) ;
    int setNiveau(int lvl) ;
    Pouvoir setPouvoir(Pouvoir pouvoir) ;

    //methodes
    void attaquer(const Pouvoir & pouvoir, Creature & creature);    // attaque la créature ciblée avec le pouvoir
    int experienceGagner(const Creature& creature);     //calcule et donne l'XP gagnée par la créature
    void information();     //affiche les stats de la créature

    private:
    //attributs
   string nom_;
   int attaque_;
   int defense_;
   int pointDeVie_;
   int PointDeVieTotal_;
   int energie_;
   int energieTotale_; //modification du nom de base energieTotal >> energieTotale
   int experience_;
   int experienceNecessaire_;
   int niveau_;
   Pouvoir pouvoir_;
};


#endif // CREATURE_H_INCLUDED
