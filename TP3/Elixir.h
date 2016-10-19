/*
Fichier: Elixir.h
Auteur(s): Alexandra LIN et Maxime HAUDEGOND
Date de creation: 4 octobre 2016
Date de modification:
Description: les elixirs servent à soigner les créatures
*/

#ifndef ELIXIR_H
#define ELIXIR_H

#include "ObjetMagique.h"
#include <iostream>
#include <string>

using namespace std;

class Elixir : public ObjetMagique
{
    public:
        Elixir();   //constructeur par défaut
        Elixir(const string& nom, int bonus);   //constructeur par paramètres
        ~Elixir();
        Elixir(const Elixir& elixir);   //constructeur par copie
        //operator
        friend ostream& operator<<(ostream& flux, Elixir& elixir);
        //surcharge de utiliserSur
        void utiliserSur(Creature& creature) const;

    private:
};

#endif // ELIXIR_H
