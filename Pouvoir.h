/*
Fichier: Pouvoir.h
Auteurs: AlexandrA LIN & Maxime HAUDEGOND
Date de creation: 14 sept 2016

Description: Un pouvoir demande une certaine quantité d’énergie pour être exécuté et
inflige un certain nombre de dégâts à une autre créature cible
*/


#ifndef POUVOIR_H_INCLUDED
#define POUVOIR_H_INCLUDED

using namespace std;

class Pouvoir{
public:
    //constructeurs
    Pouvoir();
    Pouvoir();
    //destructeur
    ~Pouvoir();
    //Accesseurs

    //Modificateurs

    private:
    //attributs
    string nom_;
    int nombreDeDegat_;
    int energieNecessaire_;

};

#endif // POUVOIR_H_INCLUDED
