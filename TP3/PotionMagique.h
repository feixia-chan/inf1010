/*
Fichier: PotionMagique.h
Auteur(s): Alexandra LIN et Maxime HAUDEGOND
Date de creation: 4 octobre 2016
Date de modification:
Description: les potions magiques permettent de rendre de la vie
*/

#ifndef POTIONMAGIQUE_H
#define POTIONMAGIQUE_H

#include "ObjetMagique.h"
#include <iostream>

using namespace std;

class PotionMagique : public ObjetMagique
{
    public:
        PotionMagique();    //constructeur par défaut
        PotionMagique(const string& nom, int bonus);    //constructeur par paramètres
        ~PotionMagique();
        PotionMagique(const PotionMagique& potion); //constructeur par copie
        //operator
        friend ostream& operator<<(ostream& flux, const PotionMagique& potion);
        //surcharge de la méthode utiliserSur
        void utiliserSur(Creature& creature) const;
    private:
};

#endif // POTIONMAGIQUE_H
