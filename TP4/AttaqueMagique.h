/*
Fichier: AttaqueMagique.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 26 octobre 2016
Description: classe abstraite pour les attaques des cr�atures magiques
*/


#ifndef ATTAQUEMAGIQUE_H
#define ATTAQUEMAGIQUE_H

#include <string>
#include <iostream>
#include <typeinfo>
#include "Creature.h" //attention aux inclusions circulaires
#include <stdlib.h>


using namespace std;

class AttaqueMagique
{
public:
    //constructeurs & destructeurs
    AttaqueMagique(int duree);
    virtual ~AttaqueMagique();

    //accesseurs
    int getDuree() const;
    void setDuree(int& duree);

    //meths
    string getTypeAttaque() const;    //nom modifi� pour rester coh�rent avec nos accesseurs
    virtual bool appliquerAttaque(Creature& creatureAdverse) =0;  //methode virtuelle pure rendant la classe abstraite. on met un bool�en pour savoir si ca a march�
    virtual bool estFini();

    //op�rateurs

    //affichage
    // a aussi une attaque magique de type class AttaqueMagique qui a une dur�e de 1
    friend ostream& operator<< (ostream& flux, AttaqueMagique& AttaqueMagique);


protected:
    int duree_;

private:
};

#endif // ATTAQUEMAGIQUE_H
