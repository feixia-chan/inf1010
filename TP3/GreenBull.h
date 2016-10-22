/*
Fichier: GreenBull.h
Auteur(s): Alexandra LIN et Maxime HAUDEGOND
Date de creation: 4 octobre 2016
Date de modification:
Description: les greenbulls permettent de rendre de l'énergie
*/

#ifndef GREENBULL_H
#define GREENBULL_H

#include "ObjetMagique.h"
#include <iostream>

using namespace std;

class GreenBull : public ObjetMagique
{
    public:
        GreenBull();
        ~GreenBull();
        GreenBull(const string& nom , int bonus);
        //operator
        friend ostream& operator<<(ostream& flux, const GreenBull& potion);
        //surcharge de la méthode utiliserSur
        void utiliserSur(Creature& creature) const;
    private:
};

#endif // GREENBULL_H
