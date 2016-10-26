/*
Fichier: AttaqueMagique.h
Auteur(s): Alexandra LIN & Maxime HAUDEGOND
Date de creation: 26 octobre 2016
Description: classe abstraite pour les attaques des cr�atures magiques
*/


#ifndef ATTAQUEMAGIQUE_H
#define ATTAQUEMAGIQUE_H

#include <string>

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
        virtual string getTypeAttaque();    //nom modifi� pour rester coh�rent avec nos accesseurs
        virtual bool appliquerAttaque() =0;  //methode virtuelle pure rendant la classe abstraite
        virtual bool estFini();

        //op�rateurs

        //affichage
        //Cette cr�ature de la classe class CreatureMagique a aussi une attaque magique de type class AttaqueMagique qui a une dur�e de 1
        friend ostream& operator<< (ostream& flux, AttaqueMagique& AttaqueMagique);


    protected:
        int duree_;

    private:
};

#endif // ATTAQUEMAGIQUE_H
