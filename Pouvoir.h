/*
Fichier: Pouvoir.h
Auteurs: Alexandra LIN & Maxime HAUDEGOND
Date de creation: 14 sept 2016

Description: Un pouvoir demande une certaine quantit� d��nergie pour �tre ex�cut� et
inflige un certain nombre de d�g�ts � une autre cr�ature cible
*/


#ifndef POUVOIR_H_INCLUDED
#define POUVOIR_H_INCLUDED

using namespace std;

class Pouvoir{
public:
    //constructeurs
    Pouvoir();
    Pouvoir(string nom, int nombreDeDegat, int energieNecessaire);

    //destructeur
    ~Pouvoir();

    //Accesseurs
    void getNom() const;
    void getNombreDeDegat() const;
    void getEnergieNecessaire() const;

    //Modificateurs
    string setNom(string nom);
    int setNombreDeDegat(int nbDeDegat);
    int setEnergieNecessaire(int energie);

    //m�thode

    void description();


    private:
    //attributs
    string nom_;
    int nombreDeDegat_;
    int energieNecessaire_;
};

#endif // POUVOIR_H_INCLUDED
